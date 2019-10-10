#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100
struct tnode {
     char *word;
     int count;
     struct tnode *left;
     struct tnode *right;
};
struct tnode *list[100];
int node = 0;
struct tnode *addtree(struct tnode *, char *);
void list_tree_node(struct tnode *);
void shellsort(void);
int getword(char *, int);
char *l_strdup(char *s);

int main(int argc, char *argv[])
{
     struct tnode *root;
     char word[MAXWORD];
     int i;
    
     root = NULL;
     while(getword(word, MAXWORD) != EOF){
         if(isalpha(word[0])){
              root = addtree(root, word);
         }
     }
     list_tree_node(root);
     shellsort();
     for(i = 0; i < node; i++){
         printf("%d: %s\n", list[i]->count, list[i]->word);
     }
     return 0;
}
struct tnode *talloc(void);
struct tnode *addtree(struct tnode *p, char *w)
{
     int cond;
    
     if(p == NULL){
         p = talloc();
         p->word = l_strdup(w);
         p->count = 1;
         p->left = p->right = NULL;
     } else if((cond = strcmp(w, p->word)) == 0) {
         p->count++;
     } else if (cond < 0) {
         p->left = addtree(p->left, w);
     } else if(cond > 0) {
         p->right = addtree(p->right, w);
     }
     return p;
}
struct tnode *talloc(void)
{
     return (struct tnode *) malloc(sizeof(struct tnode));
}
void list_tree_node(struct tnode *p)
{
     if(p != NULL){
         list_tree_node(p->left);
         if(node < 100){
              list[node++] = p;
         }
         list_tree_node(p->right);
     }
}
void shellsort(void)
{
     int gap, i, j;
     struct tnode *temp;
    
     for(gap = node / 2; gap > 0; gap /=2){
         for(i = gap; i < node; i++){
              for(j = i - gap; j >= 0; j -= gap){
                  if((list[j]->count) >= (list[j + gap]->count)){
                       break;
                  }
                  temp = list[j];
                  list[j] = list[j + gap];
                  list[j + gap] = temp;
              }
         }
     }
}

