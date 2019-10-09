#include <stdio.h>

/* x = value, n = position of x */

int binsearch(int x, int v[], int n);

int main()
{
        int v[20] = {0,1,2,3,4,5,6,7,8,9};
        printf("searching value(x) = 8\nx position(v) = %d\n n = 0-9\n", binsearch(8, v, 10));
	return 0;
}

int binsearch(int x, int v[], int n)
{
        int low, high, mid;

        low = 0;
        high = n - 1;
        while(low <= high){
                mid = (low+high) / 2;
                if(x < v[mid]){
                        high = mid - 1;
                } else if(x > v[mid]) {
                        low = mid + 1;
                } else {
                        return mid;
                }
        }
        return -1;
}
