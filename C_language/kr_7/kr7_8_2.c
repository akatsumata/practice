#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int main(int argc, char *argv[])
{
	FILE *fp;
    	char *prog = argv[0], line[MAXLINE];
    	int page_number = 1;
   
	if(argc == 1){
		printf("ERROR: non file\n");
		exit(1);
	} else { 
    		while(--argc > 0){
                	if((fp = fopen(*++argv, "r")) == NULL){
                        	fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                        	exit(1);
			} else {
            			if(page_number != 0){
                			printf("\f");
           	 			printf("title: %s, page: %d\n", *argv, page_number);
					page_number++;
				}
            			while(fgets(line, MAXLINE, fp) != NULL){
                			printf("%s", line);
            			}
				fclose(fp);
        		}
    		}
	}
	if(ferror(stdout)){
		fprintf(stderr, "%s: error writing stdout\n", prog);
		exit(2);
	}
    	exit(0);
}
