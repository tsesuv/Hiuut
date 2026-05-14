/* UnSynk XMC Assembler */
/* Build: 20260507XXXX */
/* Created by UnSynk, tsesuv notsel */

#include <stdio.h>

typedef enum {false, true} bool;

FILE *If;
FILE *Of;

bool help(void);
char upper(char c);

int main(int ac, char **av)
{	if(ac < 2) return help();

	return 0;
}

bool help(void)
{	return true;
}

char upper(char c)
{	if(('@' < c && c < '[') || ('`' < c && c < '{')) return c & 0x5F;

	return 0;
}
