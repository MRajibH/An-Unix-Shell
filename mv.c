#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<errno.h>
void print_error(char *this,char* filename1,char*filename2)
{
fprintf(stderr,"%s cannot move %s to %s\n%s\n",this,filename1,filename2,strerror(errno));
exit(EXIT_FAILURE);
}
void print_useage(char *this)
{
fprintf(stderr,"syntaxError: %s\n ",this);
exit(EXIT_FAILURE);
}
int main (int argc , char **argv)
{
    errno = 0;
    if(rename(argv[1], argv[2]) == -1)
     print_error(argv[0],argv[1],argv[2]);



   return(0);
}