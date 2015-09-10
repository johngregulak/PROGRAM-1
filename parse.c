#include "parse.h"
#include "utility.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* ReadInput()
{
	size_t BUFFER_SIZE = 512;
	char* input_string = (char*)calloc(BUFFER_SIZE, sizeof(char));
	if(fgets(input_string, (int)BUFFER_SIZE, stdin))
	{
		return input_string;
	}
	else
	{
		return NULL;
	}
}

char** ParseInput(char* input)
{
	char* working_line = input;
	working_line = ParseWhitespace(working_line);
	
	// debug message
	printf(working_line);
	
	char** split_args = ParseArguments(working_line);
	
	// debug message
	printf(working_line);
	
	split_args = ResolvePaths(split_args);
	
	// debug message
	PrintArgVector(split_args);
	
	split_args = ExpandVariables(split_args);
	
	// debug message
	PrintArgVector(split_args);
	
	free(working_line);
	working_line = NULL;
	
	return split_args;
}

char* ParseWhitespace(char* input)
{
	size_t it = 0;
	int whitespace_count = 0;
	char* line = input;
	char cur_char = line[it];
	
	// delete leading whitespace
	while (cur_char != '\0' && (cur_char == ' ' || cur_char == '\t' || cur_char == '\n'))
	{
		cur_char = line[++it];
		whitespace_count++;
	}
	line = DeleteCharacter(line, it-whitespace_count, it-1);
	
	// debug message
	printf("Made it through leading whitespace and deleted %i characters...\n",
		whitespace_count);
	printf(line);
	printf("\n");
	
	it = 0;
	whitespace_count = 0;
	
	// need flag to determine if currently operating on
	// trailing whitespace
	int contains_trailing = 0;
	// delete intermediate extra whitespace
	while (cur_char != '\0')
	{
		cur_char = line[it++];
		while (cur_char == ' ' || cur_char == '\t' || cur_char == '\n')
		{
			whitespace_count++;
			cur_char = line[it++];
			if (cur_char == '\0')
				contains_trailing = 1;
		}
		if (contains_trailing == 1)
		{
			if (whitespace_count > 0)
			{
				line = DeleteCharacter(line, it-whitespace_count-1, it-2);
			}
			break;
		}
		else if (whitespace_count > 1)
		{
			line = DeleteCharacter(line, it-whitespace_count-1, it-3);
			// must update iterator if array is changed through deletion
			it = it - (whitespace_count - 1);
		}
		whitespace_count = 0;
	}
	
	// debug message
	printf("Made it through intermediate whitespace...\n",
		whitespace_count);
	printf(line);
	printf("%i",strlen(line));
	printf("\n");
	
	// bug on return
	// current guess is somewhere writing over the return address
	// (buffer overflow)
	return line;
}

char** ParseArguments(char* input)
{
	return NULL;
}

char** ResolvePaths(char** args)
{
	return NULL;
}

char** ExpandVariables(char** args)
{
	return NULL;
}