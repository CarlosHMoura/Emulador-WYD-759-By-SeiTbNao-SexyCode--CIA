#include "main.h"

INT32 HKD_KeyPress_NewButton(BYTE button)
{
	auto CHATBTS = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65672);
	auto CHATOPCOES = g_pInterface->Instance()->getGuiFromHandle<UIControl>(90128);
	auto CHATBTCOMUM = g_pInterface->Instance()->getGuiFromHandle<UIControl>(90113);
	auto CHATGUIA = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65667);
	auto CHAT5 = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65667);
	auto CHATFUNDO = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65943);
	auto CHATDIGITAR = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65670);
	auto botafecharchat = g_pInterface->getGuiFromHandle<UIControl>(165787);
	auto chatview = g_pInterface->getGuiFromHandle<UIControl>(165788);

	if (button == 'b' || button == 'B')
	{
		botafecharchat->IsVisible = !botafecharchat->IsVisible;
		CHATBTS->IsVisible = !CHATBTS->IsVisible;
		CHATGUIA->IsVisible = !CHATGUIA->IsVisible;
		CHAT5->IsVisible = !CHAT5->IsVisible;
		CHATFUNDO->IsVisible = !CHATFUNDO->IsVisible;
		chatview->IsVisible = !chatview->IsVisible;
		CHATGUIA->IsVisible = !CHATGUIA->IsVisible;
	}
	return 0;
}//testa