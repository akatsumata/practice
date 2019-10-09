#include <stdio.h>

#define MAXLINE 100

void chap2_strcat(char s[], char t[]);

int main()
{
        char s[MAXLINE] = "hello", t[MAXLINE] = ", world";
        chap2_strcat(s, t);
        printf("%s\n", s);

        return 0;
}

void chap2_strcat(char s[], char t[])
{
        int i, j;
        i = j = 0;
        while(s[i] != '\0'){
                i++;
        }
        while((s[i++] = t[j++]) != '\0'){
                ;
        }
}
