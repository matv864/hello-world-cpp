#include "log_writer.h"

int LogWriter::write_log(const std::string& log_line) {
    std::string new_line = "\n";
    int fd = open(
        "main.log",
        O_WRONLY|O_APPEND|O_CREAT,
        0777
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
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    std::string res = asctime (timeinfo);
    res.pop_back();
    return res;
}


void LogWriter::log_start_line(){
    std::string log_line = (
        "start programm with pid " +
        std::to_string(getpid()) +
        " at " +
        get_current_time()
    );
    write_log(log_line);
}


void LogWriter::log_counter(long long int counter){
    std::string log_line = (
        "counter at " +
        get_current_time() +
        " in process with pid " +
        std::to_string(getpid()) +
        " is " +
        std::to_string(counter)
    );
    write_log(log_line);
}


void LogWriter::log_copy_start(std::string copy_name) {
    std::string log_line = (
        copy_name + 
        " is started at " +
        get_current_time() +
        " with pid " +
        std::to_string(getpid())
    );
    write_log(log_line);
}

void LogWriter::log_copy_finish(std::string copy_name) {
    std::string log_line = (
        copy_name + 
        " is finished at " +
        get_current_time()
    );
    write_log(log_line);
}

void LogWriter::log_copy_error(std::string copy_name) {
    std::string log_line = (
        copy_name + 
        " is not finished"
    );
    write_log(log_line);
}