// A collection of utility functions for the project
#ifndef _UTILITY_H
#define _UTILITY_H
#include<stdlib.h>

// Big free
// Deallocates the memory in a 2D character array
void BigFree(char** array);

// PrintArgVector
// Prints out each argument on a separate line
void PrintArgVector(char** args);

// DeleteCharacter
// Deletes a series of characters from a dynamic character array
// The start and end iterations are inclusive
char* DeleteCharacter(char* line, size_t start, size_t end);
#endif