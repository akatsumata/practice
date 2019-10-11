#include <stdio.h>

#define MAX_PROGRAM 1000

int main()
{
    int c, i , j;
    i = j = 0;
    char p[MAX_PROGRAM];
    char newp[MAX_PROGRAM];

    while((c = getchar()) != EOF) {
        c = p[i];
        ++i;
     }
     printf("元のプログラム = %s\n", p);

     for(i = 0; i < MAX_PROGRAM; ++i) {
       j = 0;
       MAX_ROGRAM = p;
       if(p != '/*[i]*/'){
         p[i] = newp[i];
         printf("コメント無しプログラム = %s\n", newp);
         ++j;
       }
        else {
          j = '\0';
        }
     }
   
     return 0;

}
