#include <stdio.h>

/* 1.ファイル複写プログラムを作る。
 　2.cの値と（c != EOF）の値を出力する　→　printfで出力*/

int main()
{

    int c;
 
    c = getchar();      /*getchat()からcの値を1つ取り出る。例えば、abcと入力したら、getchar(abc)の中から順にint c=a→cの順で処理される*/
       printf("\n");    /* while文の中の出力と同じ行にならないように、　改行を入れる。*/
       printf("cの値 = %d, (c != EOF)の値 =  %d\n", c, (c != EOF)); /* c(例えば、abcだったらまずはaがcの値となる)とc != EOFの値を出力 */

    while(c != EOF) {  /* c != EOFだったら、while文実行。*/
       putchar(c);     /*putchar()でaを複写*/
       c = getchar();  /*aが終わったので、getchar(bc)となり、次はbがcの値とされる */
       printf("\n");   /*　次の行で出力するものがあるので、同じ行にならないように、改行する */

       printf("cの値 = %d, (c != EOF)の値 =  %d\n", c, (c != EOF)); 
 
    }
    return 0;
}


