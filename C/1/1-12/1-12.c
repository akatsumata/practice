#include <stdio.h>
 
/* 例えば、あ　い　う　→あいう、縦一行にする。
　　全部改行する。空白(' ')とタブ('\t')は改行する('\n') */
 
int main()
{
    	int c, nl, nw, nc, ns;
 
    	nl = nw = nc = ns = 0;
    	c = getchar();
    	while(c != EOF) {
        	if(c == '\t' || c == ' '){
            		if(ns == 0){
                		putchar('\n');
			}
            		++ns;
        	} else {
            		putchar(c);
            		ns = 0;
        	}
        	c = getchar();
    	}
    	return 0;
}

