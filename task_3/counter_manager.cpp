#include "counter_manager.h"



long long int CounterManager::get_counter() {
    char data_from_file[128];
    int num_bytes = 128;

    int fd = open(
        "counter.txt",
        _O_RDONLY
    );
    if (fd == -1) {
        return 0; // Ошибка при открытии файла
    }
    
    read(fd, data_from_file, num_bytes);

    close(fd); 

    return atoi(data_from_file);
}


int CounterManager::set_counter(long long int new_counter) {
    std::string new_counter_string = std::to_string(new_counter);
    int fd = open(
        "counter.txt",
        O_WRONLY|O_TRUNC|O_APPEND|O_CREAT,
        0777
    );
    if (fd == -1) {
        return -1; // Ошибка при открытии файла
    }

    write(fd, new_counter_string.c_str(), new_counter_string.length());
    close(fd);

    return 0;
}