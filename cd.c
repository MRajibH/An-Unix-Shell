#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>



int main(int argc,char**argv)
{
    if (argv[1] == NULL) {
    fprintf(stderr, "lsh: expected argument to \"cd\"\n");
  } else {
    if (chdir(argv[1]) != 0) {
      perror("lsh");
    }
  }
  return 1;
}