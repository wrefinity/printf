#include <stdlib.h>
#include <stdio.h>

int mul (int a, int b);
int divider (int a, int b);
int add (int a, int b);
int sub (int a, int b);


struct student{
    char *name;
    int mat_no;
};

// struct arth{
//     int (*ptr[])(int,int);
// };



typedef struct student std;



int main ()
{
    std s1 = {"Kennedy", 1};
    int (*ptr[])(int,int) = {mul, divider, add, sub};
    

    int result = (ptr[0])(1, 2);

    printf("%s, mat-no = %d\n", s1.name, s1.mat_no);
    printf("result = %d", result);
    return 0;
}


int mul (int a, int b)
{
    return a * b;
}
int divider (int a, int b)
{
    return a / b;
}
int add (int a, int b)
{
    return a + b;
}
int sub (int a, int b)
{
    return a - b;
}
