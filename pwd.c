#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{

  char path[1024];
  getcwd(path,sizeof(path));
  printf("%s\n",path);
}