#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "directory.h"
#include "permissions.h"

void showPath(Directory *d)
{
	return;
}
Directory *createDirectory(const char *name, int permissions, int t)
{
	Directory *d = (Directory *)malloc(sizeof(Directory));
	char *temp = (char *)malloc(strlen(name) + 1 );
	strcpy( temp, name );
	d->name = temp;
	d->lastModified = t;
	d->perm = createPermissions();
	return d;
}
