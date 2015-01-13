#ifndef ISTRING_newH
#define ISTRING_newH

typedef struct _istring {
size_t length;
char string[];
} _istring, *Istring;

#define START(p) ((Istring) (p - sizeof(size_t)))
#define STRING(p) ((char*) (p + sizeof(size_t)))
#endif
