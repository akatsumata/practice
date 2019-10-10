#include <stdio.h>
 
#define MAXLINE 1000
 
int l_getline(char *, int);
int atoi(char *);
 
int main()
{
    char line[MAXLINE];
    
         while(l_getline(line, MAXLINE) > 0){
             printf("%d\n", atoi(line));
         }
    
         return 0;
}
 
#include <ctype.h>
 
int atoi(char *s)
{
         int n, sign;
    
         for (; isspace(*s); s++){
             ;
     }
         sign = (*s == '-') ? -1 : 1;
         if(*s == '+' || *s == '-'){
             s++;
         }
         for(n = 0; isdigit(*s); s++){
             n = 10 * n + (*s - '0');
         }
         return sign * n;
}
 
/* Chapter.1&4 l_getline ver.pointer */
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

