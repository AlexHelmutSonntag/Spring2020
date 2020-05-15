#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
// char * string;
// int num;
// scanf("%d",&num)
char string[1000];
// string = (char*)malloc(sizeof(char));
char numbers [10]={'0','1','2','3','4','5','6','7','8','9'};
int counts [10]  ={0,0,0,0,0,0,0,0,0,0};
scanf("%s",string);
int i =0;
while(string[i]!='\0')
{
    if(string[i] >= '0' && string[i] <= '9')    
    {   
         for(int j =0; j< 10;j++)
        {
            if (string[i]==numbers[j])
            {
                counts[j]=counts[j]+1;
            }
        }   
    }
    i++;
}
for(int i=0;i<10;i++)
{
    printf("%d ",counts[i]);
}

printf("\n");
// free(string);
    return 0;
}
