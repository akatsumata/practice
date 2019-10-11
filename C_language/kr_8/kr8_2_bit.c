#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
    	int flag;
    	int fd;          
} l_FILE;
extern l_FILE _iob[OPEN_MAX];

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

enum _flags {
    	_READ = 01,
   	_WRITE = 02,
    	_UNBUF = 04,
    	_EOR = 010,
    	_ERR = 020,
};

int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

#define feof(p)   (((p)->flag & _EOF) != 0)
#define ferror(p) (((p)->flag & _ERR) != 0)
#define fileno(p) ((p)->fd)
#define getc(p)   (--(p)->cnt >= 0 \
	 ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x, p)  (--(p)->cnt >= 0 \
	 ? *(p)->ptr++ = (x) : _flushbuf((x), p))
#define getchar()   getc(stdin)
#define putchar(x)  putc((x), stdout)

l_FILE *fopen(char*, char*);

int main(int argc, char *argv[])
{
    	l_FILE *fp;
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
        	fclose(fp);
    	}
    	return 0;
}

/*int get(int fd, long pos, char *buf, int n);

int get(int fd, long pos, char *buf, int n)
{
	if(lseek(fd, pos, 0) >= 0){
		return read(fd, but, n);
	} else {
		return -1;
	}
}*/


l_FILE *l_fopen(char *name, char *mode)
{
    	int fd;
    	l_FILE *fp;
    
	if(*mode != 'r' && *mode != 'w' && *mode != 'a'){
        	return NULL;
    	}
    	for(fp = _iob; fp < _iob + OPEN_MAX; fp++){
        	if(fp->flag & (_READ | _WRITE) == 0){
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
    	fp->flag = (*mode == 'r') ? _READ : _WRITE;
    	return fp;
}

int _fillbuf(FILE *fp)
{
    	int bufsize;
   
 	if((fp->flag&(_READ|_EOR|_ERR)) != _READ){
        	return EOF;
    	}
    	bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    	if(fp->base == NULL){
        	if((fp->base = (char *) malloc(bufsize)) == NULL) {
            		return EOF;
        	}
    	}
    	fp->ptr = fp->base;
    	fp->cnt = read(fp->fd, fp->ptr, bufsize);
    	if(--fp->cnt < 0){
        	if(fp->cnt == -1){
            		fp->flag |= _EOF;
        	} else {
            		fp->flag |= _ERR;
        	}
        	fp->cnt = 0;
        	return EOF;
    	}
    	return (unsigned char) *fp->ptr++;
}

l_FILE _iob[OPEN_MAX] = {
    	{ 0, (char *) 0, (char *) 0, _READ, 0 },
    	{ 0, (char *) 0, (char *) 0, _WRITE, 1 },
    	{ 0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2 }
};
