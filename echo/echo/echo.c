#include "echo.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>


int echo_cmd(char **stringname){
    while (*stringname != '\0'){
        printf("%s ", *stringname);
        stringname++;
    }
    printf("\n");
    return 0;
}
