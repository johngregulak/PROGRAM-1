#include "redirection.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


int main()
{
   int input;
   char str[256];

    printf( "Enter '1' to write to file, enter '2' to read from file : ");
   scanf("%d", &input);

   if (input == 1)
   {
        printf( "Enter a filename to write to : ");
        scanf("%s", str);
        printf( "\nYou entered: %s \n", str);
        file_direction(str, 0);
   }

    else if (input == 2)
   {
        printf( "Enter a filename to read from : ");
        scanf("%s", str);
        printf( "\nYou entered: %s \n", str);
        file_direction(str, 1);
   }
    else
    {
        file_direction(str, 2);
    }
   return 0;
}
