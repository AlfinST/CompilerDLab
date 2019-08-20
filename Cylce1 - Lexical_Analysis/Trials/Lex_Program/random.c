#include <stdio.h>
void main()
{
    int a=320;
    int *p=&a;
    printf("%c will work? hopenot\n",(char *)p);
}

