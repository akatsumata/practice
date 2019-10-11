#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAXLINE 1000
#define TABSTOP 8
 
int l_getline(char *, int);
void n_entab(char newline[], char line[]);
 
int main(int argc, char *argv[])
{
        int c, len, entab = 0, start_column, stop_column;
        char newline[MAXLINE], line[MAXLINE];
    
        if(argc > 4){
            printf("ERROR\n");
            exit (1);
    
        } else if(argc == 3 && *argv[1] == '-' && *argv[2] == '+'){
            char *start_column = argv[1];
              char *stop_column = argv[2];
    }
        printf("argc[0]=%s\n", argv[0]);
            printf("argc[1]=%s\n", argv[1]);
            printf("argc[2]=%s\n", argv[2]);
            printf("argc[3]=%s\n", argv[3]);
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
            n_entab(newline, line);
                printf("oriline\n%s\n", line);
                printf("newline\n%s\n", newline);
        }
        return 0;
}
 
void n_entab(char newline[], char line[])
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
                    if(l == TABSTOP){
                        l = 0;
                    }
            }
            while(line[i] == ' '){
                    ++i;
                    ++k;
                    ++l;
                    if(l == TABSTOP){
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

