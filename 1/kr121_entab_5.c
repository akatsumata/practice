#include <stdio.h>
 
#define MAXLINE 1000
#define TABSPACE 4
 
int i;
char line[MAXLINE];
char newline[MAXLINE];
 
int l_getline(char line[], int maxline);
void entab(char newline[], char line[]);
 
int main()
{
    int len;
    char line[MAXLINE];
    char newline[MAXLINE];
 
    i = 0;
    while((len = l_getline(line, MAXLINE)) > 0){
        entab(newline, line);
        printf("oriline\n%s\n", line);
        printf("newline\n%s\n", newline);
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
 
 
void entab(char newline[], char line[])
{
        int i, j, k;
 
        i = j = k = 0;
        while(line[i] != '\0' && i < MAXLINE){
                if(line[i] != ' '){
                        newline[j] = line[i];
                        ++i;
                        ++j;
                        ++k;
                        if(k == TABSPACE) {
                                k = 0;
                        }
                } else {
                        while(k < TABSPACE){
                                newline[j] = line[i - k];
                                newline[j] = '\t';
                                ++j;
                                ++k;
                        }
                ++i;
                k = 0;
                }
                newline[j] = '\0';
        }
}

