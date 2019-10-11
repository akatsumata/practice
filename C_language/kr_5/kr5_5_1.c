#include <stdio.h>
/*#include <string.h>*/

#define MAXSIZE 100

void l_strncpy(char *, char *, int);
void l_strncat(char *, char *, int);
int l_strncmp(char *, char *, int);

int main()
{
   	char s[MAXSIZE] = "Hello,world", s1[MAXSIZE];
 
 	/* strncpy */
	printf("- strncpy- \n\ncharacter1=%s\n\n", s);
 	l_strncpy(s1, s, 4);
 	printf("max char=4\nmost n char=%s\n\n", s1);
         
 	/* strncat */
 	char t[MAXSIZE] = "1234567";
     	printf("- strncat -\n\ncharacter2=%s\n", t);
     	l_strncat(s, t, 15);
     	/*printf("s=\n%s\nt=\n%s\n\n", s, t);*/
     	printf("s=\%s\n\n", s);
        
 	/* strncmp */
	printf("- strncmp -\n\n");
     	printf("character1=%s\ncharacter2=%s\nreturn=%d\n\n", s, t, l_strncmp(s, t, 9));
     	printf("character1=%s\ncharacter1=%s\nreturn=%d\n\n", s, s, l_strncmp(s, s, 10));
 	printf("character2=%s\ncharacter2=%s\nreturn=%d\n\n", t, t, l_strncmp(t, t, 6));
 
	return 0;
}

void l_strncpy(char *s, char *t, int n)
{
 	while(*t != '\0' && n > 0){
  		*s = *t;
  		++s;
  		++t;
  		n--;
 	}
 	*s = '\0';
}

void l_strncat(char *s, char *ct, int n)
{
  	while(*s != '\0'){
         	s++;
     	}
     	for(; *ct != '\0' && n > 0; s++, ct++, n--) {
         	*s = *ct;
     	}
     	*s = '\0';
}

int l_strncmp(char *s, char *t, int n)
{
     	for(; *s == *t; s++, t++) {
         	if(*s == '\0' || --n <= 0) {
              		return 0;
         	}
     	}
     	return *s - *t;
}
