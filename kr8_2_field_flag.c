#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define PERMS 066

#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20

typedef struct _iobuf {
    	int cnt;      
    	char *ptr;       
    	char *base;      
    	struct flags flag;
    	int fd;          
} FILE;
extern FILE _iob[OPEN_MAX];

FILE _iob[OPEN_MAX] = {
        { 0, (char *) 0, (char *) 0, {1, 0, 0, 0, 0}, 0 },
        { 0, (char *) 0, (char *) 0, {0, 1, 0, 0, 0}, 1 },
        { 0, (char *) 0, (char *) 0, {0, 1, 1, 0, 0}, 2 }
};

#define stdin   (&_iob[0])
#define stdout  (&_iob[1])
#define stderr  (&_iob[2])

struct field_flags {
    	unsigned int f_read    : 1;
    	unsigned int f_write   : 1;
    	unsigned int f_unbuf   : 1;
    	unsigned int f_eof     : 1;
    	unsigned int f_err     : 1;
};

int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

#define feof(p) ((p)->flag.f_eof == 1)
#define ferror(p) ((p)->flag.f_err == 1)
#define fileno(p) ((p)->fd)
#define getc(p) (--(p)->cnt >= 0 ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x, p) (--(p)->cnt >= 0 ? *(p)->ptr++ = (x) : _flushbuf((x), p))
#define getchar() getc(stdin)
#define putchar(x) putc((x), stdout)

FILE *fopen(char*, char*);
long lseek(int fd, long offset, int origin);

int main(int argc, char *argv[])
{
    	FILE *fp;
    	char mode = 'r';
    	int c;
    	if(argc == 2){
        	if((fp = fopen(argv[1], &mode)) == NULL){
            		fprintf(stderr, "can't open %s\n", argv[1]);
            		exit(1);
        	}
        	while((c = getc(fp)) != EOF) {
            		printf("%c", c);
        	}
    	}
    	return 0;
}

FILE *fopen(char *name, char *mode)
{
    	int fd;
    	FILE *fp;
    	if(*mode != 'r' && *mode != 'w' && *mode != 'a'){
        	return NULL;
    	}
    	for(fp = _iob; fp < _iob + OPEN_MAX; fp++){
        	if((fp->flag.f_read == 0 && fp->flag.f_write == 0)){
            		break;
        	}
    	}
    	if(fp >= _iob + OPEN_MAX){
        	return NULL;
    	}
    	if(*mode == 'w'){
        	fd = creat(name, PERMS);
    	} else if(*mode == 'a') {
        	if((fd = open(name, O_WRONLY, 0)) == -1) {
            		fd = creat(name, PERMS);
        	}
        	lseek(fd, 0L, 2);
    	} else {
        	fd = open(name, O_RDONLY, 0);
    	}
    	if(fd == -1){
        	return NULL;
    	}
    	fp->fd = fd;
    	fp->cnt = 0;
    	fp->base = NULL;
    	if(*mode == 'r') {
        	fp->flag.f_read = 1;
        	fp->flag.f_write = 0;
    	} else {
        	fp->flag.f_read = 0;
        	fp->flag.f_write = 1;
    	}
    	return fp;
}

int _fillbuf(FILE *fp)
{
    	int bufsize;
    	/*if(!fp->flag.f_read && fp->flag.f_eof && fp->flag.f_err) {
          	return EOF;
     	}*/
    	if(!fp->flag.f_read ==0 || fp->flag.f_eof == 1 || fp->flag.f_err == 1){
        	return EOF;
    	}
    	bufsize = fp->flag.f_unbuf ? 1 : BUFSIZ;
    	if(fp->base == NULL){
        	if((fp->base = (char *) malloc(bufsize)) == NULL) {
            		return EOF;
        	}
    	}
    	fp->ptr = fp->base;
    	fp->cnt = read(fp->fd, fp->ptr, bufsize);
    	if(--fp->cnt < 0){
        	if(fp->cnt == -1){
            		fp->flag.f_eof = 1;
       	 	} else {
            		fp->flag.f_err = 1;
        	}
        	fp->cnt = 0;
        	return EOF;
    	}
    	return (unsigned char) *fp->ptr++;
}

/*FILE _iob[OPEN_MAX] = {
    	{ 0, (char *) 0, (char *) 0, {1, 0, 0, 0, 0}, 0 },
    	{ 0, (char *) 0, (char *) 0, {0, 1, 0, 0, 0}, 1 },
    	{ 0, (char *) 0, (char *) 0, {0, 1, 1, 0, 0}, 2 }
};*/
