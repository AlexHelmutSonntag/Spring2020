#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846
// Aly Elalwany WGL13Q

// NOTE : please use "-lm"   when compiling

/*Create an enumeration type which represents colors. Name at least 3 colors in this type.
Create two other types: one for representing circles, and another one for representing squares. Both structures should be able storing the center coordinates, furthermore the radius in case of the circle and the side length in case of the square. The shapes have a color too which is given by the
enumeration type above.
1-Create a function which can be given a square and a circle as parameter. The function returns if the circle is inside the square. For example the circle (x=1, y=2, 
r=3) is inside of square (x=2, y=0, l=7) but not inside of square (x=2, y=0, h=2).

2-Create a function which gets an array of circles and a square. The function should return an array on the heap that contains the circles of this array which are inside of this square. The returned array size gets to the caller through a pointer parameter. Make sure to avoid memory leak in the program.

3-Create a function which gets an array of circles as parameter and returns the smallest blue circle from it. In case there is no blue circle in the array, return a NULL pointer.

Place the functions to a separate translation unit. Use the "include guard" idiom.
In the main program create some test code which uses all of the functions.*/

enum COLOR
{
    BLACK,
    BLUE,
    RED
};

struct Circle
{
    float x;
    float y;
    float radius;
    enum COLOR color;
    float area;
};

struct Square
{
    float x;
    float y;
    float sidelength;
    enum COLOR color;
};

bool isInside(struct Circle circle, struct Square square)
{
    float distance = sqrt((circle.x - square.x) * (circle.x - square.x) + (circle.y - square.y) * (circle.y - square.y));
    if (distance + circle.radius < square.sidelength)
    {
        return true;
    }
    else
    {
        return false;
    }
}

struct Circle *circle_inside(struct Circle circle[], struct Square square, int *ptr)
{
    struct Circle *return_array = malloc(sizeof(struct Circle) *(* ptr));

    int cnt = 0;
    for (int i = 0; i < *ptr; i++)
    {
        if (isInside(circle[i], square))
        {
            return_array[cnt] = circle[i];
            cnt++;
        }
    }
    *ptr = cnt;
    return return_array;
}

struct Circle *smallest_blue(struct Circle circle[],int * psize)
{
    struct Circle *ptr = NULL;
    struct Circle blue_circles[5];
    int cnt = 0;
    for (int i = 0; i < *psize; i++)
    {
        if (circle[i].color == 1)
        {

            blue_circles[cnt] = circle[i];
            cnt++;
        }
    }
    if (cnt != 0)
    {
        float min = blue_circles[0].area;
        int index = 0;
        for (int i = 1; i < cnt; i++)
        {
            if (blue_circles[i].area < min)
            {
                min = blue_circles[i].area;
                index = i;
            }
        }
        ptr = &blue_circles[index];
        return ptr;
    }
    else
    {
        return ptr;
    }
}

int main()
{

    struct Circle circle1 = {1, 2, 3, RED, PI * 3 * 3};
    struct Circle circle2 = {3, 4, 5, BLUE, PI * 5 * 5};
    struct Circle circle3 = {1, 2, 3, BLUE, PI * 3 * 3};
    struct Circle circle4 = {2, 1, 5, RED, PI * 3 * 3};
    struct Circle circle5 = {2, 1, 2, RED, PI * 3 * 3};

    struct Square square1 = {2, 0, 7, RED};
    struct Square square2 = {2, 0, 8, BLACK};
    struct Square square3 = {2, 0, 5, BLUE};
    struct Square square4 = {1, 1, 10, BLUE};

    struct Circle circle_array[] = {circle1, circle2, circle3, circle4, circle5};
    struct Square square_array[] = {square1, square2, square3, square4};
    /*1st task*/
    printf("%d\n", isInside(circle1, square1)); //1
    printf("%d\n", isInside(circle1, square3)); //0

    /*2nd task*/
    printf("#\n");

    int *ptr_size = malloc(sizeof(int));
    *ptr_size = (sizeof(circle_array) / sizeof(circle_array[1]));

    struct Circle *heap_array = circle_inside(circle_array, square2, ptr_size);

    for (int i = 0; i < *ptr_size; i++)
    {
        printf("x%d = %.2f y%d= %.2f radius%d = %.2f #%d COLOR ID : %d \n",i+1 ,heap_array[i].x,i+1 ,heap_array[i].y,i+1 ,heap_array[i].radius,i+1,heap_array[i].color);
    }

    /*3rd task*/
    printf("#\n");
    int *ptr_size1 = malloc(sizeof(int));
    *ptr_size1 = (sizeof(circle_array) / sizeof(circle_array[1]));
    struct Circle *sml_blue_ptr = malloc(sizeof(struct Circle));
    sml_blue_ptr = smallest_blue(circle_array, ptr_size1);
    printf("The smallest circle data: ");
    printf("x = %.2f y= %.2f radius = %.2f COLOR ID : %d \n", sml_blue_ptr->x, sml_blue_ptr->y, sml_blue_ptr->radius, sml_blue_ptr->color); //x = 1.00 y= 2.00 radius = 3.00 COLOR ID : 1
    free(ptr_size);
    free(ptr_size1);
    free(heap_array);

    return 0;
}
