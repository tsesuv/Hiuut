/* UnSynk @ Compiler */
/* Version: 1.0.3 Pre-Alpha */
/* Created by UnSynk, tsesuv notsel */

#include "Include/@.h"
#include "Include/token.h"

////////////////////////////////////////////////////////

int main(void)
{	Token t = tknset(TK_STR, "Token2");

	println("Token: %d (type), %s", t.type, t.dat);

	tkList *L = tklnew(NULL);
	tklset(L, t);
	tklset(L, tknset(TK_STR, "String"));

	L = L->head;
	println("Next: %s", L->next->token.dat);
	println("Next: %s", L->next->next->token.dat);
	println("");
	L = L->next;
	println("Now: %s", L->token.dat);
	println("Head->end: %s", L->head->end->token.dat);

	tklfree(L);

	return 0;
}

////////////////////////////////////////////////////////

bool version(void)
{	println("      UnSynk @ Compiler");
	println("------------------------------");
	println(" Version: 1.0.3 Pre-Alpha");
	println(" Build  : 2026021303");
	println("------------------------------");
	println("enter `@ /?' you get more helps.");

	return true;
}

bool help(void)
{	println("      UnSynk @ Compiler");
	println("------------------------------");
	println("Usage:");
	println("	@ </src:[\\file\\path.@]> </out:[\\file\\path]> </detail:{true|false}>");
	println("------------------------------");
	println("Options:");
	println("	/src		:	Configuration source file path.");
	println("	/?			:	Print this help message.");
	println("	/help		:	Print this help message.");
	println("	/h			:	Print this help message.");
	println("	/v			:	Print software informations.");
	println("	/version	:	Print software informations.");

	return true;
}

////////////////////////////////////////////////////////
