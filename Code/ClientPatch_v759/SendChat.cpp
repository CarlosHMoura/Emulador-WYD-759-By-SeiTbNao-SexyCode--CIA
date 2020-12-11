#include "main.h"

/* Não finalizado */
void CreateMessagePanel(char* msg, int color)
{
	static int CallBack = 0x04073CF;

	*(int*)0x04073CA = color;

	int* dat = *(int**)0x6F0AB0;

	__asm
	{
		PUSH msg
		MOV ECX, dat
		CALL CallBack
	}

	*(int*)0x04073CA = 0xFFFFAAAA;
}

int HKD_SendChat(char* command)
{
	//	if (*command != '@')
	//		return TRUE;
    UINT16 X = 0;
    UINT16 Y = 0;
    UINT16 X1 = 0;
    UINT16 Y1 = 0; 

	if (strcmp(command, "/ModoGameplay") == 0)
	{
        auto TxMP1 = g_pInterface->Instance()->getGuiFromHandle<UITextControl>(65616);
        auto TxMP2 = g_pInterface->Instance()->getGuiFromHandle<UITextControl>(65617);

        auto TxHP1 = g_pInterface->Instance()->getGuiFromHandle<UITextControl>(65614);
        auto TxHP2 = g_pInterface->Instance()->getGuiFromHandle<UITextControl>(65615);

        if (TxMP1)
        {
            TxMP1->setText("");
            TxMP2->setText("");
            TxHP1->setText("");
            TxHP2->setText("");  

        } 
		SendMsgExp(TNColor::GreenYellow, "GamePlay Ativado");
        SendMsgExp(TNColor::GreenYellow, "Dê Personagem para desativar.");
		return FALSE;
	} 
    if (sscanf_s(command, "X %hu", &X))
    {
        if (auto TESTE = g_pInterface->Instance()->getGuiFromHandle<UIControl>(69636))
        {
            TESTE->Left = X;
            char temp[56] = { 0, };
            memset(temp, 0, sizeof(temp));
            sprintf(temp, "Posição X foi alterada para %d", X);
            SendMsgExp(TNColor::NewYellow, temp);
            return false;
        }
    }
    if (sscanf_s(command, "Y %hu", &Y))
    {
        if (auto TESTE = g_pInterface->Instance()->getGuiFromHandle<UIControl>(69634))
        {
            TESTE->Top = Y;
            char temp[56] = { 0, };
            memset(temp, 0, sizeof(temp));
            sprintf(temp, "Posição Y foi alterada para %d", Y);
            SendMsgExp(TNColor::NewYellow, temp);
            return false;
        }
    }
    if (sscanf_s(command, "A %hu", &X1))
    {
        if (auto TESTE = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65641))
        {
            TESTE->Height = X1;
            char temp[56] = { 0, };
            memset(temp, 0, sizeof(temp));
            sprintf(temp, " Altura foi alterada para %d", X1);
            SendMsgExp(TNColor::NewYellow, temp);
            return false;
        }
    }
    if (sscanf_s(command, "L %hu", &Y1))
    {
        if (auto TESTE = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65641))
        {
            TESTE->Width = Y1;
            char temp[56] = { 0, };
            memset(temp, 0, sizeof(temp));
            sprintf(temp, " Largura foi alterada para %d", Y1);
            SendMsgExp(TNColor::NewYellow, temp);
            return false;
        }
    }
	return TRUE;
}