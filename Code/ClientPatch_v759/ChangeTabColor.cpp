#include "main.h"

int HKD_ChangeTabColor(char* msg)
{
	int color = 0xFFCCCCCC;

	if (!strcmp(msg, "Ajudante para iniciantes"))
		color = TNColor::NewBlue;
	else if (!strcmp(msg, "Torne-se Cidad�o"))
		color = TNColor::Default;
	else if (!strcmp(msg, "Ajudante M�gico"))
		color = TNColor::Default;
	else if (!strcmp(msg, "Abra sua Lojinha"))
		color = TNColor::Default;
	else if (!strcmp(msg, "Informa��es da Guild"))
		color = TNColor::NewYellow;
	return color;
}

