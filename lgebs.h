#ifndef LGEBS_H
#define	LGEBS_H
void     *lgebs(void *ptr, char *file, int line, int option, size_t size);
#define malloc(X)	lgebs(0, __FILE__, __LINE__, 1, X)
#define free(X)		lgebs(X, __FILE__, __LINE__, 2, 0)
#endif
