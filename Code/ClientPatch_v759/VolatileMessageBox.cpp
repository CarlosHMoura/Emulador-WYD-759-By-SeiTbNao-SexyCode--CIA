#include "main.h"
// e0 sd2 12* n da esse err6
bool SetVolatileMessageBoxText(int itemID, char* text)
{
	if (itemID == 3314) //Frango Assado
	{
		sprintf(text, "Deseja comer esse delicioso Frango Assado?");
		return true;
	}
	if (itemID == 3361) //Poção Sephira (7dias)
	{
		sprintf(text, "Deseja ativar a Poção Sephira (7d)?");
		return true;
	}
	if (itemID == 3362) //Poção Sephira (15dias)
	{
		sprintf(text, "Deseja ativar a Poção Sephira (15d)?");
		return true;
	}
	if (itemID == 3363) //Poção Sephira (30dias)
	{
		sprintf(text, "Deseja ativar a Poção Sephira (30d)?");
		return true;
	}
	if (itemID == 3364) //Poção de Saúde (7dias)
	{
		sprintf(text, "Deseja ativar a Poção de Saúde (7d)?");
		return true;
	}
	if (itemID == 3365) //Poção de Saúde (15dias)
	{
		sprintf(text, "Deseja ativar a Poção de Saúde (15d)?");
		return true;
	}
	if (itemID == 3366) //Poção de Saúde (30dias)
	{
		sprintf(text, "Deseja ativar a Poção de Saúde (30d)?");
		return true;
	}
	if (itemID == 3379) //Poção Divina (7dias)
	{
		sprintf(text, "Deseja ativar a Poção Divina (7d)?");
		return true;
	}
	if (itemID == 3380) //Poção Divina (15dias)
	{
		sprintf(text, "Deseja ativar a Poção Divina (15d)?");
		return true;
	}
	if (itemID == 3381) //Poção Divina (30dias)
	{
		sprintf(text, "Deseja ativar a Poção Divina (30d)?");
		return true;
	}
	if (itemID == 4140) //Baú de XP
	{
		sprintf(text, "Deseja ativar o Baú de Experiência?");
		return true;
	}
	if (itemID == 4144) //Baú de XP
	{
		sprintf(text, "Deseja ativar o Baú de Experiência?");
		return true;
	}
	if (itemID == 3393) //Barra de Donate (1)
	{
		sprintf(text, "Deseja ativar Barra de Donate (1 Donate)?");
		return true;
	}
	if (itemID == 3394) //Barra de Donate (10)
	{
		sprintf(text, "Deseja ativar Barra de Donate (10 Donate)?");
		return true;
	}
	if (itemID == 3395) //Barra de Donate (25)
	{
		sprintf(text, "Deseja ativar Barra de Donate (25 Donate)?");
		return true;
	}
	if (itemID == 3396) //Barra de Donate (50)
	{
		sprintf(text, "Deseja ativar Barra de Donate (50 Donate)?");
		return true;
	}
	if (itemID == 4111) //Convite_para_Lanhouse(N)
	{
		sprintf(text, "Deseja ativar Convite para Lanhouse(N)?");
		return true;
	}
	if (itemID == 4112) //Convite_para_Lanhouse(M)
	{
		sprintf(text, "Deseja ativar Convite para Lanhouse(M)?");
		return true;
	}
	if (itemID == 4113) //Convite_para_Lanhouse(A)
	{
		sprintf(text, "Deseja ativar Convite para Lanhouse(A)?");
		return true;
	}
	if (itemID == 4010) //Barra de 100kk
	{
		sprintf(text, "Deseja utilizar Barra de 100kk?");
		return true;
	}
	if (itemID == 4011) //Barra bi
	{
		sprintf(text, "Deseja utilizar Barra de 1kkk?");
		return true;
	}
	if (itemID == 4026) //Convite_para_Lanhouse(M)
	{
		sprintf(text, "Deseja utilizar Barra de 1kk?");
		return true;
	}
	if (itemID == 4028) //Convite_para_Lanhouse(A)
	{
		sprintf(text, "Deseja utilizar Barra de 5kk?");
		return true;
	}
	if (itemID == 4029) //Convite_para_Lanhouse(A)
	{
		sprintf(text, "Deseja utilizar Barra de 10kk?");
		return true;
	}
	if (itemID == 4027) //Convite_para_Lanhouse(A)
	{
		sprintf(text, "Deseja utilizar Barra de 50kk?");
		return true;
	}

	return false;
}

int AddVolatileMessageItem(int itemID)
{
	switch (itemID)
	{
	case 3314:
		return 1;
	}
	return 0;
}