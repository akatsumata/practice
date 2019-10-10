#include <stdio.h>
 
#define MAXLINE 1000
 
int l_getline(char line[], int maxline);
 
int main()
{
        int i, flag, len;
        char line[MAXLINE];
 
        i = flag = 0;
        while((len = l_getline(line, MAXLINE)) > 0){
                for(i = 0; i <= len; i++){
			if(flag == 0){
				if(line[i] == '/'){
					flag = 1;
				} else if(line[i] == '"'){
					flag = 4;
					printf("%c", line[i]);
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
			} else if(flag == 4){
				if(line[i] == '"'){
					flag = 0;
					printf("%c", line[i]);
				} else if(line[i] == '\\'){
					flag = 5;
					printf("%c", line[i]);
				} else {
					printf("%c", line[i]);
				}
			} else if(flag == 5){
				flag = 4;
				printf("%c", line[i]);
			}
		}
	}
	line[i] = '\0';
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

