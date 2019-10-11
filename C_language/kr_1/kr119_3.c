#include <stdio.h>
#define MAXLINE 1000


int l_getline(char line[], int maxline);
void copy(char to[], char from[]);
void l_reverse(char reverse[], char line[]);

int main()
{
        int len;
        char line[MAXLINE];
        char reverse[MAXLINE];

        while((len = l_getline(line, MAXLINE)) > 0){
                printf("line= %s\n", line);
                l_reverse(reverse, line);
		printf("reverse= %s\n", reverse);
        }
        return 0;
}

int l_getline(char s[], int lim)
{
        int c, i;

        for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
                s[i] = c;
        if(c == '\n') {
                s[i] = c;
                ++i;
        }
        s[i] = '\0';
        return i;
}

void copy(char to[], char from[])
{
        int i;

        i = 0;
        while((to[i] = from[i]) != '\0')
                ++i;
}

void l_reverse(char reverse[], char line[])
{
        int i, k;

        i = 0;
        while(line[i] != '\0' && line[i] != '\n'){
                ++i;
        }

        reverse[i] = '\0';

        for(k = 0; i >= k; ++k){
                reverse[i - k] = line[k];
        }
}



