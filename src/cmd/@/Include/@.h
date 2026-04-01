/* UnSynk @ Header */
/* Version: 1.0.0 Pre-Alpha */
/* Created by UnSynk, tsesuv notsel */

#ifndef AT_H
#define AT_H

////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

////////////////////////////////////////////////////////

typedef enum {false, true} bool;

////////////////////////////////////////////////////////

bool println(const char *s, ...)
{	va_list args;

	va_start(args, s);

	vprintf(s, args);
	printf("\n");

	va_end(args);

	return true;
}

bool cclne(const char *s, char *d)
{	if(!s || !d) return false;

	char *t = (char *)s;
	char *u = d;

	while(*u++ = *t++);
	*u = '\0';

	return true;
}

unsigned long int length(const char *s)
{	unsigned long int l = 0;
	char *t = (char *)s;

	while(*t++) l++;

	return l;
}

////////////////////////////////////////////////////////

#endif /* @.h */
