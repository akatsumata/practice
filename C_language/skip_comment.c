#include <stdio.h>



int skip_comment()
{
        int c, getch(void);
	void ungetch(int);
        while((c = getch()) != EOF){
                if(c == '*'){
                        if((c = getch()) == '/'){
                                break;
                        } else {
                                ungetch(c);
                        }
                }
        }
        return c;
}

