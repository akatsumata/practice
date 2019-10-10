#include <stdio.h>
#include <stdlib.h>
 
#define MAXLINE 1000
/* #define TABSTOP 8 */
 
int l_getline(char *, int);
void n_entab(char newline[], char line[], int tab_stop);
 
int main(int argc, char *argv[])
{
        int c, len, i = 1, entab = 0;
        char newline[MAXLINE], line[MAXLINE];
    
        if(argc != 4){
            printf("ERROR\n");
            exit(1);        /* UNIX 'exit(1)' = C 'return 1' */
        }
        int tab_stop = atoi(argv[2]);
        char *filename = argv[3];
 
     /* printf("argv[0]=%s\n", argv[0]);
        printf("argv[1]=%s\n", argv[1]);
        printf("argv[2]= tab_stop =%s\n", argv[2]);
        printf("argv[3]= *filename =%s\n", argv[3]); */
 
    
        while(--argc > 0 && *++argv[0] == '-'){
            while(c == *++argv[0]){
                    switch(c){
                    case 'n':
                        entab = 1;
                        break;
                    default:
                        printf("find: illegal option %c\n", c);
                        argc = 0;
                        break;
                    }
            }
        }
           while((len = l_getline(line, MAXLINE)) > 0){
                n_entab(newline, line, tab_stop);
                printf("oriline\n%s\n", line);
                printf("newline\n%s\n", newline);
           }
        
        return 0;
}
 
void n_entab(char newline[], char line[], int tab_stop)
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
                    if(l == tab_stop){
                        l = 0;
                    }
            }
            while(line[i] == ' '){
                    ++i;
                    ++k;
                    ++l;
                    if(l == tab_stop){
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

