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
 
    	i = 0;
    	while((len = l_getline(line, MAXLINE)) > 0){
       		/* entab(newline, line);*/
        	printf("oriline\n%s\n", line);
        	printf("newline\n%s\n", len);
    	}
    	return 0;
}
 
int l_getline(char s[], int lim)
{
        int c, i, k;
 
        for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
                s[i] = c;
        if(c == '\n') {
                s[i] = c;
                ++i;
        } else if(c == ' ') {
                if(k == 0){
                        printf("%s\n", c );
                        ++k;
                        ++i;
                }
        } else {
                k = 0;
 
        }
        s[i] = '\0';
        return i;
}
 
/*
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
            		if(k == TABSTOP){
                		k = 0;
            		}
        	} else {
            		while(k < TABSTOP){
                		if(line[i] == ' '){
                        		newline[j] = line[i];
                        		++i;
                        		++j;
                        		++k;
                		} else {
                			if(k == TABSTOP){
                        			k = 0;
                                        }
                		}
       	 		}
            	++i;
            	k = 0;
        	}
   	 }
    	newline[j] = '\0';
}
*/

