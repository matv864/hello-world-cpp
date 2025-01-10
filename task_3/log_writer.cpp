#include "log_writer.h"

int LogWriter::write_log(const std::string& log_line) {
    std::string new_line = "\n";
    int fd = open(
        "log.txt",
        O_WRONLY|O_APPEND|O_CREAT
    );
    if (fd == -1) {
        return -1; // Ошибка при открытии файла
    }
    
    write(fd, log_line.c_str(), log_line.length());
    write(fd, new_line.c_str(), new_line.length());

    return 0;
}


int LogWriter::log_start_line(int pid){
    write_log("hello");
    return 0;
}