#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    	int c;
   
    	if(argc != 2){
 		printf("ERROR\n");
 		exit(1);
    	}
    	if(strcmp(argv[1], "lower") == 0){
        	while((c = getchar()) != EOF){
            		putchar(tolower(c));
        	}
    	} else if(strcmp(argv[1], "upper") == 0) {
        	while((c = getchar()) != EOF){
            		putchar(toupper(c));
        	}
    	} else {
        	while((c = getchar()) != EOF){
            		putchar(c);
        	}
    	}
    	return 0;
}
