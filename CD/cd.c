#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/***** JAMES LOOK AT THIS FUNCTION AND TRY TO BREAK IT! ******/

int main(){
	
	char *cd;
	char *new_cd;
	char input[256];
	int ret, set_ret;

	cd = getenv("PWD");
	printf("%s\n",cd);
	
/********** Changing Directories **************/
	
	printf("Input: ");
	scanf("%s",input);
	ret = chdir(input);
	//if ret is'0' it worked
	if(ret == 0){
		strcat(cd,"/");
		strcat(cd,input); //adds user file to env stored in cd
		printf("New env: %s\n",cd);
		set_ret = setenv("PWD",cd,1); //sets the PWD to the new env
		cd = getenv("PWD");
		printf("With PWD: %s\n",cd);		
	}
	else{
		perror("Error");
	}

/********************************************/
	return 0;
}
