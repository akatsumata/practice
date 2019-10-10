#include <stdio.h>
#include <ctype.h>

#define MAXLINE 200

int htoi(char s[]);

int main()
{
        int n;

        char s[MAXLINE];
        printf("Hex = %sDecimal = %d\n", s, htoi(s));

        return 0;
}

int htoi(char s[])
{

        int i, n, c, hex_mark;
        i = n = hex_mark = 0;
        while((c = getchar()) != EOF){
                s[i] = c;
                if(s[i] == '0' && i == 0){
                        i++;
                } else if(s[i] == 'x' || s[i] == 'X'){
                	i = 0;
                } else if(s[i] >= '0' && s[i] <= '9'){
                        n = 16 * n + (s[i] - '0');
                        i++;
                } else if(s[i] >= 'a' && s[i] <= 'f'){
                        n = 16 * n + (s[i] - 'a' + 10);
                        i++;
                } else if(s[i] >= 'A' && s[i] <= 'F'){
                        n = 16 * n + (s[i] - 'A' + 10);
                        i++;
                }
        }
        return n;
}

