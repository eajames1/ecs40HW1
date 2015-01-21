#ifndef PERMISSIONS_H
#define PERMISSIONS_H

#include "funix.h"

// All the permissions related functions go in 
// their own permissions.cpp file.
void umask(Funix *funix, int argCount, const char *arguments[]);
Permissions *createPermissions();
#endif
