#include <stdio.h>
 
unsigned char rightrot(unsigned char x, int n);
 
int main()
{
        unsigned char x;
        int n;
        x = 26;
        n = 3;
        printf("x = %o\n", x);
        x = rightrot(x, n);
        printf("roted x = %o\n", x);
        return 0;
}
 
unsigned char rightrot(unsigned char x, int n)
{
        unsigned char y, z;
        y = z = 0;
    	y = x << (8 - n);
        z = x >> n;
    	printf("(y = %o, z = %o)\n", y, z);
        x = z | y;
        return x;
}

