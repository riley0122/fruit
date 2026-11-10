#include "graph.hpp"

Graph::Graph(GTFS gtfs_data) {
    std::cout << "Building graph..." << std::endl;
    std::vector<GTFS_Stop> gtfs_stops = gtfs_data.GetStops();

    std::unordered_map<std::string, std::string> station_id_map;
    std::unordered_set<std::string> parent_ids;
    for (size_t i = 0; i < gtfs_stops.size(); i++) {
        GTFS_Stop stop = gtfs_stops.at(i);
        if(stop.GetLocationType() == "0" && !stop.GetParentStation().empty()) {
            station_id_map[stop.GetId()] = stop.GetParentStation();
            parent_ids.insert(stop.GetParentStation());
        } else {
            station_id_map[stop.GetId()] = stop.GetId();
        }
    }

    std::stable_partition(gtfs_stops.begin(), gtfs_stops.end(), [parent_ids](GTFS_Stop stop) {
        return parent_ids.count(stop.GetId()) > 0;
    });
    
    for (size_t i = 0; i < gtfs_stops.size(); i++) {
        GTFS_Stop stop = gtfs_stops.at(i);
        std::string parent_id = station_id_map[stop.GetId()];

        if (stop.GetId() != parent_id) {
            this->station_lookup[stop.GetId()] = this->station_lookup[parent_id];
        } else {
            Station newStation(gtfs_stops.at(i));
            this->stations.push_back(newStation);
            this->station_lookup[newStation.GetId()] = i;
        }
    }

    std::unordered_map<std::string, std::vector<GTFS_Stop_time>> trip_map;
    std::vector<GTFS_Stop_time> stop_times = gtfs_data.GetStopTimes();

    for (size_t i = 0; i < stop_times.size(); i++) {
        GTFS_Stop_time stop_time = stop_times.at(i);
        trip_map[stop_time.GetTripId()].push_back(stop_time);
    }

    for (auto& pair : trip_map) {
        std::vector<GTFS_Stop_time> trip_stops = pair.second;

        std::sort(trip_stops.begin(), trip_stops.end(), [](GTFS_Stop_time a, GTFS_Stop_time b) {
            return std::stoi(a.GetStopSequence()) < std::stoi(b.GetStopSequence());
        });

        for (size_t i = 0; i < trip_stops.size() - 1; i++) {
            GTFS_Stop_time current_stop = trip_stops[i];
            GTFS_Stop_time next_stop = trip_stops[i + 1];

            if (!this->station_lookup.contains(current_stop.GetStopId()) || !this->station_lookup.contains(next_stop.GetStopId())) {
                continue;
            }

            size_t from_index = this->station_lookup[next_stop.GetStopId()];
            size_t to_index = this->station_lookup[current_stop.GetStopId()];

            Time departure(current_stop.GetDepartureTime());
            Time arrival(next_stop.GetArrivalTime());

            Connection newConnection(from_index, to_index, departure, arrival);
            this->connections.push_back(newConnection);
            this->stations[from_index].add_connection(this->connections.size() - 1);
        }
    }
    std::cout << "Finished building graph!" << std::endl;
}

size_t Graph::GetStationIndex(std::string station_id) {
    return this->station_lookup[station_id];
}

std::vector<Connection> Graph::GetRoute(Time start_time, std::vector<size_t> stations) {
    Time current_time = start_time;

    std::vector<size_t> route_connection_indexes;

    Station* start_station = &this->stations.at(stations.at(0));
    Station* end_station = &this->stations.at(stations.back());

    std::string end_station_id = end_station->GetId();

    std::vector<size_t> connection_indexes = start_station->getConnections();

    for (size_t i = 0; i < connection_indexes.size(); i++) {
        size_t current_index = connection_indexes.at(i);
        Connection* current = &this->connections.at(current_index);

        Station* to_station = &this->stations.at(current->GetTo());
        std::string to_station_id = to_station->GetId();

#ifdef DEBUG
        std::cout << "[" << current_index << "] Looking for: " << end_station_id << "; Got: " << to_station_id << std::endl;
#endif

        if (to_station_id == end_station_id) {
            route_connection_indexes.push_back(i);
            break;
        }
    }

    std::vector<Connection> route_connections;
    for (size_t i = 0; i < route_connection_indexes.size(); i++) {
        route_connections.push_back(this->connections.at(route_connection_indexes.at(i)));
    }

    return route_connections;
}

void Graph::Save() {
    std::ofstream outputfile("./graph.fruit");

    // Save format:
    // [creation date 6 bytes ddmmyy][station count 4 bytes][station data][connection count 4 bytes][connection data]

    auto now = std::chrono::system_clock::now();
    std::string date_str = std::format("{:%d%m%y}", now);
    char* date_str_data = date_str.data();
    outputfile.write(date_str_data, sizeof(char) * date_str.size());

    uint32_t station_count = this->stations.size();
    outputfile.write(reinterpret_cast<const char*>(&station_count), sizeof(station_count));

    for (int i = 0; i < this->stations.size(); i++) {
        this->stations[i].save(&outputfile);
    }

    uint32_t connection_count = this->connections.size();
    outputfile.write(reinterpret_cast<const char*>(&connection_count), sizeof(connection_count));

    for (int i = 0; i < this->connections.size(); i++) {
        Connection connection = this->connections[i];
        Station from_station = this->stations[connection.GetFrom()];
        Station to_station = this->stations[connection.GetTo()];
        connection.save(&outputfile, from_station, to_station);
    }

    outputfile.close();
}

Graph::Graph(std::string filepath) {
    // [creation date 6 bytes ddmmyy][station count 4 bytes][station data][connection count 4 bytes][connection data]
    std::string created_date = GetGraphFileCreationDate(filepath).insert(2, "/").insert(4, "/");
    std::cout << "Loading graph from " << created_date << "..." << std::endl;

    std::ifstream input_file(filepath);

    // skip date
    input_file.seekg(6);

    uint32_t station_count;
    input_file.read(reinterpret_cast<char*>(&station_count), sizeof(uint32_t));

    for (int i = 0; i < station_count; i++) {
        uint32_t station_name_length;
        input_file.read(reinterpret_cast<char*>(&station_name_length), sizeof(uint32_t));

        std::string station_name;
        station_name.resize(station_name_length);
        input_file.read(&station_name[0], sizeof(char) * station_name_length);

        uint32_t station_id_length;
        input_file.read(reinterpret_cast<char*>(&station_id_length), sizeof(uint32_t));

        std::string station_id;
        station_id.resize(station_id_length);
        input_file.read(&station_id[0], sizeof(char) * station_id_length);

        float lat;
        float lon;
        
        input_file.read(reinterpret_cast<char *>(&lat), sizeof(lat));
        input_file.read(reinterpret_cast<char *>(&lat), sizeof(lat));

        Position pos(lat, lon);

        Station readStation(station_name, station_id, pos);
        this->stations.push_back(readStation);
    }
}

std::string GetGraphFileCreationDate(std::string file_path) {
    std::ifstream input_file(file_path);

    char date_buffer[7] = {0};
    input_file.read(date_buffer, sizeof(char) * 6);
    std::string created_date(date_buffer);

    input_file.close();

    return created_date;
}
