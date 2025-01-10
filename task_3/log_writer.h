#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>


class LogWriter {
public:
    static void log_start_line();
    static void log_counter(long long int counter);
    static void log_copy_start(std::string copy_name);
    static void log_copy_finish(std::string copy_name);
    static void log_copy_error(std::string copy_name);

protected:
    static std::string get_current_time();

private:
    static int write_log(const std::string& log_line);
    
};
