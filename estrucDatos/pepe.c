#include <stdio.h>
#include <string.h>

int main()
{
    char s1[5] = "Abeja";
    char s2[5] = "abeja";
    int i;

    printf("s1=%s\t", s1);
    printf("s2=%s\n", s2);

    i = strcoll(s1, s2);

    printf("s1 es %i \n",i);
    if (i < 0)
        printf("menor que");
    else if (i > 0)
        printf("mayor que");
    else
        printf("igual a");
    printf(" s2\n");

    return 0;
}