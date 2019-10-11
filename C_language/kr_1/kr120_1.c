#include <stdio.h>

#define MAXLINE 1000
#define TABSTOP 4

char line[MAXLINE];
char new_line[MAXLINE];

int l_getline(void);
void detab(char new_line[], char line[]);

int main()
{
	int len;
	extern char line[MAXLINE];
	extern char new_line[MAXLINE];

	while((len = l_getline()) > 0){
		detab(new_line, line);
		printf("new_line = %s", new_line);
		
	}
	return 0;
}

int l_getline(void)
{
	int c, i;
	extern char line[];

	for(i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if(c == '\n'){
		line[i] = c;
		++i;
	}
	line[i] = c;
	return i;
}

void detab(char new_line[], char line[])
{
	int i, j, k;
/*	extern char line[MAXLINE];
	extern char new_line[MAXLINE];*/ 

	i =  j = k = 0;
	while((new_line[j] = line[i]) != '\0'){
		if(line[i] == '\t'){
			for(k = 0; k < TABSTOP; ++i, ++j)
				new_line[j] = ' ';
		} else {
			++i;
			++j;
		}
	}
}


/*
void detab(char new_line[], char line[])
{
	int i, j;

	i = j = 0;
	while(line[i] != '\n' && line[i] != '\0'){
		if(line[i] == '\t'){
			new_line[j] = ' ';
		} else {
			++i;
		}
	}
}*/
