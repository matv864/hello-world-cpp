#include "process_launcher.h"
#include "log_writer.h"
#include <chrono> // for ms in timestamp
#include <iostream> // for debugging


uint64_t get_timestamp_ms() {
    using namespace std::chrono;
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

int main(int argc, char* argv[]) {
    if (argc >= 2) {
        if (argv[1][0] == '1') {
            std::cout << "start copy 1";
            return 0;
        }

        if (argv[1][0] == '2') {
            std::cout << "start copy 2";
            return 0;
        }
    }

    LogWriter::log_start_line();

    long long int counter = 0;
    uint64_t last_counter_increment = get_timestamp_ms();
    uint64_t last_counter_logging = get_timestamp_ms();
    uint64_t last_copies_launching = get_timestamp_ms();
    uint64_t current_time;

    while (1) {
        current_time = get_timestamp_ms();

        if ((current_time - last_counter_increment) >= 300) {
            last_counter_increment = current_time;
            counter++;
        }
        if ((current_time - last_counter_logging) >= 1000) {
            last_counter_logging = current_time;
            LogWriter::log_counter(counter);
        }
        if ((current_time - last_copies_launching) >= 3000) {
            last_copies_launching = current_time;
        }



    }

    return 0;
}