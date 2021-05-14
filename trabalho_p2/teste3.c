#include <stdio.h>

int main(void)
{
    int test[3][2] = {{1,4},{2,5},{2,8}}, *p;

    for(p = &test[0][0]; p <= &test[2][1]; p++)
    {
        printf("%d\n", *p);
    }
    return 0;
}