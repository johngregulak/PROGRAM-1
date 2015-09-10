#include "utility.h"
#include<stdio.h>
#include<string.h>

void BigFree(char** array)
{
	size_t it = 0;
	char* line = array[it];
	
	while (line != NULL)
	{
			free(line);
			line = NULL;
			line = array[++it];
	}
}

void PrintArgVector(char** args)
{
	size_t it = 0;
	char* line = args[it];
	
	while (line != NULL)
	{
			printf(line);
			printf("\n");
			line = args[++it];
	}
}

char* DeleteCharacter(char* line, size_t start, size_t end)
{
	// Need to add 1 to number of characters deleted due to the start
	// and end iterators being inclusive
	size_t number_characters = start - end + 1;
	int current_length = strlen(line)+1;
	
	char* new_line = (char*)calloc(current_length - (int)number_characters, 
		sizeof(char));
		
	size_t it1 = 0;
	size_t it2 = 0;
	char cur_char = line[it1];
	while (cur_char != '\0')
	{
		if (!((it1 >= start) && (it1 <= end)))
		{
			new_line[it2++] = cur_char;
		}
		cur_char = line[++it1];
	}
	free(line);
	line = NULL;
	return new_line;
}