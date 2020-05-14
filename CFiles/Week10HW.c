#include<stdio.h>
#include<stdlib.h>

//atoi() converts numbers that are stored as string into int
/*

int i;
char *s;

s= "-9855"; // i= -9885
i=atoi(s);
*/

int main()
{

/*The fibonacci Task*/    
FILE *openfile=fopen("fibofileWGL13Q.txt","w+");
if(openfile==NULL)
{
    perror("File not created");
    return -1;
}

int fibo=1;
int a=0;
int b=1;
fprintf(openfile,"%d\n",a);
fprintf(openfile,"%d\n",fibo);

for(int i=2;i<20;i++)
{   fibo = a+b;

    fprintf(openfile,"%d\n",fibo);
    a=b;
    b=fibo;
}

fclose(openfile);

/*Second task*/

FILE * readptr =fopen("testfile2.txt","r");

if(readptr==NULL)
{
    perror("Error locating file\n");
}

int num;

char buffer[3];
char * pbuffer = buffer;


while (fgets(buffer,10,readptr)!=NULL)
{
int i = atoi(pbuffer);
printf("%d\n",i+1);
    
}


fclose(readptr);

 return 0;
}
