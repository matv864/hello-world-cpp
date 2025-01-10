#include <string>
#include <fcntl.h>
#include <unistd.h>


class CounterManager {
public:
    static long long int get_counter();
    static int set_counter(long long int new_counter);
    
};
