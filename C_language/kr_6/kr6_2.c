#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct tnode {
	char *word;
     	int same_6;
     	struct tnode *left;
     	struct tnode *right;
};

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *, int, int *);
void treeprint(struct tnode *);
int getword(char *, int);

int l_strcmp(struct tnode *, char *, int, int *);
void l_strcpy(char *, char *);
int getch(void);
void ungetch(int);

int main(int argc, char *argv[])
{
     	int aaaaaa1234, aaaaaa5678, aaaaaa2468;
	int bbbbbb1234, bbbbbb5678, bbbbbb2648;
	
     	struct tnode *root;
    	char word[MAXWORD];
   
     	root = NULL;
 
	if(argc != 3){
  		printf("ERROR\n");
  		exit(1);
 	}
 	if(argc == 2){
      		int len = atoi(argv[1]);
 	}
 
     	while(getword(word, MAXWORD) != EOF){
         	if(isalpha(word[0])){
              		root = addtree(root, word, len, same_6);
  		}
 	}
    	treeprint(root);
     	return 0;
}

struct tnode *talloc(void);
char *l_strdup(char *);
int l_strcmp(struct tnode *, char *, int, int *);

struct tnode *addtree(struct tnode *p, char *w, int len, int *same_6)
{
     	int cond;
    
     	if(p == NULL){
         	p = talloc();
         	p->word = l_strdup(w);
         	p->same_6 = *same_6;
         	p->left = p->right = NULL;
     	} else if((cond = l_strcmp(w, p, len, same_6)) <= 0){
         	p->left = addtree(p->left, w, len, same_6);
     	} else {
         	p->right = addtree(p->right, w, len, same_6);
 	}
     	return p;
}

int l_strcmp(struct tnode *p, char *w, int len, int *same_6)
{
     	char *s = p->word;
     	for(; *w == *s; w++, s++){
      		if(*w == '\0'){
          		return 0;
      		}
 	}
     	return *w - *s;
}

#include <stdio.h>
#include <ctype.h>
 
int getword(char *word, int lim)
{
        int c, j, getch(void), skip_comment();
        void ungetch(int);
        char *w = word;
 
        while(isspace(c = getch())){
                ;
        }
        if(c != EOF){
                *w++ = c;
        }
        if(isalpha(c) || c == ' ' || c == '#'){
                for(; --lim > 0; w++){
                        if(!isalnum(*w = getch()) && *w != '_'){
                                ungetch(*w);
                                break;
                        }
                }
        } else if(c == '\'' || c == '"'){
                for(; --lim > 0; w++){
                        if((*w = getch()) == '\\'){
                                *++w = getch();
                        } else if(*w == c) {
                                w++;
                                break;
                        } else if(*w == EOF) {
                                break;
                        }
                }
        } else if(c == '/') {
                if((j = getch()) == '*'){
                        c = skip_comment();
                } else {
                        ungetch(j);
                }
        }
        *w = '\0';
        return c;
}


void treeprint(struct tnode *p)
{
     	if(p != NULL){
         	treeprint(p->left);
         	if(p->first_6_char){
              		printf("%s\n", p->word);
  		}
         	treeprint(p->right);
     	}
}

struct tnode *talloc(void)
{
     	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *l_strdup(char *s)
{
     	char *p;
    
     	p = (char *) malloc(strlen(s) + 1);
     	if(p != NULL){
         	l_strcmp(p, s, len, same_6);
 	}
     	return p;
}
/*
void l_strcpy(char *p, char *s)
{
	int i = 0;

	while((p[i] = s[i]) != '\0'){
		i++;
	}
}
*/
#include <stdio.h>
 
int skip_comment()
{
        int c, getch(void);
    void ungetch(int);
        while((c = getch()) != EOF){
                if(c == '*'){
                        if((c = getch()) == '/'){
                                break;
                        } else {
                                ungetch(c);
                        }
                }
        }
        return c;
}


#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int getch(void)
{
     return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
     if(bufp >= BUFSIZE){
         printf("ungetch: too many characters\n");
     } else {
         buf[bufp++] = c;
 }
}
