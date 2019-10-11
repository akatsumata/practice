#include <stdio.h>
 
#define MAXLINE 1000
#define TABSTOP 8
 
int l_getline(char *, int);
void detab(char newline[], char line[]);

int main(int argc, char *argv[])
{
    	int c, len, i = 1, entab = 0;
	char newline[MAXLINE], line[MAXLINE];
  
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
	if(argc != 1){
                printf("Usage: find -x -n pattern\n");
        } else {
                while((len = l_getline(line, MAXLINE)) > 0){
                        	detab(newline, line);
                        	printf("oriline\n%s\n", line);
                        	printf("newline\n%s\n", newline);
                	}
        }
	return 0;
}

void detab(char newline[], char line[])
{
	int k = 0, line_count = 0, newline_count = 0;

     	while(line[line_count] != '\0' && newline_count < MAXLINE){
        	if(line[line_count] !='\t'){
            		newline[newline_count] = line[line_count];
            		++line_count;
            		++newline_count;
            		++k;
            		if(k == TABSTOP){
                		k = 0;
            		}
        	} else {
            		while(k < TABSTOP){
                		newline[newline_count] = ' ';
                		++k;
               		 	++newline_count;
            		/*    if(k == TABSTOP){
	              	          k = 0;
	                      }*/
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
 
