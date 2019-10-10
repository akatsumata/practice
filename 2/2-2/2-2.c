#include <stdio.h>
#define MAXLINE 1000
 
int l_getline(char line[], int maxline);
void copy(char to[], char from[]);
 
int main()
{
    	int length;
    	int max;
    	char line[MAXLINE];
    	char longest_line[MAXLINE];
 
    	max = 0;
    	while((length = l_getline(line, MAXLINE)) > 0){
        	if(length > max){
            		max = length;
            		copy(longest_line, line);
        	}
    	}
    	if(max > 0){
        	printf("%s", longest_line);
    	}
    	return 0;
}
 
/*int l_getline(char s[], int lim)
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
}*/
 
 
int l_getline(char s[], int lim)
{
    	int i, c, j;
    	i = 0;
    	j = 1;
    
        while(j == 1){
                if(i < lim - 1){
            		c = getchar();
                        if(c != EOF){
                                if(c != '\n'){
                                        s[i] = c;
                    			++i;
                                } else {
                    			s[i] = c;
                    			++i;	
                    			s[i] = '\0';
                    			j = 0;
                                }
                        } else {
                                s[i] = '\0';
                		j = 0;
                        }
                } else {
                        s[i] = '\0';
            		j = 0;
                }
        }
        return i;
}
 
void copy(char to[], char from[])
{
    	int i;
 
    	i = 0;
    	while((to[i] = from[i]) != '\0')
        	++i;
}

