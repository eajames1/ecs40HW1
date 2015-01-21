#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "funix.h"
#include "permissions.h"
#include "directory.h"

int main(int argc, const char * argv[])
{	
	Funix *f = (Funix*)malloc(sizeof(Funix));
	run(f);
	return 0;
}

void cd(Funix *funix, int argCount, const char *arguments[])
{
	/*  Calls cd() with currentDirectory as one of its parameters
	*  Unsure of what to do with count/what count is
	*  cd(funix, count, funix->currentDirectory) */
	return;
}

int eXit(Funix *funix, int argCount, const char *arguments[])
{	
	/* checks "exit" command and returns 0 on proper exit */
	exit(0);
	return 0;
}

void init(Funix *funix)
{
	funix->currentDirectory = createDirectory( "/", funix->umask, 0 );
	funix->time++;
	return;
}

void ls(Funix *funix, int argCount, const char *arguments[])
{
	/* calls ls() with currentDirectory as one of its parameters
	* ls(funix, count, funix->currentDirectory); */
	return;
}

void mkdir(Funix *funix, int argCount, const char *arguments[])
{
	/* calls mkdir() with currentDirectory as one of its parameters
	* should make a new directory? Not exactly sure what that entails
	* mkdir(funix, count, funix->currentDirectory) */
	return;
}

int processCommand(Funix *funix, char *command)
{
	/* returns 0 on proper exit
	* If "exit" command is entered */
	const char *arr[NUM_COMMANDS];
	char *check;
	int i, j;
	for( i = 0, check = command; ; i++, check = NULL)
	{
		char *temp = strtok( check, " " );
		if( temp == NULL)
		{
            		break;
		}
		arr[i] = temp;
	}
	if(strcmp(arr[0], "exit") == 0)
	{
	/* "exit" will be the first element; pass in arr+1 so that we don't pass in "exit"
	*  i-1 so as to not count "exit" in the number of args */
		eXit(funix, i-1, arr+1);
	}
	if(strcmp(arr[0], "cd") == 0)
	{
		cd(funix, i-1, arr+1);
	}
	if(strcmp(arr[0], "ls") == 0)
	{
		ls(funix, i-1, arr+1);
	}
	if(strcmp(arr[0], "mkdir") == 0)
	{
		mkdir(funix, i-1, arr+1);
	}
	if(strcmp(arr[0], "umask") == 0)
	{
		umask(funix, i-1, arr+1);
	}
	return 0;
}

void writePrompt(Funix *funix)
{
	/* shows path and '#'
	* Directory *current = funix->currentDirectory;
	* printf("a: %p ", &current);
	* printf("a: %p ", funix->currentDirectory); */
	showPath( funix->currentDirectory );
	printf(" # ");
	/* printf("\n The address of z is %p ", funix); */
}

void getCommand(Funix *funix, char *command)
{
	/* writes prompt and reads command */
	writePrompt(funix);
	fgets(command, COMMAND_LENGTH, stdin);
	
	/* Strip the command of the '\n' character */
	size_t ln = strlen(command) - 1;
	if (command[ln] == '\n')
		command[ln] = '\0';
}

void run(Funix *funix)
{
	/* reads and processes commands in a loop until proper exit */
	char command[COMMAND_LENGTH];
	init(funix);
	while(1){
		getCommand(funix, command);
		// processCommand(,)
	}
	return;
}
