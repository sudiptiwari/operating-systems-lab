#include <stdio.h>
#include <stdlib.h>
#include<unistd.h> // Unix Standard for fork(), sleep()

int main()
{
    int id;
    id = fork(); // Process creation
    if(id < 0)
    {
        printf("\nCan not create child process.\n");
        exit(-1);
    }
    else if(id == 0) // Child process
    {
        printf("\nHello from the child process.\n");
    }
    else
    {
        printf("\nHello from the parent process.\n");
    }
    return 0;
}