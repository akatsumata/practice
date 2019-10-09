#include <stdio.h>
#include <ctype.h>

#define MAXWORD 100
#define MAXLINE 100
#define FOLD 5

int l_getline(char line[], int maxline);
void fold_line(char new_line[], char line[]);

int main()
{
	char n[MAXWORD] = "1234567890123";
	printf("n :%s:\n", n);
	printf("n.10s :%.10s:\n", n);
	printf("n-15.10s :%-15.10s:\n", n);
	printf("'\\n' :hex = 0x%X\n\n", '\n');

	int len, c;
	char line[MAXLINE];
	char new_line[MAXLINE];

        
	while((len = l_getline(line, MAXLINE)) > 0){
                fold_line(new_line, line);
		printf("\n - ver. fold_line - \n");
                printf("n:\n%s0x%X", new_line, '\n');
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
    	int i, j, word_count;
 
    	i = j = word_count = 0;
    	while(line[i] != '\0' && i < MAXLINE){
        	if(word_count == FOLD){
                	new_line[j] = '\n';
			word_count = 0;
			++j;
		}
        	new_line[j] = line[i];
        	++i;
        	++j;
		++word_count;
	}
    	new_line[j] = '\0';
}		
