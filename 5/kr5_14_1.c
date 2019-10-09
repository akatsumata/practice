#include <stdio.h>
#include <string.h>

#define MAXLINE 5000

char *lineptr[MAXLINE];
int readlines(char *[], int);
void writelines(char *[], int, int);
void l_qsort(void *[], int, int, int (*comp)(void *, void*));
int numcmp(char *, char *);

int main(int argc, char *argv[])
{
    int c, nlines;
    int numeric = 0, reverse = 0;
    
    while(--argc > 0 && (*++argv)[0] == '-'){
        while(c = *++argv[0]){
            switch(c){
                case 'n':
                    numeric = 1;
                    break;
                case 'r':
                    reverse = 1;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    break;
            }
        }
    }
    if((nlines = readlines(lineptr, MAXLINE)) >= 0) {
        l_qsort((void **) lineptr, 0, nlines - 1,
            (int (*)(void *, void*))(numeric ? numcmp : strcmp));
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
    
    if (left >= right) {
        return;
    }
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if ((*comp)(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    l_qsort(v, left, last - 1, comp);
    l_qsort(v, last + 1, right, comp);
}
#include <stdlib.h>
int numcmp(char *s1, char *s2)
{
    double v1, v2;
    
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2) {
        return -1;
    } else if (v1 > v2) {
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
#define MAXLEN 1000
int l_getline(char *, int);
char *alloc(int);
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while((len = l_getline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
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
    
    if(reverse == 0){
        for (i = nlines - 1; i >= 0; i--) {
            printf("%s\n", lineptr[i]);
        }
    } else {
        for (i = 0; i < nlines; i++) {
            printf("%s\n", lineptr[i]);
        }
    }
}
int l_getline(char *s, int lim)
{
    int c;
    char *t;
    
    t = s;
    
    for (; (c = getchar()) != EOF && c != '\n'; s++) {
        *s = c;
    }
    if (c == '\n') {
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
    if (allocbuf + ALLOCSIZE - allocp >= n) {
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

