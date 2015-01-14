#define MAX 3

typedef struct 
{
	int r;
	int w;
	int x;
} Permissions;

typedef struct Dir
{
	char *name;
	int modified;
	struct Dir *subdirs;
	struct Dir *parent;
	int subdirectories;
	Permissions *perm;
} Directory;
