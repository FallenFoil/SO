#ifndef FILE_H
#define FILE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include "dynaArray.h"

char *readFile(int fd);
void separateCMD(DynaArray *cmds, DynaArray *descs, char *cmd);

#endif
