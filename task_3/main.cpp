#include "process_launcher.h"
#include "log_writer.h"
#include "counter_manager.h"

#include <sys/time.h>


struct two_pid {
    int pid_1, pid_2;
};

#ifdef _WIN32
    // Для Windows
    struct two_pid launch_copies() {
        std::string command1 = "cmd /C main.exe 1";
        std::string command2 = "cmd /C main.exe 2";
        struct two_pid result;
        result.pid_1 = ProcessLauncher::launch(command1);
        result.pid_2 = ProcessLauncher::launch(command2);
        return result;
    }
#else
    // Для UNIX-подобных систем
    struct two_pid launch_copies() {
        std::string command1 = "./main 1";
        std::string command2 = "./main 2";
        struct two_pid result;
        result.pid_1 = ProcessLauncher::launch(command1);
        result.pid_2 = ProcessLauncher::launch(command2);
        return result;
    }
#endif


long long int get_timestamp_ms() {
    struct timeval tv;
    gettimeofday(&tv, NULL);

    return (((long long int)tv.tv_sec)*1000)+(tv.tv_usec/1000);

}

int main(int argc, char* argv[]) {
    if (argc >= 2) {
        if (argv[1][0] == '1') {
            LogWriter::log_copy_start("Copy 1");
            CounterManager::set_counter(CounterManager::get_counter() + 10);
            LogWriter::log_copy_finish("Copy 1");
            return 0;
        }

        if (argv[1][0] == '2') {
            LogWriter::log_copy_start("Copy 2");
            CounterManager::set_counter(CounterManager::get_counter() * 2);
            sleep(2);
            CounterManager::set_counter(CounterManager::get_counter() / 2);
            LogWriter::log_copy_finish("Copy 2");
            return 0;
        }
    }

    LogWriter::log_start_line();

    struct two_pid pid_of_copy_processes;

    long long int last_counter_increment = get_timestamp_ms();
    long long int last_counter_logging = get_timestamp_ms();
    long long int last_copies_launching = get_timestamp_ms();
    long long int current_time;

    while (1) {
        current_time = get_timestamp_ms();

        if ((current_time - last_counter_increment) >= 300) {
            last_counter_increment = current_time;
            CounterManager::set_counter(CounterManager::get_counter() + 1);
        }
        if ((current_time - last_counter_logging) >= 1000) {
            last_counter_logging = current_time;
            LogWriter::log_counter(CounterManager::get_counter());
        }
        if ((current_time - last_copies_launching) >= 3000) {
            last_copies_launching = current_time;
            pid_of_copy_processes = launch_copies();
        }
    }

    return 0;
}