#include "process_launcher.h"
#include <iostream>
#include <string>

int main() {
    std::string command;

    // В зависимости от ОС, выберем команду для запуска
#ifdef _WIN32
    command = "cmd /C echo Hello, World!";
#else
    command = "echo Hello, World!";
#endif

    // Запускаем процесс
    int pid = ProcessLauncher::launch(command);
    if (pid == -1) {
        std::cerr << "Не удалось запустить процесс." << std::endl;
        return -1;
    }

    std::cout << "Процесс с PID: " << pid << " запущен." << std::endl;

    // Ожидаем завершения процесса
    int exitCode = ProcessLauncher::waitForProcess(pid);
    std::cout << "Процесс завершился с кодом: " << exitCode << std::endl;

    return 0;
}