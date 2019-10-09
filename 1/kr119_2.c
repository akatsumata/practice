#include <stdio.h>

#define MAXLINE 1000

int l_getline(char line[], int maxline);
void copy(char to[], char from[])
int reverse(char s[]);


int main()
{
	int len;
	int i;
	char line[MAXLINE];

	i = 0;
	while((len = l_getline(line, MAXLINE)) > 0) {
		printf("入力行群の長さ = %d\n", len);
		printf("入力行のテキスト = %s", line);
		reverse(line);
		printf("逆 = %s", line);
		printf("\n");
		++i;
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


void copy(char to[], char from[])
{
	int i;

	i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}


int reverse(char s[])
{
	char n_line[MAXLINE];
	int len;
	int i, j ;

	len = 0;
	i = 0;
	while(i < MAXLINE - 1){
		n_line[i] = s[i]
		++i
		if(s[i] == '\0'){
			++len;
		}
		n_line[i] = 0;
		copy(s, n_line);
	}
}
