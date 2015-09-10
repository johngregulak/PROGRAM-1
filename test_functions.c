#include "test_functions.h"
#include "utility.h"
#include<stdio.h>
#include<string.h>

void TestDeleteCharacter()
{
	printf("TestDeleteCharacter()\n");
	char* test_line = "This is a test line!\n";
	char* line = (char*)calloc(strlen(test_line)+1, sizeof(char));
	
	strcpy(line, test_line);
	printf("Deleting the word test from: ");
	printf(line);
	printf("\n");
	printf("The line length is: %i\n", strlen(line));
	
	line = DeleteCharacter(line, 10, 13);
	printf("The transformed line is: ");
	printf(line);
	printf("\n");
	printf("The line length is: %i", strlen(line));
	printf("\n\n\n");
	free(line);
}

void TestParseWhitespace()
{
	char* test_line = "    TEST!   HELLO! 	Again, test! test 	\ntest";
	printf("TestParseWhitespace()\n");
	char* line = (char*)calloc(strlen(test_line)+1, sizeof(char));
	
	strcpy(line, test_line);
	printf("Parsing whitespace from: ");
	printf(line);
	printf("\n");
	
	line = ParseWhitespace(line);
	printf("Line after parsing whitespace: ");
	printf(line);
	printf("\n\n\n");
	free(line);
}