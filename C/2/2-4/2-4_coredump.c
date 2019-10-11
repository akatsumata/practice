#include <stdio.h>
 
#define MAXLINE 100
 
void squeeze(char line[], char remove_char[]);
 
int main()
{
        char line[MAXLINE] = "12345012345";
        char remove_char[MAXLINE] = "123";
        squeeze(line, remove_char);
        printf("%s\n", line);
        return 0;
}
 
void squeeze(char line[], char remove_char[])
{
        int i, j, k;
        for(i = k = 0; line[i] != '\0'; i++){
                for(j = 0; remove_char[j] != '\0'; j++){
                        if(line[i] != remove_char[j]){
                                line[k++] = line[i];
                        } else if(line[i] == remove_char[j]){
                                i++;
                        }
                }
        }
        line[k] = '\0';
}

