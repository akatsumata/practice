#include <stdio.h>
#define MAXLINE 1000

/* line入力したテキスト、len入力行群の長さ、longest一番長い行 */

int getline(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char s[]);

int main()
{
    int len;
   
    char line[MAXLINE];
    

   
    while((len = getline(line, MAXLINE)) > 0){
           printf("入力したテキスト = %s\n", line);
      
           reverse(line);

           printf("逆に並べる = %s\n", line);
     
           return 0;
}

int getline(char s[], int lim)
{
    int c, i;

    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if(c == 'n') {
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
    while((to[i] = from[i] != '\0')
          ++i;
}

void revers(char [])
{
    char gyaku[MAXLINE];
    int len;
    int i, n;

    len = 0;
    for(i = 0, i < MAXLINE - 1; ++i) {
       if(s[i] == '\0')
         break;
         ++len;
     }
     for(i=len-1, n=0; i >= 0; --i, ++n) {
          gyaku[n] = s[i];
     }
     gyaku[n] = '\0';

     printf("%s %s\n", s, gyaku);

     return 0;
}
