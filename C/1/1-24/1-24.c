#include <stdio.h>

#define MAXLINE 1000

int l_getline(char line[], int maxline);

int main()
{
	int i, len;
	char line[MAXLINE]; 

	i = 0;
	while((len = l_getline(line, MAXLINE)) > 0){
		for(i = 0; i < len; i++){
			if(line[i] == '{'){
				printf("%c", line[i]);
				if(line[i] == '}'){
					printf("%c", line[i]);
					i--;
				} else if(line[i] != '}'){
					printf("ERROR\n");
				} else {
					printf("%c", line[i]);
				}
			} else if(line[i] == '['){
				if(line[i] == ']'){
					printf("%c", line[i]);
					i--;
				} else {
					printf("%c", line[i]);
				}
			} else if(line[i] == '('){
				if(line[i]  == ')'){
					printf("%c", line[i]);
					i--;
				} else {
					printf("%c", line[i]);
				}
			} else {
				printf("%c", line[i]);
			}
		}
	}
	line[i] = '\0';
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

