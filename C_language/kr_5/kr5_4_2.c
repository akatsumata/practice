#include <stdio.h>

#define MAXLINE 100

int strend(char *, char *);

int main(void)
{
 	int strend(char *, char *);
     	char *s = "hello, world";
     	char *t1 = "world";
 	char *t2 = "programming";

 	printf("s=%s, t1=%s, return %d\n\n", s, t1, strend(s, t1)); 
 	printf("s=%s, t2=%s, return=%d\n", s, t2, strend(s, t2));

     	return 0;
}

int strend(char *s, char *t)
{
     	char *ps = s;
     	char *pt = t;
    
     	while(*s != '\0'){
        	 s++;
     	}
     	while(*t != '\0'){
        	t++;
     	}
     	while(*s == *t){
         	if(s == ps || t == pt){
              	break;
  		}
         	s--;
         	t--;
     	}
     	if(*s == *t && t == pt && *s != 0){
             	return 1;
        } else {
      		return 0;
	}
}
