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

