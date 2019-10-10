#include <stdio.h>
#include <string.h>
void reverse(char s[]);
int main()
{
        char s[] = "abcde";
        reverse(s);
        printf("in=abcde\nreverse=%s\n", s);
        return 0;
}
void reverse(char s[])
{
        static int i = 0;
        int c, j;
        j = strlen(s) - (i+1);
        if(i < j){
                c = s[i];
                s[i++] = s[j];
                s[j] = c;
                reverse(s);
        }
}

