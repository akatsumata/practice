#include <fcntl.h>
#include "syscalls_field.h"

#define PERMS 0666

long write(int fd, char *, int n);

int main(int argc, char *argv[])
{
        FILE *fp;
        char c;
 
        if((fp = fopen("kr8_2.txt", "r")) == NULL){
                return 1;
        } else {
                while((c = getc(fp)) != EOF){
                        write(1, &c, 1);
                }
        }
        return 0;
}

long lseek(int fd, long int offset, int origin);

FILE *fopen(char *name, char *mode)
{
    	int fd;
    	FILE *fp;
    
	if(*mode != 'r' && *mode != 'w' && *mode != 'a'){
        	return NULL;
    	}
    	for(fp = _iob; fp < _iob + OPEN_MAX; fp++){
        	if((fp->flag._read == 0 && fp->flag._write == 0)){
            		break;
        	}
    	}
    	if(fp >= _iob + OPEN_MAX) {
        	return NULL;
    	}
    	if(*mode == 'w'){
        	fd = creat(name, PERMS);
    	} else if (*mode == 'a') {
        	if((fd = open(name, O_WRONLY, 0)) == -1){
            		fd = creat(name, PERMS);
        	}
        	lseek(fd, 0L, 2);
    	} else {
        	fd = open(name, O_RDONLY, 0);
    	}
    	if(fd == -1) {
        	return NULL;
    	}
    	fp->fd = fd;
    	fp->cnt = 0;
    	fp->base = NULL;
    	fp->flag._unbuf = 0;
    	fp->flag._eor = 0;
    	fp->flag._err = 0;
    	if(*mode == 'r') {
        	fp->flag._read = 1;
        	fp->flag._write = 0;
    	} else {
        	fp->flag._read = 0;
        	fp->flag._write = 1;
    	}
    	return fp;
}

void *malloc (long int size);
long read (int fd, char *buf, int n);

int _fillbuf(FILE *fp)
{
    	int bufsize;
     
	if(fp->flag._read == 0 || fp->flag._eor == 1 || fp->flag._err == 1){
        	return EOF;
    	}
    	bufsize = fp->flag._unbuf ? 1 : BUFSIZ;
    	if(fp->base == NULL) {
        	if((fp->base = (char *) malloc(bufsize)) == NULL) {
            		return EOF;
        	}
    	}
    	fp->ptr = fp->base;
    	fp->cnt = read(fp->fd, fp->ptr, bufsize);
    	if(--fp->cnt < 0) {
        	if(fp->cnt == -1){
            		fp->flag._eor = 1;
        	} else {
            		fp->flag._err = 1;
        	}
        	fp->cnt = 0;
        	return EOF;
    	}
    	return (unsigned char) *fp->ptr++;
}
