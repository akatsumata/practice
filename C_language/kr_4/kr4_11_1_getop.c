/* getop.c */

#include <stdio.h>
#include <ctype.h>
#include "calc.h"

#define NUMBER '0'

int getch(void);

int getop(char s[])
{
    int i, c;
    static int before = 0;
    if (before == 0) {
        c = getch();
    } else {
        c = before;
        before = 0;
    }
    while ((s[0] = c) == ' '|| c == '\t')
        c = getch();
    s[1] = '\0';
    i = 0;
    if (!isdigit(c) && c != '.' && c != '-') {
        return c;
    }
    if (c == '-') {
        if (isdigit(c = getch()) || c == '.') {
            s[++i] = c;
        } else {
            if (c != EOF) {
                before = c;
            }
            return '-';
        }
    }
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    if (c == '.') {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    s[i] = '\0';
    if (c != EOF) {
        before = c;
    }
    return NUMBER;
}

