#include "log_writer.h"

int LogWriter::write_log(const std::string& log_line) {
    std::string new_line = "\n";
    int fd = open(
        "main.log",
        O_WRONLY|O_APPEND|O_CREAT
    );
    if (fd == -1) {
        return -1; // Ошибка при открытии файла
    }
    
    write(fd, log_line.c_str(), log_line.length());
    write(fd, new_line.c_str(), new_line.length());

    close(fd);

    return 0;
}


std::string LogWriter::get_current_time() {
    time_t current_time = std::time(nullptr);
    return ctime(&current_time);
}


int LogWriter::log_start_line(){
    std::string current_time = "00:00:00";
    std::string log_line = (
        "start programm with pid " +
        std::to_string(getpid()) +
        " at " +
        current_time
    );
    write_log(log_line);
    return 0;
}


int LogWriter::log_counter(long long int counter){
    std::string current_time = "00:00:00";
    std::string log_line = (
        "counter at " +
        current_time +
        " in process with pid " +
        std::to_string(getpid()) +
        " is " +
        std::to_string(counter)
    );
    write_log(log_line);
    return 0;
}


int LogWriter::log_copy_start(std::string copy_name) {
    std::string current_time = "00:00:00";
    std::string log_line = (
        copy_name + 
        " is started at " +
        current_time +
        " with pid " +
        std::to_string(getpid())
    );
    write_log(log_line);
    return 0;
}

int LogWriter::log_copy_finish(std::string copy_name) {
    std::string current_time = "00:00:00";
    std::string log_line = (
        copy_name + 
        " is finished at " +
        current_time
    );
    write_log(log_line);
}

int LogWriter::log_copy_error(std::string copy_name) {
    std::string log_line = (
        copy_name + 
        " is not finished"
    );
    write_log(log_line);
}