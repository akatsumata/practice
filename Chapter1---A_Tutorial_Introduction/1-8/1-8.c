#include <stdio.h>
 
int main()
{
    	int c, space, tab, kaigyo;
 
    	space = tab = kaigyo = 0;
    	while ((c = getchar()) != EOF) {
          	if (c == ' ')
             		++space;
         	else if (c == '\t' )
             		++tab;
         	else if (c == '\n' )
             		++kaigyo;
    	}
 
    	printf("空白 = %d, タブ = %d, 改行 = %d\n", space, tab, kaigyo);
   
    	return 0;
 
}

