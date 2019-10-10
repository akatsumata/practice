#include <stdio.h>
 
#define IN    1
#define OUT 0
 
 
long main()
{
    long c, nl, nw, nc, state;
 
    state = OUT;
    nl = nw = nc = 0;
 
    nc = 2147483700;
    while(nc >= 0) {
        printf("nc = %d\n", nc);
        c == '\n';
            if(c == '\n')
                ++nl;
            if(c == ' ' || c == '\n' || c == '\t')
                state = OUT;
            else if (state == OUT) {
                state = IN;
                ++nw;
              }
     }
 
    printf("nl = %d, nw = %d, nc = %d\n", nl, nw, nc);
 
    return 0;
 
}
