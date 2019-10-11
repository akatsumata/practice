#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];

struct nlist{
    	struct nlist *next;
    	char *name;
    	char *defn;
};

unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *, char *);
void undef(char *);
char *l_strdup(char *);

int main()
{
    	int i;
    	
	install("undef", ", C programming");
    	printf("- before undef -\n");
    	for(i = 0; i < HASHSIZE; i++){
        	if(hashtab[i]){
            		printf("%s %s\n", hashtab[i]->name, hashtab[i]->defn);
        	}
    	}
    
    	undef("undef");
    	printf("\n- after undef-\n");
    	for(i = 0; i < HASHSIZE; i++){
        	if(hashtab[i] != NULL){
            		printf("%s %s\n", hashtab[i]->name, hashtab[i]->defn);
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
        	if(strcmp(s, np->name) == 0){
            		return np;
 		}
    	}
    	return NULL;
}

struct nlist *install(char *name, char *defn)
{
    	struct nlist *np;
    	unsigned hashval;
    
    	if((np = lookup(name)) == NULL){
        	np = (struct nlist *) malloc(sizeof(*np));
        	if(np == NULL || (np->name = strdup(name)) == NULL){
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
    	struct nlist  *prevp, *np;
    	unsigned hashval = hash(s);
    	for(np = hashtab[hashval]; np != NULL; np = np->next){
        	if(strcmp(s, np->name) == 0){
            		break;
 		}
        	prevp = np;
    	}
    	if(np != NULL){
        	if(prevp == NULL){
            		hashtab[hashval] = np->next;
        	} else { 
            		prevp->next = np->next;
 		}
        	free((void *) np->name);
        	free((void *) np->defn);
        	free((void *) np);
    	}
}
