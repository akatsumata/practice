#include <stdio.h>
 
#define MAXLINE 100
 
int any(char line[], char any_string[]);
 
int main()
{
    	int first_location;
        char line[] = "23456789";
        char any_string[] = "567";
        first_location = any(line, any_string);
        printf("line\n=%s\nant_string\n=%s\nfirst_location\n=%d\n", line, any_string, first_location);
        return 0;
}
 
int any(char line[], char any_string[])
{
        int i, j, l;
 
        for(i = 0; line[i] != '\0'; i++){
                for(j = 0; any_string[j] != '\0'; j++){
                        if(line[i] == any_string[j]){
                                return i;
                    	}
                }
    	}
   	return -1;
}

