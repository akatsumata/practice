#include <stdio.h>

/* nl改行　nw単語カウント　nc文字カウント　→単語は文字列になるということか？
    文字列カウントをするプログラムを作る？超難問。   p.140参考。勉強しないとわからない。
　　出力は、文字列なので、%s */


int main(int argc, char *argv[])
{
    int i;
    for(i = 1; i < argc ; i++)
        printf("%d 番目の文字列 %s\n", i, argv[i]);
    printf("単語数%d\n", argc);
    return 0;
}

