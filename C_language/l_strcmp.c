#include <string.h>

int l_strcmp(char *s,  *p)
{
        char *t = p->word;
    
        for(; *s == *t; s++, t++){
          	if(*s == '\0'){
                	return 0;
             	}
        }
        return *s - *t;
}

