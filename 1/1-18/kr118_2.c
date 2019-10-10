#include <stdio.h>

#define MAXLINE 1000
 
int l_getline(char line[], int maxline);
void copy(char to[], char from[]);
void l_remove(char real_line[], int len, char line[]);
 
int main()
{
	int len;
	char line[MAXLINE];
	char real_line[MAXLINE];
 
	while((len = l_getline(line, MAXLINE)) > 0){
   		 if(len != '\t' && len != ' '){	
			len = leal_line;
			printf("入力行群の長さ = %d\n", len);
			printf("出力されるテキスト = %s\n", real_line);
		}
		if(len == 
          ++i;
      }
      return 0;
}
 
int l_getline(char s[], int lim)
{
    int c, i;
 
    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if(c == 'n') {
        s[i] = c;
        ++i;
     }
     s[i] = '\0';
     return i;
}
 
void copy(char to[], char from[])
{
    int i;
 
    i = 0;
    while((to[i] = from[i] != '\0')
          ++i;
}
 
void l_remove(char line[], int len, char real_line[])
{
    int i, c;
    c = 0;
 
/* ブランクとタブを取り除く */
    for(i = 0, line[i] != '\n'; ++i){
        if(c == ' ' || c == '\t' ) {
          ++i;
        }
        else{
           real_line[j] = line[i];
           ++j;
        }
     
     }
/* 空白行を削除する */
       if(c == ' ' || c == '\t'){
            real_line = '\0';
            return real_line;
        }
}

