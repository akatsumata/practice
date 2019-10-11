#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main()
{
        unsigned x;
        int n;
        x = 11;
        n = 2;
        x = rightrot(x, n);
        printf("%d\n", x);
        return 0;
}

unsigned rightrot(unsigned x, int n)
{
        int y, z;
        y = z = 0;
        y = x & ~(~0 << n);
        z = x >> n;
        x = z | y;
        return x;
}
