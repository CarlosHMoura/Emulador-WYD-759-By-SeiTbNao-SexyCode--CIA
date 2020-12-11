#include "main.h"  

BOOL __stdcall HKD_ControlEventClick(int Handle, int Scene)//by seitbnao
{
	printf("\nHandle: %d Scene: %d\n", Handle, Scene);

	MSG_MessageWhisper  m;
	DWORD* pointer_gameinterface;

	auto p_Size = m.Size = sizeof(m);
	auto p_Packet = m.Type = _MSG_MessageWhisper;
	auto p_ClientID = m.ID = GetClientID();
	auto player = GetChar();
	auto isNovato = player.BaseScore.Level == 0;
	int conn = 0;
	int SendHandleID = -1;
	auto game = reinterpret_cast<GameInterface*>(pointer_gameinterface);

	auto Edit = g_pInterface->Instance()->getGuiFromHandle<UITextControl>(195501);
	auto CHATBTS = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65672);
	auto CHATOPCOES = g_pInterface->Instance()->getGuiFromHandle<UIControl>(90128);
	auto CHATBTCOMUM = g_pInterface->Instance()->getGuiFromHandle<UIControl>(90113);
	auto CHATGUIA = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65667);
	auto CHAT5 = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65667);
	auto CHATFUNDO = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65943);
	auto CHATDIGITAR = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65670);
	auto botafecharchat = g_pInterface->getGuiFromHandle<UIControl>(165787);
	auto chatview = g_pInterface->getGuiFromHandle<UIControl>(165788);
	auto painelserial = g_pInterface->Instance()->getGuiFromHandle<UIControl>(195500);
	/*auto paineldonate = g_pInterface->Instance()->getGuiFromHandle<UIControl>(265686);*/

	SendHandleID = Handle;

	/*Desativa o autoativação de novas fieldscene2 adicionadas*/
	if (SendHandleID == 65646)
		SendHandleID = 1;

	if (SendHandleID == 195502)//ATIVAR PINCODE
		SendHandleID = 2;

	if (SendHandleID == 196099)//abre painel pincode
		SendHandleID = 3;

	/*if (SendHandleID == 195503)// menu passe
		SendHandleID = 4;*/

	/*if (SendHandleID == 265629)// abre donate store
		SendHandleID = 5;*/


	if (SendHandleID == 80003)// 
		SendHandleID = 6;

	if (SendHandleID == 80004)//  
		SendHandleID = 7;


	if (SendHandleID == 80006)// 
		SendHandleID = 8;

	if (SendHandleID == 65562)// esc
		SendHandleID = 9;


	if (SendHandleID == 165787)// fecha chat
		SendHandleID = 10;


	if (SendHandleID == 165788)//mostra chat
		SendHandleID = 11;

	/*if (SendHandleID == 265692)//HotStore
		SendHandleID = 12;*/

	if (SendHandleID == -1)
		return true;

#pragma region Switch Botoes

	switch (SendHandleID)
	{//by[SexyCode]

	case 1: // enter world
	{
		chatview->IsVisible = false;
		painelserial->IsVisible = false;
		//paineldonate->IsVisible = false;

	}break;
	case 2: //envia pincode
	{
		m.Size = sizeof(m);
		m.Type = _MSG_MessageWhisper;
		m.ID = GetClientID();
		strcpy(m.MobName, "pin");
		strcpy(m.String, Edit->getText());
		SendPacket((char*)&m, sizeof m);
		painelserial->IsVisible = false;

	}break;
	case 3: //abre painel pincode
	{
		painelserial->IsVisible = !painelserial->IsVisible;

	}break;
	case 4://fecha painel pincode
	{
		auto GuiAlvo = g_pInterface->Instance()->getGuiFromHandle<UIControl>(195500);

		if (GuiAlvo != NULL)
		{
			GuiAlvo->IsVisible = false;
		}

	}break;
	/*case 5: // fechar painel batalha
	{
		auto GuiAlvo = g_pInterface->Instance()->getGuiFromHandle<UIControl>(589832);
		GuiAlvo->IsVisible = !GuiAlvo->IsVisible;
		paineldonate->IsVisible = !paineldonate->IsVisible;
	}break;*/
	case 6: // fechar painel coveiro
	{
	}break;
	case 7:
	{


	}break;

	case 8:
	{


	}break;

	case 9:
	{
		painelserial->IsVisible = false;
		//paineldonate->IsVisible = false;

	}break;

	case 10: //FECHAR CHAT
	{
		botafecharchat->IsVisible = false;
		CHATBTS->IsVisible = false;
		CHATOPCOES->IsVisible = false;
		CHATBTCOMUM->IsVisible = false;
		CHATGUIA->IsVisible = false;
		CHAT5->IsVisible = false;
		CHATFUNDO->IsVisible = false;
		CHATDIGITAR->IsVisible = false;
		chatview->IsVisible = true;

	}break;
	case 11:
	{
		botafecharchat->IsVisible = true;
		CHATBTS->IsVisible = true;
		CHATGUIA->IsVisible = true;
		CHATFUNDO->IsVisible = true;
		chatview->IsVisible = false;
	}break;
	case 12:
	{
	}break;
	return FALSE;
	}

#pragma endregion


	return TRUE;
}

__declspec(naked) void HookNaked::NKD_HandleScene()
{//by seitbnao
	__asm
	{
		MOV EAX, 0x6F0AB0
		MOV EDX, DWORD PTR DS : [EAX]
		MOV ECX, EDX
		MOV EAX, 0x49A7FC
		CALL EAX
		PUSH EAX
		PUSH DWORD PTR SS : [EBP + 0x8]

		CALL HKD_ControlEventClick

		TEST EAX, EAX
		JNZ Jump

		PUSH 0x004B3E75 // Fim da função, ignora completamente os handles
		RETN;

	Jump: // retornou true então executa normalmente as funções do exe

		CMP DWORD PTR SS : [EBP + 0x8] , 0x10006
			PUSH 0x004B2435
			RETN;
	}
}

__declspec(naked) void HookNaked::NKD_ControlEventClick()
{//by seitbnao
	__asm
	{
		MOV EAX, 0x6F0AB0
		MOV EDX, DWORD PTR DS : [EAX]
		MOV ECX, EDX
		MOV EAX, 0x49A7FC
		CALL EAX
		PUSH EAX
		PUSH DWORD PTR SS : [EBP + 0x8]
		CALL HKD_ControlEventClick
		TEST EAX, EAX
		JNZ Jump

		MOV ECX, DWORD PTR SS : [EBP - 0x2460]
		PUSH 0x0046B56E// Fim da função, ignora completamente os handles
		RETN

		Jump :// retornou true então executa normalmente as funções do exe
		PUSH 0x0046B578
			RETN
	}
}
