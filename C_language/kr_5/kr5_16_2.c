#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];
int readlines(char *[], int);
void writelines(char *[], int, int);
void l_qsort(void *[], int, int, int (*comp)(void *, void*));
int l_numcmp(char *, char *);
int l1_strcmp(char *, char *);
int l2_strcmp(char *, char *);


int main(int argc, char *argv[])
{
    	int c, nlines, var;
    	int numeric = 0, reverse = 0, fold = 0, directory_order = 0;
    
    	while(--argc > 0 && (*++argv)[0] == '-'){
        	while(c = *++argv[0]){
            		switch(c){
                	case 'n':
                    		numeric = 1;
                    		break;
                	case 'r':
                    		reverse = 1;
                    		break;
                	case 'f':
                    		fold = 1;
                    		break;
                	case 'd':
                    		directory_order = 1;
                    		break;
                	default:
                    		printf("find: illegal option %c\n", c);
				argc = 0;
				break;
            	}
        	}
    	}
    	if((nlines = readlines(lineptr, MAXLINES)) >= 0){
        	l_qsort((void **) lineptr, 0, nlines - 1,
            		(int (*)(void *, void*))(numeric ? l_numcmp : fold ? l2_strcmp : l1_strcmp));
        	writelines(lineptr, nlines, var);
        	return 0;
    	} else {
        	printf("input too big to sortn");
        	return 1;
    	}
}

void l_qsort(void *v[], int left, int right,
           int (*comp)(void *, void *))
{
    	int i, last;
    	void swap(void *v[], int, int);
    
    	if(left >= right){
        	return;
    	}
   	swap(v, left, (left + right) / 2);
    	last = left;
    	for(i = left + 1; i <= right; i++){
        	if((*comp)(v[i], v[left]) < 0){
            		swap(v, ++last, i);
        	}
    	}
    	swap(v, left, last);
    	l_qsort(v, left, last - 1, comp);
    	l_qsort(v, last + 1, right, comp);
}

#include <stdlib.h>
int l_numcmp(char *s1, char *s2)
{
    	double v1, v2;
    
    	v1 = atof(s1);
    	v2 = atof(s2);
    	if(v1 < v2){
        	return -1;
    	} else if(v1 > v2) {
        	return 1;
    	}
    	return 0;
}

#include <ctype.h>
int l1_strcmp(char *s, char *t)
{
    	for( ; tolower(*s) == tolower(*t); s++, t++){  /* tolower : upper >> lower */
        	if(*s == '\0'){
            		return 0;
        	}
    	}
    	return tolower(*s) - tolower(*t);
}

#include <ctype.h>
int l2_strcmp(char *s1, char *s2)
{
	char s, t;
	int fold, directory_order;

    	if(fold == 1 && directory_order == 1){
        	while(s == t){
            		for(; !isalnum(*s1) && *s1 != ' ' && *s1 != '\0'; s++){
                		;
			}
            		for(; !isalnum(*s2) && *s2 != ' ' && *s2 != '\0'; t++){
                		;
			}
            		s = tolower(*s1);
            		t = tolower(*s2);
            		if(s == t && s == '\0'){
                		return 0;
            		}
            		s++;
           	 	t++;
        	}
        	return s - t;
    	} 
    	while(s == t){
        		for(; !isalnum(*s1) && *s1 != ' ' && *s1 != '\0'; s++){
            			;
			}
        		for(; !isalnum(*s2) && *s2 != ' ' && *s2 != '\0'; t++){
            			;
			}
        		if(*s1 == *s2 && *s1 == '\0'){
            			return 0;
        		}
        		s = *s1;
        		t = *s2;
        		s1++;
        		s2++;
    	}
    	return s - t;
}


void swap(void *v[], int i, int j)
{
    	void *temp;
    	temp = v[i];
    	v[i] = v[j];
   	v[j] = temp;
}

#define MAXLEN 1000
int l_getline(char *, int);
char *alloc(int);
int readlines(char *lineptr[], int maxlines)
{
    	int len, nlines;
    	char *p, line[MAXLEN];
    	nlines = 0;
    	while((len = l_getline(line, MAXLEN)) > 0){
        	if(nlines >= maxlines || (p = alloc(len)) == NULL){
            		return -1;
        	} else {
            		line[len - 1] = '\0';
            		strcpy(p, line);
            		lineptr[nlines++] = p;
        	}
    	}
    	return nlines;
}
void writelines(char *lineptr[], int nlines, int reverse)
{
    	int i;
    
    	if(reverse == 1){
        	for(i = nlines - 1; i >= 0; i--){
            		printf("%s\n", lineptr[i]);
        	}
    	} else {
        	for(i = 0; i < nlines; i++){
            		printf("%s\n", lineptr[i]);
        	}
    	}
}

int l_getline(char *s, int lim)
{
    	int c;
    	char *t;
    
    	t = s;
    
    	for(; (c = getchar()) != EOF && c != '\n'; s++){
        	*s = c;
    	}
    	if(c == '\n'){
        	*s = c;
        	s++;
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

void afree(char *p)
{
        if(p >= allocbuf && p < allocbuf + ALLOCSIZE){
                allocp = p;
        }
}

