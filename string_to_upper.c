#include <stdio.h>
#include <stdlib.h>

void printer(char *name)
{
    int x;

    for(x =0; name[x] != '\0'; x++)
    {
        if(name[x] >= 'a' && name[x] <='z')
        name[x] = name[x] - 32;
    }


    printf("%s", name);
}


int main ()
{
    char name[] = "Wrash Andrew";

    printer(name);
    return 0;
}