#include "dirwalk.h"
#include <getopt.h>
#include <stdio.h>
#include <locale.h>

int main(int argc, char *argv[]) {
 char* DIR_PATH = ".";

    if (argc > 1 && argv[1][0] != '-') {
        DIR_PATH = argv[1]; 
    }

    int opt;
    enum FileTypes types;
    while ((opt = getopt(argc - 1, &argv[1], "ldfs")) != -1) {
    switch (opt) {
    case 'l':

      view_list_from_dir(DIR_PATH, ONLY_LINK);
      break;
    case 'd':

      view_list_from_dir(DIR_PATH, ONLY_DIR);
      break;
    case 'f':

      view_list_from_dir(DIR_PATH, ONLY_FILE);
      break;
      case 's':
      view_list_from_dir(DIR_PATH,SORTED);
      break;
    default:
      fprintf(stderr, "Usage: %s [dir][-l] [-d] [-f] [-s]\n", argv[0]);
      exit(EXIT_FAILURE);
    }
  }

  return 0;
}