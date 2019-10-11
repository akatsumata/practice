#include "syscalls.h"
#include <fcntl.h>

#define PERMS 0666

int write(int fd, char *buf, int n);
FILE* fopen(char* name, char* mode);

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

long lseek(int fd, long offset, int origin);

FILE* fopen(char* name, char* mode)
{
    	int fd;
   	FILE *fp;
    
	if(*mode != 'r' && *mode != 'w' && *mode != 'a'){
        	return NULL;
    	}
    	for(fp = _iob; fp < _iob + OPEN_MAX; fp++){
        	if((fp->flag & (_READ | _WRITE)) == 0){
            		break;
 		}
    	}
    	if(fp >= _iob + OPEN_MAX){
        	return NULL;
    	}
    	if((*mode == 'w')){
        	fd = creat(name, PERMS);
    	} else if((*mode == 'a')){
        	if((fd = open(name, O_WRONLY, 0)) == -1){
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

void *malloc (long int size);
int read(int fd, char *buf, int n);

int _fillbuf(FILE *fp)
{
    	int bufsize;
    	if((fp->flag & (_READ | _EOF | _ERR)) != _READ){
        	return EOF;
    	}
    	bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    	if(fp->base == NULL){
        	if((fp->base = (char*) malloc(bufsize)) == NULL){
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
