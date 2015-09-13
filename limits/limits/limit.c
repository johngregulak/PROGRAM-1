#include "limit.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>



int main(){

    pid_t childPID = fork();

    if (childPID == 0)  // child process
    {

        printf("Child process has completed.\n");
    }
    else if (childPID > 0)  // parent process
    {
        //wait for child process to finish
        printf("Parent process has completed.\n");
		waitpid(childPID, &status, 0);
    }
    else  // fork failed
    {
        printf("Fork() has failed!\n");
        return 1;
    }
    printf("=============================================================\n");
    printf("Printing Limits for Command:    \n")
    printf("=============================================================\n");
    printf("Max File Size:                               Bytes          |\n");
    printf("Max Open Files:                              Files          |\n");
    printf("Max Processes                                Processes      |\n");
    printf("Max Pending Signals:                         Signals        |\n");



    return 0;

}
