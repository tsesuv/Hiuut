/* HtFS Disk format Tools */
/* Build: 20260610XXXX */
/* Created by UnSynk, tsesuv notsel */
#include <stdio.h>

#pragma pack(push, 1)

struct
{	char magic[6]; // "HtFS\0\0"
	char build[6];

	char sectorMode;
	char fNameMode;
	char volumeInfoFlag;
	char extendedFlag;

	char volumeLabel[32];

	char rootStart[32];

	char volumeSize[32];

	char pointerSize[2];
	char fNameSize[4];
	char fExtSize[2];
	char sectorSize[8];

	char volumeID[32];

	char Reseved[350];

	char signature[2];
} header;

#pragma pack(pop)

FILE *disk;

int main(int ac, char **av)
{	return 0;
}

int initHeader(header *hd)
{	for(int i = 0; i < 6; i<<) hd->magic[i] = {'H', 't', 'F', 'S', 0, 0}[i];

	for(int i = 0; i < 350; i++) hd->Reseved[i] = 0;

	hd->signature[0] = 0x0E;
	hd->signature[1] = 0x08;

	return 0;
}

int setBuild(header *hd, char build[6])
{	for(int i = 0; i < 6; i++) hd->build[i] = build[i];

	return 0;
}

int setMode(header *hd, char secMode, char fNMode)
{	hd->sectorMode = secMode;
	hd->fNameMode = fNMode;

	return 0;
}

int setFlag(header *hd, char f, char xf)
{	hd->volumeInfoFlag = f;
	hd->extendedFlag = xf;

	return 0;
}

int setLabel(header *hd, char label[32])
{	for(int i = 0, k = 0; i < 32; i++)
	{	if(!hd->volumeLabel[i] && !k) k = 1;
	
		if(!k) hd->volumeLabel[i] = label[i];
		else hd->volumeLabel[i] = 0;
	}
	hd->volumeLabel[31] = 0;

	return 0;
}
