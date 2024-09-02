#include<stdio.h>
int main()
{
     FILE *fp;
     fp = fopen("tirth.txt","w");
     fprintf(fp,"tirth bhayani\n");
     fclose(fp);

     printf("data written successfully\n");

     fp = fopen("tirth.txt","r");
     
     if(fp == NULL)
     {
        printf("not opening file\n");
     }
     char ch;
     while((ch=fgetc(fp))!=EOF)
     {
        printf("%c",ch);
     }
     fclose(fp);
}