/* #include <stdio.h> */
/* #include <ctype.h> */

int htoi(char s[])
{

        int i, n, c;
        i = n = 0;
        while((c = getchar()) != EOF){
                s[i] = c;
                if(s[i] == '0'){
                        i++;
                        if(s[i] == 'x' && s[i] == 'X'){
                                i++;
                        }
                } else if(s[i] >= '0' && s[i] <= '9'){
                        n = 16 * n + (s[i] - '0');
                        i++;
                } else if(s[i] >= 'a' && s[i] <= 'f'){
                        n = 16 * n + (s[i] - 'a' + 10);
                        i++;
                } else if(s[i] >= 'A' && s[i] <= 'F'){
                        n = 16 * n + (s[i] - 'A' + 10);
                        i++;
                }
        }
        return n;
}


