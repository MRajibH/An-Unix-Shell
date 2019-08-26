#include<stdio.h>
#include<stdlib.h>

int main(int argc , char ** argv)
{
    FILE *fp;
   char input1[100];

    //printf("%s",argv[2]);
    fp = fopen(argv[2],"w+");/*  open for reading and writing */
    if (fp == NULL)
    {
        perror("fopen");

    }
    fgets(input1, 100, stdin);

    fprintf(fp, "%s\n", input1);

    fclose(fp);
    return 0;
}