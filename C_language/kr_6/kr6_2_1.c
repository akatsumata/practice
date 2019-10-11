#include <stdio.h>
#include <ctype.h>
#include <string.h>

int same = 0;
struct tnode {
     char *word;
     int same;
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
     int n, same = 0;
     
 if(argc <= 1 || argc > 2 || atoi(*(argv+1)) > 0){
         printf("Wrong parameters, use default - 6 -\n");
         n = 6;
         printf("n = %d\n", n);
     } else {
         num = abs(atoi(*(argv+1)));
 }
 n = (--argc && (*++argv)[0] == '-') ? atoi(argv[0] + 1) : 6;
 root = NULL;     
     while(getword(word, MAXWORD) != EOF){
         if(isalpha(word[0]) && strlen(word) >= n){
              root = addtree(root, word, n, &same);
         }
         same = 0;
     }
     treeprint(root);
     return 0;
}
struct tnode *talloc(void);
int compare(char *, struct tnode *, int, int *);
char *strdup(char *);
struct tnode *addtree(struct tnode *p, char *w, int n, int *same)
{
     int cond;
    
     if(p == NULL){
         p = talloc();
         p->word = strdup(w);
         p->find = *same;
         p->left = p->right = NULL;
     } else if((cond = compare(w, p, n, same)) < 0) {
         p->left = addtree(p->left, w, n, same);
     } else if(cond > 0) {
         p->right = addtree(p->right, w, n, same);
     }
     return p;
}
int compare(char *s, struct tnode *p, int n, int *same)
{
     int i;
     char *t = p->word;
    
     for(i = 0; *s == *t; i++, s++, t++){
         if(*s == '\0'){
              return 0;
         }
     }
     if(i >= n){
         *found = 1;
         p->found = 1;
     }
     return *s - *t;
}
#include <stdlib.h>
struct tnode *talloc(void)
{
     return (struct tnode *) malloc(sizeof(struct tnode));
}
char *strup(char *s)
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
         if(p->found){
              printf("%s\n", p->word);
         }
         treeprint(p->right);
     }
}
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

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int getch(void)
{
     return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
     if(bufp >= BUFSIZE) {
         printf("ungetch: too many characters\n");
     } else {
         buf[bufp++] = c;
     }
}

int skip_comment()
{
     int c;
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

