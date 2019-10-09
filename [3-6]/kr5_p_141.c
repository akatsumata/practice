#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int l_getline(char *line, int max);

int main(int argc, char *argv[])
{
	char line[MAXLINE];
	long lineno = 0;
	int c, except = 0, number = 0, found = 0;

	while(--argc > 0 && (*++argv)[0] =='-'){
		while(c = *++argv[0]){
		switch(c){
			case 'x':
				except = 1;
				break;
			case 'n':
				number = 1;
				break;
			default:
				printf("find: illegal option %c\n", c);
				argc = 0;
				found = -1;
				break;
			}
		}
	}
	if(argc != 1){
		printf("Usage: find pattern\n");
	} else {
		while(l_getline(line, MAXLINE) > 0){
			lineno++;
			if((strstr(line, *argv) != NULL) != except){
				if(number){
					printf("%ld:",lineno);
				}
				printf("%s", line);
				found++;
			}
		}
	}
	return found;
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

