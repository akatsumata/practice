#include<stdio.h>

#define MAXLINE 1000

void expand(char s1[], char s2[]);

int main()
{
	char s11[MAXLINE] = "a-z";
	char s13[MAXLINE] = "A-Z-";
	char s14[MAXLINE] = "-a-z";
	char s15[MAXLINE] = "-a-b-c";
	char s2[MAXLINE];

	expand("a-z", s2);
        printf("\n%s\nexpand\n%s\n", "a-z", s2);

        expand(s13, s2);
        printf("\n%s\nexpand\n%s\n", s13, s2);

        expand(s14, s2);
        printf("\n%s\nexpand\n%s\n", s14, s2);

        expand(s15, s2);
	printf("\n%s\nexpand\n%s\n", s15, s2);
	
	return 0;
}

void expand(char s1[], char s2[])
{
	int i, j, stock;
	stock = 0;
	for(i = j = 0; s1[i] != '\0'; i++, j++){
		stock = s1[i];
		if(s1[i + 1] == '-' && s1[i + 2] >= stock){
			i = i + 2;
			while(stock < s1[i]){
				s2[j] = stock;
				++stock;
				++j;
			}
		} else {
			s2[j] = s1[i];
		}
	}
	s2[j] = '\0';
}		
