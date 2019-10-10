#include <stdio.h>
#define MAXLINE 100

int l_getline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
	int len, cw ;
	char n_line[MAXLINE];
	char line[MAXLINE];
	
	cw = 0;
	while((len = l_getline(line, MAXLINE)) > 0 ){
		if(cw != ' ' && cw != '\t' && cw != '\n'){
			printf("入力したテキスト = %s\n", line);
			printf("出力されるテキスト = %s\n", n_line);
		}
		else if(cw == ' ' && cw == '\t'){
			++cw;
		}
		else if(len == 0){
			printf("\n");
		}

	}
	return 0;
}


int l_getline(char s[], int lim)
{
	int c, i;

	for(i = 0; i < lim-1 &&(c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if(c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

