#include <stdio.h>
#include <stdlib.h>
#include "funix.h"
#include "permissions.h"

// So all the permissions related methods go in this file...
void umask(Funix *funix, int argCount, const char *arguments[])
{
	// Checks "umask" command and executes it if it is proper
}
Permissions *createPermissions()
{
	Permissions *p = (Permissions *)malloc(sizeof(Permissions));
        p->r = 1;
        p->w = 1;
        p->x = 1;
}
