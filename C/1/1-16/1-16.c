#include <stdio.h>
 
#define MAXLINE 30
 
/* line入力したテキスト、len入力行群の長さ、longest一番長い行 */
 
int l_getline(char line[], int maxline);
void copy(char to[], char from[]);
 
int main()
{
    	int len;
    	int max;
    	char line[MAXLINE];
    	char longest[MAXLINE];
 
	max = 0;
    	while((len = l_getline(line, MAXLINE)) > 0){
        	if(len > max){
            		max = len;
            		copy(longest, line);
        	}
        	printf("入力行群の長さ = %d\n", len);
        	printf("入力したテキスト = %s\n", line);
    	}
    	return 0;
}
 
 
int l_getline(char s[], int lim)
{
    	int c, i;
 
    	for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
        	s[i] = c;
        	if(c == 'n') {
            		s[i] = c;
            		++i;
        	}
	}
    	s[i] = '\0';
    	return i;
}
 
 
void copy(char to[], char from[])
{
    	int i;
 
    	i = 0;
   	while((to[i] = from[i]) != '\0'){
        	++i;
	}
}

