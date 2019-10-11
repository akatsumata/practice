#include <stdio.h>
#define MAXLINE 1000
int l_getline(char *, int);
int strindex(char *, char *);
char pattern[] = "char";
int main()
{
        char line[MAXLINE];
        int found = 0;
        int i;
        while (l_getline(line, MAXLINE) > 0){
                if((i = strindex(line, pattern)) >= 0){
                        printf("%d:%s", i, line);
                        found++;
                }
        }
        printf("line include of 'char': %dline\n", found);
        return 0;
}
int l_getline(char *s, int lim)
{
        int c;
        char *t;
        t = s;
        while(--lim > 0 && (c = getchar()) != EOF && c != '\n') {
                *s++ = c;
        }
        if(c == '\n'){
                *s++ = c;
        }
        *s = '\0';
        return s - t;
}
int strindex(char *s, char *t)
{
        char *sp, *tp, *p;
        for(sp = s; *s != '\0'; s++){
                for(tp = t, p = s; *t != '\0' && *s == *t; s++, t++){
                        ;
                }
                if((t - tp) > 0 && *t == '\0'){
                        return p - sp;
                }
                t = tp;
                s = p;
        }
        return -1;
}

