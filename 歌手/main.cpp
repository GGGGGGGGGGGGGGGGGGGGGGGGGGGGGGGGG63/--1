#include <stdio.h>
#include "stdlib.h"
#include "string.h"
int main()
{
    char *p;
    p=(char *)malloc(4);
    printf("%x\n",p);
    strcpy(p, "hi");
    printf("%x\n",p);
    printf("%s\n",p);
    free(p);
    return 0;
}
