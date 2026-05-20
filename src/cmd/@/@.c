/* UnSynk @ Compiler */
/* Build: 20260519XXXX */
/* Created by UnSynk, tsesuv notsel */

#include "Include/@.h"
#include "Include/token.h"

FILE *infile;
FILE *outfile;

int main(int ac, char **av)
{	if(ac == 1)
	{	return 0;
	}

	uint lenth = catlen((byte **)av, ac);
	byte *ag = (byte *)malloc((lenth + ac) * sizeof(byte));
	bytecat(ag, (byte **)av, ac);

	printf("Length: %d\n", lenth);
	for(uint i = 0; i < lenth; i++) printf("%c ($%02X)\n", ag[i], ag[i]);

	uint place = 0;
	bit flag[1];
	set(&flag[0], 0); // Detect & geted /i: option

	// 引数チェック部分
	for(uint i = 0; i < lenth; i++)
	{	if(get(cmpe(ag + i, "/i:", 3)) && !get(flag[0]))
		{	place = i + 3;
			set(&flag[0], 1);
			printf("Detect /i: %d (p: %d, %c)\n", i, place, ag[place]);
		}
	}

	// ファイル名獲得
	if(get(flag[0]))
	{	uint i = lenn(ag + place);

		// 領域確保
		byte *inname = (byte *)malloc(i * sizeof(byte));
		// 名前を引数からコピー
		bytesete(inname, ag, 0, place, i, '_', "/\\:;");
		printf("fname: %s, name size: %d\n", inname, i);
		infile = fopen(inname, "rb"); // ファイルオープン

		if(!infile) // ファイルがなかった場合
		{	printf("[ E ] @: main: fopen: Can't open file: %s\n", inname);
		} else // ファイルが存在する場合
		{	printf("[ D ] @: main: Cat file: %s\n", inname);

			// ファイルサイズ獲得
			uint fsize = getfsize(infile) + 1;
			byte *text = (byte *)malloc(fsize * sizeof(byte));
			// ファイルの内容をコピー
			text[fread(text, 1, fsize - 1, infile)] = 0;
			fclose(infile);

			printf("READED TEXT (VALUE):\n%s\n", text);

			// Token関連のテスト
			Token t = tknnew();
			tknset(&t, TK_IDR, "MDL");
			printf("Token: %s(%s)\n", type2str(t.type), t.dat);
			tknset(&t, TK_NME, "case0");
			printf("Token: %s(%s)\n", type2str(t.type), t.dat);
			tknfree(&t);

			free(text);
		}

		free(inname);
	}

	free(ag);

	return 0;
}
