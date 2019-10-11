#include <stdio.h>

#define MAXLINE 100

int any(char s1[], char s2[]);

int main()
{
	int s;
        char s1[] = "23456789";
        char s2[] = "567";
        s = any(s1, s2);
        printf("s1\n=%s\ns2\n=%s\ns\n=%d\n", s1, s2, s);
        return 0;
}
 



int any(char s1[], char s2[])
{
	int i, j;
	for(i = j = 0; s1[i] != '\0'; i++){
		for(j = 0; s2[j] != '\0'; j++){
			if(s1[i] == s2[j]){
				i = j;
				return i;
			}
		}
	}
	return -1;
}
