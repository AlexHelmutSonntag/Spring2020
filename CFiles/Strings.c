#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{

    char Mystring[] = "My String";
    char Ali[] = "Ali";

    //*****//
    //strlen(string) = gives out the length of the string. ps: you have to use %ld to avoid warnings as it is of type long int.

    //also the function changes the string so you can't use constant strings with it.
    printf("%ld\n", strlen(Mystring)); //9 counts space as character and doesn't count the \0 at the end. It sees it as an array.
    printf("%ld\n", strlen(Ali));      //3
    for (int i = 0; i < strlen(Mystring); i++)
    {
        printf("%c", Mystring[i]); //My String//prints out the string by iterating through the array
    }
    printf("\n");

    for (int i = 0; i < strlen(Ali); i++)
    {
        printf("%c", Ali[i]); //Ali//prints out the string by iterating through the array
    }
    printf("\n");

    //*****//

    //strcpy(destination,source) = copies a string to an existing string

    char src[50], dest[50];
    //this is wrong, it's invalid in C and C++
    //-> src="this is source"; //WRONG!

    strcpy(src, "This is source");
    strcpy(dest, "This is destination");

    for (int i = 0; i < strlen(src); i++)
    {
        printf("%c", src[i]); //This is source//prints out the string by iterating through the array
    }
    printf("\n%s\n", src); //This is source// or you could print it out like this.
    printf("%s\n", dest);  //This is destination

    //*****//
    //if you're trying to copy a string with strcpy()  into an array and the final string would be greater than the array, then it gives you an error.
    //strncpy(destination,source,how_many_characters_to_copy)= takes a third argument which the maximum number of characters you wanna copy.

    char name1[40], name2[12];

    strcpy(name1, "Hello how are you doing");
    printf("%s\n", name1);          //Hello How are you doing
    strncpy(name2, name1, 10);      //copies the first 10 characters of name1 into name2
    printf("%s\n", name2);          //Hello how
    printf("%ld\n", strlen(name2)); // the length of string name2 is now 10 as it counts the spaces and the null character"\0".

    char myString[] = "My Name is Jason";
    char temp[50];

    strncpy(temp, myString, sizeof(temp) - 1);       //size of the array temp and -1 for the null character.
    printf("the length is %ld\n", strlen(myString)); //16
    printf("%s\n", temp);                            //My Name is Jason

    //*****//

    //strcat(destination,input)//concatenates a string with a string.
    char Stringcat[] = "Hello";
    char input[80];
    //scanf("%s",input);//how you scan a string. I input Hello there
    //printf("%s",input);//Hello
    //scanf("%s",input);//There
    //printf("%s\n",strcat(Stringcat,input));//HelloThere
    // you could face buffer overflow problems if the size of Stringcat can't take the whole array after concatenation.

    //strncat(destination,input,num_of_characters_to_add)

    char bugs[100];
    char addon[] = "String added to bugs";

    strncat(bugs, addon, 6);
    printf("%s\n", bugs); //String as these are the first 6 characters in addon
    strncat(bugs, addon, sizeof(addon) - 1);
    printf("%s\n", bugs); //StringString added to bugs

    //strcmp(str1,str2)
    //Used as a boolean and returns value of int type.
    //(==) compares addresses.
    //it compares content not string addresses.
    //doesn't compare arrays, can be used to compare thigns stored in arrays of different sizes.
    //doesn't compare characters.
    //you can use arguments as "Apples" and "A" but not 'a'.
    //if both string arguments are the same it returns 0.
    //if return value < 0 then it indicates str1 is less than str2
    //if return value > 0 then it indicates str1 is more than str2

    //** as long as the string with more characters is before the comma it gives a +ve number.
    //printf("%d\n",strcmp("hellothere","seven"));//1
    //printf("%d\n",strcmp("six","hellotherepal"));//-1

    printf("%d\n", strcmp("A", "B"));          //-1
    printf("%d\n", strcmp("A", "A"));          //0
    printf("%d\n", strcmp("B", "A"));          //1
    printf("%d\n", strcmp("C", "A"));          //1
    printf("%d\n", strcmp("Z", "a"));          //-1 //lower case is always more than upper case
    printf("%d\n", strcmp("apples", "apple")); //1
    printf("%d\n", strcmp("", "apple"));       //-1
    //strncmp(str1,str2,number_of_characters_you_want_to_compare)
    //used as boolean as well
    //can be used to search for a specific word

    int Number = 25;
    int *pNumber = &Number;

    printf("%p\n", &Number);  //hexadecimal //address of Number
    printf("%d\n", *pNumber); //25 //dereference the value at pNumber
    printf("%p\n", pNumber);  //hexadecimal //address of Number
    printf("%p\n", &pNumber); //hexadecimal //address of pNumber

    //strchr(string,character_sought_of_type_char)
    //it uses pointers
    //technically it takes 2nd argument an int but the compiler converts the char automatically at run time to int"ASCII" value.

    char str[] = "The quick brown fox"; // the string to be searched
    char ch = 'q';                      //the characeter we are looking for
    char *pGot_char = NULL;             // pointer intialized to NULL
    pGot_char = strchr(str, ch);        //stores address where ch is found
    printf("%s\n", pGot_char);          //quick brown fox
    //it's gonna look in the string we provided for q and once it does, it stores the address of that q in the pointer pGot_char.
    //pGot_char will point to the value ("quick brown fox")

    //strstr(string_searched,substring_you_look_for)
    //searches one string for the first occurrence of a substring
    //returns a pointer to the position in the first string where the substring is found
    //if no match found, returns NULL

    char text[100] = "Every dog has his day";
    char word[100] = "dog";
    char *pFound = NULL;
    pFound = strstr(text, word); //searches for first occurrence of string in word. it appeaars at the 7th char in text.
    //search case is sensetive. "Dog" will not be found
    printf("%s\n", pFound); //dog has his day// it grabs the whole string starting from the word you searched for.

    //strtok(string_to_be_tockenized,string_containing_all_possible_delimeter)
    char Strinng[80] = "Hello how are you -- my name is - jason";
    const char s[2] = "-";
    char *token;
    token = strtok(Strinng, s);

    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, s);
    }
    /* a bunch of useful string functions that return Boolean values
Function        Tests for 

islower()       Lowercase letter
isupper()       Uppercase letter
isalpha()       Uppercase or lowercase letter
isalnum()       Uppercase or lowercase letter or digit
iscntrl()       Control character
isprint()       Any printing character including space
isgraph()       Any printing character excluding space
isdigit()       Decimal digit ('0'to'9')
isxdigit()      Hexadecimal digit ('0'to'9', 'A' to 'F', 'a' to 'f')
isblank()       Standard blank characters (space,'\t')
isspace()       White space character (space,'\n','\t','\v','\r','\f')
ispunct()       Printing character for which isspace () and isalnum() return false.
*/
    /*
char Buff[100];
int nLetters=0;
int nDigits=0;
int nPunct =0;

scanf("%s",Buff);

while(Buff[i])
{
    if(isalpha(Buff[i]))
        {++nLetters;}

   else if(isdigit(Buff[i]))
       { ++nDigits;
       }
    else if(ispunct(Buff[i]))
        {++nPunct;
        }

    i++;
}
printf("char: %d digits : %d  punct : %d\n",nLetters,nDigits,nPunct);
*/

    /*
char text1[100];
char substring[40];

printf("Enter the string to be searched\n");
scanf("%s",text1);//helmut

printf("\n Enter sought string");
scanf("%s",substring);//mut


for(int i=0;(text1[i]=(char)toupper(text1[i]))!='\0';++i);//HELMUT
for(int i=0;(substring[i]=(char)toupper(substring[i]))!='\0';++i);//MUT

printf("%s\n",text1);//HELMUT
printf("%s\n",substring);//MUT
printf("the second string %s found in the first\n",((strstr(text1,substring)==NULL)?"was not":"was"));//was found.
*/

    char tyson[100] = "tyson";
    char son[100] = "son";

    if (strstr(tyson, son))
    {
        printf("%s is in %s\n", son, tyson);
    } //son is in tyson

    /*
atof()//ASCII to float
atoi()//ASCII to integer
atol()//ASCII to long
atoll()//ASCII to long long
*/

    return 0;
}
