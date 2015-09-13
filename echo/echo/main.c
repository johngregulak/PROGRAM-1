#include "echo.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>



int main(){

    char *states[256] = {"California", "Oregon", "Washington",
    "Texas", "TEST", "Student", "Nick", "GET", "YOUR",
    "SHIT", "TOGETHER!", '\0'};
    echo_cmd(states);

    return 0;

}
