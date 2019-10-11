#include <stdio.h>
 
#define MAXLINE 1000
 
int l_getline(char line[], int maxline);
 
int main()
{
        int i, flag, quat, len;
        char line[MAXLINE];
 
        i = flag = quat = 0;
        while((len = l_getline(line, MAXLINE)) > 0){
                for(i = 0; i <= len; i++){
                        if(flag == 0){
                if(line[i] == '"' && quat == 0){
                    quat = 1;
                } else if(line[i] == '"' && quat == 1){
                    quat = 0;
                }
                                if(line[i] == '/' && quat == 0){
                                        flag = 1;
                                } else {
                                        printf("%c", line[i]);
                                }
                        } else if(flag == 1){
                                if(line[i] == '*'){
                                        flag = 2;
                                } else {
                                        flag = 0;
                                        printf("%c", '/');
                                        printf("%c", line[i]);
                                }
                        } else if(flag == 2){
                                if(line[i] == '*'){
                                        flag = 3;
                                }
                        } else if(flag == 3){
                                if(line[i] == '/'){
                                        flag = 0;
                                } else {
                                        flag = 2;
                                }
            }
        }
    }
        return 0;
}
 
int l_getline(char s[], int lim)
{
    int c, i;
    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if(c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

