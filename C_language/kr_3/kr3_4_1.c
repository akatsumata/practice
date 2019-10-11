#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
        int i1, i2;
        char s[128];
	i1 = SCHAR_MIN;
	i2 = SCHAR_MAX;
        itoa(SCHAR_MIN, s);
        printf("value i1=%d\nstring =%s\n", SCHAR_MIN, s);
	itoa(SCHAR_MAX, s);
	printf("value i2=%d\nstring =%s\n", SCHAR_MAX, s);
}

void itoa(int n, char s[])
{
        int i, x, sign;
	x = 0;

	if((sign = n) < 0){
                x = -1;
        } else {
                x = 1;
        }

        i = 0;
        do{
                s[i++] = x * (n % 10) + '0';
        } while((n /= 10) != 0);
        if(sign < 0){
                s[i++] = '-';
        }
        s[i] = '\0';
        reverse(s);
}

void reverse(char s[])
{
        int c, i, j;

        for(i = 0, j = strlen(s) - 1; i < j; i++, j--){
                c = s[i];
                s[i] = s[j];
                s[j] = c;
        }
}

