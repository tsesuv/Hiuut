/* UnSynk Processing system Header */
/* Version: 1.0.4 Pre-Alpha */
/* Created by UnSynk, tsesuv notsel */

#ifndef TOKEN_H
#define TOKEN_H

////////////////////////////////////////////////////////

#include "@.h"

////////////////////////////////////////////////////////

typedef enum
{	TK_OP,
	TK_NEWL,
	TK_NUM,
	TK_STR,
	TK_IDEN,
	TK_KEYW,
	TK_LPAREN,
	TK_RPAREN,
	TK_LBRACKET,
	TK_RBRACKET,
	TK_COMMA,
	TK_COLON,
	TK_DOT,
	TK_AT,
	TK_VOID,
	TK_EOF
} tkType;

typedef struct
{	tkType type;
	char *dat;
	unsigned long int line;
} Token;

typedef struct tkList
{	struct tkList *head;
	Token token;
	unsigned long int tkCnt;
	struct tkList *next;
	struct tkList *end;
} tkList;

////////////////////////////////////////////////////////

Token tknnew(void);
Token tknclne(Token *t);
Token tknset(const tkType type, const char *dat);

tkList *tklnew(tkList *head);
bool tklset(tkList *L, const Token t);

bool tknfree(Token *t);
bool tklfree(tkList *L);

tkList *tokenalizer(const char *s);
tkList *parser(tkList *L);

////////////////////////////////////////////////////////

Token tknnew(void)
{	Token t;

	t.type = TK_VOID;
	t.dat = "";
	t.line = 0;

	return t;
}

Token tknclne(Token *t)
{	Token v = tknnew();

	cclne(v.dat, t->dat);
	v.line = t->line;

	return v;
}

Token tknset(const tkType type, const char *dat)
{	Token t;

	t.type = type;
	t.dat = (char *)dat;
	t.line = 0;

	return t;
}

tkList *tklnew(tkList *head)
{	tkList *L = (tkList *)malloc(sizeof(tkList));

	L->head = head == NULL ? L : head; // 仮にここで常にNULLにしてるとcaptもNULLになっちゃう問題があるからこうしてる
	L->token.type = TK_VOID;
	L->token.dat = "";
	L->token.line = 0;
	L->tkCnt = 0;
	L->next = NULL;
	L->end = L;

	return L;
}

bool tklset(tkList *L, const Token t)
{	tkList *node = tklnew(L->head);

	node->token.type = t.type;
	node->token.dat = t.dat;
	node->token.line = t.line;
	node->tkCnt = ++L->head->tkCnt; // tkCntはどうやらトークンのインデックスを表すようになったようです。但しcapt、お前はただのカウンタとして働け
	node->next = NULL;
	node->end = node;

	L->head->end->next = node;
	L->head->end = node;

	return true;
}

bool tknfree(Token *t)
{	t->type = TK_VOID;
	t->line = 0;

	return true;
}

bool tklfree(tkList *L)
{	tkList *tmp;
	L = L->head;
	while(L != NULL)
	{	tmp = L->next;

		tknfree(&L->token);
		L->tkCnt = 0;
		L->head = NULL;
		L->next = NULL;
		L->end = NULL;

		free(L);

		L = tmp;
	}

	return true;
}

tkList *tokenalizer(const char *s)
{	tkList *L = tklnew(NULL);

	char *tmp = (char *)malloc(sizeof(char));
	unsigned long int k = 0;

	unsigned long int memsize = 1;

	for(unsigned long int i = 0; i < length(s); i++)
	{	if(memsize <= k)
		{	memsize *= 2;
			tmp = (char *)realloc(tmp, memsize * sizeof(char));
		}

		if(s[i] == '+')
		{	tklset(L, tknset(TK_NUM, tmp));
			free(tmp);
			tmp = (char *)malloc(sizeof(char));
			k = 0;
		}

		tmp[k] = s[i];
		k++;
	}

	free(tmp);

	return L;
}

////////////////////////////////////////////////////////

#endif /* token.h */
