#include "log_writer.h"

#include <iostream>

int main(int argc, char* argv[]) {
    if (argc >= 2) {
        if (argv[1][0] == '1') {
            std::cout << "start copy 1";
            return 0;
        }

        if (argv[1][0] == '2') {
            std::cout << "start copy 2";
            return 0;
        }
    }

    std::cout << "launch main part\n";
    int res = LogWriter::log_start_line(1);
    std::cout << res;
    return 0;
}