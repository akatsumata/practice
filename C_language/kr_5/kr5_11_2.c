#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void entab(char *tab);
void detab(char *tab);
int main (int argc,char *argv[])
{
    /* argv[0] = detab */
    int tab = atoi(argv[1]);        /* => TABSTOP */
    char *filename = argv[2];
    
    if(argc > 3){
        printf("ERROR\n");
 exit(1);      /* UNIX "exit(1)" = C "return 1" <= stop program */
    }
    detab(tab, filename);
    entab(tab, filename);
    return 0;
}
void entab(char *tab)
{
 int c, pos;
 int i, nspace = 0, ntab = 0;
 int tab = atoi(argv[1]);
 for(i = 1; (c=getchar()) != EOF; i++){
    if(c == ' '){
      if(i != tab){
         ++nspace;
      } else {
         nspace = 0;
         ++ntab;
       }
    } else {
       while(ntab > 0){
         putchar('\t');
         ntab--;
       }
       if(c == '\t'){
         nspace = 0;
         putchar('\t');
       } else {
         while(nspace > 0){
           putchar(' ');
         /* nspace--;*/
          }
          putchar(c);
       }
       if(c == '\n'){
         printf("\n");
         i = 0;
         ntab = 0;
         nspace = 0;
        }
     }
  }
  return 0;
}

void detab(char *tab)
{
  int i = 1, c;
  int tab = atoi(argv[1]);
  while((c = getchar()) != EOF){
     if(c == '\t'){
       while(i <= tab){
         putchar(' ');
         } 
       i = 0;
     } else {
        putchar(c);
        ++i;
     }
     if(c == '\n'){   
        printf("\n");
        i = 1;
     }
  }
  return 0;
}
