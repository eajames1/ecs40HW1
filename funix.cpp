#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "funix.h"

int main(int argc, const char * argv[])
{	
	Funix *f = (Funix*)malloc(sizeof(Funix));
	run(f);
    return 0;
}

void cd(Funix *funix, int argCount, const char *arguments[])
{
	// Calls cd() with currentDirectory as one of its parameters
	//cd(funix, count, funix->currentDirectory)
}

int eXit(Funix *funix, int argCount, const char *arguments[])
{	
	exit(0);
	return 0;
}

void getCommand(Funix *funix, char *command)
{
	fgets(command, sizeof(command)*COMMAND_LENGTH, stdin);
	
	// Strip the command of the '\n' character
	size_t ln = strlen(command) - 1;
	if (command[ln] == '\n')
		command[ln] = '\0';

	// If "exit" command is entered
	if(strcmp(command, "exit") == 0){
		const char *a[NUM_COMMANDS];
		eXit(funix, 0, a);
	}
}


void init(Funix *funix)
{
		Directory d;
		char name[] = "/";
		d.name = name;
		d.modified = 1;
		Permissions p;
		p.r = 1;
		p.w = 1;
		p.x = 1;
		d.perm = &p;
		funix->currentDirectory = &d;
		Directory *current = funix->currentDirectory;
		printf("b: %p \n", funix->currentDirectory);//&current);
		// printf("%s\n", funix->currentDirectory->name);
		// printf("%i\n", funix->currentDirectory->modified);
		// printf("\n The address of y is %p ", funix);
		funix->umask++;
}

void ls(Funix *funix, int argCount, const char *arguments[])
{
	// calls ls() with currentDirectory as one of its parameters
	// ls(funix, count, funix->currentDirectory);
}

void mkdir(Funix *funix, int argCount, const char *arguments[])
{
	// calls mkdir() with currentDirectory as one of its parameters
	// mkdir(funix, count, funix->currentDirectory)
}

int processCommand(Funix *funix, char *command)
{
	// returns 0 on proper exit
	// if( eXit(funix, command))
	// {
	// 	return(0);
	// }
}

void writePrompt(Funix *funix)
{
	//Directory *current = funix->currentDirectory;
	//printf("a: %p ", &current);
	printf("a: %p ", funix->currentDirectory);
	printf("# ");
	// printf("\n The address of z is %p ", funix);
}

void umask(Funix *funix, int argCount, const char *arguments[])
{
	// Checks "umask" command and executes it if it is proper
}

void run(Funix *funix)
{
	char *command;

	while(1){
		init(funix);
		writePrompt(funix);
		getCommand(funix, command);
		// printf("\n The address of x is %p ", funix);
	}
}
