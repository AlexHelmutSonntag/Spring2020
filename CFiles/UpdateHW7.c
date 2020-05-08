#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//Copy Function
void copyStringv3(char* to,char* from)
{
    while(*from)
  { *to++ = *from++;} 
    *to='\0';
}



//Cat function
void Catstring(char* to, char* from)
{   
    
    while(*to!='\0')
    {   
        to++;
    }
    while (*from!='\0')
    {
        *to = *from;
        to++; 
        from++;
    }

*to='\0';
}

void swap(char *Name,char *SecondName){

char *temp = (char*)malloc((strlen(Name))*sizeof(char));

strcpy(temp,Name);
strcpy(Name,SecondName);
strcpy(SecondName,temp);

} 
int main (){    
char Name[] = "George";
char SecondName[] = "Fillip";

swap(Name , SecondName);

printf("%s\n",Name);
printf("%s\n",SecondName);
void copyStringv3(char* to,char* from);
char Src[]="COVID-19";
char*pSrc =Src;
char Dest[69];
char *pDest =Dest;

copyStringv3(pDest,pSrc);//Copies from Src to Dest.
printf("%s\n",Dest);//COVID-19

void Catstring(char* to, char* from);
char BUDA[] = "BUDA";
char PEST[] = "PEST";
char* pBUDA = BUDA;
char* pPEST =PEST;
Catstring(pBUDA,pPEST);
printf("%s\n",BUDA);



return 0;
}
