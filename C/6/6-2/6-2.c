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

