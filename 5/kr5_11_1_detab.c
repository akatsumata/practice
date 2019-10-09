#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    	int c, i, ntab;
	
	if(argc > 3){	   
 		printf("ERROR\n");
		exit(1);
	}
	int t = atoi(argv[1]);
	char *filename = argv[2];

   /* 	if(argc != 2 || atoi(argv[1]) <= 0){
        	printf("ERROR\n");
        	return 1;
    	}*/
    	i = 1;
    	while((c = getchar()) != EOF){
        	if(i == '\t'){
            		while(i <= t){
             	 		putchar(' ');
            		} 
         		i = 0;
        	} else if(c == '\n') {   
            		printf("\n");
            		i = 1;
        	} else {
            		putchar(c);
            		++i;
        	}
    	}
    	return 0;
}
