#include<stdio.h>
#include<stdlib.h>

/*#define TABSTOP 8*/
void n_entab(char *);
void n_detab(char *);

int main(int argc, char *argv[])
{
 	int c, nblank;
 	if(argc > 3){
  		printf("ERROR\n");
  		exit(1);
 	}
 
	int tab_stop = atoi(argv[1]);
 	char *filename = argv[2];
 	n_detab(tab_stop);
 	n_entab(tab_stop);
 
	return 0;
}

void n_entab(char *argv[1])
{
 	int c, ntab = 0, nblank = 0, tab_stop = 0;
 	int i = 0;
 	while((c == getchar()) != EOF){
  		if(c == ' '){
   			if(nblank < tab_stop){
    				++nblank;
   			} else if(nblank == tab_stop){
    				putchar('\t');
    				nblank = 0;
    				++ntab;
   			}
  		} else {
   			if(c == '\t'){
    				nblank = 0;
   			} else if(c == '\n'){
    				putchar(c);
    				nblank = ntab = i = 0;
  			} else {
   				putchar(c);
  			}
 			++i;
		}
 	}
}

void n_detab(char *argv[1])
{
 	int i, c, tab_stop = 0;
 	while((c = getchar()) != EOF){
  		if(c == '\t'){
   			for(i = 1; i <= tab_stop; i++){
    				putchar(' ');
   			}
  		} else if(c == '\n'){
   			putchar('\n');
   			i = 1;
  		} else {
   			putchar(c);
   			++i;
  		} 
 	}
}
