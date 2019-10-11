#include <stdio.h>

void expand(char s1[], char s2[]);

int main()
{
	char s1[30];
	char s2[30];
	expand(s1,s2);
	printf("s1 =%s\ns2 =%s\n", s1, s2);
	return 0;
}

void expand(char s1[], char s2[])
{
	int i, j, flag, stock;

	i = j = flag = stock = 0;
	while(s1[i] != EOF){
		while(s1[i] != '\0'){
			if(flag == 0){
				if(s1[i] == '-'){
					flag = 1;
					s2[j] = s1[i];
					++i;
					++j;
				} else if(s1[i] >= 'a' && s1[i] <= 'z' && s1[i] >= 'A' && s1[i] <= 'Z' && s1[i] >= '0' && s1[i] <= '9'){
					flag = 2;
					++i;
				} else {
					s2[j] = s1[i];
                                        ++i;
                                        ++j;
					flag = 0;
				}
			}
			if(flag == 1){
				if(s1[i] >= 'a' && s1[i] <= 'z' && s1[i] >= 'A' && s1[i] <= 'Z' && s1[i] >= '0' && s1[i] <= '9'){
					stock = s1[i];
					flag = 2;
				} else {
					s2[j] = s1[i];
                                        ++i;
                                        ++j;
				}
			}
			if(flag == 2){
				if(s1[i] == '-'){
					flag = 3;
					++i;
				} else {
					s2[j] = s1[i];
                                        ++i;
                                        ++j;
				}
			}
			if(flag == 3){
                                 if(s1[i] >= 'a' && s1[i] <= 'z' && s1[i] >= 'A' && s1[i] <= 'Z' && s1[i] >= '0' && s1[i] <= '9'){
					flag = 4;
					while(stock < s1[i]){
					 	s2[j] = s1[i];
                                        	++j;
					}
				} else {
					flag = 1;
					s2[j] = s1[i];
                                        ++i;
                                        ++j;
				}
			}
			if(flag == 4){
				if(s1[i] == '-'){
					flag = 5;
					++i;
				} else if(s1[i] == '\n'){
					s2[j] = '\n';
					i = j = 0;
					flag = 0;
                                } else if(s1[i] >= 'a' && s1[i] <= 'z' && s1[i] >= 'A' && s1[i] <= 'Z' && s1[i] >= '0' && s1[i] <= '9'){
					flag = 2;
				} else {
					s2[j] = s1[i];
                                        ++i;
                                        ++j;
				}
			}
			if(flag == 5){
                                if(s1[i] >= 'a' && s1[i] <= 'z' && s1[i] >= 'A' && s1[i] <= 'Z' && s1[i] >= '0' && s1[i] <= '9'){
					flag = 2;
				} else if(s1[i] == '\n'){
					s2[j] = '-';
					++j;
					s2[j] = '\n';
					flag = 0;
				} else {
					s2[j] = s1[i];
                                        ++i;
                                        ++j;
				}
			}
			i = j = 0;
			flag = 0;
		}
	}
	s2[j] = '\0';
}
