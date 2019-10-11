#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000
#define MAXLINES 2000

int l_getline(char *, int);
char *alloc(int);


int main(int argc, char *argv[])
{
    	int n, nlines, len, i;
    	char *p;
    	char line[MAXLEN];
    	char *lineptr[MAXLINES];
    
    	if(argc == 1){
        	n = 10;
    	} else if(argc == 2 && (*++argv)[0] == '-') {
        	n = atoi(argv[0] + 1);
    	} else {
        	printf("ERROR\n");
        /*	return 1;*/
		exit(1);
    	}
    	if(n < 1){
        	printf("ERROR\n");
        /*	return 1;*/
		exit(1);
    	}
    	nlines = 0;
    	while((len = l_getline(line, MAXLEN)) > 0) {
        	p = alloc(len);
        	line[len - 1] = '\0';
        	strcpy(p, line);
        	lineptr[nlines++] = p;
    	}
    	if(n > nlines){
        	n = nlines;
    	}
    	for(i = nlines - n; i < nlines; i++){
        	printf("%dline: %s\n", i + 1, lineptr[i]);
    	}
    	return 0;
}

int l_getline(char *s, int lim)
{
    	int c;
    	char *t;
    
    	t = s;
    	while(--lim > 0 && (c = getchar()) != EOF && c != '\n'){
        *s++ = c;
    	}
    	if(c == '\n'){
        	*s++ = c;
    	}
    	*s = '\0';
    	return s - t;
}

#define ALLOCSIZE 10000
char allocbuf[ALLOCSIZE];
char *allocp = allocbuf;

char *alloc(int n)
{
    	if(allocbuf + ALLOCSIZE - allocp >= n){
        	allocp += n;
        	return allocp - n;
    	} else {
        	return 0;
    	}
}
