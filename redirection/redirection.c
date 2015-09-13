#include "redirection.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>



int file_direction(char *filename, int flag)
{
    if (flag == 0){       //redirect output to file
        int status;
        int fd = open(filename, O_CREAT|O_WRONLY, 0777);
        printf("Return Value of FD: %d\n", fd);
        if (fd == -1)
        {
            printf("Error. Cannot Access File.\n");
            exit(1);
        }
        pid_t pid = fork();
        char *const cmdList[] = {"/bin/ls", "-l", NULL};
        if (pid == 0)     // child process
        {
            printf("Inside Child Process\n");
            close(1);
            dup(fd);
            close(fd);
            execv("/bin/ls", cmdList);

            printf("Unknown command\n");   //if execv doesn't work, it should print this statement
            exit(0);                       //then exit if it doesn't work
        }
        else if (pid > 0)     // parent process
        {
            printf("Inside Parent Process\n");
            waitpid(pid, &status, 0);
            close(fd);
        }
        else    // fork failed
        {
            printf("Fork() has failed!\n");
            return 1;
        }
    }

    else if (flag == 1){       //receive input from file
        int status;
        int fd = open(filename, O_RDONLY);
        printf("Return Value of FD: %d\n", fd);
        if (fd == -1)
        {
            printf("Error. Cannot Access File.\n");
            exit(1);
        }
        pid_t pid = fork();
        char *const inputList[] = {"./input", NULL};
        if (pid == 0)     // child process
        {
            printf("Inside Child Process\n");
            close(0);
            dup(fd);
            close(fd);
            execv("./input", inputList);

            printf("Unknown command\n");   //if execv doesn't work, it should print this statement
            exit(0);                       //then exit if it doesn't work

        }
        else if (pid > 0)     // parent process
        {
            printf("Inside Parent Process\n");
            waitpid(pid, &status, 0);
            close(fd);
        }
        else    // fork failed
        {
            printf("Fork() has failed!\n");
            return 1;
        }



    }

    else if (flag ==2){         //signal an error for invalid usage
        printf("Invalid Usage. Please try again.");
    }


}
