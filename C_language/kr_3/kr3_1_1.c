#include <stdio.h>

#define MAXARRAY 50

/* x = value, n = position of x */

int binsearch(int x, int v[], int n);

int main()
{
	int x, n;
	char position[MAXARRAY];
	x = 2;
	n = 0;
	while(n < MAXARRAY && position[n] != -1){
		position[n] = n;
		x = binsearch(x, v, n);
		++n;
	}
	if(position[n] == -1){
		printf("%d\n", -1);
	} else {
		printf("%d\n", x);
	}
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

/*int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while(low <= high){
		mid = (low+high) / 2;
		if(x < v[mid]){
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return(value == v[mid] ? mid : -1);
} */ 
