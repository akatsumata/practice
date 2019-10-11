#include <stdio.h>

#define MAXLINE 1000
#define MAXLEN 5           /* 文字列5カウントしたら折り返し */

int getline(char line[], int lim);

int main()
{
    int len;
    char line[MAXLINE];

    while((len = getline(line, MAXLINE)) > 0) {
          printf("%s\n", line);
     }
     return 0;
}


int getline(char line[], int lim);
{
    int c, i;
    int nc;
    nc = 0;
    
    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        if(nc >= MAXLEN || c == '\t' || c == ' ') {
          line[i] = c;
          ++i;
          line[i] = '\n';
          nc =0;
         }
         else {
            line[i] = c;
            ++nc;
         }
      }

    if(c == '\n') {
       line[i] = c;
       ++i;
    }
    line[i] = '\0';

    return i;
}
