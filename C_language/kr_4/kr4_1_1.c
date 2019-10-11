#include <stdio.h>
#define MAXLINE 1000
 
int strrindex(char source[], char searchfor[]);
int l_getline(char line[], int max);
char pattern[] = "rld";
int main()
{
    char line[MAXLINE];
    int found, position;
    found = 0;
    while (l_getline(line, MAXLINE) > 0) {
        if ((position = strrindex(line, pattern)) >= 0){
            printf("line=\n%s\nposition=\n%d\n", line, position);
            found++;
        }
    }
    return found;
}
 
int strrindex(char s[], char t[])
{
    int i, j, k, position;
    position = -1;
    for(i = 0; s[i] != '\0'; i++){
        for(j = i, k =  0; t[k] != '\0' && s[j] == t[k]; j++, k++){
            ;
        }
        if(k > 0 && t[k] == '\0'){
            position = i;
            /* i += k - 1; */
        }
    }
    return position;
}
 
int l_getline(char s[], int lim)
{
    int c, i;
    
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
         s[i++] = c;
    }
    if (c == '\n'){
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

