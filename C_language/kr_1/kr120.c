/* 適当な数のブランク＝空白を文字としてカウントする＝n文字（nは各自で決定してよい）ということ？
問題の意味がよくわからない。*/

#include <stdio.h>
#define nTABSTOP 3

int main()
{
    int c, i;
    i = 0;
    while((c = getchar()) != EOF) {
          if(c == '\t') {
            i = nTABSTOP;
            putchar(' ');
          }
          else
            ++i;
     }
    return 0;
}
