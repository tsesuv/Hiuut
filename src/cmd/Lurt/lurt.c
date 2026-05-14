/* Lurt - Line editor, text editor */
/* Build: 20260505XXXX */
/* Created by UnSynk, tsesuv notsel */

#include <stdio.h>

typedef struct sdt
{	char *ln;
	struct sdt *pr;
	struct sdt *nx;
};

typedef unsigned char uchr;

FILE *fp;
uchr FLAG = 0; // X, X, X, X, X, X, X, Editing anon file

int main(int ac, char **av)
{	if(ac < 2) FLAG |= 0x1;

	return 0;
}
