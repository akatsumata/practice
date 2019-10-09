#include <stdio.h>

#define MAXLINE 100

int strend(char *, char *);

int main(void)
{
 	int strend(char *, char *);
 	
	char s1[MAXLINE] = "hello,";
 	char t1[MAXLINE] = "world";  
 	printf("s1=%s\nt1=%s\nreturn=%d\n\n", s1, t1, strend(s1, t1));
 
	char s2[MAXLINE] = "hello,world";
 	/*char t2[MAXLINE] = "C_programming";*/  
 	printf("s2=%s\nt1=%s\nreturn=%d\n", s2, t1, strend(s2, t1));
     
	return 0;

}

int strend(char *s, char *t)
{

    	char *ps = ps;
        char *pt = pt;

     	while(*s != '\0'){
         	s++;
     	}
     	while(*t != '\0'){
         	t++;
     	}
     	if(*s == *t && pt == t && *s != 0){
             	return 1;
        } else {
      		return 0;
	}
}
