#ifdef _WIN32
    #include <windows.h>
#else
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <unistd.h>
#endif

#include <string>

class ProcessLauncher {
public:
    // Запуск программы в фоновом режиме
    static int launch(const std::string& command);

    // Ожидание завершения процесса и получение его кода возврата
    static int waitForProcess(int pid);

    // проверка запущен ли процесс
    static int isProcessActive(int pid);

private:
#ifdef _WIN32
    // Для Windows
    static int launchWindows(const std::string& command);
    static int waitForProcessWindows(HANDLE processHandle);
    static int isProcessActiveWindows(HANDLE processHandle);
#else
    // Для UNIX-подобных систем
    static int launchUnix(const std::string& command);
    static int waitForProcessUnix(pid_t pid);
    static int isProcessActiveUnix(pid_t pid);
#endif
};