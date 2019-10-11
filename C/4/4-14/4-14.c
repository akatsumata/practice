#include <stdio.h>
#define swap(t, x, y) {t temp = x; x = y; y = temp;}
int main()
{
        int x, y;
        x = 1;
        y = 2;
        printf("x=%d,y=%d\n\n", x, y);
        swap(int, x, y);
        printf("swap x=%d,swap y =%d\n", x, y);
        return 0;
}

