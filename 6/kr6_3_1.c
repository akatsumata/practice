#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode{
        char *word;
        struct list *line;
        struct tnode *left;
        struct tnode *right;
};

struct list{
	struck tnode *p_word;
	int line_number[100];
	int count;
}

struct line *addline(struct tnode *, struct lines *, int);
void treeprint(struct tnode *);
void lineprint(struct lines *);
int binsearch_noise_word(char *);
int getword(char *, int);

int main(void)
{
    	struct tnode *root;
    	char word[MAXWORD];
	int line_number = 1

    	root = NULL;
    	while(getword(word, MAXWORD) != EOF){
        	if(isalpha(word[0])){
            		if(noise_word(word)) {
                		root = addtree(root, word, line_number);
            		}
        	}
    	}
    	treeprint(root);
    	return 0;
}

int binsearch _noize_word(char *word)
{
        char *noize_word[] = {"the", "and"};
        int cond;
        int low, high, mid;
        low = 0;
        high = sizeof(noise_word) / sizeof(char *) - 1;

        while(low <= high){
                mid = (low + high) / 2;
                if((cond = l_strcmp(w, noise_word[mid])) < 0){
                        high = mid - 1;
                } else if(cond > 0) {
                        low = mid + 1;
                } else {
                        return mid;
                }
        }
        return - 1;
}


struct tnode *talloc(void);
struct lines *line_alloc(void);
char *l_strdup(char *);
struct tnode *addtree(struct tnode *p, char *w, int nline)
{
    int cond;
    if (p == NULL) 
        p = talloc(); 
        p->word = l_strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
        p->lines = addline(p, NULL, nline);
    } else if ((cond = l_strcmp(w, p->word)) == 0) {
        p->count++;  
        addline(p, p->lines, nline);
    } else if (cond < 0) { 
        p->left = addtree(p->left, w, nline);
    } else { 
        p->right = addtree(p->right, w, nline);
    }
    return p;
}
void treeprint(struct tnode *p)
{
    	if(p != NULL){
        	treeprint(p->left);
        	printf("%4d %s\n", p->count, p->word);
        	line_print(p->lines);
        	treeprint(p->right);
    	}
}

struct line *addline(struct tnode *p, struct n_line *l, int nline)
{
    	if(l == NULL){ 
        	l = line_alloc();
        	l->word = p;
        	l->line_number[0] = nline;
        	l->count = 1;
    	} else if (l->number[l->count-1] != nline) {
        	l->number[l.count++] = nline;
    	}
    	return l;
}

void lineprint(struct lines *l)
{
    	int i;
    	for(i=0; i < l.count; i++){
        	printf("line=%d:", l->number[i]);
		if(i != l.count - 1){
			printf(", ");
    		}
	}
}

struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}
struct lines *lalloc(void)
{
    return (struct lines *) malloc(sizeof(struct lines));
}
