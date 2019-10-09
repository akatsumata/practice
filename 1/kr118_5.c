#include <stdio.h>
#define MAXLINE 1000

int l_getline(char line[], int maxline);

int main()
{
	int len;
	int new_line;
	char line[MAXLINE];
	char loingest[MAXLINE];

	new_line = 0;
	while((len = l_getline(line, MAXLINE)) > 0){
		if(len != ' '){
			printf("len = %s\n", len);
		}
		return 0;
	}
}

int l_getline(char s[], int lim)
{
	int c, i;

	for(i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = 0;
	if(c == '\n'){
		s[i] = c;
		++i;	
	} else if(c == (' ''\n') && c == ('\t''\n')){
		s[i] = '\0';
		printf("\n");
		++i;
	}
	s[i] = '\0';
	return i;
}
