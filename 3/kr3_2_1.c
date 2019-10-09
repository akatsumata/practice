#include <stdio.h>

void escape(char new_line[], char old_line[]);
void reverse_escape(char new_line[], char old_line[]);

int main()
{
        char old_line[100] = "C_programming\tc\nsource\ncode";
        char new_line[100];

        printf("Original line=%s\n", old_line);
        escape(new_line, old_line);
        printf("escape=%s\n", new_line);
        reverse_escape(new_line, old_line);
        printf("Reverse escape=%s\n", old_line);

        return 0;
}

void escape(char new_line[], char old_line[])
{
        int i, j;

        j = 0;
        for(i = 0; old_line[i] != '\0'; i++){
                switch(old_line[i]){
                        case '\n':
                                new_line[j] = '\\';
                                j++;
                                new_line[j] = 'n';
                                break;
                        case '\t':
                                new_line[j] = '\\';
                                j++;
                                new_line[j] = 't';
                                break;
                        default:
                                new_line[j] = old_line[i];
                                j++;
                                new_line[j] = old_line[i];
                                break;
                }
                ++j;
        }
        old_line[i] = '\0';
}

void reverse_escape(char new_line[], char old_line[])
{
        int i, j;

        j = 0;
        for(i = 0; old_line[i] != '\0'; i++){
                switch(old_line[i]){
                        case '\\':
                        switch(old_line[i + 1]){
                                case 'n':
                                        new_line[j] = '\n';
                                        break;
                                case 't':
                                        new_line[j] = '\t';
                                        break;
                                default:
                                        new_line[j] = '\\';
                                        ++j;
                                        new_line[j] = old_line[i];
                                        break;
                        }
                        default:
                                new_line[j] = old_line[i];
                                break;
                }
        }
        old_line[i] = '\0';
}
