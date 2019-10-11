#include <stdio.h>
#define MAXLENGTH 1000
void expand(char s1[], char s2[]);
int main()
{
    	char s1[MAXLENGTH], s2[MAXLENGTH],
         	s3[MAXLENGTH];
    
    	expand("-a-z-", s1);   
    	expand("a-z0-9", s2);
    	expand("a-b-c", s3);
    
    	printf("%s\n%s\n%s\n", s1, s2, s3);
    
    	return 0;
}
void expand(char s1[], char s2[])
{
    	int i, j, c;
    
    	for(i = 0, j = 0; s1[i] != '\0'; i++, j++) {
        	c = s1[i];
        	if(s1[i + 1] == '-' && s1[i + 2] >= c){
            		i += 2;
            	for (; c < s1[i]; c++, j++){
                	s2[j] = c;
            	}
            	j--;
            	i--;
        	} else {
            		s2[j] = s1[i];
        	}
    	}
    	s2[j] = '\0';
}
