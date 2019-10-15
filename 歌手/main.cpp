#include <stdio.h>
#include "stdlib.h"
#include "string.h"
int main()
{
    char *p;
    char s[8]="hello! ";
    int *q;
    int a[2]={1819043176,2105711};
    p=(char *)a;
    q=(int *)s;
    printf("%d    %d    ",*q,*(q+1));
    printf("%s\n",p);
    return 0;
}
