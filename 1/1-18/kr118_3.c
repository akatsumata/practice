#include <stdio.h>

#define MAXLINE 1000

int l_getline(char line[], int maxline);
void copy(char to[], char from[]);


int main()
{
	int len;
	int i;
	char line[MAXLINE];
	char w_line[MAXLINE];

	i = 1;
	while((len = l_getline(line, MAXLINE)) > 0){
		if(len != 0){
			printf("\n");
		}
		if(c == ' ' || c == '\t'){
			w_line[i] = '\0';
			w_line = 0;
			return w_line;
			printf("入力行群の長さ = %d\n", len);
			printf("入力行のテキスト = %s", w_line);
		}

		else{
			printf("\n\n");
		}
		++i
	}
	return 0;
}


int l_getline(char s[], int lim)
{
	int c, i;

	for(i = 0; i < lim - 1 && (c = getchar()) !=  EOF && c != '\n'; ++i)
		s[i] = c;
		if(c == '\n'){
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
