#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAXLINE 1000
 
int main(int argc, char** argv)
{
        char line[MAXLINE];
        long lineno = 0;
        int c, except = 0, number = 0, found = 0;
        FILE *fp;
    
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
        while(--argc > 0){
                if((fp = fopen(*++argv, "r")) != NULL){
                    	lineno = 0;
                }
                while(fgets(line, MAXLINE, fp) > 0){
                    	lineno++;
                    	if((strstr(line, *argv) != NULL) != except){
                            	if(number){
                                	printf("%ld:", lineno);
                            	}
                            	printf("%s: %s", *argv, line);
                            	found++;
                    	}
                }
    	}
        if(ferror(fp)){
                fprintf(stderr, "%s: ERROR\n", *argv);
                exit(2);
        }
	fclose(fp);
        return found;
}

