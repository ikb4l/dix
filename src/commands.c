#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <commands.h>

int dir_cont(char* d) {
  return strcmp(d, ".") == 0 || strcmp(d, "..") == 0;
}

void list_dir(struct args_t p) {
  DIR* d = opendir(p.dir);
  struct dirent* dir;

  if(d) {
    while ((dir = readdir(d)) != NULL) {
      if(!dir_cont(dir->d_name)) {
        if(dir->d_type == DT_DIR) {
          print_dir(dir);
        } else {
          print_file(dir);
        }
      }
    }
    closedir(d);
  }
  printf("\n");
}

void print_dir(struct dirent* dir) {
  printf("%s/  ", dir->d_name);
}

void print_file(struct dirent *dir) {
  printf("%s  ", dir->d_name);
}

