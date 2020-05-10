#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

//This file is about Structs in C

struct date 
{
    int month;
    int day;
    int year;
};
struct month {
//A struct that contains an array
    int numberofDays;
    char name[3];
};
//Nested structures
struct time
{
    int hours;
    int minutes;
    int seconds;
};
struct dateAndTime
{
    struct date sdate; // first member of struct is of type struct date and called sdate
    struct time stime;// second member of struct is of type struct time and called stime
};
//You don't necessarily have to define a struct outside if you want to make a nested struct.
//But this means you won't be able to use struct date outside of this scope
struct Timenested {
    struct datelocal {int day;
                 int month;
                 int year;
                  }dob;
    int hour;
    int minutes;
    int seconds;
};

//A struct of two members of type pointer to an int.
struct intPtrs
{
    int *p1;
    int *p2;

};

struct names {

    char first[20];
    char last[20];
};

//Or
struct pnames{

    char *first;
    char *last;
};
struct namect{

    char *fname;//using pointers instead of arrays
    char *lname;
    int letters;
};
struct item
{
    char * itemName;
    int qty;
    float amount;
    float price;
};
void read_item(struct item *i)
{
    printf("NAME:\n");
    scanf("%s",i->itemName);
    printf("Price:\n");
    scanf("%f",&i->price);
    printf("Qunatity:\n");
    scanf("%i",&i->qty);

    i->amount =(float)i->qty*i->price;

}
void print_item(struct item *i)
{
    printf("Item name : %s\n",i->itemName);
    printf("Item name : %f\n",i->price);
    printf("Item name : %i\n",i->qty);
    printf("Item name : %.2f\n",i->amount);
    
}


void getinfo(struct namect *pst)
{
    int SLEN=100;
    char temp[SLEN];
    // char*Ptemp=(char*)malloc(50);
    // Ptemp = temp;
    // printf("Please enter your first name\n");
    // scanf("%c",temp);
    // strcpy(temp,Ptemp);
    //allocate memory for the pointer fname which is the member of struct namect which is the type of the pointer pst
    pst->fname=(char*)malloc(strlen(temp)+1);

    //copy name to allocated memory, passing fname of struct pst and temp is being added to it using strcpy
    strcpy(pst->fname,temp);

    printf("Please enter your last name\n");
  //  s_gets(temp,SLEN); // this is supposed work like scanf for strings but it is somehow bugged now
    pst->lname=(char*)malloc(strlen(temp)+1);
    strcpy(pst->lname,temp);//passing lname as a parameter and storing the last name from temp in it.
};
//Structs with functions

struct Family {

char name[20];
int age;
char father [20];
char mother [20];

};
bool siblings(struct Family member1, struct Family member2)
{

if(strcmp(member1.mother,member2.mother)==0)
return true;
else
{
    return false;
}
}
//Same function but done by passing pointers of type struct Family
bool siblingsv1(struct Family *pmember1,struct Family *pmember2 )
{
    if(strcmp(pmember1->mother,pmember2->mother))
    return true;
else
{return false;}

}
//Same function but done by passing a constant pointer of type struct Family
//Any attempt to change the value of the pointers will cause an error message during compilation so we can't modify what it is pointing to.
//you could change the value of the variable to which it points
bool siblingsv2(struct Family *const pmember1,struct Family *const pmember2)
{
    if(strcmp(pmember1->mother,pmember2->mother)==0)
    return true;

    else
    {return false;}
    
}
struct funds{
char bank[50];
double bankfund;
char save[50];
double savefund;
};
double sum(struct funds moolah)
{
    return(moolah.bankfund + moolah.savefund);
}

int main ()
{


struct date Today = {2,7,2019};
struct date Yesterday = {.day = 29,.month = 4 , .year = 2020};


struct date myDates [10]; // each element has 3 members.

myDates[1].month = 8;
myDates[1].day = 8;
myDates[1].year = 1992;

struct date myDates1[5] = {{12,10,1975}, {12,30,1986}, {11,15,2005}}; //initializes only the first 3 elements in array myDates


//struct with an array member
struct month aMonth;
aMonth.numberofDays =31;
strcpy(aMonth.name,"Jan");//copying the string to the array
//aMonth.name[1] ='J'; and so on instead.

struct month aMonth1 = {31,{'j','a','n'}};//another way to initialize this with it.

//Accessing members of nested structs


struct dateAndTime event;// you define var event

event.sdate.month = 10;
++event.stime.seconds;

struct dateAndTime party = {{2,1,2015},{3,30,0}}; // each member inside dateAndTime struct is a struct of 3 members.
struct dateAndTime Abschiedsparty = {{.month =2,.day=1,.year=2015},{.hours=3,.minutes=30,.seconds=0}}; // each member inside dateAndTime struct is a struct of 3 members.
                //{ Date struct of members month, day and year.}    {Time struct of members hour, minutes and seconds}

//Array of nested structures.
struct dateAndTime events[100];// the array events is declared to contain 100 elements of type struct dateAndTime
events[0].stime.hours =12;
events[0].stime.minutes = 0;
events[0].stime.seconds = 0;
events[1].sdate.day = 26;
events[1].sdate.month = 1;
events[1].sdate.year = 1999;


//Using pointers with structures.
/*
-Pointers to structures are easier to manipulate than structures themselves
-Many data representations use data structures that use pointers to other structures
*/

/*
struct date 
{
    int month;
    int day;
    int year;
};
*/
struct date *datePtr =NULL; // pointer to a struct called date.

struct date TodaysDate;

datePtr = &TodaysDate;//a pointer of type struct date points to a var of type struct date

//This says, whatever datePtr points to access that and make the member day = 21.
//Also, you syntax must be  (*datePtr) because the . has higher precedence than the indirection operator *
(*datePtr).day = 21;
(*datePtr).month = 1;
(*datePtr).year = 2001;
//If we want to test the value of month stored in the date structure pointed to by datePtr 
if((*datePtr).month==12){
    int sth1=1;
}
if(datePtr->month==12)
{
        int sth2=2;
}
    //Both are the same
//But then C has it's own syntax. when you wanna access what the structure is pointing to 
//instead of typing (*x).y you can express it as x->y which means the member y of pointer x of type struct sth
/*
struct date
{
    int month;
    int day;
    int year;
};
*/
//The pointer is of type struct datev1 and so is today.
struct date today, *todayPtr=NULL;

todayPtr =&today;

todayPtr->month = 9;
todayPtr->day =1;
todayPtr->year =1999;

printf("Today's date is %i %i %i\n",todayPtr->month,todayPtr->day,todayPtr->year%100);
//Today's date is 9 1 99
printf("\n");
/*
struct intPtrs
{
    int *p1;
    int *p2;

};
*/
//Pointers are members of the struct
struct intPtrs Pointers;
int i1 = 100, i2;

//Here Pointers is a struct that contains two members which are pointers, then when you want to access them you use the (.) then you assign the address to it.
Pointers.p1 =&i1;
Pointers.p2 =&i2;
//then when you dereference it then you need to use the (*) because you are not accessing an element of a structure, you are dereferencing a pointer
//We are not creating a structure pointer, we are creating a variable int that contains two pointers as elements.
*Pointers.p2 = -97;

printf("i1=%i,*Pointers.p1 = %i\n",i1,*Pointers.p1);
printf("i2=%i,*Pointers.p2 = %i\n",i2,*Pointers.p2);
printf("\n");
/*struct names {

    char first[20];
    char last[20];

};

//Or
struct pnames{
    
    char *first;
    char *last;
};
*/
struct names veep = {"Talia", "Summers"};
//Allocating 40 bytes to hold the two names
struct pnames treas = {"Brad", " Fallingjaw"};
//The struct holds two addresses which takes a total of 16 bytes because they're pointers
//the struct pnames allocates no space to store strings, it allocates only two pointers inside that structure
//it can be used only with strings that have had space allocated for them elsewhere 
//such as string constants or strings in arrays
printf("%s and %s \n",veep.first,treas.first);
printf("\n");
/*
struct funds{
int FUNDLEN =50;
char bank[FUNDLEN];
double bankfund;
char save[FUNDLEN];
double savefund;
};
double sum(struct funds moolah)
{
    return(moolah.bankfund + moolah.savefund);
}

*/

struct funds stan ={
    "Garlic-Melon Bank",//could've been .bank="Garlic-Melon Bank"
    4032.27,//.bankfund=
    "Lucky's Savings and Loan",//could've been .fund="Lucky's...."
    8543.94//.savefund = 
};
double sum(struct funds moolah);
printf("Stan has a total of $%.2f.\n",sum(stan));

//You could have passed a pointer of this structure but then you make it of type constant (the value of pointer changes but not to which it points) in order to pass only the address and also protect the date from being changed in the original struct
struct namect *ptr;
// getinfo(ptr);


/*

struct item
{
    char * itemName;
    int qty;
    float amount;
    float price;
};
void read_item(struct item *i)
{
    printf("NAME:\n");
    scanf("%s",i->itemName);
    printf("Price:\n");
    scanf("%f",&i->price);
    printf("Qunatity:\n");
    scanf("%i",&i->qty);

    i->amount =(float)i->qty*i->price;

}
void print_item(struct item *i)
{
    printf("Item name : %s\n",i->itemName);
    printf("Item name : %f\n",i->price);
    printf("Item name : %i\n",i->qty);
    printf("Item name : %.2f\n",i->amount);
    
}*/

   struct item ITM;
    struct item *pITM;
    pITM=&ITM;
    pITM->itemName=(char*)malloc(30*sizeof(char));

    read_item(pITM);
    print_item(pITM);

free(pITM->itemName);
 





    return 0;
}
