#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 100

int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;
	void fcompare(FILE *, FILE *);
    	char *prog = argv[0];

	if(argc != 3){
		printf("ERROR\n");
		exit(1);
	} else if(argc == 3) {
		while(--argc > 0){
        		if((fp1 = fopen(argv[1], "r")) == NULL){
            			fprintf(stderr, "%s: can't open %s\n", prog, argv[1]);
            			exit(1);
        		} else if((fp2 = fopen(argv[2], "r")) == NULL) {
            			fprintf(stderr, "%s: can't open %s\n", prog, argv[2]);
            			exit(1);
        		} else {
        			fcompare(fp1, fp2);
        			fclose(fp1);
        			fclose(fp2);
			}
		}
    	} else {
        	fprintf(stderr, "%s:ERROR\n", prog);
        	exit(2);
    	}
    	exit(0);

	return 0;
}

void fcompare(FILE *fp1, FILE *fp2)
{
    	char fp1_line[MAXLINE], fp2_line[MAXLINE];
    	int line_count = 1;

    	while((fgets(fp1_line, MAXLINE, fp1) != NULL) &&
		(fgets(fp2_line, MAXLINE, fp2) != NULL)){
        	if(strcmp(fp1_line, fp2_line) != 0){
            		printf("line: %d\nfile1: %sfile2: %s", line_count, fp1_line, fp2_line);
            		exit(0);
        	}
        	line_count++;
    	}
}
