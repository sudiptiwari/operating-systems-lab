#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Unix Standard for fork(), sleep()
#include <signal.h> // for kill()

int main()
{
    int id;
    id = fork();
    if (id < 0)
    {
        printf("\nCould not create a child process.\n");
        exit(-1);
    }
    else if (id == 0) /*Child Process*/
    {
        printf("\nChild Process(PID=%d) created.\n", getpid());
        printf("\nChild Process(PID=%d) killing Parent Process(PID=%d).\n", getpid(), getppid());

        // kill(getppid());

        // Send SIGTERM to terminate the process
        if (kill(getppid(), SIGTERM) == 0)
        {
            printf("Process with PID %d has been terminated.\n", getppid());
        }
        else
        {
            perror("Error killing process");
        }

        printf("\nChild Process(PID=%d) terminated Parent Process. Rest of the code of Parent Process will not execute.\n", getpid());
    }
    else
    {
        // This is a Parent Process.
        // Parent Process executes before child process normally.
        printf("\nParent Process(PID=%d) created.\n", getpid());
        printf("\nParent Process(PID=%d) going to sleep for 3 seconds. Rest of my code will not be executed. \n", getpid());
        sleep(3);
        printf("\nParent Process(PID=%d)'s this code after sleep will never be executed.\n", getpid());
    }
    return 0;
}