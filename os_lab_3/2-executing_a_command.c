#include<stdio.h>
#include<stdlib.h>


int main()
{
    const char* system_command = "ls";

    int status = system(system_command);
    if(status == -1)
    {
        printf("\nCan not execute system command.\n");
        exit(-1);
    }
    else
    {
        printf("\nSystem command is executed.\n");
    }
    return 0;
}