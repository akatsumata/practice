#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct nlist{
        struct nlist *next;
        char *name;
        char *defn;
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];

unsigned int hash(char *);
struct nlist *lookup(char *);
struct nlist *install(char *, char *);
void l_define(void);
char *l_strdup(char *);
void undef(char *);
int getword(char *, int);

int getch(void);
void ungetch(int);

#define MAXWORD 100

int main(int argc, char *argv[])
{
        char w[MAXWORD];
        struct nlist *p;

        while(getword(w, MAXWORD) != EOF){
                if(strcmp(w, "#") == 0){
                        l_define();
                } else if(!isalpha(w[0])) {
                        printf("%s", w);
                } else if((p = lookup(w)) == NULL) {
                        printf("%s", w);
                } else {
                        ungetch(p->defn);
                }
        }
        return 0;
}

unsigned hash(char *s)
{
        unsigned hashval;

        for(hashval = 0; *s != '\0'; s++){
                hashval = *s + 31 * hashval;
        }
        return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
        struct nlist *np;

        for(np = hashtab[hash(s)]; np != NULL; np = np->next){
                if(strcmp(np->name, s) == 0){
                        return np;
                }
        }
        return NULL;
}

struct nlist *install(char *name, char* defn)
{
        struct nlist *np;
        unsigned hashval;

        if((np = lookup(name)) == NULL){
                np = (struct nlist *) malloc(sizeof (*np));
                if(np == NULL || (np->name = l_strdup(name)) == NULL){
                        return NULL;
                }
                hashval = hash(name);
                np->next = hashtab[hashval];
                hashtab[hashval] = np;
        } else {
                free((void *) np->defn);
        }
        if((np->defn = l_strdup(defn)) == NULL){
                return NULL;
        }
  	return np;
}

void undef(char *s)
{
        struct nlist *np, *prevp;
        prevp = 0;

        for(np = hashtab[hash(s)]; np != NULL; np = np->next) {
                if(strcmp(s, np->name) == 0){
                        if(prevp == NULL){
                                hashtab[hash(s)] = np->next;
                        } else {
                                prevp->next = np->next;
                        }
                        free((void *) np->name);
                        free((void *) np->defn);
                        free((void *) np);
                }
        }
}

void l_define(void)
{
    	int c, i;
    	char defn[MAXWORD], word[MAXWORD], name[MAXWORD];

     	while((c = getch()) == ' ' || c == '\t'){
         	;
 	}
     	ungetch(c);
    	if(strcmp(word, "define") == 0) {
        	getword(name, MAXWORD);
      		while((c = getch()) == ' ' || c == '\t'){
         		;
 		}
     		ungetch(c);
        	for(i = 0; i < MAXWORD - 1; i++){
            		if((defn[i] = getch()) == EOF || defn[i] == '\n'){
                		break;
            		}
        	}
        	defn[i] = '\0';
        	install(name, defn);
    	} else if (strcmp(word, "undef") == 0) {
     		while((c = getch()) == ' ' || c == '\t'){
         		;
 		}
     		ungetch(c);
        	undef(name);
    	}
}
