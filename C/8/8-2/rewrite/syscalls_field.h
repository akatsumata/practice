#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20
 
struct flags {
        unsigned int _read    : 1;
        unsigned int _write   : 1;
        unsigned int _unbuf   : 1;
        unsigned int _eor     : 1;
        unsigned int _err     : 1;
};
 
typedef struct _iobuf{
        int cnt;
        char *ptr;
        char *base;
        struct flags flag;
        int fd;
} FILE;
 
extern FILE _iob[OPEN_MAX];
 
#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])
 
int _fillbuf(FILE *);
int _flushbuf(int, FILE *);
 
#define feof(p)     (((p)->flag & _eof) != 0)
#define ferror(p)   (((p)->flag & _err) != 0)
#define fileno(p)   ((p)->fd)
#define getc(p)     (--(p)->cnt >= 0 ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x,p)   (--(p)->cnt >= 0 ?  *(p)->ptr++ = (x) : _flushbuf((x), p))
#define getchar()   getc(stdin)
#define putchar(x)  putc((x), stdout)
 
FILE _iob[OPEN_MAX] = {
        { 0, (char *) 0, (char *) 0, .flag._read = 1, .fd = 0 },
        { 0, (char *) 0, (char *) 0, .flag._write = 1, .fd = 1 },
        { 0, (char *) 0, (char *) 0,
            .flag._write = 1, .flag._unbuf = 1, .fd = 2 }
};
FILE *fopen(char*, char*);

