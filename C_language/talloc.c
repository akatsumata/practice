#include <stdio.h>
#include <stdlib.h>

struct tnode *talloc(void)
{
    	return (struct tnode *) malloc(sizeof(struct tnode));
}

