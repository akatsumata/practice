#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct tnode{
     	char *word;
     	int same_6;
     	struct tnode *left;
     	struct tnode *right;
};

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *, int, int *);
void treeprint(struct tnode *);
int getword(char *, int);


int main(int argc, char *argv[])
{
     	struct tnode *root;
     	char word[MAXWORD];
     	int same_6 = 0;

	int aaaaaaaaaa, aaaaaabbbb, aaaaaaabab;
	int bbbbbbbbbb, bbbbbbaaaa, bbbbbbabab;
     
	
	if(argc != 2){
		printf("Usage: find pattern\n");
	}
	int len = atoi(argv[1]);

	printf("first_len_char = %d char\n", len);

	root = NULL;     
     	while(getword(word, MAXWORD) != EOF){
         	if(isalpha(word[0]) && strlen(word) >= len){
              		root = addtree(root, word, len, &same_6);
         	}
         	same_6 = 0;
     	}

     	treeprint(root);
     	return 0;
}

struct tnode *talloc(void);
char *l_strdup(char *);
int l_strcmp(char *, struct tnode *, int, int *);

struct tnode *addtree(struct tnode *p, char *w, int len, int *same_6)
{
     	int cond;
    
     	if(p == NULL){
         	p = talloc();
         	p->word = l_strdup(w);
         	p->same_6 =*same_6;
         	p->left = p->right = NULL;
     	} else if((cond = l_strcmp(w, p, len, same_6)) <= 0) {
         	p->left = addtree(p->left, w, len, same_6);
     	} else {
         	p->right = addtree(p->right, w, len, same_6);
     	}
     	return p;
}

int l_strcmp(char *s, struct tnode *p, int len, int *same_6)
{
     	int i;
     	char *t = p->word;
    
     	for(i = 0; *s == *t; i++, s++, t++){
         	if(*s == '\0'){
              		return 0;
         	}
     	}
     	if(i >= len){
         	*same_6 = 1;
         	p->same_6 = 1;
     	}
     	return *s - *t;
}

#include <stdlib.h>
struct tnode *talloc(void)
{
     	return (struct tnode *) malloc(sizeof(struct tnode));
}
char *l_strdup(char *s)
{
     	char *p;
    
     	p = (char *)malloc(strlen(s)+1);
     	if(p != NULL){
         	strcpy(p, s);
 	}
     	return p;
}

void treeprint(struct tnode *p)
{
     	if(p != NULL){
         	treeprint(p->left);
         	if(p->same_6){
              		printf("%s\n", p->word);
         	}
         	treeprint(p->right);
     	}
}
/*
#include <stdio.h>
#include <ctype.h>

int getword(char *word, int lim)
{
        int c, getch(void), skip_comment();
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
                if(((c + 1) == getch()) == '*'){
                        c = skip_comment();
                } else {
                        ungetch(c + 1);
                }
        }
        *w = '\0';
        return c;
}


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
*/