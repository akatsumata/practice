#include <stdio.h>

#define MAXLINE 1000

char line[MAXLINE];
int l_getline(char line[], int maxline);

int main()
{
	int i, len;
	i = 0;
	while((len = l_getline(line, MAXLINE)) > 0){
		if(line[i] == '/' && line[i + 1] == '*'){
			if(line[i] == '*' && line[i + 1] == '/'){
				line[i] = '\n';
			} else {
				printf("%c", line[i]);
				++i;
			}
		} else {
			printf("%c", line[i]);
			++i;
		}
	}
	return 0;
}

int l_getline(char s[], int lim)
{
	int c, i;
	for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if(c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
