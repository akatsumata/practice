#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "unistd.h"

void error(char *, ...);

int main(int argc, char *argv[])
{
    	int fp;
    	void filecopy(int f1, int f2);
    	char *prog = argv[0];
    
	if(argc == 1){
        	filecopy(0, 1);
    	} else {
        	while(--argc > 0){
            		if((fp = open(*++argv, O_RDONLY, 0)) == -1){
                		error("cp: can't open %s", *argv);
            		} else {
                		filecopy(fp, 1);
                		close(fp);
            		}
    		}
	}
    	exit(0);
}

void filecopy(int f1, int f2)
{
    	int fp, n;
    	char buf[BUFSIZ];
   
    	while((n = read(f1, buf, BUFSIZ)) > 0){
        	if(write(f2, buf, n) != n){
            		error("cp: write error on file");
        	}
    	}
}

#include <stdarg.h>

void error(char *fmt, ...)
{
    	va_list args;
   
    	va_start(args, fmt);
    	fprintf(stderr, "error: ");
    	vfprintf(stderr, fmt, args);
    	fprintf(stderr, "\n");
    	va_end(args);
    	exit(1);
}
