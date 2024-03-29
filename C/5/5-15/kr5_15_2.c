#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines, int reverse);
void l_qsort(void *v[], int left, int right, 
            int (*comp) (void *, void *));
int l_numcmp(char *, char *);
int l1_strcmp(char *, char *);
int l2_strcmp(char *, char *);

int main(int argc, char *argv[])
{
    	int nlines;
    	int c, numeric = 0, fold = 0, reverse = 0;
    
    	while(--argc > 0 && (*++argv)[0] == '-'){
        	while(c = *++argv[0]){
            		switch(c){       
            		case 'n':
                		numeric = 1;
                		break;
            		case 'f':
                		fold = 1;
                		break;
             		case 'r':
                		reverse = 1;
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
            		(int (*)(void *, void*))((numeric == 1) ? l_numcmp:
                                     	(fold == 1) ? l2_strcmp : l1_strcmp));
        	writelines(lineptr, nlines, reverse);
        	return 0;
    	} else {
        	printf("input too big to sort\n");
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


void swap(void *v[], int i, int j)
{
    	void *temp;
    	temp = v[i];
    	v[i] = v[j];
    	v[j] = temp;
}

int l1_strcmp(char *s, char *t)
{
 	for( ; *s == *t; s++, t++){
  		if(*s == '\0'){
   			return 0;
  		}
 	}
 	return *s - *t;
}

int l2_strcmp(char *s, char *t)
{
    	for( ; tolower(*s) == tolower(*t); s++, t++){  /* tolower : upper >> lower */
        	if(*s == '\0'){
            		return 0;
        	}
    	}
    	return tolower(*s) - tolower(*t);
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
        int i, variable;
        if(variable == 0){
                for(i = 0; i < nlines; i++){
                        printf("%s\n", lineptr[i]);
                }
        } else {
                for(i = nlines - 1; i >= 0; i--){
                        printf("%s\n", lineptr[i]);
                }
        }
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
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;
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

