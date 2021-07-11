#include <stdio.h>
#include <stdlib.h> // exit
#include <unistd.h> // argument parsing
#include <dix.h>

void parse_arguments(int argc, char** argv, struct args_t* p) {
  int opt;
  while((opt = getopt(argc, argv, ":h")) != -1) {
    switch(opt) {
      case 'h':
        p->help = 1;
        break;
      case '?':
        fprintf(stderr, "dix: invalid argument '%c'\n", optopt);
        exit(EXIT_FAILURE);
        break;
    }
  }
}

void print_help_text() {
  printf(
    "Usage: dix [OPTIONS]\n"
    "  -h\tshows this message and exits.\n"
    "\n"
  );
  printf("dix %s (c) 2021 ikb4l\n", DIX_VERSION);
}

int main(int argc, char** argv) {
  struct args_t p = { 0 };
  parse_arguments(argc, argv, &p);
  
  if(p.help) {
    print_help_text();
  } else {
    print_help_text();
  }
}

