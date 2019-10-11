#include <stdio.h>

#define MAXLINE 100

void squeeze(char line[], char remove_char[]);

int main()
{
	char line[MAXLINE] = "12345012345";
	char remove_char[MAXLINE] = "2";
	squeeze(line, remove_char);
	printf("%s\n", line);
	return 0;
}

void squeeze(char line[], char remove_char[])
{
	int i, j, k;
	for(i = k = 0; line[i] != '\0'; i++){
		for(j = 0; remove_line[j] != '\0'; j++){
			if(line[i] != remove_line[j]){
				line[k++] = line[i];
			} else if(line[i] == remove_line[j]){
				k++;
			}
		}
	}
	s1[k] = '\0';
}
