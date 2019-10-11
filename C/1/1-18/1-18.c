#include <stdio.h>
#define MAXLINE 1000
 
int l_getline(char line[], int maxline);
void line_remove(char line[], char real_line[]);
 
int main()
{
    	int len;
    	int i = 0;
    	char line[MAXLINE];
    	char real_line[MAXLINE];
 
    	while((len = l_getline(line, MAXLINE)) > 0){
        	printf("line=%s\n", line);
        	if(line[0] != '\n'){    
            		line_remove(line, real_line);
                	printf("real_line=%s\n", real_line);
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
 
void line_remove(char line[], char real_line[])
{
    	int i, j = 0;
 
    	for(i = 0; line[i] != '\n' && line[i] != '\0'; ++i){
        	if(line[i] == ' ' && line[i] == '\t'){
            		real_line[i] = line[i];
            		++j;
            		++i;
        	} else if (line[i] != ' ' && line[i] != '\t'){
            		real_line[i] = line[i];
            		j = 0;
        	}
    	}
    	if(line[i] == '\n'){
        	real_line[i - j] = '\n';
        	real_line[i - j + 1] = '\0';
    	} else {
        	real_line[i - j] = '\n';
    	}
    
}

