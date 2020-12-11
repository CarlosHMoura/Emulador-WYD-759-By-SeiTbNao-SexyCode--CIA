#include "main.h"

int HKD_ChangeTabColor(char* msg)
{
	int color = 0xFFCCCCCC;

	if (!strcmp(msg, "Ajudante para iniciantes"))
		color = TNColor::NewBlue;
	else if (!strcmp(msg, "Torne-se Cidadão"))
		color = TNColor::Default;
	else if (!strcmp(msg, "Ajudante Mágico"))
		color = TNColor::Default;
	else if (!strcmp(msg, "Abra sua Lojinha"))
		color = TNColor::Default;
	else if (!strcmp(msg, "Informações da Guild"))
		color = TNColor::NewYellow;
	return color;
}

