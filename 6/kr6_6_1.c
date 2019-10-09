#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

unsigned int hash(char *);
struct nlist *lookup(char *);
struct nlist *install(char *, char *);
char *l_strdup(char *);
void undef(char *);
int getword(char *, int);
#define MAXWORD 10000
int getch(void);
void ungetch(int);

struct nlist{
    	struct nlist *next;
    	char *name;
    	char *defn;
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];

void find_define(void);
int main()
{
	int c, i;
	char word[MAXWORD], name[MAXWORD], defn[MAXWORD];
	struct nlist *p;
	
	while((c = getword(word, MAXWORD)) != EOF){
		switch(c){
			case '#':
				if(!strcmp(word, "#define")){
					find_define();
				}
				break;
			default:
				printf("%s", word);
				break;
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

void find_define(void)
{
	int c, i;
	char word[MAXWORD], name[MAXWORD], defn[MAXWORD];

	while(c != '\n' && isspace(c = getword(word, MAXWORD))){
		install(name, defn);
	}
	printf("%s = ", word);
}
