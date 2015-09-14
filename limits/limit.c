#include "limit.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


int main(){

    int childID, status, line_print;
    int line_count = 0;
    pid_t childPID = fork();
    char file[256] = "/proc/";
    char PID[256];
    char location[256] = "/limits";
    char limit_string[256];

    if (childPID == 0)  // child process
    {
        //execute command here. Get info from parent
        printf("Child process has completed.\n");
    }
    else if (childPID > 0)  // parent process
    {
        //wait for child process to finish
        waitpid(childPID, &status, 0);
        childID = getpid();
        sprintf(PID, "%d", childID);
        printf("This is PID, childID: %s, %d\n", PID, childID);
        strcat(file, PID);
        strcat(file, location);
        printf("Info is in: %s \n\n", file);

        FILE *limit_file;
        limit_file = fopen(file, "r");

        while (fgets(limit_string, sizeof(limit_string), limit_file)) {
                if ((line_count == 3) || (line_count ==7) || (line_count == 8) || (line_count == 12))
                {
                    printf("%s", limit_string);
                }
            line_count++;
        }
        printf("\nParent process has completed. Child ID is %d\n", childID);

		fclose(limit_file);
    }
    else  // fork failed
    {
        printf("Fork() has failed!\n");
        return 1;
    }

    return 0;

}
