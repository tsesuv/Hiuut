/* bked - Book Editor */
/* Build: 20260607XXXX */
/* Created by UnSynk, tsesuv notsel */

#include <stdio.h>

/*

bookSelf\machine\UnSynk\Hiuut Build = 20260607XXXX

v

book    = machine
page    = "UnSynk\Hiuut"
section = "Build"
article = #20260607XXXX

book    = machine
page    = "UnSynk\"
section = ""
article = ""
の中の
book    = machine
page    = "Hiuut"
section = "Build"
article = #20260607XXXX
って感じの実装にしたいよなぁ...

*/

typedef struct
{	char *page;
	char *section;
	char *article;
} book;

FILE *bookFile;

int main(int ac, char **av)
{	return 0;
}
