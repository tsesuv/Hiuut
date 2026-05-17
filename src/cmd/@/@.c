/* UnSynk @ Compiler */
/* Build: 20260518XXXX */
/* Created by UnSynk, tsesuv notsel */

#include <stdio.h>
#include <stdlib.h>
#include "Include/token.h"

FILE *infile;
FILE *outfile;

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

	byte arg_in_opt[] = "/i";
	byte arg_in_opt2[] = "/i:";

	uint k = 0;
	uint place = 0;
	bit flag;
	flag.f = 0;
	for(uint i = 0; i < l; i++)
	{	if(cmp(ag[i], arg_in_opt[k]).f || cmp(ag[i], arg_in_opt2[k]).f)
		{	k++;
			if(cmp(ag[i], 0).f || cmp(ag[i], ':').f)
			{	flag.f = 1;
				place = ++i;
				printf("Detect /i: %d\n", i);
				break;
			} else flag.f = 0;
		} else
		{	k = 0;
			flag.f = 0;
		}
	}

	if(flag.f)
	{	uint i = place;

		while(ag[i++]);

		byte *inname = (byte *)malloc((i - place) * sizeof(byte));

		for(uint k = place; k < i; k++)
		{	inname[k - place] = ag[k];
		}

		printf("fname: %s, name size: %d\n", inname, i - place);

		infile = fopen(inname, "r");

		if(!infile)
		{	printf("[ E ] @: main: fopen: Can't open file: %s\n", inname);
		} else
		{	byte c = 0;
			byte r = 255;

			printf("[ D ] @: main: Cat file: %s\n", inname);

			while(r)
			{	r = fread(&c, 1, 1, infile);
				putchar(c);
			} printf("\n");

			fclose(infile);
		}

		free(inname);
	}

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
