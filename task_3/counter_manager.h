#include <string>
#include <fcntl.h>


class CounterManager {
public:
    static long long int get_counter();
    static int set_counter(long long int new_counter);
    
};
