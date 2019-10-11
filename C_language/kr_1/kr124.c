#include <stdio.h>

#define SUCCESS 1
#define ERROR 0

int main()
{
    int c, i,
    i = 0;
    c = getchar();
    while(c != EOF){
        i = getchar();
        
        if((c == '(' && c == ')') || (c == '[' && c ==']') || (c == '{' && c =='}'))
          printf("SUCCESS\n");
          ++i;
         else
           printf("ERROR\n");
      }
   return 0;
}

