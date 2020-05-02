#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stddef.h>
#include<stdbool.h>

//int arraySum(int array[],const int n);//function prototype could be here before int main or anywhere before the first time it's called

int main(){


int *pointer=NULL;//It means that this pointer doesn't point to anywhere in the memory and prevents accidentally overwriting memory,
int number=99;//declaration of number must precede the declaration of pointer
int *pNumber=&number;//compiler must have already allocated space for number.
*pNumber=16;//using * to dereference the value stored at the address to to which pNumber points.


int count=10,x;
int *int_pointer=NULL;
int_pointer=&count;//stores the address of count as value
x=*int_pointer;//takes the value stored at the address to which the pointer points
printf("count = %i x =%i\n",count,x);//10   10
printf("%d\n",(int) sizeof(int_pointer));//8 to avoid cast warnings at compile, pointer size =8bits int size = 4bits
printf("%ld\n",sizeof(int_pointer));//8 the argument is of type %ld because a pointer's size is 8 bits and the regular int is of 4 bits
printf("%p\n",&int_pointer);


//you can subtract a pointer from a pointer and it will give you a pointer.
//for example if you are trying to find how many elements there are between two elements in an array where a pointer points to the 2nd element and a pointer points to the 10th element, you can subtract both pointers and you get the number of elements between them.
//you could subtract one pointer from another to get an integer.
//you could subtract an integer from a pointer to get a pointer.
//Most of these are used on arrays but keep in mind boundaries of arrays, outbounds and underbounds.

long value = 9999L;
const long *pvalue= &value;

//*pvalue = 8888L;//ERROR because you can't change the value of variable through the pointer.
value = 8888L;//but you could still do this.
//the pointer itself is not constant. You can still change what it points to.
long sumnum = 8888L;
pvalue=&sumnum;//it's okay because u are changing the address stored in pvalue, not the value of (value) using the pointer.

int somevalue =43;
//you could also have a pointer that stores the value of an address constantly
int *const pcount=&somevalue;//this means the address stored in a pointer cannot be changed
int item=6;
//pcount=&item;//ERROR;attempt to change a constant pointer
*pcount =345; // but you can still change the value.
//const int *pointer ---> pointer of constant value.
//int *const pointer ---> pointer of constant address.
//then there's this..
int things=90;
const int *const Pvalue = &things;//you can't change neither the address to which the pointers points, nor the value of the var using the pointer.
//you could still change the value of things directly;
things = 91;
//if you wanted to make everything constant, then also define things as constant

//Void pointers
//when assigning a void pointer to a variable of some type, you have to cast the pointer to that type.
int A=10;
float F =2.34;
char ch ='k';

void* vptr;
vptr=&A;
printf("value of A= %i\n",*(int*)vptr);//casting vptr to type int
vptr=&F;
printf("value of F= %.3f\n",*(float*)vptr);//casting vptr to type float
vptr=&ch;
printf("value of ch= %c\n",*(char*)vptr);//casting vptr to type char


//Pointers with arrays.
//You can use a pointer to hold the address of different variables at different times(must be of same type).
//Pointers to arrays generaly result in code that uses less memory and executes faster.

int Values[100]={1,2,3};

int *pValues;
//when you define a pointer that is used to point to the elements of an array, you do not designate the pointer as type "pointer to array"
// you designate the pointer as pointing to the type that is contained in the array.

pValues = Values;//you don't need to put & sign because values array is a pointer
//This points to the first element of the array.
//The C compiler treats the appearance of an array name without a subscript as a pointer to the array.
//Specifying values without a subscript has the effect of producing a pointer to the first element of Values.
//as if you pointed to the first element pValues =&Values[0]
//pValues=&Values[0]; = pValues =Values;
//Values[100]={1,2,3};
//ar[i] = *(ar+i) they are equivalent. both work if ar is the name of an array and ar is a pointer variable.
//Using an expression like ar++ only works if ar is a pointer variable.
printf("%i\n",*pValues);//1
printf("%i\n",*pValues+1);//2
printf("%i\n",*pValues+2);//3

//if you want a pointer that points to the 2nd element of the array (1st index)
int *pValues1 = &Values[1];
printf("%i\n",*pValues1);//2
pValues1++;
printf("%i\n",*pValues1);//3




int values[10]={3,7,-9,3,6,-1,7,0,1,5};
int arraySum(int array[],const int n);

printf("The sum is %i\n",arraySum(values,10));//22

int*parrvalues = values;
*(parrvalues+2)= 9;//makes value[2]=9. the third element.

printf("The sum is %i\n",arraySum(values,10));//40

int arraySumv2( int *pointrr,const int n);
printf("The sum is %i\n",arraySumv2(parrvalues,10));//40 returns the same value but by passing in a pointrr to the array instead of the array.

//we noticed here that to pass an array to a function, we simply specify the name of the array
//to produce a pointer to an array you need only to specify the name of the array
//this implies that the call to the arraySum() function, what was passed to the function was actually a pointer to the array values.
//Explains why you are able to change the elements of an aray from within a function.
//When you pass data to a function, that data won't change outside of that function unless it's inputted in the function as a POINTER!
//The only way for elements to get changed outside of a function is when you are passing pointers inside the function.
//This also proves that Arrays are indeed pointers, just using different syntax.

//If you are going to be using index numbers to reference the elements of an array that is passed to a function, declare the corresponding formal parameter to be ana rray.
//more correctly reflects the use of the array by the function
//If you are using the argument as a pointer to the array, declare it to be of type pointer.
//With this concept, the function arraySum could've been written like this 
/*

int arraySum(int *array,const int n)
{


    int sum=0;
    int *const arrayEnd = array+n;

    for(;array<arrayEnd;array++)
    sum+=array;
    return sum;
}
And for calling it in the main body:-

void main()
{

    int arraySum(int *array,const int n);
    int values[10]={3,7,-9,3,6,-1,7,9,1,-5};

    printf("The sum is %i\n,arraySum(values,10));
}
*/
//Summary
/*
int urn[3];
int*ptr1 ,*ptr2;

Valid               Invalid
ptr1++;             urn++;
ptr2=ptr1 + 2;      ptr2 = ptr2 + ptr1; //You can't sum addresses
ptr2 = urn +1;      ptr2 = urn * ptr1;// You can't multiply pointer with sth
*/

//Last Example about pointer arithmetic.

char multiple[]="a string";
char*p=multiple;

for (int i =0;i<strlen(multiple);i++)
{

printf("multiple[%d]=%c,  *(p+%d) =%c,  &multiple[%d] = %p,  p+%d = %p\n",i,multiple[i],i,*(p+i),i,&multiple[i],i,p+i);
/*
value             dereference         address                 Value
multiple[0]=a,  *(p+0) =a,  &multiple[0] = 0x7fffeb4eee2f,  p+0 = 0x7fffeb4eee2f
multiple[1]= ,  *(p+1) = ,  &multiple[1] = 0x7fffeb4eee30,  p+1 = 0x7fffeb4eee30
multiple[2]=s,  *(p+2) =s,  &multiple[2] = 0x7fffeb4eee31,  p+2 = 0x7fffeb4eee31
multiple[3]=t,  *(p+3) =t,  &multiple[3] = 0x7fffeb4eee32,  p+3 = 0x7fffeb4eee32
multiple[4]=r,  *(p+4) =r,  &multiple[4] = 0x7fffeb4eee33,  p+4 = 0x7fffeb4eee33
multiple[5]=i,  *(p+5) =i,  &multiple[5] = 0x7fffeb4eee34,  p+5 = 0x7fffeb4eee34
multiple[6]=n,  *(p+6) =n,  &multiple[6] = 0x7fffeb4eee35,  p+6 = 0x7fffeb4eee35
multiple[7]=g,  *(p+7) =g,  &multiple[7] = 0x7fffeb4eee36,  p+7 = 0x7fffeb4eee36
*/
}
long multiple2[]={15L,25L,35L,45L};
long * pmult=multiple2;


for (int i=0;i < sizeof(multiple2) / sizeof(multiple2[0]);i++)
{

printf("Address p+%d  (&multiple2[%d]) : %llu *(p+%d)  value : %ld\n",i,i,(unsigned long long)(pmult+i),i,*(pmult+i));
/*
we used %llu because that is the format specifier of the address of a long int 
Address p+0  (&multiple2[0]) : 140736516163552 *(p+0)  value : 15
Address p+1  (&multiple2[1]) : 140736516163560 *(p+1)  value : 25
Address p+2  (&multiple2[2]) : 140736516163568 *(p+2)  value : 35
Address p+3  (&multiple2[3]) : 140736516163576 *(p+3)  value : 45
*/
}
/* ***********************************/
//Pointers with strings



void copyString(char to[],char from[]);
void copyStringv2(char* to,char* from);
void copyStringv3(char* to,char* from);
char ALII[]="Alii";
char ALII2[100];
char *pALII = ALII;
char *pALII2 =ALII2;

char NOTTINGHAM[]="NOTTINGHAM";
char *pNOTTINGHAM = NOTTINGHAM;
char BRIISH[100];
char *pBRIISH =BRIISH;
copyString(BRIISH,NOTTINGHAM);//We passed the arrays
printf("%s\n",BRIISH);//NOTTINGHAM
copyStringv2(pALII2,pALII);//copies from ALII[] to ALII2
printf("%s\n",ALII2);//Alii
char ALII3[]="AliiMAGDI";
char *pALII3 = ALII3;
copyStringv3(pALII2,pALII3);//copies what's in ALII3 to ALII2 using the pointer
printf("%s\n",ALII2);//AliiMAGDI 

char ARR[]="MAGDI";
const char* pARR =ARR;
int Length(const char * string);
printf("%d\n",Length(pARR));//5


char ARR2[]="ALI MAGDI";
const char* pARR2 =ARR2;
int Lengthv2(const char * string);//this also works 
printf("%d\n",Lengthv2(pARR2));//9



void swapp(int * x, int * y);

int x1 = 6;
int y1 = 9; 
int* px =&x1;
int* py =&y1;
printf("x:%d y: %d\n",x1,y1);
swapp(px,py);
printf("x:%d y: %d\n",x1,y1);

//Tips about pointers with parameters and using constants.

/*
you apply the const keyword to a parameter that is a pointer to specify that function will not change the value to which teh argument points.
the only reason why you would pass a pointer constant to a function as a parameter is that because you don't want the values outside the function changing.

*/
//we passed 
void Square(int * const x);

int num = 9;

Square (&num);//we passed a copy of the address and it's called passing by reference. 
printf("%d\n",num);//81

//we could've made a pointer and allocate memory dynamically for it.
int *numsth = (int *) malloc (sizeof(int) );//This means we allocated memory for this pointer dynamically and made it equal to the size of one integer.
//now we could dereference it and set it to a value, then this value is the one we pass it's address.
*numsth = 4;
Square(numsth);// we passed the copy of the address of numsth to the function and because it is a pointer the value gets changed outside of the function as well and transmits to the value which the pointer points to. this is the location located dynamically which before executing the function had 4 in it. Now it has 16. we print it out.
printf("%d\n",*numsth);//16

//malloc()
/*
-First of all, you aren't gonna create memory you are not gonna use.
-If you do need more, you can allocate more, you don't have to go back and recompile.
-Depends on the concept of a pointer
-Runs on embedded systems and it limits how much memory you use based on the need.
-The majority of production programs will use dynamic memory allocation


You have two ways to store data.
Heap and Stack.

Heap : allows for more change and you can arbitrarily change the size of data objects and sticks around a lot longer.
Stack : is more limiting and used for everything from function arguements and local variables.

You have to free the space when it is no longer used by you. Because memory is an important resource. In low level embedded type systems.

*/

//malloc(),calloc() and realloc()

/*MALLOC
-You specify the number of bytes of memory that you want allocated as the argument.
-Returns the address of the first byte of memory that it allocated.
-Because you get an address returned, a Pointer is the only place to put it.
*/
int *pNummer = (int*)malloc(100);//You call malloc and create 100 bytes for malloc and because malloc only returns address you cast it into type int pointer.
/*You are requesting 100 bytes of memory and assigned the address of this memory block to pNummer.
-pNummer will point to the first int location at the beginning of the 100 bytes that were allocated.
-Can hold 25 int values on my computer because they require 4 bytes each.
-Assume that type int requires 4 bytes. But if you have a different system than me maybe you will have a bigger or smaller size for int.

So it is better to remove the assumption that ints are 4 bytes.
SYNTAX
int *pNummer = (int*)malloc(sizeof(int));
-This works on different architectures and systems.
you multiply inside of malloc for example :-
(int*) malloc(sizeof(int)*10) gives you size of 10 integers.

-If the memory that you requested can not be allocated for any reason, malloc returns NULL.
int *pNummer = (int*)malloc(25*sizeof(int))
if(!pNummer)
{
    //code to deal with memory allocation failure
}
*/


/*
Releasing memory:-

-Always release memory if you allocate it.
-A memory leak occurs when allocate some memory and you do not retain the reference to it and you are unable to release the memory.
-Often occurs within a loop.
-Because you do not release the memory when it is no longer required, your program consumes more and more of the available memory on each loop iteration and evenrtually may occupy it all.
-To free memory you allocated it you must have access to that address.

free(pNummer);
pNummer=NULL;
The free() function has a formal parameter of type void*
- You can pass a pointer of any type as the argument
-As long as pNummer contains the address that was returned when the memory was allocated, the entire block of memory will be freed for further use.
-You should always set the pointer to NULL afterwards to signall that the memory allocated has been freed.
*/


/*calloc()
advantages over 
-It allocated memory as a number of elements of agiven size.
-It initializes the memory that is allocated so that all bytes are zero.
-It has two arguments : Number of data items for which space is required, size of each data item.
SYNTAX
int* pointer = (cast*)calloc(number of elements you need allocated, sizeeof(type of var));
Example:-
            int*pNummer = (int*)calloc(75,sizeof (int));

//Here we allocated 75 integers of size of int.

-if return value will be NULL if it was not possible to allocate the memory requested
-Very similar to using malloc(), but the big plus is that you know the memory area will be initialized to 0
*/


/*realloc()
-Enables you to reuse or extend memory that you previously allocated using malloc() or calloc()
-Expects two argument values : 
1-A pointer containing the address that was previously returned by a call to malloc() or calloc ()
2-The size in bytes of the new memory you want allocate

SYNTAX
str = (char*) realloc(str,25*sizeof(char));

-Allocates the amount of memory you specify by the second argument
-Transfers the contents of the previously allocated memory referenced by the pointer that you supply as the first argument to the newly allocated memory. It already knows the amount of memory you allocated before to that pointer and then it adds the size you want to reallocate to that pointer.
-Returns a void* pointer to the new memory(you have to cast it just like malloc() and calloc() ) or NULL if the operation fails for some reason.
-The most important feature of this operation is that realloc() preserves the contents of the original memory area.
*/

char *str;

/*initial memory allocation*/
str = (char*) malloc(5*sizeof(char));
strcpy(str,"jason");//String = jason Address = 0x7fffc9258300
printf("String = %s Address = %p\n",str,str);

/*Reallocating memory */
str = (char*) realloc(str,25*sizeof(char));
strcat(str,".com");
printf("String = %s Address = %p\n",str,str);//String = jason Address = 0x7fffc9258300

free(str);

/*Guidelines for memory allocation*/

/*
-Allocating memory on the heap carries some overhead with it
-Allocating many small blocks of memory will caryy much more overhead than allocating fewer larger blocks
-Only hang on to the memory as long as you need it. Release it when you don't need it anymore.
-Always ensure that you decide where in your code you'll release the memory when you write the code that allocates it, make sure you have access to that pointer. Wherever you allocate a memory in a function, release it in that function
-Make sure you do not overwrite the address of memory you have allocated on the heap before you have released it
-This will cause a memory leak.
-Be especially careful when allocating memory within a loop.
*/

int size; 
char*text= NULL;

printf("Enter limit of the text:");
scanf("%d",&size); //Enter the size you want to allocate

text = (char*)malloc(size*sizeof(char));//allocates the size dynamically


if(text!=NULL)//Only if the pointer doesn't point to NULL, execute this Block
{
    printf("Enter some text: \n");//enter the string
    scanf("%s",text);

    printf("Inputted text is : %s\n",text);//you don't have to dereference for text, because it is a character pointer, you only dereference for int pointers and so forth.
}

free(text);
text = NULL;



    return 0;
}

void Square(int * const x)// we didn't really need to make this of const. just to demonstrate that the value of the pointer which is the address of x can't be changed but the value of the variable to which it points can be changed locally and globally.
{

    *x = (*x) * (*x);// we can change the value of the var to which the pointer points but can't change the value of the point itself which is the address of the var
}



bool *SendMessage(const char* pmessage){

//we can change the address but we can't change to what it's pointing to (the value of the pointer itself)
//code to send the message.

return 0;
}


void swapp(int * x, int * y)
{
    int temp = *x;
    *x=*y;
    //y = &temp; // only makes the pointer y point to address of temp and without dereferencing it, the value to which address y points remains the same. 
    *y=temp;//dereferencing the value at the address to which y points and making it equal to that of temp.
//optional to put return; but it's useless.
}
//Function summing up elements in the array
int arraySum (int array[],const int n)
{       
    int sum=0,*ptr;
    int *const arrayEnd =array+n;//points to the (address of the first element of the array+n(size of array)) which means it points to the last element of the array.
    for(ptr=array;ptr<arrayEnd;ptr++)
    sum+=*ptr;//sum = sum + the value at the address stored in ptr.


    return sum;
}

//we could have made this this way by passing in a pointer instead of an array.

int arraySumv2( int *pointrr,const int n) 
{   
int sum =0;
int *const arrayEnd = pointrr+n;

for (;pointrr<arrayEnd;pointrr++)
{
    sum+=*pointrr;
}
return sum;
}

//copying a string from one to another.
void copyString(char to[],char from[])
{
    int i;
    for(i=0;from[i]!='\0';++i)
    {   to[i]=from[i];}
        to[i]='\0';
}
//copying a string using pointers.
void copyStringv2(char* to,char* from)
{
    for(;*from!='\0';++from,++to)
    { *to=*from;}
    *to ='\0';
}
void copyStringv3(char* to,char* from)
{
    while(*from)
  { *to++ = *from++;} //Post incrementation which means it adds only one after the statement is done. if before it would add to that variable before it executes that statement

    *to='\0';
}
//Measures string's length
int Length(const char * string)
{   int length=0;
    const char* lastAddress = string;
    while(*lastAddress)
    {
        ++lastAddress;
    }
    length = lastAddress - string;

return length;
}
//this concept also works
int Lengthv2(const char * string)
{   int length=0;
    while(*string)
    {
       string++;
       length+=1;
    }

return length;
}
