#include "main.h"

bool NewItensDay(INT32 Item)
{
	switch (Item)
	{

	case 5682:
		return TRUE; 
	}

	return FALSE;
}

void FormataValidadeEsferas(char* msg, STRUCT_ITEM* item)
{
	int dia, ano, mes;
	memset(&dia, 0x0, sizeof(int));
	memset(&ano, 0x0, sizeof(int));
	memset(&mes, 0x0, sizeof(int));

	for (int i = 0; i < 3; ++i)
	{ 
		switch (item->stEffect[i].cEffect)
		{
		case 110:
			dia = item->stEffect[i].cValue;
			break;
		case 109:
			ano = item->stEffect[i].cValue;
			break;
		case 106:
			mes = item->stEffect[i].cValue;
			break;
		}
	}

	char msgtes[100];


	if (dia)
		sprintf(msg, "V�lido por %02d dia(s)", dia);
	else
		sprintf(msg, "V�lido at�: [%02d:%02d:20%02d]", dia, mes, ano);

	if (mes)
		sprintf(msg, "V�lido at�: [%02d:%02d:20%02d]", dia, mes, ano);
	else
		sprintf(msg, "V�lido at�: [%02d:%02d:20%02d]", dia, mes, ano);

	if (ano)
		sprintf(msg, "V�lido at�: [%02d:%02d:20%02d]", dia, mes, ano);
	else
		sprintf(msg, "Aguardando ativa��o.");
}

void FormataValidadeFada(char* msg, STRUCT_ITEM* item)
{
	int dia, hora, min;
	memset(&dia, 0x0, sizeof(int));
	memset(&hora, 0x0, sizeof(int));
	memset(&min, 0x0, sizeof(int));

	for (int i = 0; i < 3; ++i)
	{
		//ta errado aq .. nao entra na condi��o?
		switch (item->stEffect[i].cEffect)
		{
		case 110:
			dia = item->stEffect[i].cValue;
			break;
		case 107:
			hora = item->stEffect[i].cValue;
			break;
		case 108:
			min = item->stEffect[i].cValue;
			break;
		}
	}
	if (dia && !min && !hora)
		sprintf(msg, "V�lido por %d dia(s)", dia);

	else
		sprintf(msg, "V�lido at�: %d / %0d / %s", dia, hora, min);

}

void FormataValidadeTraje(char* msg, STRUCT_ITEM* item)
{
	int dia, ano, mes;
	memset(&dia, 0x0, sizeof(int));
	memset(&ano, 0x0, sizeof(int));
	memset(&mes, 0x0, sizeof(int));

	for (int i = 0; i < 3; ++i)
	{
		//ta errado aq .. nao entra na condi��o?
		switch (item->stEffect[i].cEffect)
		{
		case 110:
			dia = item->stEffect[i].cValue;
			break;
		case 109:
			ano = item->stEffect[i].cValue;
			break;
		case 106:
			mes = item->stEffect[i].cValue;
			break;
		}
	}

	if (dia)
		sprintf(msg, "V�lido por %02d dia(s)", dia);
	else
		sprintf(msg, "V�lido at�: [%02d:%02d:%02d]", dia, mes, ano);

	if (mes)
		sprintf(msg, "V�lido at�: [%02d:%02d:%02d]", dia, mes, ano);
	else
		sprintf(msg, "V�lido at�: [%02d:%02d:%02d]", dia, mes, ano);

	if (ano)
		sprintf(msg, "V�lido at�: [%02d:%02d:%02d]", dia, mes, ano);
	else
		sprintf(msg, "Aguardando ativa��o.");

	/*if (dia && !mes && !ano)
		sprintf(msg, "V�lido por %02d dia(s)", dia);

	else
		sprintf(msg, "V�lido at�: [%02d:%02d:%02d]", dia, mes, ano);*/
}