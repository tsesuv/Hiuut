/* UnSynk @ Compiler */
/* Build: 20260505XXXX */
/* Created by UnSynk, tsesuv notsel */

#include <stdio.h>
#include "str.h"

FILE *infile;

bool isSpc(char c);

int main(int ac, char **av)
{	int i = 0;
	str s = strset("Hello, world!");
	txoutln(s);

	return 0;
}

bool isSpc(char c)
{	return (c == ' ');
}
