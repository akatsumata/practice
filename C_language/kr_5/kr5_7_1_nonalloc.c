#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];
int readlines(char *lineptr[], char *linestock, int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main()
{
    	int nlines;
    	char linestock[MAXLINES];  
    	if((nlines = readlines(lineptr,  linestock, MAXLINES)) >= 0){
        	qsort(lineptr, 0, nlines - 1);
        	writelines(lineptr, nlines);
        	return 0;
    	} else {
        	printf("error: input too big to sort\n");
        	return 1;
    	}
}

#define MAXLEN 1000
#define MAXSTOCK 5000;
int l_getline(char *, int);
/* readlines: read input lines */
int readlines(char *lineptr[], char *linestock, int maxlines)
{
    	int len, nlines;
    	char line[MAXLEN];
    	char *p = linestock;     
    	char *linestop = linestock + MAXSTOCK;
    
   	nlines = 0;
    	while((len = l_getline(line, MAXLEN)) > 0){
        	if(nlines >= maxlines || p + len > linestop){
            		return -1;
        	} else {
            		line[len - 1] = '\0';
            		strcpy(p, line);
            		lineptr[nlines++] = p;
            		p += len;
        	}
    	}
    	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    	int i;
    
    	for(i = 0; i < nlines; i++){
        	printf("%s\n", lineptr[i]);
	}
}

int l_getline(char *s, int lim)
{
    	int c;
    	char *temp = s;
    	for(; --lim > 0 && (c=getchar()) != EOF && c!='\n'; s++){
        	*s = c;
    	}
    	if(c=='\n'){
        	*s++ = c;
    	}
    	*s = '\0';
    	return s - temp;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *lineptr[], int left, int right)
{
    	int i, last;
    	void swap(char *lineptr[], int i, int j);
    
    	if(left >= right){
        	return;
    	}
    	swap(lineptr, left, (left + right)/2);
    	last = left;
    	for(i = left + 1; i <= right; i++){
        	if(strcmp(lineptr[i], lineptr[left]) < 0){
            		swap(lineptr, ++last, i);
        	}
    	}
    	swap(lineptr, left, last);
    	qsort(lineptr, left, last - 1);
    	qsort(lineptr, last + 1, right);
}

void swap(char *lineptr[], int i, int j)
{
    	char *temp;
    
    	temp = lineptr[i];
    	lineptr[i] = lineptr[j];
    	lineptr[j] = temp;
}
