#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Unix Standard for fork(), sleep()
#include <sys/wait.h>

int main()
{
    int id;
    id = fork(); // Process creation
    if (id < 0)
    {
        printf("\nCan not create child process.\n");
        exit(-1);
    }
    else if (id == 0) // Child process
    {
        printf("\nChild Process(PID=%d)\n", getpid());
        for (int i = 0; i < 5; ++i)
        {
            printf("\nChild Process(PID=%d) doing time pass..(%d)\n", getpid(),i); // Simulating child process to be busy with its own task
        }
    }
    else
    {
        // Parent Process
        printf("\nParent Process(PID=%d) waits for Child Process to complete after this and then carries on with Parent Process.\n", getpid());
        // wait();
        int status;
        wait(&status); // Wait for Child Process to execute fully.
        printf("Exit status of the child process: %d\n", WEXITSTATUS(status));
        printf("\nParent Process(PID=%d) is back after completion of child process.\n", getpid());
    }
    return 0;
}