#include "process_launcher.h"
#include <iostream>

#ifdef _WIN32

// Для Windows используем CreateProcess
int ProcessLauncher::launch(const std::string& command) {
    return launchWindows(command);
}

int ProcessLauncher::launchWindows(const std::string& command) {
    STARTUPINFO si = { sizeof(STARTUPINFO) };
    PROCESS_INFORMATION pi;
    if (!CreateProcess(NULL, const_cast<char*>(command.c_str()), NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        std::cerr << "Ошибка запуска процесса: " << GetLastError() << std::endl;
        return -1;
    }

    return pi.dwProcessId; // Возвращаем PID процесса
}

int ProcessLauncher::waitForProcess(int pid) {
    return waitForProcessWindows((HANDLE)pid);
}

int ProcessLauncher::waitForProcessWindows(HANDLE processHandle) {
    DWORD exitCode;
    WaitForSingleObject(processHandle, INFINITE);
    if (GetExitCodeProcess(processHandle, &exitCode)) {
        return exitCode;
    }
    return -1;
}

#else

// Для UNIX-подобных систем используем fork и exec
int ProcessLauncher::launch(const std::string& command) {
    return launchUnix(command);
}

int ProcessLauncher::launchUnix(const std::string& command) {
    pid_t pid = fork();
    if (pid == -1) {
        std::cerr << "Ошибка fork" << std::endl;
        return -1;
    }

    if (pid == 0) { // Дочерний процесс
        execlp(command.c_str(), command.c_str(), (char*)NULL);
        // Если execlp вернул, значит произошла ошибка
        std::cerr << "Ошибка запуска команды: " << command << std::endl;
        exit(-1);
    }

    return pid; // Возвращаем PID процесса
}

int ProcessLauncher::waitForProcess(int pid) {
    return waitForProcessUnix(pid);
}

int ProcessLauncher::waitForProcessUnix(pid_t pid) {
    int status;
    if (waitpid(pid, &status, 0) == -1) {
        std::cerr << "Ошибка ожидания процесса" << std::endl;
        return -1;
    }

    if (WIFEXITED(status)) {
        return WEXITSTATUS(status); // Возвращаем код завершения процесса
    }
    return -1;
}

#endif