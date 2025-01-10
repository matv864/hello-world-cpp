#ifndef PROCESS_LAUNCHER_H
#define PROCESS_LAUNCHER_H

#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


class LogWriter {
public:
    static int log_start_line(int pid);

    

private:
    static int write_log(const std::string& log_line);
};

#endif // PROCESS_LAUNCHER_H