#include <stdio.h>
#define MAXLINE 1000
int main()
{
        char s[MAXLINE];
        int n;
        void itoa(int, char *);
        n = 12345;
        itoa(n, s);
        printf("%d\n%s\n", n, s);
        return 0;
}
#include <string.h>
void reverse(char *s)
{
        int c;
        char *t;
        for(t = s + (strlen(s) - 1); s < t; s++, t--) {
                c = *s;
                *s = *t;
                *t = c;
        }
}
void itoa(int n, char *s)
{
        int sign;
        char *t;
        void reverse(char *);
        t = s;
        if((sign = n) < 0) {
                n = -n;
        }
        do{
                *s++ = n % 10 + '0';
        } while ((n /= 10) > 0);
        if(sign < 0){
                *s++ = '-';
        }
        *s = '\0';
        reverse(t);
}

