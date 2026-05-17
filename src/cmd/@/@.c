/* UnSynk @ Compiler */
/* Build: 20260517XXXX */
/* Created by UnSynk, tsesuv notsel */

#include <stdio.h>
#include <stdlib.h>
#include "Include/token.h"

FILE *infile;

bit cmp(byte a, byte b);
uint len(byte *p);

int main(int ac, char **av)
{	if(ac == 1)
	{	return 0;
	}

	uint l = 0;
	for(uint k = 0; k < ac; k++)
	{	for(uint i = 0; i < len(av[k]); i++) l++;
	}

	byte *ag = (byte *)malloc((l + ac) * sizeof(byte));

	l = 0;
	for(uint k = 0; k < ac; k++)
	{	for(uint i = 0; i < len(av[k]); i++)
		{	ag[l++] = *(av[k] + i);
		}
		ag[l++] = 0;
	}

	printf("Length: %d\n", l);

	for(uint i = 0; i < l; i++) printf("%c ($%02X)\n", ag[i], ag[i]);

	free(ag);

	return 0;
}

bit cmp(byte a, byte b)
{	bit x;

	x.f = (a == b);

	return x;
}

uint len(byte *p)
{	byte *t = p;

	while(*p++);

	return p - t - 1;
}
