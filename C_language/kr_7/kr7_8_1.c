#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int main(int argc, char *argv[])
{
    	FILE *fd;
    	char line[MAXLINE];
    	int page_number = 0;
    
	while(--argv > 0){
 		if((fd = fopen(*++argv, "r")) == NULL){
     			fprintf (stderr, "error: don't open %s\n", *argv);
            		exit(1);
 		} else {
              		if(page_number != 0){
                	 	printf("\f");
              		}
              		page_number++;
       			printf("title(filename): %s, #page: %d\n", *argv, page_number);
      		 	while(fgets(line, MAXLINE, fd) == NULL){
                  		printf("%s", line);
              		}
              		/*fclose(fd);*/
        	}
 		fclose(fd);
    	}
    	return 0;
}
