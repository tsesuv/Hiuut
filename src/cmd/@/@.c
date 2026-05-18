/* UnSynk @ Compiler */
/* Build: 20260518XXXX */
/* Created by UnSynk, tsesuv notsel */

#include "Include/@.h"
#include "Include/token.h"

FILE *infile;
FILE *outfile;

int main(int ac, char **av)
{	if(ac == 1)
	{	return 0;
	}

	uint l = catlen((byte **)av, ac);
	byte *ag = (byte *)malloc((l + ac) * sizeof(byte));
	bytecat(ag, (byte **)av, ac);

	printf("Length: %d\n", l);
	for(uint i = 0; i < l; i++) printf("%c ($%02X)\n", ag[i], ag[i]);

	byte arg_in_opt[] = "/i";
	byte arg_in_opt2[] = "/i:";
	uint place = 0;
	bit flag;
	set(&flag, 0);

	// 引数チェック部分
	for(uint i = 0, k = 0; i < l; i++)
	{	if(get(cmp(ag[i], arg_in_opt[k])) || get(cmp(ag[i], arg_in_opt2[k])))
		{	k++;
			if(get(cmp(ag[i], 0)) || get(cmp(ag[i], ':')))
			{	set(&flag, 1);
				place = ++i;
				printf("Detect /i: %d (p: %d)\n", i, place);
				break;
			} else set(&flag, 0);
		} else
		{	k = 0;
			set(&flag, 0);
		}
	} // 引数

	// ファイル名獲得
	if(get(flag))
	{	uint i = place;

		// ファイル名長さ獲得
		while(ag[i++]);

		// 領域確保
		byte *inname = (byte *)malloc((i - place) * sizeof(byte));
		// 名前をフラット引数からコピー
		byteset(inname, ag, place, i);
		printf("fname: %s, name size: %d\n", inname, i - place);
		infile = fopen(inname, "rb");

		if(!infile)
		{	printf("[ E ] @: main: fopen: Can't open file: %s\n", inname);
		} else // ファイルが存在する場合
		{	printf("[ D ] @: main: Cat file: %s\n", inname);

			uint fsize = getfsize(infile) + 1;
			byte *text = (byte *)malloc(fsize * sizeof(byte));
			text[fread(text, 1, fsize - 1, infile)] = 0;
			

			printf("READED TEXT (VALUE):\n%s\n", text);

			Token t = tknnew();
			tknset(&t, TK_IDR, "MDL");
			printf("Token: %s(%s)\n", type2str(t.type), t.dat);
			tknset(&t, TK_ENT, "");
			printf("Token: %s(%s)\n", type2str(t.type), t.dat);
			tknfree(&t);

			free(text);
			fclose(infile);
		}

		free(inname);
	}

	free(ag);

	return 0;
}
