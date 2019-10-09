#include <stdio.h>

/*[単語が出てきたらカウント→箱に入れる]→ヒストグラムにする 
  ndigit：ヒストグラム */

#define  IN 1
#define OUT 0

int main()
{
	int c, i, word, length, ;
	int ndigit[10];
	i = word = length = 0;

	while((c = getchar())  != EOF){
	





  int c, nl, nw, nc, state;
 
    state = out;
    nl = nw = nc = 0;
    while((c = getchar()) != EOF) {
        ++nc;
        if(c == '\n')
            ++nl;
        if(c == '  ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == out) {
            state = IN;
            ++nw;
         }
      }
 ){
		
		else{
			putchar(c);
			c = getchar();
		}
		++getchar(c);
	}




int main()
{
    int c, ns;
 
    ns = 0;
    while((c = getchar()) != EOF) {
         if (c == ' ') {
            if (ns == 0) {
               putchar(c);
               ++ns;
             }
          }
          else {
               putchar(c);
               ns = 0;
          }
      }      
    return 0;
}



int main()
{
    int c, i, space, word, kaigyo;
    int ndigit[30];
    space = word = kaigyo = 0;
    for(i = 0; i < 30; ++i)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF)
           ++ndigit[c];
        if (c == ' ' || c == '\n' || c == '\t')
           kaigyo = OUT;
        else if (kaigyo == OUT) {
                kaigyo = IN;
                ++word;
              }


    printf("digits =");

    for(i = 0; i < 30; ++i)
       printf("%d\n", ndigit[i]);
    printf("\n");
}

