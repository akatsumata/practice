#include <stdio.h>
 
#define MAXLINE  1000 
#define TABSTOP 1    
 
int getline(char line[], int maxline);
void copy(char to[], char from[]);
int entab(char tline[], int len, int space);
 
int main()
{
    int len;
    int c, i;
    char line[MAXLINE];
    
      i = 0;
      while((c = getchar()) != EOF) {
         printf("入力行の数 = %d, 入力した文字列 = %s", len, line);
        
         if(c == ' ' || c == '\t') {
           i = TABSTOP;
           putchar(' ');
           printf("置き換えられた入力行の数 = %d, 置き換えられた文字列 = %s", len, line);
         }
         else{
           ++i;
         }
      return 0;
      }
                                                                                                         

int getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
       s[i] = c;
      if (c == '\n') {
          s[i] = c;
          ++i;
       }

       s[i] = '\0';
       return i;
}
                                                                                                                                                                    

void copy(char to[], char from[])
{
    int i;                                                                                                                                                                             
    i = 0;
    while ((to[i] = from[i]) != '\0')                                                                                                                                                             ++i;
}
                                                                                                                                                                                              int entab(char line[], int len, int tspace)
{   
    char tline[MAXLINE];                                                                                                                                                                          int i, len, tspace;
    len = tspace = 0;
    while(tspace <= TABSTOP)
          ++i;
}
