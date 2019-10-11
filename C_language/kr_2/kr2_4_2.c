#include <stdio.h>

#define MAXLINE 100

void squeeze(char line[], char remove_char[]);

int main()
{
        char line[] = "12345012345";
        char remove_char[] = "234";
        squeeze(line, remove_char);
        printf("%s\n", line);
        return 0;
}

void squeeze(char line[], char remove_char[])
{
        int i, j, k, l;

       	for(i = k = 0; line[i] != '\0'; i++){
           	for(j = 0; remove_char[j] != '\0'; j++){
			printf("i = %d, j = %d, k =%d\n", i, j, k);
                        if(line[i] == remove_char[j]){
				break;
			}
		}		
		if(remove_char[j] == '\0'){
			line[k++] = line[i];
                }
	}
        line[k] = '\0';
}
