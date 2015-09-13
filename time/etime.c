#include "etime.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/types.h>



int main(int argc, char *argv)
{

    struct timeval timeofday;
    gettimeofday(&timeofday, NULL);     //second value for timezone is null
    double beginning_time=timeofday.tv_sec+(timeofday.tv_usec/1000000.0);  //store the starting time




    pid_t childPID = fork();

    if (childPID == 0)  // child process
    {
        //execv();
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

    printf("--end of program--\n");

    gettimeofday(&timeofday, NULL);
    double finishing_time=timeofday.tv_sec+(timeofday.tv_usec/1000000.0); //get second time of day for comparison
    printf("Execution time: %f\n", finishing_time - beginning_time);


    return 0;


}
