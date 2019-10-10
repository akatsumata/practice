#include <stdio.h>

#define MAXLINE 1000

int l_getline(char line[], int maxline);

int main()
{
	int l_small, r_small;
	int l_med, r_med;
	int l_large, r_large;
	int i, len;
	char line[MAXLINE];

	l_small = r_small = 0;
	l_med = r_med = 0;
	l_large = r_large = 0;
	i = 0;
	while((len = l_getline(line, MAXLINE)) > 0){
		while(line[i] != '\0'){
			++i;
			for(i = 0; i < MAXLINE; ++i){
				if(line[i] == '('){
					++l_small;
				} else if(line[i] == ')'){
					++r_small;
				}
			}
			if((l_small > 0 || r_small > 0) && l_small != r_small){
				printf("Unbalanced small\n");
			}
		}
		
		while(line[i] != '\0'){
                        ++i;
                        for(i = 0; i < MAXLINE; ++i){
                                if(line[i] == '['){
                                        ++l_med;
                                } else if(line[i] == ']'){
                                        ++r_med;
                                }
                        }
                        if((l_med > 0 || r_med > 0) && l_med != r_med){
                                printf("Unbalanced med\n");
                        }
                }

		while(line[i] != '\0'){
                        ++i;
                        for(i = 0; i < MAXLINE; ++i){
                                if(line[i] == '{'){
                                        ++l_large;
                                } else if(line[i] == '}'){
                                        ++r_large;
                                }
                        }
                        if((l_large > 0 || r_large > 0) && l_large != r_large){
                                printf("Unbalanced large\n");
                        }
                }
		line[i] == '\0';
		return 0;
	}
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
