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

uint catlen(byte **s, uint cnt);
uint bytecat(byte *dis, byte **src, uint cnt);
uint byteset(byte *dis, byte *src, uint to, uint from, uint len);
uint bytefill(byte *dis, byte fdat, uint start, uint len);
uint getfsize(FILE *fp);
uint len(byte *p);
uint lenn(byte *p);
bit cmp(byte a, byte b);
byte get(bit b);
byte set(bit *b, byte v);

////////////////////////////////////////////////////////

uint catlen(byte **s, uint cnt)
{	uint t = 0;

	for(uint i = 0; i < cnt; i++) t += lenn(s[i]);

	return t;
}

uint bytecat(byte *t, byte **s, uint cnt)
{	uint n = 0;

	for(uint k = 0; k < cnt; k++)
	{	for(uint i = 0; i < lenn(s[k]); i++) t[n++] = *(s[k] + i);
	}

	return n;
}

uint byteset(byte *dis, byte *src, uint to, uint from, uint len)
{	for(uint i = from; i < from + len; i++)
	{	dis[to] = src[i];

		if(dis[to] != src[i]) return to;

		to++;
	}

	return len;
}

uint bytefill(byte *dis, byte fdat, uint start, uint len)
{	for(uint i = start; i < len; i++)
	{	dis[i] = fdat;

		if(dis[i] != fdat) return i - len;
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

uint lenn(byte *p)
{	return len(p) + 1;
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
