#include <stdio.h>
 
#define MAXLINE 1000
#define TABSTOP 4
 
int i;
char oriline[MAXLINE];
char newline[MAXLINE];
 
int l_getline(char line[], int maxline);
void entab(char newline[], char oriline[]);
 
int main()
{
    int len;
    char oriline[MAXLINE];
    char newline[MAXLINE];
 
    i = 0;
    while((len = l_getline(oriline, MAXLINE)) > 0){
        entab(newline, oriline);
        printf("oriline\n%s\n", oriline);
        printf("newline\n%s\n", newline);
    }
    return 0;
}
 
int l_getline(char s[], int lim)
{
        int c, i;
 
        for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
                s[i] = c;
        if(c == '\n') {
                s[i] = c;
                ++i;
    }
        s[i] = '\0';
        return i;
}
 
 
void entab(char newline[], char oriline[])
{
	int i, j, k;
    
	i = j = k = 0;
	for(i = 0; i < MAXLINE; ++i){
		if(oriline[i] == ' '){
			++k;
                        if(k < TABSTOP){
				++k;
			} else if(k == TABSTOP){
                        	k = 0;
                        	i = i -3;
                        	oriline[i] = '\t';
                        	newline[j] = oriline[i];
			}
		} else if(oriline[i] != ' '){
			k = 0;
			++i;
			++j;
			newline[j] = oriline[i];
		}
	}
	

/*    while(line[i] != '\0' && i < MAXLINE){
        if(line[i] !=' '){
            newline[j] = line[i];
            ++i;
            ++j;
            ++k;
            if(k == TABSPACE){
                k = 0;
        
            }
        } else {
            while(k < TABSPACE){
                ++k;
                ++i;
            }
            ++i;
            k = 0;
        }
    }*/
    newline[j] = '\0';
}

