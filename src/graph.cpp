#include "graph.hpp"

Graph::Graph(GTFS gtfs_data) {
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

            size_t from_index = this->station_lookup[current_stop.GetStopId()];
            size_t to_index = this->station_lookup[current_stop.GetStopId()];

            Time departure(current_stop.GetDepartureTime());
            Time arrival(next_stop.GetArrivalTime());

            Connection newConnection(from_index, to_index, departure, arrival);
            this->connections.push_back(newConnection);
            this->stations[from_index].add_connection(this->connections.size() - 1);
        }
    }
}

size_t Graph::GetStationIndex(std::string station_id) {
    return this->station_lookup[station_id];
}

std::vector<Connection> Graph::GetRoute(Time start_time, std::vector<size_t> stations) {
    Time current_time = start_time;

    std::vector<size_t> route_connection_indexes;

    Station* start_station = &this->stations.at(stations.at(0));
    Station* end_station = &this->stations.at(stations.back());

    std::vector<size_t> connection_indexes = start_station->getConnections();

    for (size_t i = 0; i < connections.size(); i++) {
        size_t current_index = connection_indexes.at(i);
        Connection* current = &this->connections.at(current_index);

        Station* to_station = &this->stations.at(current->GetTo());
        std::string to_station_id = to_station->GetId();

        std::string end_station_id = end_station->GetId();

        if (to_station_id == end_station_id) {
            route_connection_indexes.push_back(i);
        }
    }

    std::vector<Connection> route_connections;
    for (size_t i = 0; i < route_connection_indexes.size(); i++) {
        route_connections.push_back(this->connections.at(route_connection_indexes.at(i)));
    }

    return route_connections;
}
