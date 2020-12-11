#include "main.h"


int lapse = 0;

void HookNaked::HookFunction(DWORD* pointer_gameinterface)
{
    /*
    pesquisa na fieldscene2 por ID  = 589832
    é o painel do Inv
    substitua o existente por esse aqui https://pastebin.com/i33imtne
     
    */ 
#pragma region Donate/Honra Inv

    if (auto DonateInv = g_pInterface->Instance()->getGuiFromHandle<UITextControl>(250099))
    {
        DonateInv->setConstString("%d", g_pClientInfo->Info.Cash);
    }
    if (auto HonraInv = g_pInterface->Instance()->getGuiFromHandle<UITextControl>(250199))
    {
        HonraInv->setConstString("Honra: %d", g_pClientInfo->Info.Honra);
    }
#pragma endregion
    
#pragma region Reposição HUD BySexyCode
    
    //auto CHATBTS = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65672);
    //auto CHATOPCOES = g_pInterface->Instance()->getGuiFromHandle<UIControl>(90128);
    //auto CHATBTCOMUM = g_pInterface->Instance()->getGuiFromHandle<UIControl>(90113);
   //// auto CHATGUIA = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65667);
   // auto CHAT5 = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65667);
  //  auto CHATFUNDO = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65943);
    auto CHATDIGITAR = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65670);  // ABRIR BTN DO MENU NÃO É PELA SRC 

  //  auto Menuconfig = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65788);

    //  auto ExpBar1 = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65655);
    //  auto ExpBar2 = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65656);
    // auto ExpBar3 = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65657);
    //  auto ExpBar4 = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65658);
    // auto ExpBar5 = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65659);
    // auto ExpBar6 = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65660);
    //  auto ExpBar7 = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65661);
    // auto ExpBar8 = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65662);
    //  auto ExpBar9 = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65663);
   // auto ExpBar10 = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65664);

    auto BUFFS = g_pInterface->Instance()->getGuiFromHandle<UIControl>(568876);

  //  auto StatusXP1 = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65637);
  //  auto StatusXP2 = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65638);
  //  auto StatusXP3 = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65639);

   // auto HP = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65621);
   // auto MP = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65623);

  //  auto TxMP1 = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65616);
   // auto TxMP2 = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65617);

  //  auto TxHP1 = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65614);
  //  auto TxHP2 = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65615);

  //  auto TxNome = g_pInterface->Instance()->getGuiFromHandle<UIControl>(69635);
  //  auto TxLevel1 = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65613);
  //  auto TxLevel2 = g_pInterface->Instance()->getGuiFromHandle<UIControl>(65612);
     
#pragma endregion

    auto game = reinterpret_cast<GameInterface*>(pointer_gameinterface);

    if ((lapse++ % 500) == 0)// normal 500
    {
        //Atualizaçao lenta

        lapse = 0;
    }

    
    for (int i = 0; i < 32; i++)
    {
        /*esse dos grupos */
       /* if (auto BFGP = game->getElementByIndex<UIControl>(i, BUFFGRUPOS))
        {

        }*/

        /* tempos dos buffs*/
        if (auto BFTMP = game->getElementByIndex<UIControl>(i, BUFFTEMPO))
        {
            BFTMP->Left = -19 + BFTMP->Height + BFTMP->Left;
            BFTMP->Top = 30;
        }
        
        /*icones 568876*/ 
        if (auto BFICON = game->getElementByIndex<UIControl>(i, BUFFICONES))
        {
            BFICON->Top = -3;  
            BFICON->Width = 25;
            BFICON->Height = 25;
            BFICON->Left = -29 + BFICON->Height + BFICON->Left;
        } 
       
    } 
        #pragma endregion 
}