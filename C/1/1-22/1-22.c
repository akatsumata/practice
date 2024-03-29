#include <stdio.h>
#define MAXLINE 100
#define FOLD 5  /* n=5 */

int l_getline(char line[], int maxline);
void fold_line(char new_line[], char line[]);

int main()
{
        int len;
        char line[MAXLINE];
        char new_line[MAXLINE];
        while((len = l_getline(line, MAXLINE)) > 0){
                fold_line(new_line, line);
                printf("%s", new_line);
        }
        return 0;
}

int l_getline(char s[], int lim)
{
        int c, i;
        for(i = 0; i < lim - 1&& (c = getchar()) != EOF && c != '\n'; ++i)
                s[i] = c;
        if(c == '\n'){
                s[i] = c;
                ++i;
        }
        s[i] = '\0';
        return i;
}


void fold_line(char new_line[], char line[])
{
	int i, j, n, lastblank;

	i = j = n = lastblank = 0;
	while(line[i] != '\0' && i < MAXLINE){
		if(n == FOLD){
			if(new_line[lastblank] == ' '){
				new_line[lastblank] = '\n';
				n = 1;
			} else {
				new_line[j] = '\n';
				++j;
			}
		}
		if(line[i] == ' '){
			lastblank = i;
		}
		new_line[j] = line[i];
		++i;
		++j;
		++n;
	}
	new_line[j] = '\0';
}
