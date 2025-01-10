#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>


class LogWriter {
public:
    static int log_start_line();
    static int log_counter(long long int counter);
    static int log_copy_start(std::string copy_name);
    static int log_copy_finish(std::string copy_name);
    static int log_copy_error(std::string copy_name);

protected:
    static std::string get_current_time();

private:
    static int write_log(const std::string& log_line);
    
};
