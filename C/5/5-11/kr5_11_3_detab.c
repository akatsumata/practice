#include <stdio.h>
#include <stdlib.h>
 
#define MAXLINE 1000
/* #define TABSTOP 8 */
 
int l_getline(char *, int);
void n_detab(char newline[], char line[], int tab_stop);
 
int main(int argc, char *argv[])
{
        int c, len, i = 1, detab = 0;
        char newline[MAXLINE], line[MAXLINE];
    
        if(argc != 4){
            printf("ERROR\n");
            exit(1);        /* UNIX 'exit(1)' = C 'return 1' */
        }
        int tab_stop = atoi(argv[2]);
        char *filename = argv[3];
 
    /*printf("argv[0]=%s\n", argv[0]);
        printf("argv[1]=%s\n", argv[1]);
        printf("argv[2]= tab_stop =%s\n", argv[2]);
        printf("argv[3]= *filename =%s\n", argv[3]);*/
 
    
        while(--argc > 0 && *++argv[0] == '-'){
            while(c == *++argv[0]){
                    switch(c){
                    case 'n':
                        detab = 1;
                        break;
                    default:
                        printf("find: illegal option %c\n", c);
                        argc = 0;
                        break;
                    }
            }
        }
           while((len = l_getline(line, MAXLINE)) > 0){
                n_detab(newline, line, tab_stop);
                printf("oriline\n%s\n", line);
                printf("newline\n%s\n", newline);
           }
        
        return 0;
}
 
void n_detab(char newline[], char line[], int tab_stop)
{
    int k = 0, line_count = 0, newline_count = 0;
 
         while(line[line_count] != '\0' && newline_count < MAXLINE){
            if(line[line_count] !='\t'){
                    newline[newline_count] = line[line_count];
                    ++line_count;
                    ++newline_count;
                    ++k;
                    if(k == tab_stop){
                        k = 0;
                    }
            } else {
                    while(k < tab_stop){
                        newline[newline_count] = ' ';
                        ++k;
                            ++newline_count;
                    }
                    ++line_count;
                    k = 0;
            }
        }
        newline[newline_count] = '\0';
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

