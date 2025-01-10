#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


class CounterManager {
public:
    static long long int get_counter();
    static int set_counter(long long int new_counter);
    
};
