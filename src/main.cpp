#include <iostream>
#include "config.hpp"
#include "cli.hpp"
#include "gtfs.hpp"

Config* initialize_config();
CLI* initialize_cli(int argc, char* argv[]);
GTFS* initialize_gtfs(Config* config);

void run_plan(Config* config);

int main(int argc, char *argv[]) {
    Config* config = initialize_config();
    if (!config->GetIsValid()) {
        std::cout << "Invalid config file!" << std::endl;
        return 1;
    }

    CLI* cli = initialize_cli(argc, argv);
    if (!cli->GetIsValid()) {
        cli->usage(argv[0]);
        return 1;
    }

    switch (cli->GetCommand()) {
        case COMMAND_PLAN:
            run_plan(config);
            break;
        default:
            cli->usage(argv[0]);
            cli->help();
            break;
    }

    return 0;
}

Config* initialize_config() {
    Config* config = new Config("config.cfg");
    config->Read();
    return config;
}

CLI* initialize_cli(int argc, char* argv[]) {
    CLI* cli = new CLI(argc, argv);
    return cli;
}

GTFS* initialize_gtfs(Config* config) {
    GTFS* gtfs = new GTFS(config->GetGTFSFolderPath());
    gtfs->Read();
    return gtfs;
}

void run_plan(Config* config) {
    GTFS* gtfs = initialize_gtfs(config);
}
