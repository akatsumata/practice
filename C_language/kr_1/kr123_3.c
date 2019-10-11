#include <stdio.h>
 
#define MAXLINE 1000
 
int l_getline(char line[], int lim);
 
int main()
{
    int len;
    char line[MAXLINE];
 
    while((len = l_getline(line, MAXLINE)) > 0) {
          printf("%s\n", line);
     }
     return 0;
}
 
 
int l_getline(char line[], int lim)
{
	int c, i;
	c = 0;
	for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		while(c == '/' && c + 1 == '*') {
			++i;
			if(c == '*' && c + 1 == '/'){
				i = 0;
				printf = '\n';
				++i;
			} else {
				i
	
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

