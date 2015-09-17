#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>


void exit_cmd(char *input_string){
    printf("Exiting shell...\n");
}

int main(){

	//below is to test exit_cmd

	char input_string[5];
	char compare_string[5] = "exit";

	printf("Please enter exit: ");
	scanf("%s",input_string);

    	int i = 0;
	for(i; i<5;i++){
        input_string[i]=tolower(input_string[i]);
	}
	printf("You entered in: '%s' \n",input_string);

    if (strcmp(input_string,compare_string) == 0){
        exit_cmd(input_string);
    }
    else{
        printf("Error: Unknown Command.\n");
    }

	return 0;
}
