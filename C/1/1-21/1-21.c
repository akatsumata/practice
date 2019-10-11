#include <stdio.h>
 
#define MAXLINE  1000
#define TABSTOP 8  
 
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
 
   	while((len = l_getline(line, MAXLINE)) > 0){
    		entab(newline, line);
        	printf("oriline:\n%s\n", line);
    		printf("newline:\n%s\n", newline);
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
    	/* k:count space , l:count i to TABSTOP */
    	int i, j, k, l;
    
    	i = j = k = l = 0;
    	while(line[i] != '\0'){
        	if(line[i] != ' '){
            		newline[j] = line[i];
            		++i;
            		++j;
            		++l;
            		if(l == TABSTOP){
                		l = 0;
            		}
        	}
        	while(line[i] == ' '){
            		++i;
            		++k;
            		++l;
            		if(l == TABSTOP){
                		newline[j] = '\t';
                		++j;
                		k = 0;
                		l = 0;
            		}
        	}
        	while(k > 0){
            		newline[j] = ' ';
            		++j;
            		--k;
        	}
    	}
    	newline[j] = '\0';
}

