#include <stdio.h>

void expand(char s1[], char s2[]);

int main()
{
        char s1[100] = "a-z";
        char s2[100];
        expand(s1,s2);
        printf("s1 =%s\ns2 =%s\n", s1, s2);
        return 0;
}

void expand(char s1[], char s2[])
{
        int i, j, flag;
        char start, end;
	
	flag = 0;
        while(s1[i] != EOF){
		if(s1[i] != '\0'){
			start = s1[i];
			++i;
			if(s1[i] == '-'){
				flag = 1;
				++i;
		}	}
		if(flag == 2){
			if(s1[i] != '\0'){
				end = s1[i];
				for(i = start; i <= end; i++){
					s2[j] = s1[i];
					++j;
				}
			}
		}
	}
	s2[j] = '\0';
			
}
