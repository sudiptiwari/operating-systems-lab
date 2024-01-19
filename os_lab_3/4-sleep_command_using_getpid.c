#include <stdio.h>
#include<stdlib.h> // for exit()
#include<unistd.h> // Unix Standard for fork(), sleep()

int main()
{
    // Get the PID of the current process
    int pid = getpid();
    printf("Process with PID %d is starting.\n", pid);

    // Forking to create a child process
    int id = fork();

    // Check if fork was successful
    if(id < 0)
    {
        printf("\nError: Cannot create child process.\n");
        exit(-1);
    } else if(id == 0)
    {
        // Code block for the child process
        printf("\nChild Process (PID=%d): Context switched from the parent process.\n", getpid());
    } else if(pid == getpid())
    {
        // Code block for the parent process
        printf("\nParent Process (PID=%d): Context switching to child process. Parent will sleep for 3 seconds...\n", getpid());
        
        // Sleep for 3 seconds to allow context switching
        sleep(3);

        // Parent wakes up after sleep
        printf("\nParent Process (PID=%d): Just woke up after 3 seconds!\n", getpid());
    }
    
    return 0;
}
