/* UnSynk @ language Token header */
/* Build: 20260517XXXX */
/* Created by UnSynk, tsesuv notsel */

#ifndef TOKEN_H
#define TOKEN_H

typedef unsigned char byte;
typedef unsigned int uint;

typedef struct
{	byte f:1;
} bit;

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

#endif /* token.h */
