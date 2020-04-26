#include<stdio.h>
//This is still bugged. 
char grid[3][3]={    
                {'N','N','N'},
                {'N','N','N'},
                {'N','N','N'},

};

char Markboard1(int x,int  y){

while (x>4||y>4||x<0 ||y<0)
{
    printf("\nenter a valid coordinate\n");

scanf("%d %d",&x,&y);
}


if(grid[x-1][y-1] == 'N')
{grid[x-1][y-1] = 'X';}
for (int row=0;row<3;row++)
{
       for (int column=0;column<3;column++)
       {  
            printf("%c   ",grid[row][column]);          
       } 
       printf("\n");
}

return grid ;
}

char Markboard2(int x,int  y){

while (x>4||y>4||x<0 ||y<0)
{
    printf("\nenter a valid coordinate\n");

scanf("%d %d",&x,&y);
}

if(grid[x-1][y-1] == 'N')
{grid[x-1][y-1] = 'O';}
for (int row=0;row<3;row++)
{
       for (int column=0;column<3;column++)
       {  
            printf("%c   ",grid[row][column]);          
       } 
       printf("\n");
}

return grid ;
}


char Win1(int x)
{ char Win[100];
//For rows
    if (grid[0][0]=='X'&&grid[0][1]=='X'&&grid[0][2]=='X') 
        {Win[100] = "Player 1 wins";}
    
    else if(grid[1][0]=='X'&&grid[1][1]=='X'&&grid[1][2]=='X') 
        {Win[100] = "Player 1 wins";}
    
    else if(grid[2][0]=='X'&&grid[2][1]=='X'&&grid[2][2]=='X') 
        {Win[100] = "Player 1 wins";}
//for columns
    else if(grid[1][0]=='X'&&grid[2][0]=='X'&&grid[3][0]=='X') 
        {Win[100] = "Player 1 wins";}
    
    else if(grid[1][1]=='X'&&grid[2][1]=='X'&&grid[3][1]=='X') 
        {Win[100] = "Player 1 wins";}
  
     else if(grid[1][2]=='X'&&grid[2][2]=='X'&&grid[3][2]=='X') 
        {Win[100] = "Player 1 wins";}
//for diagonals
     else if(grid[0][0]=='X'&&grid[1][1]=='X'&&grid[2][2]=='X') 
        {Win[100] = "Player 1 wins";}
   
     else if(grid[0][2]=='X'&&grid[1][1]=='X'&&grid[2][0]=='X') 
        {Win[100] = "Player 1 wins";}

    else
    {
        Win[100]="No Winner";
    }    

return Win[100];
}

char Win2(int x)
{ char Win[100];
//For rows
    if (grid[0][0]=='O'&&grid[0][1]=='O'&&grid[0][2]=='O') 
        {Win[100] = "Player 2 wins";}
    
    else if(grid[1][0]=='O'&&grid[1][1]=='O'&&grid[1][2]=='O') 
        {Win[100] = "Player 2 wins";}
    
    else if(grid[2][0]=='O'&&grid[2][1]=='O'&&grid[2][2]=='O') 
        {Win[100] = "Player 2 wins";}
//for columns
    else if(grid[1][0]=='O'&&grid[2][0]=='O'&&grid[3][0]=='O') 
        {Win[100] = "Player 2 wins";}
    
    else if(grid[1][1]=='O'&&grid[2][1]=='O'&&grid[3][1]=='O') 
        {Win[100] = "Player 2 wins";}
  
     else if(grid[1][2]=='O'&&grid[2][2]=='O'&&grid[3][2]=='O') 
        {Win[100] = "Player 2 wins";}
//for diagonals
     else if(grid[0][0]=='O'&&grid[1][1]=='O'&&grid[2][2]=='O') 
        {Win[100] = "Player 2 wins";}
   
     else if(grid[0][2]=='O'&&grid[1][1]=='O'&&grid[2][0]=='O') 
        {Win[100] = "Player 2 wins";}

    else
    {
        Win[100]="No Winner";
    }
    
return Win[100];
}

int main(){


printf("This is the grid : \n");
for (int row=0;row<3;row++)
{
       for (int column=0;column<3;column++)
       {
            printf("%c   ",grid[row][column]);
            
       } 
       printf("\n");
}
printf("\nPlayer 1('X') : pick row and column  \n");
int x,y;
scanf("%d %d",&x,&y);
Win1(1);
Markboard1(x,y);

printf("\nPlayer 2('O') : pick row and column\n");
scanf("%d %d",&x,&y);
Win2(2);
Markboard2(x,y);

printf("\nPlayer 1('X') : pick row and column  \n");
scanf("%d %d",&x,&y);
Win1(1);
Markboard1(x,y);


printf("\nPlayer 2('O') : pick row and column\n");
scanf("%d %d",&x,&y);
Win2(2);
Markboard2(x,y);


printf("\nPlayer 1('X') : pick row and column  \n");
scanf("%d %d",&x,&y);
Win1(1);
Markboard1(x,y);


printf("\nPlayer 2('O') : pick row and column\n");
scanf("%d %d",&x,&y);
Win2(2);
Markboard2(x,y);

printf("\nPlayer 1('X') : pick row and column  \n");
scanf("%d %d",&x,&y);
Win1(1);
Markboard1(x,y);


printf("\nPlayer 2('O') : pick row and column\n");
scanf("%d %d",&x,&y);
Win2(2);
Markboard2(x,y);

printf("\nPlayer 1('X') : pick row and column  \n");
scanf("%d %d",&x,&y);
Win1(1);
Markboard1(x,y);
/*
grid[x-1][y-1] = 'X';
for (int row=0;row<3;row++)
{
       for (int column=0;column<3;column++)
       {
            printf("%c   ",grid[row][column]);
            
       } 
       printf("\n");
}*/
return 0;
}
