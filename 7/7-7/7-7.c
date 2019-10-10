#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

int main(int argc, char *argv[])
{
    	char line[MAXLINE], pattern[MAXLINE];
    	int c, except = 0, number = 0, found = 0;
    	FILE *fp;
    	void findfile(FILE *, int, int, char *, char *);
    
    	while(--argc > 0 && (*++argv)[0] == '-'){
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
    	if(argc >= 1){
        	strcpy(pattern, *argv);
    	} else {
        	printf("Usage: find -x -n pattern filename\n");
        	exit(1);
    	}
    	if(argc == 1){
        	findfile(stdin, except, number, pattern, 0);
    	} else {
        	while(--argc > 0){
            		if((fp = fopen(*++argv, "r")) == NULL){
                		fprintf(stderr, "can't open %s\n", *argv);
                		exit(1);
            		} else {
                		findfile(fp, except, number, pattern, *argv);
                		fclose(fp);
            		}
        	}
    	}
        if(ferror(fp)){
                fprintf(stderr, "%s: ERROR\n", *argv);
                exit(2);
        }
    	exit(0);
}

void findfile(FILE *fp, int except, int number, char *pattern, char *filename)
{
    	char line[MAXLINE];
    	long lineno = 0;
    
    	while(fgets(line, MAXLINE, fp) != NULL){
        	lineno++;
        	if((strstr(line, pattern) != NULL) != except){
            		if(filename){
                		printf("filename: %s\n", filename);
            		}
            		if(number){
                		printf("%ld: ", lineno);
            		}
            		printf("%s", line);
        	}
    	}
}


