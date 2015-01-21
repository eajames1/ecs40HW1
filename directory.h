#ifndef DIRECTORY_H
#define DIRECTORY_H

#define MAX 3

typedef struct 
{
	int r;
	int w;
	int x;
} Permissions;

typedef struct Dir
{
	const char *name;
	int lastModified;
	struct Dir *subdirs;
	struct Dir *parent;
	int subdirectories;
	Permissions *perm;
} Directory;
Directory *createDirectory(const char *name, int permissions, int t);
void showPath(Directory *d);
#endif
