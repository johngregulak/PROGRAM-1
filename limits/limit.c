#include "limit.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


int main(){

    int childID, status;
    pid_t childPID = fork();
    char file[256] = "/proc/";
    char PID[256];
    char location[256] = "/limits";

    if (childPID == 0)  // child process
    {

        printf("Child process has completed.\n");
    }
    else if (childPID > 0)  // parent process
    {
        //wait for child process to finish

        childID = getpid();
        sprintf(PID, "%d", childID);
        printf("This is PID, childID: %s, %d\n", PID, childID);
        strcat(file, PID);
        strcat(file, location);
        //printf("Info is in: %s \n", file);
        FILE * fp;
        char limit_string[256];
        fp = fopen (file, "r");

        while (fgets(limit_string, sizeof(limit_string), fp)) {
        printf("%s", limit_string);
        }

        printf("Parent process has completed. Child ID is %d\n", childID);
		waitpid(childPID, &status, 0);
		fclose(fp);
    }
    else  // fork failed
    {
        printf("Fork() has failed!\n");
        return 1;
    }
    /*
    printf("|=====================================================================|\n");
    printf("|Printing Limits for Command:                                         |\n");
    printf("|=====================================================================|\n");
    printf("|Max File Size:                                            Bytes      |\n");
    printf("|Max Open Files:                                           Files      |\n");
    printf("|Max Processes                                             Processes  |\n");
    printf("|Max Pending Signals:                                      Signals    |\n");
    printf("\n");

    */
    return 0;

}
