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
struct tnode *addtree(struct tnode *, char *);
void l_qsort(void);

void treeprint(struct tnode *);
int getword(char *, int);

int main(int argc, char *argv[])
{
    	struct tnode *root;
    	char word[MAXWORD];
    	int i, node;
    	
	root = NULL;
    	while(getword(word, MAXWORD) != EOF){
        	if(isalpha(word[0])){
            		root = addtree(root, word);
        	}
    	}
    	treeprint(root);
    	l_qsort();
    	for(i = 0; i < node; i++){
        	printf("count = %d, word = %s\n", list[i]->count, list[i]->word);
    	}
    	return 0;
}

struct tnode *talloc(void)
{
    	return (struct tnode *) malloc(sizeof(struct tnode));
}

void treeprint(struct tnode *p)
{
    	if(p != NULL){
        	treeprint(p->left);
        	printf("%4d %s\n", p->count, p->word);
        	treeprint(p->right);
    	}
}

void l_qsort(void)
{
    	int gap, i, j, node;
    	struct tnode *temp;
    
    	for(gap = node / 2; gap > 0; gap /= 2){
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

struct tnode *talloc(void);
char *l_strdup(char *s);
struct tnode *addtree(struct tnode *p, char *w)
{
    	int cond;
    
    	if(p == NULL){
        	p = talloc(); 
        	p->word = l_strdup(w);
        	p->count = 1;
        	p->left = p->right = NULL;
    	} else if((cond = strcmp(w, p->word)) == 0){
        	p->count++;
    	} else if(cond < 0){
        	p->left = addtree(p->left, w);
    	} else {
        	p->right = addtree(p->right, w);
    	}
    	return p;
}
