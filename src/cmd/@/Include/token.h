/* UnSynk @ language Token header */
/* Build: 20260519XXXX */
/* Created by UnSynk, tsesuv notsel */

#ifndef TOKEN_H
#define TOKEN_H

////////////////////////////////////////////////////////

#include "@.h"

////////////////////////////////////////////////////////

typedef enum
{	TK_VOID,
	TK_ENT,
	TK_IDR,
	TK_NME,
	TK_SYM,
	TK_STR,
	TK_NUM,
	TK_EOF
} tkType;

typedef struct
{	tkType type;
	byte *dat;
} Token;

////////////////////////////////////////////////////////

Token tknnew(void);
bit tknset(Token *t, tkType type, byte *d);
uint tknsplit(Token *t, byte *txt, uint cnt);
bit tknfree(Token *t);
byte *type2str(tkType type);

////////////////////////////////////////////////////////

Token tknnew(void)
{	Token t;

	t.type = TK_VOID;
	t.dat = (byte *)malloc(sizeof(byte));

	return t;
}

bit tknset(Token *t, tkType type, byte *d)
{	bit x;

	t->type = type;
	t->dat = (byte *)realloc(t->dat, lenn(d) * sizeof(byte));

	bytefill(t->dat, 0, 0, lenn(t->dat));
	byteset(t->dat, d, 0, 0, lenn(d));

	x.f = 1;

	return x;
}

uint tknsplit(Token *t, byte *txt, uint cnt)
{	uint i = 0;
	uint k = 0;
	uint msize = 1;
	byte *chunk = (byte *)malloc(sizeof(byte));

	while(1)
	{	if(msize < i)
		{	msize *= 2;
			chunk = (byte *)realloc(chunk, msize * sizeof(byte));
		}

		chunk[i] = *txt;

		if(get(cmp(*txt, '\t'))) *txt = ' ';

		if(get(cmp(*txt, ' ')))
		{	chunk[i] = 0;
			if(k == cnt)
			{	free(t->dat);
				t->dat = chunk;

				break;
			}

			msize = 1 + (i = 0);

			chunk = (byte *)realloc(chunk, sizeof(byte));

			k++;
		} else i++;

		txt++;

		if(!txt)
		{	chunk[i - 1] = 0;

			free(t->dat);
			t->dat = chunk;

			break;
		}
	}

	return 0;
}

bit tknfree(Token *t)
{	bit x;

	t->type = TK_VOID;
	free(t->dat);

	x.f = 1;

	return x;
}

byte *type2str(tkType type)
{	if(type == TK_VOID) return "TK_VOID";
	else if(type == TK_ENT) return "TK_ENT";
	else if(type == TK_IDR) return "TK_IDR";
	else if(type == TK_NME) return "TK_NME";
	else if(type == TK_SYM) return "TK_SYM";
	else if(type == TK_STR) return "TK_STR";
	else if(type == TK_NUM) return "TK_NUM";
	else if(type == TK_EOF) return "TK_EOF";

	return NULL;
}

////////////////////////////////////////////////////////

#endif /* token.h */
