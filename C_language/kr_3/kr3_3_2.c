#include <stdio.h>

void expand(char s1[], char s2[]);

int main()
{
        char s1[30] = {a-z};
        char s2[30];
        expand(s1,s2);
        printf("s1 =%s\ns2 =%s\n", s1, s2);
        return 0;
}

void expand(char s1[], char s2[])
{
        int i, j, k;
	char stock[k];

        while(s1[i] != EOF){
		if(s1[i] != '\0'){
			stock[k] = s1[i];
			++i;
			if(s1[i] == '-' && s1[i + 1] >= stock[k]){
				++i;
				while(stock[k] < s1[i]){
					s2[j] = stock[k];
					++j;
					++k;
				}
			} else {
				s2[j] = stock[k];
				++j;
			}
		}
		s2[j] = '\0';
	}
}
