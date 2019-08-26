#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
static char input[2048];
int count=0;
char **agr;
char **quit;
char **a= (char *[]){"pwd", "cd", "cat","mv","quit", ">>"};


int main(int argc , char **argv)
{
   while(1)
   {


       int i = 0;
       pid_t pid;

    fputs("command > ", stdout);
    fgets(input, 2048, stdin);
    char *piece = strtok(input," ");

    //exit
    quit = (char**)malloc(sizeof(char*)*2);
    while(piece != NULL)
    {
    quit[i] = (char*)malloc((strlen(piece)+1) * sizeof(char));
    strcpy(quit[i],piece);
    i++;
    if(i>0)
    {
        break;
    }
    }
    if(strcmp(a[4],quit[0])== -10 )
    {
        break;
    }


       pid = fork();
       if (pid == 0)
     {
    // Child process

      agr = (char**)malloc(sizeof(char*)*4);

     //char *piece = strtok(input," ");

       while(piece!= NULL && count<4)
      {
        //printf("%s\n",piece);
       agr[count] = (char*)malloc((strlen(piece)+1) * sizeof(char));

        strcpy(agr[count],piece);
        //printf("%s\n",agr[count]);
         count++;
         piece = strtok(NULL," ");

      }

  //pwd

    //detecting first string agrument

    if(strcmp(a[0],agr[0]) == -10)
    {

        execv("./pwd",agr);
    }
    if(strcmp(a[0],agr[0]) == 0)
    {
        printf("Sorry,you should not use anythig with PWD command:Try again\n");
    }
    else if(strcmp(a[1],agr[0]) == 0 )
    {

        execv ("./cd" ,agr);
    }
    else if(strcmp(a[1],agr[0]) == -10)
    {


         execv("./mv",agr);
    }
     else if(strcmp(a[2],agr[0]) == 0 && strcmp(a[5],agr[1])== 0 && count == 3)
    {

        execv("./cat",agr);
    }
    else if(strcmp(a[2],agr[0]) == -10)
    {
        printf("Enter [ cat >> <filename.txt ]>\n");
    }

     else if(strcmp(a[3],agr[0]) == 0)
    {

        execv("./mv",agr);
    }


    else
    {
        printf("Enter any of Cd / pwd/cat/rm please\n");
    }
      count = 0;
      free(agr);
    }


  else if (pid < 0) {
    // Error forking
    perror("lsh");
  } else {
    // Parent process
    wait(NULL);
    printf("\n");
    }

   }
}