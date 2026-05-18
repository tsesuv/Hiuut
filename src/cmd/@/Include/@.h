/* UnSynk @ Header */
/* Build: 20260518XXXX */
/* Created by UnSynk, tsesuv notsel */

#ifndef AT_H
#define AT_H

////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////

typedef unsigned char byte;
typedef unsigned int uint;

typedef struct
{	byte f:1;
} bit;

////////////////////////////////////////////////////////

uint len(byte *p);
bit cmp(byte a, byte b);

////////////////////////////////////////////////////////

uint catlen(byte **s, uint cnt)
{	uint t = 0;
	for(uint k = 0; k < cnt; k++)
	{	for(uint i = 0; i < len(s[k]); i++) t++;
		t++;
	}

	return t;
}

uint bytecat(byte *t, byte **s, uint cnt)
{	uint n = 0;

	for(uint k = 0; k < cnt; k++)
	{	for(uint i = 0; i < len(s[k]); i++)
		{	t[n++] = *(s[k] + i);
		}
		s[n++] = 0;
	}

	return n;
}

uint byteset(byte *dis, byte *src, uint start, uint len)
{	for(uint i = 0; i < len; i++)
	{	dis[i] = src[i + start];

		if(dis[i] != src[i + start]) return i;
	}

	return len;
}

uint getfsize(FILE *fp)
{	uint fsize = 0;

	fseek(fp, 0, SEEK_END);
	fsize = ftell(fp);
	rewind(fp);

	return fsize;
}

uint len(byte *p)
{	byte *t = p;

	while(*p++);

	return p - t - 1;
}

bit cmp(byte a, byte b)
{	bit x;

	x.f = (a == b);

	return x;
}

byte get(bit b)
{	return b.f;
}

byte set(bit *b, byte v)
{	return b->f = v;
}

////////////////////////////////////////////////////////

#endif /* @.h */
