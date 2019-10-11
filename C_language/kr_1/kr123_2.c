#include <stdio.h>
 
#define MAXLINE 1000
 
int i;
char line[MAXLINE];
 
int l_getline(char line[], int maxline);
 
int main()
{
    int i, j, k, len, comment;
    char line[MAXLINE];
 
    i = j = k = 0;
    while((len = l_getline(line, MAXLINE)) > 0){
        if(line[i] == '/' && line[i + 1] == '*'){
                i = i + 2;
                comment = 1;
        } else if(line[i] = '*' && line[i + 1] == '/'){
                i = i + 2;
                comment = 0;
        } else if(comment == 1){
                ++i;
        } else {
                printf("%c", line[i]);
                ++i;
        }
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
 
