#include <stdio.h>
#include <ctype.h>
 
int getword(char *word, int lim)
{
        int c, getch(void), skip_comment();
        void ungetch(int);
        char *w = word;
 
        while(isspace(c = getch())){
                ;
        }
        if(c != EOF){
                *w++ = c;
        }
        if(isalpha(c) || c == ' ' || c == '#'){
                for(; --lim > 0; w++){
                        if(!isalnum(*w = getch()) && *w != '_'){
                                ungetch(*w);
                                break;
                        }
                }
        } else if(c == '\'' || c == '"'){
                for(; --lim > 0; w++){
                        if((*w = getch()) == '\\'){
                                *++w = getch();
                        } else if(*w == c) {
                                w++;
                                break;
                        } else if(*w == EOF) {
                                break;
                        }
                }
        } else if(c == '/') {
                if(((c + 1) == getch()) == '*'){
                        c = skip_comment();
                } else {
                        ungetch(c + 1);
                }
        }
        *w = '\0';
        return c;
}

