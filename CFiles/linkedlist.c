#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>



typedef struct node
{
    struct node * prev;
    char name [128];
    char FamilyName [128];
    int YearOfBirth;
    struct node *next;
}node;
void PrintPerson(struct node* Person)
{
    printf("Name : %s Family Name : %s Year of birth %i \n",Person->name,Person->FamilyName,Person->YearOfBirth);
}

node * createNewNode(node*prev,char * name,char* FamilyName,int YearOfBirth)
{
    node * x = malloc(sizeof(node));
    x->prev = prev;
    strcpy(x->name,name);
    strcpy(x->FamilyName,FamilyName);
    x->YearOfBirth = YearOfBirth;
    x->next = NULL;
    return x;
}

void appendNode(node* node1,node* node2)
{
    node1->next =node2;
    node2->prev=node1;
}

int lookupData(node * head,char * name,char *FamilyName)
{      
    if(strcmp(head->FamilyName,FamilyName)==0)
       { if(strcmp(head->name,name)==0)
        {
            return head->YearOfBirth;
        }
       }
        if(head->next !=NULL)
        {
            return lookupData(head->next,name,FamilyName);
        
        }
    return -1;
}

node * pop(node *x)
{   
    node * y = x->next;
    x->next=NULL;
    y->prev =NULL;

    return y;
}

// n1 <-> n2 <-> n3 <->n4
//        x      y

_Bool swap(node* swapMe)
{
    node * x = swapMe;//n2
    node*y = x->next; //n3
    x->prev->next=y;
    y->prev=x->prev;
    x->next=y->next;
    y->next->prev=x;
    y->next = x;
    x->prev=y;

return true;
}



int main (){

    char x[] = "blah";
    char xfamilyname[]="FAMILY";
    node *head = createNewNode(NULL,x,xfamilyname,10);
    char y[] = "lol";
    char yfamilyname[]="YFAMILY";
    node * a = createNewNode(NULL,y,yfamilyname,11);
    appendNode(head,a);
    char z[] = "IamLegend";
    char zfamilyname[]="ZFAMILY";
    node* b = createNewNode (NULL,z,zfamilyname,12);
    appendNode(a,b);
    char lookup[] = "IamLegend";
    int output = lookupData(head,"fuckoff","Notmyname");//-1
    printf("%d\n",output);
    char tailchar[]="WAZZUP";
    char famtailchar[]="TAILFAMILY";
    node* tail = createNewNode(NULL,tailchar,famtailchar,10);
    appendNode(b,tail);
    pop(a);//works
    PrintPerson(head);
    

    return 0;
}
