#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;
    int count = 0;

    for (count = 0; count < 5; count++)
    {
        pid = fork();

        if (pid == 0) // Child process
        {
            exit(0);
        }
        else if (pid > 0) // Parent process
        {
            printf("Zombie process created, PID: %d\n", pid);
            sleep(1);
        }
        else // Fork failed
        {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }
    }

    pause(); // Suspend the parent process

    return (EXIT_SUCCESS);
}
