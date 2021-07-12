#include <dix.h>
#include <dirent.h>

#ifndef COMMANDS_H
#define COMMANDS_H

int dir_cont(char* d);
void list_dir(struct args_t p);
void print_dir(struct dirent* dir);
void print_file(struct dirent* dir);

#endif

