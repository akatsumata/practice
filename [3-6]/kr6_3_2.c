#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define NOISEWORDS_SIZE   (sizeof noisewords / sizeof noisewords[0])

struct tnode {
    	char *word;
    	int lines[100];
    	int count;
    	struct tnode *left;
    	struct tnode *right;
};

char *noisewords[] = {
    	"and", "the"
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
int binsearch(char *, char * noisewords[], int);

int main() {
    	struct tnode *root;
    	char word[MAXWORD];

    	root = NULL;
    	while(getword(word, MAXWORD) != EOF){
        	if(isalpha(word[0])){
            		if(binsearch(word, noisewords, NOISEWORDS_SIZE) == -1){
                		root = addtree(root, word);
     			}
 		}
    	}
    	treeprint(root);
    	return 0;
}

struct tnode *talloc(void);
char *l_strdup(char *s);

struct tnode *addtree(struct tnode *p, char *w)
{
    	int cond;
    	if(p == NULL){
        	p = talloc();
        	p->word = l_strdup(w);
        	p->lines[p->count++] = 1;
        	p->left = p->right = NULL;
    	} else if((cond = strcmp(w, p->word)) == 0) {
        	if(p->lines[p->count - 1] != 1){
            		p->lines[p->count++] = 1;
 		}
    	} else if(cond < 0) {
        	p->left = addtree(p->left, w);
    	} else {
        	p->right = addtree(p->right, w);
    	}
    	return p;
}

void treeprint(struct tnode *p)
{
    	int i;
    	if(p != NULL){
        	treeprint(p->left);
        	printf("%s:", p->word);
        	for(i = 0; i < p->count; i++){
            		printf("%d, ", p->lines[i]);
 		}
        	printf("\n");
        	treeprint(p->right);
    	}
}

int binsearch(char *word, char *noisewords[], int n) {
    	int cond;
    	int low, high, mid;
    	low = 0;
    	high = n - 1;
    	while(low <= high){
        	mid = (low + high) / 2;
        	if((cond = strcmp(word, noisewords[mid])) < 0){
            		high = mid - 1;
        	} else if(cond > 0) {
            		low = mid + 1;
        	} else {
            		return mid;
        	}
    	}
    	return -1;
}

int getword(char *word, int lim)
{
    	int c, getch(void);
    	void ungetch(int);
    	char *w = word;
    	while(isspace(c = getch()) && c != '\n'){
        	;
    	}
    	if(c != EOF){
        	*w++ = c;
    	}
    	if(!isalpha(c)){
        	if(c == '\n'){
            		*w++;
 		}
        	*w = '\0';
        	return c;
    	}
    	for(; --lim > 0; w++){
        	if(!isalnum(*w = getch())){
            		ungetch(*w);
            		break;
        	}
    	}
    	*w = '\0';
    	return word[0];
}


struct tnode *talloc(void)
{
    	struct tnode *p = (struct tnode *) malloc(sizeof (struct tnode));
}
