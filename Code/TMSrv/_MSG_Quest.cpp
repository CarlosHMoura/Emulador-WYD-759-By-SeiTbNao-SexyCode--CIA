#include "ProcessClientMessage.h"   


void Exec_MSG_Quest(int conn, char* pMsg)
{
	MSG_STANDARDPARM2* m = (MSG_STANDARDPARM2*)pMsg;

	int npcIndex = m->Parm1;
	int confirm = m->Parm2;

	if (npcIndex < MAX_USER || npcIndex >= MAX_MOB)
		return;

	int npcMode = -1;

	int npcMerc = pMob[npcIndex].MOB.Merchant;
	int npcGrade = pMob[npcIndex].MOB.BaseScore.Level;

	if (pUser[conn].Trade.OpponentID)
	{
		RemoveTrade(pUser[conn].Trade.OpponentID);
		RemoveTrade(conn);
		return;
	}

	if (pUser[conn].TradeMode)
	{
		SendClientMessage(conn, g_pMessageStringTable[_NN_CantWhenAutoTrade]);
		return;
	}


#pragma region Set npcMode Base

	if (npcMerc == 100 && npcGrade == 0)
		npcMode = QUEST_COVEIRO;

	if (npcMerc == 100 && npcGrade == 36)
		npcMode = QUEST_BENCAODEDEUS;

	if (npcMerc == 100 && npcGrade == 39)
		npcMode = AMELIA;

	if (npcMerc == 100 && npcGrade == 40)
		npcMode = QUEST_EQUILIBRIO;

	if (npcMerc == 100 && npcGrade == 1)
		npcMode = QUEST_JARDINEIRO;

	if (npcMerc == 100 && npcGrade == 2)
		npcMode = QUEST_KAIZEN;

	if (npcMerc == 100 && npcGrade == 3)
		npcMode = QUEST_HIDRA;

	if (npcMerc == 100 && npcGrade == 4)
		npcMode = QUEST_ELFOS;

	if (npcMerc == 100 && npcGrade == 5)
		npcMode = LIDER_APRENDIZ;

	if (npcMerc == 100 && npcGrade == 9 || npcMerc == 100 && npcGrade == 8 || npcMerc == 100 && npcGrade == 7)
		npcMode = PERZEN;

	if (npcMerc == 100 && npcGrade == 13)
		npcMode = QUEST_CAPAREAL;

	if (npcMerc == 100 && npcGrade == 14)
		npcMode = CAPAVERDE_TELEPORT;

	if (npcMerc == 100 && npcGrade == 15)
		npcMode = MOLARGARGULA;

	if (npcMerc == 100 && npcGrade == 16)
		npcMode = CHEFE_DE_TREINO;

	if (npcMerc == 100 && npcGrade == 22)
		npcMode = SOBREVIVENTE;

	if (npcMerc == 100 && npcGrade == 30)
		npcMode = GUARDA_REAL_I;

	if (npcMerc == 100 && npcGrade == 31)
		npcMode = GUARDA_REAL_II;

	if (npcMerc == 100 && npcGrade == 32)
		npcMode = GUARDA_REAL_III;

	if (npcMerc == 100 && npcGrade == 33)
		npcMode = GUARDA_REAL_IV;

	if (npcMerc == 100 && npcGrade == 34)
		npcMode = GUARDA_REAL_V;

	if (npcMerc == 100 && npcGrade == 41)
		npcMode = GUARDA_REAL_VI;

	if (npcMerc == 100 && npcGrade == 37)
		npcMode = KRUNO;

	if (npcMerc == 200)
		npcMode = CURANDEIRA;

	if (npcMerc == 72)
		npcMode = UXMAL;

	if (npcMerc == 7 && npcGrade == 33) //Bama
		npcMode = MESTREGRIFO;

	if (npcMerc == 36)
		npcMode = TREINADORNEWBIE1;

	if (npcMerc == 40)
		npcMode = TREINADORNEWBIE2;

	if (npcMerc == 41)
		npcMode = TREINADORNEWBIE3;

	if (npcMerc == 8)
		npcMode = CAPAVERDE_TRADE;

	if (npcMerc == 78)
		npcMode = BLACKORACLE;

	if (npcMerc == 120)
		npcMode = CARBUNCLE_WIND;

	if (npcMerc == 4)
		npcMode = GOLD_DRAGON;

	if (npcMerc == 201)
		npcMode = UPADOR;

	if (npcMerc == 10)
		npcMode = AMU_MISTICO;

	if (npcMerc == 11)
		npcMode = EXPLOIT_LEADER;

	if (npcMerc == 12)
		npcMode = JEFFI;

	if (npcMerc == 13)
		npcMode = SHAMA;

	if (npcMerc == 14)
		npcMode = KING;

	if (npcMerc == 15)
		npcMode = KING;

	if (npcMerc == 19)
		npcMode = COMP_SEPHI;

	if (npcMerc == 26)
		npcMode = KINGDOM;

	if (npcMerc == 30)
		npcMode = ZAKUM;

	if (npcMerc == 31)
		npcMode = MESTREHAB;

	if (npcMerc == 100 && npcGrade == 38)
		npcMode = UNICORNIO_PURO;

	if (npcMerc == 15 && npcGrade == 13)
		npcMode = JULIARZAN;

	if (npcMerc == 15 && npcGrade == 12)
		npcMode = JULIGELO;

	if (npcMerc == 68)
		npcMode = GODGOVERNMENT;

	if (npcMerc == 58)
		npcMode = MOUNT_MASTER;

	if (npcMerc == 62)
		npcMode = ARZAN_DRAGON;

	if (npcMerc == 76)
		npcMode = URNAMMU;

	if (npcMerc == 74)
		npcMode = KIBITA;

	if (npcMerc == 75)  
		npcMode = EVENTO_DROP;

	if (npcMerc == 74 && npcGrade == 42)
		npcMode = BATALHA_REAL;
	 

	if (npcMode == -1)
		return;

#pragma endregion

	switch (npcMode)
	{
#pragma region MOUNT_MASTER
	case MOUNT_MASTER:
	{
		int mountIndex = pMob[conn].MOB.Equip[14].sIndex;

		if (mountIndex < 2330 || mountIndex >= 2390)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Cure_animals]);
			return;
		}

		if (pMob[conn].MOB.Equip[14].stEffect[0].sValue > 0)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Cure_animals]);
			return;
		}

		int price = g_pItemList[mountIndex].Price;

		if (confirm == 0)
		{
			sprintf(temp, g_pMessageStringTable[_DS_S_cure_price_D], g_pItemList[mountIndex].Name, price);
			SendSay(npcIndex, temp);
			return;
		}

		if (pMob[conn].MOB.Coin < price)
		{

			SendMsgExp(conn, g_pMessageStringTable[_NN_Not_Enough_Money], TNColor::Default, false);
			return;
		}

		if (price < 0 || price > 2000000000)
			return;

		pMob[conn].MOB.Coin -= price;

		int vit = BASE_GetItemAbility(&pMob[conn].MOB.Equip[14], EF_MOUNTLIFE);

		vit -= rand() % 3;

		if (vit > 0)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Cured]);
			pMob[conn].MOB.Equip[14].stEffect[1].cValue = vit;
			pMob[conn].MOB.Equip[14].stEffect[0].sValue = 20;
			pMob[conn].MOB.Equip[14].stEffect[2].cEffect = 5;
		}
		else
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Cure_failed]);
			memset(&pMob[conn].MOB.Equip[14], 0, sizeof(STRUCT_ITEM));
		}


		pMob[conn].GetCurrentScore(conn);
		SendItem(conn, ITEM_PLACE_EQUIP, 14, &pMob[conn].MOB.Equip[14]);
		MountProcess(conn, &pMob[conn].MOB.Equip[14]);
		SendScore(conn);
		SendEtc(conn);

		sprintf(temp, "etc,mount ressurect index:%d vit:%d - %d", pMob[conn].MOB.Equip[14].sIndex, vit, pMob[conn].MOB.Equip[14].stEffect[1].cEffect);
	Log( temp, 0,  pUser[conn].IP);
	} return;
#pragma endregion
#pragma region ZAKUM
	case ZAKUM:
	{
		char UserNameArea[128];

		int count = GetUserInArea(2180, 1160, 2296, 1270, UserNameArea);

		if (count < 1)
			sprintf(temp, g_pMessageStringTable[_NN_Zakum_Quest_empty]);
		else
			sprintf(temp, g_pMessageStringTable[_SD_Zakum_Quest_by_S_N], UserNameArea, count - 1);

		SendSay(npcIndex, temp);
	} break;
#pragma endregion
#pragma region AMU_MISTICO
	case AMU_MISTICO:
	{
		if (pMob[conn].extra.QuestInfo.Mortal.TerraMistica != 0 || pMob[conn].extra.ClassMaster != MORTAL)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Hurry_Helping_them]);
			break;
		}

		if (confirm == 0)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Monster_Attaking_Us_Help]);
			break;
		}

		/*  if (pMob[conn].Leader)
		{
		SendSay(npcIndex, g_pMessageStringTable[_NN_Party_Only]);
		break;
		}

		int partycont = 0;

		for (int i = 0; i < MAX_PARTY; i++)
		if (pMob[conn].PartyList[i] > 0 && pMob[conn].PartyList[i] < MAX_USER)
		partycont++;

		if (partycont == 0)
		{
		SendSay(npcIndex, g_pMessageStringTable[_NN_Party_Only]);
		break;
		}*/

		pMob[conn].extra.QuestInfo.Mortal.TerraMistica = 1;

		SendMsgExp(conn, g_pMessageStringTable[_NN_Get_Watching_Town_Mission], TNColor::Default, false);
		sprintf(temp, "etc,mysticalland complete. name:%s", pMob[conn].MOB.MobName);
	Log( temp, 0,  pUser[conn].IP);
	} break;
#pragma endregion
#pragma region QUEST_COVEIRO
	case QUEST_COVEIRO:
	{
		if (pMob[conn].extra.ClassMaster != MORTAL) //&& pMob[conn].extra.ClassMaster != ARCH)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Level_Limit2]);
			break;
		}

		int minlevel = pMob[conn].extra.ClassMaster == MORTAL ? 39 : 39;
		int maxlevel = pMob[conn].extra.ClassMaster == MORTAL ? 116 : 116;

		if (pMob[conn].MOB.CurrentScore.Level < minlevel || pMob[conn].MOB.CurrentScore.Level >= maxlevel)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Level_limit]);
			break;
		}

		int i = 0;

		for (i = 0; i < pMob[conn].MaxCarry; i++)
		{
			if (pMob[conn].MOB.Carry[i].sIndex != 4038)
				continue;

			BASE_ClearItem(&pMob[conn].MOB.Carry[i]);
			SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);
			break;
		}

		if (i == pMob[conn].MaxCarry)
		{
			sprintf(temp, g_pMessageStringTable[_SN_BRINGITEM], g_pItemList[4038].Name);
			SendSay(npcIndex, temp);
			break;
		}

		pMob[conn].QuestFlag = 1;
		pMob[conn].CheckQuest = 600 + pMob[conn].extra.CheckTimeKersef; 
		DoTeleport(conn, 2398 + rand() % 5 - 3, 2105 + rand() % 5 - 3);
		sprintf(temp, "etc,quest256 ticket coveiro name:%s level:%d", pMob[conn].MOB.MobName, pMob[conn].MOB.BaseScore.Level);
		Log( temp, 0,  pUser[conn].IP);
	} break;
#pragma endregion
#pragma region QUEST_BENCAODEDEUS
	case QUEST_BENCAODEDEUS:
	{
		if (pMob[conn].extra.ClassMaster != MORTAL)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Level_Limit2]);
			break;
		}

		int minlevel = pMob[conn].extra.ClassMaster == MORTAL ? 69 : 69;
		int maxlevel = pMob[conn].extra.ClassMaster == MORTAL ? 74 : 74;

		if (pMob[conn].MOB.CurrentScore.Level < minlevel || pMob[conn].MOB.CurrentScore.Level >= maxlevel)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Level_limit]);
			break;
		}

		DoTeleport(conn, 2651 + rand() % 5 - 3, 1984 + rand() % 5 - 3);

		sprintf(temp, "etc,quest256 ticket benção de Deus name:%s level:%d", pMob[conn].MOB.MobName, pMob[conn].MOB.BaseScore.Level);
		Log(temp, "-system", 0);
	} break;
#pragma endregion
#pragma region QUEST_JARDINEIRO
	case QUEST_JARDINEIRO:
	{
		if (pMob[conn].extra.ClassMaster != MORTAL) //&& pMob[conn].extra.ClassMaster != ARCH)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Level_Limit2]);
			break;
		}

		int minlevel = pMob[conn].extra.ClassMaster == MORTAL ? 115 : 115;
		int maxlevel = pMob[conn].extra.ClassMaster == MORTAL ? 190 : 190;

		if (pMob[conn].MOB.CurrentScore.Level < minlevel || pMob[conn].MOB.CurrentScore.Level >= maxlevel)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Level_limit]);
			break;
		}

		int i = 0;

		for (i = 0; i < pMob[conn].MaxCarry; i++)
		{
			if (pMob[conn].MOB.Carry[i].sIndex != 4039)
				continue;

			BASE_ClearItem(&pMob[conn].MOB.Carry[i]);
			SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);
			break;
		}

		if (i == pMob[conn].MaxCarry)
		{
			sprintf(temp, g_pMessageStringTable[_SN_BRINGITEM], g_pItemList[4039].Name);
			SendSay(npcIndex, temp);
			break;
		}

		pMob[conn].QuestFlag = 2;
		pMob[conn].CheckQuest = 600 + pMob[conn].extra.CheckTimeKersef;
		/*	//pMob[conn].MOB.CheckQuestisDead = FALSE;*/
		DoTeleport(conn, 2234 + rand() % 5 - 3, 1714 + rand() % 5 - 3);
		sprintf(temp, "etc,quest256 ticket jardineiro name:%s level:%d", pMob[conn].MOB.MobName, pMob[conn].MOB.BaseScore.Level);
	Log( temp, 0,  pUser[conn].IP);
	} break;
#pragma region QUEST_KAIZEN
	case QUEST_KAIZEN:
	{
		if (pMob[conn].extra.ClassMaster != MORTAL) //&& pMob[conn].extra.ClassMaster != ARCH)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Level_Limit2]);
			break;
		}

		int minlevel = pMob[conn].extra.ClassMaster == MORTAL ? 190 : 190;
		int maxlevel = pMob[conn].extra.ClassMaster == MORTAL ? 265 : 265;

		if (pMob[conn].MOB.CurrentScore.Level < minlevel || pMob[conn].MOB.CurrentScore.Level >= maxlevel)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Level_limit]);
			break;
		}

		int i = 0;

		for (i = 0; i < pMob[conn].MaxCarry; i++)
		{
			if (pMob[conn].MOB.Carry[i].sIndex != 4040)
				continue;

			BASE_ClearItem(&pMob[conn].MOB.Carry[i]);
			SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);
			break;
		}

		if (i == pMob[conn].MaxCarry)
		{
			sprintf(temp, g_pMessageStringTable[_SN_BRINGITEM], g_pItemList[4040].Name);
			SendSay(npcIndex, temp);
			break;
		}

		pMob[conn].QuestFlag = 3;
		pMob[conn].CheckQuest = 600 + pMob[conn].extra.CheckTimeKersef;
		//pMob[conn].MOB.CheckQuestisDead = FALSE;
		DoTeleport(conn, 464 + rand() % 5 - 3, 3902 + rand() % 5 - 3);
		sprintf(temp, "etc,quest256 ticket kaizen name:%s level:%d", pMob[conn].MOB.MobName, pMob[conn].MOB.BaseScore.Level);
	Log( temp, 0,  pUser[conn].IP);
	} break;
#pragma endregion
#pragma region QUEST_HIDRA
	case QUEST_HIDRA:
	{
		if (pMob[conn].extra.ClassMaster != MORTAL) //&& pMob[conn].extra.ClassMaster != ARCH)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Level_Limit2]);
			break;
		}

		int minlevel = pMob[conn].extra.ClassMaster == MORTAL ? 265 : 265;
		int maxlevel = pMob[conn].extra.ClassMaster == MORTAL ? 320 : 320;

		if (pMob[conn].MOB.CurrentScore.Level < minlevel || pMob[conn].MOB.CurrentScore.Level >= maxlevel)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Level_limit]);
			break;
		}

		int i = 0;

		for (i = 0; i < pMob[conn].MaxCarry; i++)
		{
			if (pMob[conn].MOB.Carry[i].sIndex != 4041)
				continue;

			BASE_ClearItem(&pMob[conn].MOB.Carry[i]);
			SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);
			break;
		}

		if (i == pMob[conn].MaxCarry)
		{
			sprintf(temp, g_pMessageStringTable[_SN_BRINGITEM], g_pItemList[4041].Name);
			SendSay(npcIndex, temp);
			break;
		}

		pMob[conn].QuestFlag = 4;
		pMob[conn].CheckQuest = 600 + pMob[conn].extra.CheckTimeKersef;
		//pMob[conn].MOB.CheckQuestisDead = FALSE;
		DoTeleport(conn, 668 + rand() % 5 - 3, 3756 + rand() % 5 - 3);
		sprintf(temp, "etc,quest256 ticket hidra name:%s level:%d", pMob[conn].MOB.MobName, pMob[conn].MOB.BaseScore.Level);
	Log( temp, 0,  pUser[conn].IP);
	} break;
#pragma endregion
#pragma region QUEST_ELFOS
	case QUEST_ELFOS:
	{
		if (pMob[conn].extra.ClassMaster != MORTAL) //&& pMob[conn].extra.ClassMaster != ARCH)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Level_Limit2]);
			break;
		}

		int minlevel = pMob[conn].extra.ClassMaster == MORTAL ? 320 : 320;
		int maxlevel = pMob[conn].extra.ClassMaster == MORTAL ? 350 : 350;

		if (pMob[conn].MOB.CurrentScore.Level < minlevel || pMob[conn].MOB.CurrentScore.Level >= maxlevel)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Level_limit]);
			break;
		}

		int i = 0;

		for (i = 0; i < pMob[conn].MaxCarry; i++)
		{
			if (pMob[conn].MOB.Carry[i].sIndex != 4042)
				continue;

			BASE_ClearItem(&pMob[conn].MOB.Carry[i]);
			SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);
			break;
		}

		if (i == pMob[conn].MaxCarry)
		{
			sprintf(temp, g_pMessageStringTable[_SN_BRINGITEM], g_pItemList[4042].Name);
			SendSay(npcIndex, temp);
			break;
		}

		pMob[conn].QuestFlag = 5;
		pMob[conn].CheckQuest = 600 + pMob[conn].extra.CheckTimeKersef;
		 
		//pMob[conn].MOB.CheckQuestisDead = FALSE;
		DoTeleport(conn, 1322 + rand() % 5 - 3, 4041 + rand() % 5 - 3);
		SendMsgExp(conn, "Quests Resetadas.", TNColor::Default, false);
		sprintf(temp, "etc,quest256 ticket elfos name:%s level:%d", pMob[conn].MOB.MobName, pMob[conn].MOB.BaseScore.Level);
	Log( temp, 0,  pUser[conn].IP);
	} break;
#pragma endregion
#pragma region JEFFI
	case JEFFI:
	{
		if (pMob[conn].MOB.Equip[13].sIndex == 447 || pMob[conn].MOB.Equip[13].sIndex == 692)
		{
			int price = 0;
			if (pMob[conn].MOB.Equip[13].sIndex == 447)
				price = 1000000;

			else
			{
				if (pMob[conn].MOB.Equip[13].sIndex != 692)
					break;

				price = 5000000;
			}

			if (pMob[conn].MOB.Coin >= price)
			{
				if (price == 1000000)
				{
					pMob[conn].MOB.Coin -= 1000000;
					pMob[conn].MOB.Equip[13].sIndex = rand() % 3 + 448;
				}
				else
				{
					pMob[conn].MOB.Coin -= 5000000;
					pMob[conn].MOB.Equip[13].sIndex = rand() % 3 + 693;
				}

				SendItem(conn, ITEM_PLACE_EQUIP, 13, &pMob[conn].MOB.Equip[13]);
				SendEtc(conn);
				SendSay(npcIndex, g_pMessageStringTable[_NN_Processing_Complete]);
				SetAffect(conn, 44, 20, 20);
				SendScore(conn);

				sprintf(temp, "etc,jeffi make reset50-100 name:%s level:%d", pMob[conn].MOB.MobName, pMob[conn].MOB.BaseScore.Level);
			Log( temp, 0,  pUser[conn].IP);
			}
			else
			{
				if (price == 1000000)
					SendSay(npcIndex, g_pMessageStringTable[_NN_Need_1000000_Gold]);
				else
					SendSay(npcIndex, g_pMessageStringTable[_NN_Need_5000000_Gold]);
			}
		}
		else
		{
			int Ori = 0;
			int Lac = 0;

			for (int i = 0; i < pMob[conn].MaxCarry; i++)
			{
				if (pMob[conn].MOB.Carry[i].sIndex == 419)
					Ori += pMob[conn].MOB.Carry[i].stEffect[0].cEffect == 61 ? pMob[conn].MOB.Carry[i].stEffect[0].cValue : 1;

				if (pMob[conn].MOB.Carry[i].sIndex == 420)
					Lac += pMob[conn].MOB.Carry[i].stEffect[0].cEffect == 61 ? pMob[conn].MOB.Carry[i].stEffect[0].cValue : 1;
			}

			if (Ori >= 10 || Lac >= 10)
			{
				if (pMob[conn].MOB.Coin >= 1000000)
				{
					for (; Ori >= 10 || Lac >= 10;)
					{
						if (Ori >= 10)
						{
							Combine(conn, 419, 412);
							Ori -= 10;
						}
						if (Lac >= 10)
						{
							Combine(conn, 420, 413);
							Lac -= 10;
						}
					}
					SendSay(npcIndex, g_pMessageStringTable[_NN_Processing_Complete]);
					pMob[conn].MOB.Coin -= 1000000;
					SetAffect(conn, 44, 20, 20);
					SendScore(conn);
					SendCarry(conn);
					SendEtc(conn);

					sprintf(temp, "etc,jeffi make lac_ori name:%s level:%d", pMob[conn].MOB.MobName, pMob[conn].MOB.BaseScore.Level);
				Log( temp, 0,  pUser[conn].IP);
				}
				else
					SendSay(npcIndex, g_pMessageStringTable[_NN_Need_1000000_Gold]);

			}
			else
				SendSay(npcIndex, g_pMessageStringTable[_NN_Need_10_Particle]);
		}

	} break;
#pragma endregion
#pragma region SHAMA
	case SHAMA:
	{
		int circle = pMob[conn].MOB.Equip[13].sIndex;

		int ncircle = circle;
		int circlemode = 0;

		if (circle != 448 && circle != 449 && circle != 450)
		{
			if (circle != 693 && circle != 694 && circle != 695)
			{
				SendSay(npcIndex, g_pMessageStringTable[_NN_Need_Pure_Divine]);
				break;
			}
			ncircle -= 693;
			circlemode = 2;
		}
		else
		{
			ncircle -= 448;
			circlemode = 1;
		}

		/*if (circlemode == 1 && pMob[conn].extra.QuestInfo.Circle == 1)
		{
		SendSay(npcIndex, g_pMessageStringTable[_NN_Youve_Done_It_Already]);
		break;
		}*/

		int specialreset = 50;

		if (circlemode == 2)
			specialreset = 100;

		int special = pMob[conn].MOB.SpecialBonus;

		for (int i = 0; i < 4; i++)
		{
			if (pMob[conn].MOB.BaseScore.Special[i] <= specialreset)
			{
				special += pMob[conn].MOB.BaseScore.Special[i];
				pMob[conn].MOB.BaseScore.Special[i] = 0;
			}
			else
			{
				special += specialreset;
				pMob[conn].MOB.BaseScore.Special[i] -= specialreset;
			}
		}

		pMob[conn].MOB.SpecialBonus = special;

		if (circlemode == 1)
			pMob[conn].extra.QuestInfo.Circle = 1;

		if (ncircle == 0)
			pMob[conn].MOB.LearnedSkill &= 0xFFFFFF00;
			pMob[conn].extra.SecLearnedSkill &= 0xFFFFFF00;

		if (ncircle == 1)
			pMob[conn].MOB.LearnedSkill &= 0xFFFF00FF;
			pMob[conn].extra.SecLearnedSkill &= 0xFFFF00FF;

		if (ncircle == 2)
			pMob[conn].MOB.LearnedSkill &= 0xFF00FFFF;
			pMob[conn].extra.SecLearnedSkill &= 0xFF00FFFF;

		BASE_GetBonusSkillPoint(&pMob[conn].MOB, &pMob[conn].extra);

		memset(&pMob[conn].MOB.Equip[13], 0, sizeof(STRUCT_ITEM));
		
		SendItem(conn, ITEM_PLACE_EQUIP, 13, &pMob[conn].MOB.Equip[13]);
		SendEtc(conn);
		SendSay(npcIndex, g_pMessageStringTable[_NN_Initialize_Skill]);
		SetAffect(conn, 44, 20, 20);

		sprintf(temp, "etc,device circle quest item:%d mode:%d type:%d", circle, circlemode, ncircle);
		Log(pUser[conn].AccountName, temp, pUser[conn].IP);

		break;
	} break;
#pragma endregion
#pragma region KING
	case KING:
	{
		int ReiClan = pMob[npcIndex].MOB.Clan;

		int Clan = pMob[conn].MOB.Clan;
		int cLevel = pMob[conn].MOB.CurrentScore.Level;
		int CapeMode = 0;

		STRUCT_ITEM* Capa = &pMob[conn].MOB.Equip[15];

		if (Capa->sIndex == 543 || Capa->sIndex == 545)
			Clan = 7;

		if (Capa->sIndex == 544 || Capa->sIndex == 546)
			Clan = 8;

		if (Capa->sIndex == 734 || Capa->sIndex == 736)
			Clan = 7;

		if (Capa->sIndex == 735 || Capa->sIndex == 737)
			Clan = 8;

		if (Capa->sIndex == 3191 || Capa->sIndex == 3194)
			Clan = 7;

		if (Capa->sIndex == 3192 || Capa->sIndex == 3195)
			Clan = 8;

		if (Capa->sIndex == 3197 || Capa->sIndex == 1767)
			Clan = 7;

		if (Capa->sIndex == 3198 || Capa->sIndex == 1770)
			Clan = 8;

		if (Capa->sIndex == 543 || Capa->sIndex == 544 || Capa->sIndex == 1767 || Capa->sIndex == 1770 || Capa->sIndex == 3191 || Capa->sIndex == 3194 || Capa->sIndex == 3192 || Capa->sIndex == 3195 || Capa->sIndex == 3197 || Capa->sIndex == 3198)
			CapeMode = 2;

		if (Capa->sIndex == 545 || Capa->sIndex == 546 || Capa->sIndex == 549)
			CapeMode = 1;

		if (Capa->sIndex == 3193)
			CapeMode = 1;

		if (Capa->sIndex == 3196)
			CapeMode = 1;

		if (Clan != 0 && Clan != ReiClan)
			break;


		// int Saphire = Sapphire;
		int Saphire = 15;
		/* if (ReiClan == 8)
		{
		if (Sapphire == 1)
		Saphire = 60;
		if (Sapphire == 2)
		Saphire = 32;
		if (Sapphire == 4)
		Saphire = 16;
		if (Sapphire == 16)
		Saphire = 4;
		if (Sapphire == 32)
		Saphire = 2;
		if (Sapphire == 64)
		Saphire = 1;
		}*/

		if (confirm == 0)
		{

			SendMsgExp(conn, g_pMessageStringTable[_DN_Need_D_Sapphire], TNColor::Default, false);
			break;
		}

		if (pMob[conn].MOB.Equip[10].sIndex == 1742 && pMob[conn].MOB.Equip[11].sIndex >= 1760 && pMob[conn].MOB.Equip[11].sIndex <= 1763)
		{
			int sAgua = 0;
			int sTerra = 0;
			int sSol = 0;
			int sVento = 0;


			for (int i = 0; i < pMob[conn].MaxCarry; i++)
			{
				if (pMob[conn].MOB.Carry[i].sIndex == 5334)
					sAgua = 1;

				if (pMob[conn].MOB.Carry[i].sIndex == 5335)
					sTerra = 1;

				if (pMob[conn].MOB.Carry[i].sIndex == 5336)
					sSol = 1;

				if (pMob[conn].MOB.Carry[i].sIndex == 5337)
					sVento = 1;
			}

			if (sAgua == 1 && sTerra == 1 && sSol == 1 && sVento == 1)
			{
				for (int i = 0; i < pMob[conn].MaxCarry; i++)
				{
					if (pMob[conn].MOB.Carry[i].sIndex == 5334 && sAgua == 1)
					{
						memset(&pMob[conn].MOB.Carry[i], 0, sizeof(STRUCT_ITEM));

						pMob[conn].MOB.Carry[i].sIndex = 5338;

						SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);
						sAgua = 0;
					}

					if (pMob[conn].MOB.Carry[i].sIndex == 5335 && sTerra == 1)
					{
						memset(&pMob[conn].MOB.Carry[i], 0, sizeof(STRUCT_ITEM));
						SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);
						sTerra = 0;
					}

					if (pMob[conn].MOB.Carry[i].sIndex == 5336 && sSol == 1)
					{
						memset(&pMob[conn].MOB.Carry[i], 0, sizeof(STRUCT_ITEM));
						SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);
						sSol = 0;
					}

					if (pMob[conn].MOB.Carry[i].sIndex == 5337 && sVento == 1)
					{
						memset(&pMob[conn].MOB.Carry[i], 0, sizeof(STRUCT_ITEM));
						SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);
						sVento = 0;
					}
				}

				memset(&pMob[conn].MOB.Equip[10], 0, sizeof(STRUCT_ITEM));
				SendItem(conn, ITEM_PLACE_EQUIP, 10, &pMob[conn].MOB.Equip[10]);

				memset(&pMob[conn].MOB.Equip[11], 0, sizeof(STRUCT_ITEM));
				SendItem(conn, ITEM_PLACE_EQUIP, 11, &pMob[conn].MOB.Equip[11]);

				SendSay(npcIndex, g_pMessageStringTable[_NN_My_King_Bless1]);

				sprintf(temp, "etc,king make ideal_stone name:%s level:%d", pMob[conn].MOB.MobName, pMob[conn].MOB.BaseScore.Level);
			Log( temp, 0,  pUser[conn].IP);

				break;
			}

			if (pMob[conn].extra.ClassMaster == MORTAL && pMob[conn].MOB.CurrentScore.Level >= 299 && pMob[conn].Mode != MOB_WAITDB)
			{

				int cls = pMob[conn].MOB.Equip[11].sIndex - 1760;

				MSG_DBCreateArchCharacter sm_ca;
				memset(&sm_ca, 0, sizeof(MSG_DBCreateArchCharacter));

				sm_ca.Size = sizeof(MSG_DBCreateArchCharacter);
				sm_ca.Type = _MSG_DBCreateArchCharacter;
				sm_ca.ID = conn;

				sm_ca.MobClass = cls;
				sm_ca.MortalFace = pMob[conn].extra.MortalFace;
				sm_ca.MortalSlot = pUser[conn].Slot;

				strncpy(sm_ca.MobName, pMob[conn].MOB.MobName, NAME_LENGTH);



				for (int i = 0; i < MAX_AFFECT; i++)
				{
					auto Core = pMob[conn].Affect[i];

					if (Core.Type <= 0) continue;

					if (Core.Type == 34 && Core.Level == TRUE)
					{
						sm_ca.isDivina = true;
						sm_ca.DivinaTimer = Core.Time;
						sm_ca.DivinaEndTimer = pMob[conn].extra.DivineEnd;
						break;
					}
				}

				strncpy(sm_ca.MobName, pMob[conn].MOB.MobName, NAME_LENGTH);
				memset(&pMob[conn].MOB.Equip[10], 0, sizeof(STRUCT_ITEM));
				SendItem(conn, ITEM_PLACE_EQUIP, 10, &pMob[conn].MOB.Equip[10]);

				memset(&pMob[conn].MOB.Equip[11], 0, sizeof(STRUCT_ITEM));
				SendItem(conn, ITEM_PLACE_EQUIP, 11, &pMob[conn].MOB.Equip[11]);

				pMob[conn].Mode = MOB_WAITDB;
				SendClientMessage(conn, "Você criou o Arch. Que a glória de Sephira esteja com você.");
				DBServerSocket.SendOneMessage((char*)&sm_ca, sizeof(MSG_DBCreateArchCharacter));

				sprintf(temp, "etc,king_arch name:%s class:%d mortalface:%d mortalslot:%d", pMob[conn].MOB.MobName, cls, pMob[conn].extra.MortalFace, pUser[conn].Slot);
				Log(pUser[conn].AccountName, temp, pUser[conn].IP);

				break;
			}
		}

		if (CapeMode >= 2)
		{
			if (ReiClan == 7)
				SendClientMessage(conn, g_pMessageStringTable[_NN_My_King_Bless1]);
			else
				SendClientMessage(conn, g_pMessageStringTable[_NN_My_King_Bless2]);

			break;
		}

		if ((pMob[conn].extra.ClassMaster == CELESTIAL || pMob[conn].extra.ClassMaster == CELESTIALCS || pMob[conn].extra.ClassMaster == SCELESTIAL) && (pMob[conn].MOB.Equip[15].sIndex == 3199 || pMob[conn].MOB.Equip[15].sIndex == 573))
		{
			int NumSepInv = 0;

			for (int i = 0; i < pMob[conn].MaxCarry; i++)
			{
				if (pMob[conn].MOB.Carry[i].sIndex == 697)
					NumSepInv++;

				else if (pMob[conn].MOB.Carry[i].sIndex == 4131)
					NumSepInv += 10;
			}

			if (NumSepInv < Saphire)
			{
				sprintf(temp, g_pMessageStringTable[_DN_Need_D_Sapphire], Saphire);
				SendClientMessage(conn, temp);
				break;
			}

			MSG_STANDARDPARM sm_us;
			memset(&sm_us, 0, sizeof(MSG_STANDARDPARM));

			sm_us.ID = 0;
			sm_us.Type = _MSG_DBUpdateSapphire;

			sm_us.Size = sizeof(MSG_STANDARDPARM);

			sm_us.Parm = ReiClan == 7;

			DBServerSocket.SendOneMessage((char*)&sm_us, sizeof(MSG_STANDARD));

			for (int i = 0; i < pMob[conn].MaxCarry && Saphire > 0; i++)
			{
				if (pMob[conn].MOB.Carry[i].sIndex == 697)
				{
					memset(&pMob[conn].MOB.Carry[i], 0, sizeof(STRUCT_ITEM));
					SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);
					Saphire--;
				}

				else if (pMob[conn].MOB.Carry[i].sIndex == 4131)
				{
					memset(&pMob[conn].MOB.Carry[i], 0, sizeof(STRUCT_ITEM));
					SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);

					if ((Saphire - 10) < 0)
						Saphire = 0;

					else
						Saphire -= 10;
				}
			}

			if ((pMob[conn].extra.ClassMaster == CELESTIAL || pMob[conn].extra.ClassMaster == CELESTIALCS))
			{
				if (ReiClan == 7)
				{
					pMob[conn].MOB.Equip[15].sIndex = 3197;
					SendItem(conn, ITEM_PLACE_EQUIP, 15, &pMob[conn].MOB.Equip[15]);
					SendClientMessage(conn, g_pMessageStringTable[_NN_My_King_Bless1]);
				}
				if (ReiClan == 8)
				{
					pMob[conn].MOB.Equip[15].sIndex = 3198;
					SendItem(conn, ITEM_PLACE_EQUIP, 15, &pMob[conn].MOB.Equip[15]);
					SendClientMessage(conn, g_pMessageStringTable[_NN_My_King_Bless2]);
				}
			}

			if ((pMob[conn].extra.ClassMaster == SCELESTIAL))
			{
				if (ReiClan == 7)
				{
					pMob[conn].MOB.Equip[15].sIndex = 1767;
					SendItem(conn, ITEM_PLACE_EQUIP, 15, &pMob[conn].MOB.Equip[15]);
					SendClientMessage(conn, g_pMessageStringTable[_NN_My_King_Bless1]);
				}
				if (ReiClan == 8)
				{
					pMob[conn].MOB.Equip[15].sIndex = 1770;
					SendItem(conn, ITEM_PLACE_EQUIP, 15, &pMob[conn].MOB.Equip[15]);
					SendClientMessage(conn, g_pMessageStringTable[_NN_My_King_Bless2]);
				}
			}

			int Guild = pMob[conn].MOB.Guild;
			int Group = ServerGroup;
			int Server = Guild / MAX_GUILD;
			int usGuild = Guild & MAX_GUILD - 1;

			if (Guild && pMob[conn].MOB.GuildLevel == 9)
			{
				MSG_GuildInfo sm_gi;
				memset(&sm_gi, 0, sizeof(MSG_GuildInfo));

				sm_gi.Type = _MSG_GuildInfo;
				sm_gi.Size = sizeof(MSG_GuildInfo);
				sm_gi.ID = conn;

				sm_gi.Guild = Guild;

				GuildInfo[Guild].Clan = ReiClan;
				GuildInfo[Guild].Fame = 0;

				sm_gi.GuildInfo = GuildInfo[Guild];

				DBServerSocket.SendOneMessage((char*)&sm_gi, sizeof(MSG_GuildInfo));
			}

			sprintf(temp, "etc,get mantle %d - sapphire:%d", pMob[conn].MOB.Equip[15].sIndex, Saphire);
			Log(pUser[conn].AccountName, temp,pUser[conn].IP);

			break;
		}

		if (cLevel < 219)
		{
			SendClientMessage(conn, g_pMessageStringTable[_NN_Need_Level]);
			break;
		}

		if (CapeMode != 1 || cLevel >= 255)
		{
			int NumSepInv = 0;

			for (int i = 0; i < pMob[conn].MaxCarry; i++)
			{
				if (pMob[conn].MOB.Carry[i].sIndex == 697)
					NumSepInv++;

				else if (pMob[conn].MOB.Carry[i].sIndex == 4131)
					NumSepInv += 10;
			}

			if (NumSepInv < Saphire && pMob[conn].MOB.Equip[13].sIndex != 4081)
			{
				sprintf(temp, g_pMessageStringTable[_DN_Need_D_Sapphire], Saphire);
				SendClientMessage(conn, temp);
				break;
			}

			MSG_STANDARDPARM sm_us;
			memset(&sm_us, 0, sizeof(MSG_STANDARDPARM));

			sm_us.ID = 0;
			sm_us.Type = _MSG_DBUpdateSapphire;

			sm_us.Size = sizeof(MSG_STANDARDPARM);

			sm_us.Parm = ReiClan == 7;

			DBServerSocket.SendOneMessage((char*)&sm_us, sizeof(MSG_STANDARD));

			for (int i = 0; i < pMob[conn].MaxCarry && Saphire > 0 && pMob[conn].MOB.Equip[13].sIndex != 4081; i++)
			{
				if (pMob[conn].MOB.Carry[i].sIndex == 697)
				{
					memset(&pMob[conn].MOB.Carry[i], 0, sizeof(STRUCT_ITEM));
					SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);
					Saphire--;
				}

				else if (pMob[conn].MOB.Carry[i].sIndex == 4131)
				{
					memset(&pMob[conn].MOB.Carry[i], 0, sizeof(STRUCT_ITEM));
					SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);

					if ((Saphire - 10) < 0)
						Saphire = 0;

					else
						Saphire -= 10;
				}
			}

			if (pMob[conn].MOB.Equip[13].sIndex == 4081)
			{
				memset(&pMob[conn].MOB.Equip[13], 0, sizeof(STRUCT_ITEM));
				SendItem(conn, ITEM_PLACE_EQUIP, 13, &pMob[conn].MOB.Equip[13]);
			}

			if (CapeMode == 0)
			{
				if (Capa->sIndex != 548)
					memset(&pMob[conn].MOB.Equip[15], 0, sizeof(STRUCT_ITEM));

				if (ReiClan == 7)
					pMob[conn].MOB.Equip[15].sIndex = 545;
				else
					pMob[conn].MOB.Equip[15].sIndex = 546;
			}

			if (CapeMode == 1)
			{
				if (Capa->sIndex == 3193)
				{
					if (ReiClan == 7)
						pMob[conn].MOB.Equip[15].sIndex = 3191;
					else
						pMob[conn].MOB.Equip[15].sIndex = 3192;
				}

				else if (Capa->sIndex == 3196)
				{
					if (ReiClan == 7)
						pMob[conn].MOB.Equip[15].sIndex = 3194;
					else
						pMob[conn].MOB.Equip[15].sIndex = 3195;
				}

				else
				{
					if (Capa->sIndex != 549)
						memset(&pMob[conn].MOB.Equip[15], 0, sizeof(STRUCT_ITEM));

					if (ReiClan == 7)
						pMob[conn].MOB.Equip[15].sIndex = 543;
					else
						pMob[conn].MOB.Equip[15].sIndex = 544;
				}
			}


			SendItem(conn, ITEM_PLACE_EQUIP, 15, &pMob[conn].MOB.Equip[15]);

			if (ReiClan == 7)
				SendClientMessage(conn, g_pMessageStringTable[_NN_My_King_Bless1]);
			else
				SendClientMessage(conn, g_pMessageStringTable[_NN_My_King_Bless2]);

			int Guild = pMob[conn].MOB.Guild;
			int Group = ServerGroup;
			int Server = Guild / MAX_GUILD;
			int usGuild = Guild & MAX_GUILD - 1;

			if (Guild && pMob[conn].MOB.GuildLevel == 9)
			{
				MSG_GuildInfo sm_gi;
				memset(&sm_gi, 0, sizeof(MSG_GuildInfo));

				sm_gi.Type = _MSG_GuildInfo;
				sm_gi.Size = sizeof(MSG_GuildInfo);
				sm_gi.ID = conn;

				sm_gi.Guild = Guild;

				GuildInfo[Guild].Clan = ReiClan;

				sm_gi.GuildInfo = GuildInfo[Guild];

				DBServerSocket.SendOneMessage((char*)&sm_gi, sizeof(MSG_GuildInfo));
			}

			sprintf(temp, "etc,get mantle %d - sapphire:%d", pMob[conn].MOB.Equip[15].sIndex, Saphire);
			Log(pUser[conn].AccountName, temp, pUser[conn].IP);

			break;
		}
		else
		{
			SendClientMessage(conn, g_pMessageStringTable[_NN_Need_Level]);
			break;
		}
	} break;
#pragma endregion
#pragma region KINGDOM BROKER
	case KINGDOM:
	{
		int Clan = pMob[conn].MOB.Clan;


		time_t rawtime;
		tm* timeinfo;

		time(&rawtime);
		timeinfo = localtime(&rawtime);
		/*timeinfo->tm_wday == 6 ||*/
		if (timeinfo->tm_wday == 0)
		{
			SendClientMessage(conn, g_pMessageStringTable[_NN_NotEquip_Saturday]);
			break;
		}

		if (Clan != 7 && Clan != 8)
		{
			if (Clan == 7)
				SendClientMessage(conn, g_pMessageStringTable[_NN_My_King_Bless1]);
			else
				SendClientMessage(conn, g_pMessageStringTable[_NN_My_King_Bless2]);

			break;
		}

		if (confirm == 0)
		{
			SendClientMessage(conn, g_pMessageStringTable[_NN_Leaving_kingdom]);

			break;
		}
		int Saphire = 16;
		int NumSepInv = 0;

		for (int i = 0; i < pMob[conn].MaxCarry; i++)
		{
			if (pMob[conn].MOB.Carry[i].sIndex == 697)
				NumSepInv++;

			else if (pMob[conn].MOB.Carry[i].sIndex == 4131)
				NumSepInv += 10;
		}

		if (NumSepInv < Saphire)
		{
			sprintf(temp, g_pMessageStringTable[_DN_Need_D_Sapphire], Saphire);
			SendClientMessage(conn, temp);
			break;
		}



		for (int i = 0; i < pMob[conn].MaxCarry && Saphire > 0; i++)
		{
			if (pMob[conn].MOB.Carry[i].sIndex == 697)
			{
				memset(&pMob[conn].MOB.Carry[i], 0, sizeof(STRUCT_ITEM));
				SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);
				Saphire--;
			}

			else if (pMob[conn].MOB.Carry[i].sIndex == 4131)
			{
				memset(&pMob[conn].MOB.Carry[i], 0, sizeof(STRUCT_ITEM));
				SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);

				if ((Saphire - 10) < 0)
					Saphire = 0;

				else
					Saphire -= 10;
			}
		}


		if (pMob[conn].MOB.Equip[15].sIndex == 543 || pMob[conn].MOB.Equip[15].sIndex == 544)
			pMob[conn].MOB.Equip[15].sIndex = 549;

		if (pMob[conn].MOB.Equip[15].sIndex == 545 || pMob[conn].MOB.Equip[15].sIndex == 546)
			pMob[conn].MOB.Equip[15].sIndex = 548;

		if (pMob[conn].MOB.Equip[15].sIndex == 3191 || pMob[conn].MOB.Equip[15].sIndex == 3192)
			pMob[conn].MOB.Equip[15].sIndex = 3193;

		if (pMob[conn].MOB.Equip[15].sIndex == 3194 || pMob[conn].MOB.Equip[15].sIndex == 3195)
			pMob[conn].MOB.Equip[15].sIndex = 3196;

		if (pMob[conn].MOB.Equip[15].sIndex == 3197 || pMob[conn].MOB.Equip[15].sIndex == 3198)
			pMob[conn].MOB.Equip[15].sIndex = 3199;

		if (pMob[conn].MOB.Equip[15].sIndex == 1767 || pMob[conn].MOB.Equip[15].sIndex == 1770)
			pMob[conn].MOB.Equip[15].sIndex = 3199;

		if (Clan == 7)
			SendClientMessage(conn, g_pMessageStringTable[_NN_My_King_Bless1]);
		else
			SendClientMessage(conn, g_pMessageStringTable[_NN_My_King_Bless2]);

		SendItem(conn, ITEM_PLACE_EQUIP, 15, &pMob[conn].MOB.Equip[15]);

		pMob[conn].GetCurrentScore(conn);

		MSG_STANDARDPARM sm_scl;
		memset(&sm_scl, 0, sizeof(MSG_STANDARDPARM));

		sm_scl.Type = _MSG_SetClan;
		sm_scl.Size = sizeof(MSG_STANDARDPARM);
		sm_scl.ID = conn;
		sm_scl.Parm = pMob[conn].MOB.Clan;
		m->ClientTick = CurrentTime;

		GridMulticast(pMob[conn].TargetX, pMob[conn].TargetY, (MSG_STANDARD*)&sm_scl, 0);

		SendEquip(conn, conn);
		sprintf(temp, "etc,remove mantle");
		Log(temp, pUser[conn].AccountName, pUser[conn].IP);
		break;

	} break;
#pragma endregion
#pragma region URNAMMU
	case URNAMMU:
	{
		if (pMob[conn].extra.ClassMaster != CELESTIALCS)
		{
			sprintf(temp, g_pMessageStringTable[_SN_NEEDCLASS], "Sub Celestial");
			SendClientMessage(conn, temp);
			break;
		}
		if (pMob[conn].MOB.Equip[11].sIndex < 1760 || pMob[conn].MOB.Equip[11].sIndex > 1763)
		{
			sprintf(temp, g_pMessageStringTable[_SN_WANTEQUIPITEM], "o Sephirot da classe escolhida e ter 2000 de Fama");
			SendClientMessage(conn, temp);
			break;
		}
		if (pMob[conn].extra.Fame < 2000)
		{
			sprintf(temp, g_pMessageStringTable[_DN_NEEDFAME], 2000);
			SendClientMessage(conn, temp);
			break;
		}

		sprintf(temp, "etc,change SubClass class:%d to %d name:%s level:%d", pMob[conn].MOB.Class, pMob[conn].MOB.Equip[11].sIndex - 1760, pMob[conn].MOB.MobName, pMob[conn].MOB.BaseScore.Level);
		Log(temp, "-system", 0);

		pMob[conn].extra.Fame -= 2000;

		pMob[conn].extra.SaveCelestial[1].Class = pMob[conn].MOB.Equip[11].sIndex - 1760;

		pMob[conn].extra.SaveCelestial[1].BaseScore.Str = BaseSIDCHM[pMob[conn].MOB.Class][0];
		pMob[conn].extra.SaveCelestial[1].BaseScore.Int = BaseSIDCHM[pMob[conn].MOB.Class][1];
		pMob[conn].extra.SaveCelestial[1].BaseScore.Dex = BaseSIDCHM[pMob[conn].MOB.Class][2];
		pMob[conn].extra.SaveCelestial[1].BaseScore.Con = BaseSIDCHM[pMob[conn].MOB.Class][3];

		memset(pMob[conn].extra.SaveCelestial[1].SkillBar1, 0, 4);
		memset(pMob[conn].extra.SaveCelestial[1].SkillBar2, 0, 16);

		int special = pMob[conn].extra.SaveCelestial[1].SpecialBonus;
		int specialreset = 55;

		for (int i = 0; i < 4; i++)
		{
			if (pMob[conn].extra.SaveCelestial[1].BaseScore.Special[i] <= 55)
			{
				special += pMob[conn].extra.SaveCelestial[1].BaseScore.Special[i];
				pMob[conn].extra.SaveCelestial[1].BaseScore.Special[i] = 0;
			}
			else
			{
				special += specialreset;
				pMob[conn].extra.SaveCelestial[1].BaseScore.Special[i] -= specialreset;
			}
		}

		pMob[conn].extra.SaveCelestial[1].SpecialBonus = special;
		
		pMob[conn].extra.SaveCelestial[1].LearnedSkill &= 0xFF000000;
		pMob[conn].extra.SecLearnedSkill &= 0xFF00FFFF;
		memset(&pMob[conn].MOB.Equip[11], 0, sizeof(STRUCT_ITEM));

		SendItem(conn, ITEM_PLACE_EQUIP, 11, &pMob[conn].MOB.Equip[11]);

		SendClientMessage(conn, g_pMessageStringTable[_NN_My_King_Bless1]);
		break;
	} break;
#pragma endregion
#pragma region UXMAL
	case UXMAL:
	{
		struct tm when;
		time_t now;
		time(&now);
		when = *localtime(&now);

		if (when.tm_min >= 0 && when.tm_min <= 15 || when.tm_min >= 20 && when.tm_min <= 35 || when.tm_min >= 40 && when.tm_min <= 55)
		{
			SendClientMessage(conn, "Quest em progresso. Volte nos minutos (16~19) - (36~39) - (56~59).");
			break;
		}

		if (pMob[conn].Leader != -1 && pMob[conn].Leader)
		{
			SendClientMessage(conn, g_pMessageStringTable[_NN_Party_Leader_Only]);
			break;
		}

		int i = 0;

		int sala = -1;

		for (i = 0; i < pMob[conn].MaxCarry; i++)
		{
			if (pMob[conn].MOB.Carry[i].sIndex != 5134)
				continue;

			sala = BASE_GetItemSanc(&pMob[conn].MOB.Carry[i]);

			if (sala > 6)
				sala = 6;

			break;
		}

		if (i == pMob[conn].MaxCarry)
		{
			sprintf(temp, g_pMessageStringTable[_SN_BRINGITEM], g_pItemList[5134].Name);
			SendClientMessage(conn, temp);
			break;
		}
		int j = 0;

		for (j = 0; j < (sala == 0 ? 2 : 3); j++)
		{
			if (Pista[sala].Party[j].LeaderID == 0)
				break;
		}

		if (j == (sala == 0 ? 2 : 3))
		{
			SendClientMessage(conn, g_pMessageStringTable[_NN_Night_Limited]);
			break;
		}

		int c = 0;
		for (c = 0; c < 3; c++)
		{
			if (Pista[sala].Party[c].LeaderID == conn)
				break;
		}
		if (c != 3)
		{
			SendClientMessage(conn, g_pMessageStringTable[_NN_Night_Already]);
			break;
		}

		sprintf(temp, "%s Registrou RuneQuest type:%d conn:%d  level:%d", pMob[conn].MOB.MobName, sala, conn, pMob[conn].MOB.BaseScore.Level);
	Log( temp, 0,  pUser[conn].IP);

		Pista[sala].Party[j].LeaderID = conn;
		Pista[sala].Party[j].MobCount = 0;
		Pista[sala].Party[j].Sala = sala;
		strncpy(Pista[sala].Party[j].LeaderName, pMob[conn].MOB.MobName, NAME_LENGTH);

		BASE_ClearItem(&pMob[conn].MOB.Carry[i]);
		SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);

		SendClientMessage(conn, g_pMessageStringTable[_NN_TicketUsed]);

	} break;
#pragma endregion
#pragma region ARZAN_DRAGON
	case ARZAN_DRAGON:
	{
		if (pMob[conn].MOB.Coin < 2000000)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_snowimp_need_2MGold]);
			break;
		}

		int Materiais[5] = { 0, 0, 0, 0, 0 };

		for (int i = 0; i < pMob[conn].MaxCarry; i++)
		{
			if (pMob[conn].MOB.Carry[i].sIndex < 1721 || pMob[conn].MOB.Carry[i].sIndex > 1725)
				continue;

			int Id = pMob[conn].MOB.Carry[i].sIndex - 1721;

			Materiais[Id]++;
		}

		if (Materiais[0] < 10 || Materiais[1] < 2 || Materiais[2] < 4 || Materiais[3] < 1 || Materiais[4] < 1)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Need_5_materials]);
			break;
		}

		if (Materiais[0] > 10)
			Materiais[0] = 10;

		if (Materiais[1] > 2)
			Materiais[1] = 2;

		if (Materiais[2] > 4)
			Materiais[2] = 4;

		if (Materiais[3] > 1)
			Materiais[3] = 1;

		if (Materiais[4] > 1)
			Materiais[4] = 1;

		for (int x = 0; x < 5; x++)
		{
			for (int i = 0; i < pMob[conn].MaxCarry && Materiais[x] > 0; i++)
			{
				if (pMob[conn].MOB.Carry[i].sIndex == (1721 + x))
				{
					memset(&pMob[conn].MOB.Carry[i], 0, sizeof(STRUCT_ITEM));
					SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);
					Materiais[x]--;
				}
			}
		}

		pMob[conn].MOB.Coin -= 2000000;
		SendEtc(conn);

		STRUCT_ITEM Item;

		memset(&Item, 0, sizeof(STRUCT_ITEM));

		Item.sIndex = 1726;
		Item.stEffect[0].cEffect = 43;
		Item.stEffect[0].cValue = rand() % 4;

		PutItem(conn, &Item);

		SendMsgExp(conn, g_pMessageStringTable[_NN_snowimp_create_success], TNColor::Default, false);
		sprintf(temp, "etc,arzan_dragon snowimp create name:%s level:%d", pMob[conn].MOB.MobName, pMob[conn].MOB.BaseScore.Level);
	Log( temp, 0,  pUser[conn].IP);
	}break;
#pragma endregion
#pragma region GOLD_DRAGON
	case GOLD_DRAGON:
	{
		int treasure = CombineTreasureMap(conn);

		if (treasure)
			break;

		for (int i = 0; i < 8; i++)
		{
			if (g_pTreasure[i].Source == 0)
				continue;

			int x = 0;

			for (x = 0; x < pMob[conn].MaxCarry; x++)
			{
				if (pMob[conn].MOB.Carry[x].sIndex == g_pTreasure[i].Source)
					break;
			}

			if (x != pMob[conn].MaxCarry)
			{
				char itemlog[1024];

				sprintf(temp, "tra,_gold_ 0");

				BASE_GetItemCode(&pMob[conn].MOB.Carry[x], itemlog);
				strcat(temp, itemlog);

				//Log(temp, pUser[conn].AccountName, pUser[conn].IP);

				memset(&pMob[conn].MOB.Carry[x], 0, sizeof(STRUCT_ITEM));

				SendItem(conn, ITEM_PLACE_CARRY, x, &pMob[conn].MOB.Carry[x]);

				int _rand = rand() % 1000;

				STRUCT_ITEM Item;

				memset(&Item, 0, sizeof(STRUCT_ITEM));

				if (_rand < g_pTreasure[i].Rate[0])
					memcpy(&Item, &g_pTreasure[i].Target[0], sizeof(STRUCT_ITEM));

				else if (_rand < g_pTreasure[x].Rate[1])
					memcpy(&Item, &g_pTreasure[i].Target[1], sizeof(STRUCT_ITEM));

				else if (_rand < g_pTreasure[i].Rate[2])
					memcpy(&Item, &g_pTreasure[i].Target[2], sizeof(STRUCT_ITEM));

				else if (_rand < g_pTreasure[i].Rate[3])
					memcpy(&Item, &g_pTreasure[i].Target[3], sizeof(STRUCT_ITEM));

				else if (_rand < g_pTreasure[i].Rate[4])
					memcpy(&Item, &g_pTreasure[i].Target[4], sizeof(STRUCT_ITEM));

				if (Item.sIndex == 0)
				{
					SendSay(npcIndex, g_pMessageStringTable[_NN_Next_Chance]);
					return;
				}

				sprintf(temp, "tra,%s 0", pUser[conn].AccountName);

				BASE_GetItemCode(&Item, itemlog);
				strcat(temp, itemlog);

				//Log(temp, "_gold_", pUser[conn].IP);

				PutItem(conn, &Item);

				SendSay(npcIndex, g_pMessageStringTable[_NN_Congratulations]);
				return;
			}
		}

		int Cristais[7] = { -1, -1, -1, -1, -1, -1, -1 };
		int NumCristal = 0;

		for (int i = 0; i < pMob[conn].MaxCarry; i++)
		{
			int ItemId = pMob[conn].MOB.Carry[i].sIndex;

			if (ItemId >= 421 && ItemId <= 427 && Cristais[ItemId - 421] == -1)
			{
				Cristais[ItemId - 421] = i;
				NumCristal++;
			}
		}

		if (Cristais[0] != -1 && Cristais[1] != -1 && Cristais[2] != -1 && Cristais[3] != -1 && Cristais[4] != -1 && Cristais[5] != -1 && Cristais[6] != -1)
		{
			if (pMob[conn].MOB.Equip[6].sIndex == 0)
			{
				SendSay(npcIndex, g_pMessageStringTable[_NN_Equip_Weapon_To_Enchant]);
				break;
			}

			int sanc = BASE_GetItemSanc(&pMob[conn].MOB.Equip[6]);

			if (sanc > 0)
			{
				SendSay(npcIndex, g_pMessageStringTable[_NN_Only_Nomal_Weapons]);
				break;
			}

			if ((pMob[conn].MOB.Equip[0].sIndex / 10) == 0)
				SendEmotion(conn, 23, 0);

			else
				SendEmotion(conn, 15, 0);

			int cEffect1 = pMob[conn].MOB.Equip[6].stEffect[0].cEffect;
			int cEffect2 = pMob[conn].MOB.Equip[6].stEffect[1].cEffect;
			int cEffect3 = pMob[conn].MOB.Equip[6].stEffect[2].cEffect;

			int cValue1 = pMob[conn].MOB.Equip[6].stEffect[0].cValue;
			int cValue2 = pMob[conn].MOB.Equip[6].stEffect[1].cValue;
			int cValue3 = pMob[conn].MOB.Equip[6].stEffect[2].cValue;

			pMob[conn].MOB.Equip[6].stEffect[0].cEffect = 0;
			pMob[conn].MOB.Equip[6].stEffect[0].cValue = 0;

			pMob[conn].MOB.Equip[6].stEffect[1].cEffect = 0;
			pMob[conn].MOB.Equip[6].stEffect[1].cValue = 0;

			pMob[conn].MOB.Equip[6].stEffect[2].cEffect = 0;
			pMob[conn].MOB.Equip[6].stEffect[2].cValue = 0;

			SetItemBonus(&pMob[conn].MOB.Equip[6], (25 * NumCristal / 10) + g_pItemList[pMob[conn].MOB.Equip[6].sIndex].ReqLvl, 1, pMob[conn].DropBonus);

			for (int i = 0; i < 7; i++)
				memset(&pMob[conn].MOB.Carry[Cristais[i]], 0, sizeof(STRUCT_ITEM));

			SendCarry(conn);

			SendMsgExp(conn, g_pMessageStringTable[_SN_I_Wwill_Enchant_Your_Weapon], TNColor::Default, false);
			SendItem(conn, ITEM_PLACE_EQUIP, 6, &pMob[conn].MOB.Equip[6]);

			sprintf(temp, g_pMessageStringTable[_SN_Now_I_Will_Enchant_Your], pMob[conn].MOB.MobName);
			SendSay(npcIndex, temp);

			SetAffect(conn, 44, 200, 200);
			SendScore(conn);

			sprintf(temp, "etc,crystal %d-%d from %d:%d %d:%d %d:%d to %d:%d %d:%d %d:%d", NumCristal, pMob[conn].MOB.Equip[6].sIndex, cEffect1, cValue1, cEffect2, cValue2, cEffect3, cValue3, pMob[conn].MOB.Equip[6].stEffect[0].cEffect, pMob[conn].MOB.Equip[6].stEffect[0].cValue, pMob[conn].MOB.Equip[6].stEffect[1].cEffect, pMob[conn].MOB.Equip[6].stEffect[1].cValue, pMob[conn].MOB.Equip[6].stEffect[2].cEffect, pMob[conn].MOB.Equip[6].stEffect[2].cValue);
		Log( temp, 0,  pUser[conn].IP);

			break;
		}

		SendSay(npcIndex, g_pMessageStringTable[_NN_Gather_7_Clistals]);
	} break;
#pragma endregion
#pragma region EXPLOIT_LEADER
	case EXPLOIT_LEADER:
	{
		if (pMob[conn].extra.QuestInfo.Mortal.TerraMistica == 0)
		{
			BASE_GetLanguage(temp, _NN_Guard_This_Village);
			SendSay(npcIndex, temp);
			break;
		}

		if (pMob[conn].extra.QuestInfo.Mortal.TerraMistica != 2)
		{
			BASE_GetLanguage(temp, _SN_All_Villagers_Thanks_Your, pMob[conn].MOB.MobName);
			SendSay(npcIndex, temp);
			break;
		}

		int _Level = pMob[conn].MOB.CurrentScore.Level;
		int _ItemID = 551;
		int _ItemType = 1;

		if (_Level >= 50)
		{
			if (_Level >= 80)
			{
				_ItemID = rand() % 4 + 559;
				_ItemType = 0;
			}
			else
			{
				_ItemID = rand() % 4 + 555;
				_ItemType = 1;
			}
		}
		else
		{
			_ItemID = rand() % 4 + 551;
			_ItemType = 1;
		}

		STRUCT_ITEM Item;
		memset(&Item, 0, sizeof(STRUCT_ITEM));

		Item.sIndex = _ItemID;

		int _rd = rand() % 10;

		int bonustype = g_pBonusType[_rd];

		int bonusvalue1 = g_pBonusValue[_rd][_ItemType][0];
		int bonusvalue2 = g_pBonusValue[_rd][_ItemType][1];
		int fvalue = bonusvalue2 + 1 - bonusvalue1;
		int tvalue = rand() % fvalue + bonusvalue1;

		Item.stEffect[0].cEffect = 43;

		for (int z = 1; z <= 2; ++z)
		{
			int rd_ = rand() % 8;

			if (rd_)
			{
				switch (rd_)
				{
				case 1:
					Item.stEffect[z].cEffect = 2;
					Item.stEffect[z].cValue = rand() % 21 + 5;
					break;

				case 2:
					Item.stEffect[z].cEffect = 26;
					Item.stEffect[z].cValue = rand() % 11 + 5;
					break;

				case 3:
					Item.stEffect[z].cEffect = 5;
					Item.stEffect[z].cValue = rand() % 51 + 20;
					break;

				case 4:
					Item.stEffect[z].cEffect = 60;
					Item.stEffect[z].cValue = rand() % 7 + 2;
					break;

				case 5:
					Item.stEffect[z].cEffect = 7;
					Item.stEffect[z].cValue = rand() % 16 + 5;
					break;

				case 6:
					Item.stEffect[z].cEffect = 8;
					Item.stEffect[z].cValue = rand() % 16 + 5;
					break;

				case 7:
					Item.stEffect[z].cEffect = 9;
					Item.stEffect[z].cValue = rand() % 16 + 5;
					break;
				}
			}
			else
			{
				Item.stEffect[z].cEffect = 4;
				Item.stEffect[z].cValue = rand() % 41 + 20;
			}
		}

		PutItem(conn, &Item);

		pMob[conn].extra.QuestInfo.Mortal.TerraMistica = 3;

		SendMsgExp(conn, g_pMessageStringTable[_NN_Watching_Town_Awarded], TNColor::Default, false);

		sprintf(temp, "etc,mystical_land complete %d-%d:%d:%d:%d:%d:%d name:%s conn:%d", Item.sIndex, Item.stEffect[0].cEffect, Item.stEffect[0].cValue, Item.stEffect[1].cEffect, Item.stEffect[1].cValue, Item.stEffect[2].cEffect, Item.stEffect[2].cValue, pMob[conn].MOB.MobName, conn);
	Log( temp, 0,  pUser[conn].IP);
	} break;
#pragma endregion
#pragma region MESTREHAB
	case MESTREHAB:
	{

		if (confirm == 0)
		{
			sprintf(temp, g_pMessageStringTable[_DN_Want_Stat_Init], StatSapphire);
			SendMsgExp(conn, temp, TNColor::Default, false);
		 
			return;
		}

		for (int i = 1; i < 8; i++)
		{
			if (pMob[conn].MOB.Equip[i].sIndex)
			{
				 
				sprintf(temp, g_pMessageStringTable[_NN_Cant_with_armor], StatSapphire);
				SendMsgExp(conn, temp, TNColor::Red, false);

				return;
			}
		}

		int NumSappInv = 0;

		int RetornoHab = 0;

		for (int i = 0; i < pMob[conn].MaxCarry; i++)
		{
			if (pMob[conn].MOB.Carry[i].sIndex == 697)
				NumSappInv++;

			else if (pMob[conn].MOB.Carry[i].sIndex == 4131)
				NumSappInv += 10;

			else if (pMob[conn].MOB.Carry[i].sIndex == 3336)
				RetornoHab = 1;
		}

		if (NumSappInv < StatSapphire && RetornoHab == 0)
		{ 
			sprintf(temp, g_pMessageStringTable[_DN_Need_D_Sapphire2], StatSapphire);
			SendMsgExp(conn, temp, TNColor::Red, false);

			return;
		}

		if (RetornoHab == 1)
		{
			for (int i = 0; i < pMob[conn].MaxCarry; i++)
			{
				if (pMob[conn].MOB.Carry[i].sIndex == 3336)
				{
					memset(&pMob[conn].MOB.Carry[i], 0, sizeof(STRUCT_ITEM));
					SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);

					break;
				}
			}

			goto DiretoReset;
		}
		if (NumSappInv > StatSapphire)
			NumSappInv = StatSapphire;

		for (int i = 0; i < pMob[conn].MaxCarry && NumSappInv > 0; i++)
		{
			if (pMob[conn].MOB.Carry[i].sIndex == 697)
			{
				memset(&pMob[conn].MOB.Carry[i], 0, sizeof(STRUCT_ITEM));
				SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);

				NumSappInv--;
			}

			else if (pMob[conn].MOB.Carry[i].sIndex == 4131 && NumSappInv >= 10)
			{
				memset(&pMob[conn].MOB.Carry[i], 0, sizeof(STRUCT_ITEM));
				SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);

				NumSappInv -= 10;
			}
		}
	DiretoReset:

		int cls = pMob[conn].MOB.Class;

		if (cls < 0 || cls > 3)
			return;

		int resetp = 100;
		int score = pMob[conn].MOB.ScoreBonus;
		int str = pMob[conn].MOB.BaseScore.Str - BaseSIDCHM[cls][0];
		int _int = pMob[conn].MOB.BaseScore.Int - BaseSIDCHM[cls][1];
		int dex = pMob[conn].MOB.BaseScore.Dex - BaseSIDCHM[cls][2];
		int con = pMob[conn].MOB.BaseScore.Con - BaseSIDCHM[cls][3];

		if (str <= resetp)
		{
			pMob[conn].MOB.BaseScore.Str -= str;
			score += str;
		}
		else
		{
			pMob[conn].MOB.BaseScore.Str -= resetp;
			score += resetp;
		}

		if (_int <= resetp)
		{
			pMob[conn].MOB.BaseScore.Int -= _int;
			score += _int;
		}
		else
		{
			pMob[conn].MOB.BaseScore.Int -= resetp;
			score += resetp;
		}

		if (dex <= resetp)
		{
			pMob[conn].MOB.BaseScore.Dex -= dex;
			score += dex;
		}

		else
		{
			pMob[conn].MOB.BaseScore.Dex -= resetp;
			score += resetp;
		}

		if (con <= resetp)
		{
			pMob[conn].MOB.BaseScore.Con -= con;
			score += con;
		}
		else
		{
			pMob[conn].MOB.BaseScore.Con -= resetp;
			score += resetp;
		}

		sprintf(temp, "etc,mestre_hab resetscore 100 name:%s conn:%d", pMob[conn].MOB.MobName, conn);
	Log( temp, 0,  pUser[conn].IP);

		BASE_GetBonusScorePoint(&pMob[conn].MOB, &pMob[conn].extra);
		BASE_GetHpMp(&pMob[conn].MOB, &pMob[conn].extra);

		SetAffect(conn, 44, 20, 20);

		SendScore(conn);
		SendEtc(conn);
		SendMsgExp(conn, "Pontos resetados.", TNColor::GreenYellow, false);

	} break;
#pragma endregion
#pragma region TREINADORNEWBIE1
	case TREINADORNEWBIE1:
	{
		if (pMob[conn].extra.ClassMaster != MORTAL || pMob[conn].MOB.CurrentScore.Level >= FREEEXP || pMob[conn].extra.QuestInfo.Mortal.Newbie != 0)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_NewbieQuest_Already1]);
			break;
		}
		int i = 0;

		for (i = 0; i < pMob[conn].MaxCarry; i++)
		{
			if (pMob[conn].MOB.Carry[i].sIndex == 451)
				break;
		}

		if (i == pMob[conn].MaxCarry)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_NewbieQuest_Cheerup1]);
			break;
		}
		sprintf(temp, "etc,newbiequest1 complete name:%s conn:%d", pMob[conn].MOB.MobName, conn);
	Log( temp, 0,  pUser[conn].IP);

		pMob[conn].extra.QuestInfo.Mortal.Newbie = 1;

		SendMsgExp(conn, g_pMessageStringTable[_NN_NewbieQuest_Reward1], TNColor::Default, false);

		STRUCT_ITEM Item;
		memset(&Item, 0, sizeof(STRUCT_ITEM));

		//Pot com 20
		Item.sIndex = 682;
		Item.stEffect[0].cEffect = 61;
		Item.stEffect[0].cValue = 20;

		PutItem(conn, &Item);

		SendScore(conn);
		SendCarry(conn);
	} break;
#pragma endregion
#pragma region TREINADORNEWBIE2
	case TREINADORNEWBIE2:
	{
		if (pMob[conn].extra.ClassMaster != MORTAL || pMob[conn].MOB.CurrentScore.Level >= FREEEXP || pMob[conn].extra.QuestInfo.Mortal.Newbie != 1)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_NewbieQuest_Already2]);
			break;
		}
		int i = 0;

		for (i = 0; i < pMob[conn].MaxCarry; i++)
		{
			if (pMob[conn].MOB.Carry[i].sIndex == 452)
				break;
		}

		if (i == pMob[conn].MaxCarry)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_NewbieQuest_Cheerup2]);
			break;
		}
		sprintf(temp, "etc,newbiequest2 complete name:%s conn:%d", pMob[conn].MOB.MobName, conn);
	Log( temp, 0,  pUser[conn].IP);

		pMob[conn].extra.QuestInfo.Mortal.Newbie++;

		SendMsgExp(conn, g_pMessageStringTable[_NN_NewbieQuest_Reward2], TNColor::Default, false);

		int WeaponId = pMob[conn].MOB.Equip[6].sIndex;
		int cls = pMob[conn].MOB.Class;

		if (WeaponId > 0 && WeaponId < MAX_ITEMLIST)
		{
			int ReqLv = g_pItemList[WeaponId].ReqLvl;

			if (ReqLv > 39)
				break;

			pMob[conn].MOB.Equip[6].stEffect[0].cEffect = 0;
			pMob[conn].MOB.Equip[6].stEffect[0].cValue = 0;
			pMob[conn].MOB.Equip[6].stEffect[1].cEffect = 0;
			pMob[conn].MOB.Equip[6].stEffect[1].cValue = 0;
			pMob[conn].MOB.Equip[6].stEffect[2].cEffect = 0;
			pMob[conn].MOB.Equip[6].stEffect[2].cValue = 0;

			SetItemBonus(&pMob[conn].MOB.Equip[6], 50 + ReqLv, 1, 0);
			SendItem(conn, ITEM_PLACE_EQUIP, 6, &pMob[conn].MOB.Equip[6]);
		}

		SendScore(conn);
		SendCarry(conn);
	} break;
#pragma endregion
#pragma region TREINADORNEWBIE3
	case TREINADORNEWBIE3:
	{
		if (pMob[conn].extra.ClassMaster != MORTAL || pMob[conn].MOB.CurrentScore.Level >= FREEEXP || pMob[conn].extra.QuestInfo.Mortal.Newbie != 2)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_NewbieQuest_Already3]);
			break;
		}
		int i = 0;

		for (i = 0; i < pMob[conn].MaxCarry; i++)
		{
			if (pMob[conn].MOB.Carry[i].sIndex == 453)
				break;
		}

		if (i == pMob[conn].MaxCarry)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_NewbieQuest_Cheerup3]);
			break;
		}
		sprintf(temp, "etc,newbiequest3 complete name:%s conn:%d", pMob[conn].MOB.MobName, conn);
	Log( temp, 0,  pUser[conn].IP);

		pMob[conn].extra.QuestInfo.Mortal.Newbie++;

		SendMsgExp(conn, g_pMessageStringTable[_NN_NewbieQuest_Reward3], TNColor::Default, false);

		for (int j = 1; j < 8; j++)
		{
			int itemId = pMob[conn].MOB.Equip[6].sIndex;

			if (itemId > 0 && itemId < MAX_ITEMLIST)
			{
				int ReqLv = g_pItemList[itemId].ReqLvl;

				pMob[conn].MOB.Equip[j].stEffect[0].cEffect = 0;
				pMob[conn].MOB.Equip[j].stEffect[0].cValue = 0;
				pMob[conn].MOB.Equip[j].stEffect[1].cEffect = 0;
				pMob[conn].MOB.Equip[j].stEffect[1].cValue = 0;
				pMob[conn].MOB.Equip[j].stEffect[2].cEffect = 0;
				pMob[conn].MOB.Equip[j].stEffect[2].cValue = 0;

				SetItemBonus(&pMob[conn].MOB.Equip[j], 50 + ReqLv, 1, 0);
				BASE_SetItemSanc(&pMob[conn].MOB.Equip[j], 3, 0);

				SendItem(conn, ITEM_PLACE_EQUIP, j, &pMob[conn].MOB.Equip[j]);
			}
		}
		SendScore(conn);
		SendCarry(conn);
	} break;
#pragma endregion
#pragma region CHEFE_DE_TREINO 
	case CHEFE_DE_TREINO:
	{
		int ItemReq = 524; //EMBLEMA DO ORC

		int i = 0;
		for (i = 0; i < pMob[conn].MaxCarry; i++)
		{
			if (pMob[conn].MOB.Carry[i].sIndex != ItemReq)
				continue;

			break;
		}

		int x = 0;
		int invfree = 0;

		for (x = 0; x < pMob[conn].MaxCarry; x++)
		{
			if (pMob[conn].MOB.Carry[x].sIndex == 0)
				invfree++;
		}

		if (invfree <= 0) //são 2 itens q recebe (coloca 0 no code), pq 1 é do próprio baú
		{
			SendMsgExp(conn, "Falta espaço no inventário.", TNColor::Red, false);
			return;
		}

		if (i != pMob[conn].MaxCarry)
		{
			int amount = BASE_GetItemAmount(&pMob[conn].MOB.Carry[i]);

			if (amount > 1)
				BASE_SetItemAmount(&pMob[conn].MOB.Carry[i], amount - 1);
			else

				BASE_ClearItem(&pMob[conn].MOB.Carry[i]);
			SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);

			STRUCT_ITEM Item;
			memset(&Item, 0, sizeof(STRUCT_ITEM));

			int _rd = rand() % 100;

			if (_rd < 25) //25%
			{
				Item.sIndex = 501; //Anel Iniciante
				Item.stEffect[0].cEffect = 43; //efeito REF
				Item.stEffect[0].cValue = 3; //valor
				Item.stEffect[1].cEffect = 2; //efeito DN
				Item.stEffect[1].cValue = 45; //valor
			}

			else if (_rd < 50) //25%
			{
				Item.sIndex = 505; //Anel Iniciante
				Item.stEffect[0].cEffect = 43; //efeito REF
				Item.stEffect[0].cValue = 3; //valor
				Item.stEffect[1].cEffect = 2; //efeito DN
				Item.stEffect[1].cValue = 45; //valo
			}
			else if (_rd < 75) //25%
			{
				Item.sIndex = 503; //Anel Iniciante
				Item.stEffect[0].cEffect = 43; //efeito REF
				Item.stEffect[0].cValue = 3; //valor
				Item.stEffect[1].cEffect = 60; //efeito MG
				Item.stEffect[1].cValue = 20; //valo
			}
			else //25%
			{
				Item.sIndex = 506; //Anel Iniciante
				Item.stEffect[0].cEffect = 43; //efeito REF
				Item.stEffect[0].cValue = 3; //valor
				Item.stEffect[1].cEffect = 60; //efeito MG
				Item.stEffect[1].cValue = 20; //valo
			}

			PutItem(conn, &Item);
			sprintf(temp, "etc,newbiequest4 complete name:%s conn:%d", pMob[conn].MOB.MobName, conn);
		Log( temp, 0,  pUser[conn].IP);
			sprintf(temp, g_pMessageStringTable[_SN_Item_Arrived], g_pItemList[Item.sIndex].Name);
			SendMsgExp(conn, temp, TNColor::Default, false);
			break;
		}

		sprintf(temp, g_pMessageStringTable[_SN_BRINGITEM], g_pItemList[ItemReq].Name);
		SendSay(npcIndex, temp);
	} break;
#pragma endregion
#pragma region COMP_SEPHI
	case COMP_SEPHI:
	{
		if (confirm == 0)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Soul_n_8_Sephera]);
			break;
		}
		int Pedras = 0;

		for (int j = 0; j < 8; j++)
		{
			for (int i = 0; i < pMob[conn].MaxCarry; i++)
			{
				if (pMob[conn].MOB.Carry[i].sIndex != (1744 + j))
					continue;

				Pedras++;
				break;
			}
		}

		if (Pedras < 8)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Need_8_Sephera]);
			break;
		}
		if (pMob[conn].MOB.Coin < 30000000)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Need_8_Sephera]);
			break;
		}

		pMob[conn].MOB.Coin -= 30000000;
		SendEtc(conn);

		for (int j = 0; j < 8; j++)
		{
			for (int i = 0; i < pMob[conn].MaxCarry; i++)
			{
				if (pMob[conn].MOB.Carry[i].sIndex != (1744 + j))
					continue;

				BASE_ClearItem(&pMob[conn].MOB.Carry[i]);
				SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);

				Pedras--;
				break;
			}
		}

		STRUCT_ITEM Item;

		memset(&Item, 0, sizeof(STRUCT_ITEM));


		if (pMob[npcIndex].MOB.Exp == 994)
			Item.sIndex = 1762;

		else if (pMob[npcIndex].MOB.Exp == 995)
			Item.sIndex = 1761;

		else if (pMob[npcIndex].MOB.Exp == 996)
			Item.sIndex = 1763;

		else if (pMob[npcIndex].MOB.Exp == 997)
			Item.sIndex = 1760;

		PutItem(conn, &Item);
		SendSay(npcIndex, g_pMessageStringTable[_NN_Sepherot_created]);

		sprintf(temp, "etc,sephirot create class:%d name:%s conn:%d", pMob[npcIndex].MOB.Exp, pMob[conn].MOB.MobName, conn);
	Log( temp, 0,  pUser[conn].IP);

	} break;
#pragma endregion
#pragma region CAPAVERDE_TELEPORT
	case CAPAVERDE_TELEPORT:
	{
		if (pMob[conn].extra.ClassMaster != MORTAL)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Level_Limit2]);
			break;
		}

		if (pMob[conn].MOB.CurrentScore.Level < 99 || pMob[conn].MOB.CurrentScore.Level >= 150)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Level_limit]);
			break;
		}

		DoTeleport(conn, 2245 + rand() % 5 - 3, 1576 + rand() % 5 - 3);

		sprintf(temp, "etc,quest_aprendiz1 npcteleport name:%s conn:%d", pMob[conn].MOB.MobName, conn);
	Log( temp, 0,  pUser[conn].IP);
	} break;
#pragma endregion
#pragma region CAPAVERDE_TRADE
	case CAPAVERDE_TRADE:
	{
		if (pMob[conn].extra.ClassMaster != MORTAL)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Level_Limit2]);
			break;
		}

		if (pMob[conn].MOB.CurrentScore.Level < 99 || pMob[conn].MOB.CurrentScore.Level >= 150)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Level_limit]);
			break;
		}

		if (pMob[conn].MOB.Equip[13].sIndex != 4080)
		{
			sprintf(temp, g_pMessageStringTable[_SN_WANTEQUIPITEM], g_pItemList[4080].Name);
			SendSay(npcIndex, temp);
			break;
		}

		if (pMob[conn].MOB.Equip[15].sIndex != 0)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Youve_Done_It_Already]);
			break;
		}

		sprintf(temp, "etc,quest_aprendiz2 complete name:%s conn:%d", pMob[conn].MOB.MobName, conn);
	Log( temp, 0,  pUser[conn].IP);

		BASE_ClearItem(&pMob[conn].MOB.Equip[13]);
		SendItem(conn, ITEM_PLACE_EQUIP, 13, &pMob[conn].MOB.Equip[13]);

		memset(&pMob[conn].MOB.Equip[15], 0, sizeof(STRUCT_ITEM));
		pMob[conn].MOB.Equip[15].sIndex = 4006;

		SendItem(conn, ITEM_PLACE_EQUIP, 15, &pMob[conn].MOB.Equip[15]);

		pMob[conn].GetCurrentScore(conn);
		SendScore(conn);

		SendEmotion(conn, 14, 3);

		sprintf(temp, g_pMessageStringTable[_DN_Play_Quest], "Formatura Aprendiz");
		SendMsgExp(conn, temp, TNColor::Default, false);
	} break;
#pragma endregion
#pragma region MOLARGARGULA
	case MOLARGARGULA:
	{
		if (pMob[conn].extra.ClassMaster != MORTAL)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Level_Limit2]);
			break;
		}

		if (pMob[conn].MOB.CurrentScore.Level < 199 || pMob[conn].MOB.CurrentScore.Level >= 254)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Level_limit]);
			break;
		}

		sprintf(temp, "etc,quest_molar1 npcteleport name:%s conn:%d", pMob[conn].MOB.MobName, conn);
	Log( temp, 0,  pUser[conn].IP);

		DoTeleport(conn, 817 + rand() % 5 - 3, 4062 + rand() % 5 - 3);
	} break;
#pragma endregion
#pragma region BLACKORACLE
	case BLACKORACLE:
	{
		int i = 0;

		for (i = 0; i < pMob[conn].MaxCarry; i++)
		{
			if (pMob[conn].MOB.Carry[i].sIndex == 1740)
				break;
		}

		if (i == pMob[conn].MaxCarry)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Set_Soul]);
			break;
		}

		if (pMob[conn].MOB.Carry[i + 1].sIndex != 1741)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Set_Soul]);
			break;
		}


		int NumSepInv = 0;
		int j = 0;

		for (j = 0; j < pMob[conn].MaxCarry; j++)
		{
			if (pMob[conn].MOB.Carry[j].sIndex == 697)
				NumSepInv++;

			else if (pMob[conn].MOB.Carry[j].sIndex == 4131)
				NumSepInv += 10;
		}

		if (NumSepInv < 10)
		{
			sprintf(temp, g_pMessageStringTable[_DN_Need_D_Sapphire], 10);
			SendSay(npcIndex, temp);
			break;
		}
		int Saphire = 10;

		for (j = 0; j < pMob[conn].MaxCarry && Saphire > 0; j++)
		{
			if (pMob[conn].MOB.Carry[j].sIndex == 697)
			{
				memset(&pMob[conn].MOB.Carry[j], 0, sizeof(STRUCT_ITEM));
				SendItem(conn, ITEM_PLACE_CARRY, j, &pMob[conn].MOB.Carry[j]);
				Saphire--;
			}

			else if (pMob[conn].MOB.Carry[j].sIndex == 4131)
			{
				memset(&pMob[conn].MOB.Carry[j], 0, sizeof(STRUCT_ITEM));
				SendItem(conn, ITEM_PLACE_CARRY, j, &pMob[conn].MOB.Carry[j]);

				if ((Saphire - 10) < 0)
					Saphire = 0;

				else
					Saphire -= 10;
			}
		}

		memset(&pMob[conn].MOB.Carry[i], 0, sizeof(STRUCT_ITEM));
		SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);

		memset(&pMob[conn].MOB.Carry[i + 1], 0, sizeof(STRUCT_ITEM));
		SendItem(conn, ITEM_PLACE_CARRY, i + 1, &pMob[conn].MOB.Carry[i + 1]);

		STRUCT_ITEM Item;
		memset(&Item, 0, sizeof(STRUCT_ITEM));

		Item.sIndex = 1742;

		PutItem(conn, &Item);

		sprintf(temp, "etc,stone_immortality create name:%s conn:%d", pMob[conn].MOB.MobName, conn);
	Log( temp, 0,  pUser[conn].IP);

	} break;
#pragma endregion
#pragma region QUEST_CAPAREAL
	case QUEST_CAPAREAL:
	{
		if (pMob[conn].extra.ClassMaster != MORTAL)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Level_Limit2]);
			break;
		}

		if (pMob[conn].MOB.CurrentScore.Level < 199 || pMob[conn].MOB.CurrentScore.Level >= 254)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Level_limit]);
			break;
		}

		DoTeleport(conn, 1740 + rand() % 5 - 3, 1725 + rand() % 5 - 3);

		sprintf(temp, "etc,questreal npcteleport name:%s conn:%d", pMob[conn].MOB.MobName, conn);
	Log( temp, 0,  pUser[conn].IP);
	} break;
#pragma endregion
#pragma region CARBUNCLE_WIND
	case CARBUNCLE_WIND:
	{
		if (pMob[conn].extra.ClassMaster != MORTAL)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Level_Limit2]);
			break;
		}

		/*if (pMob[conn].MOB.CurrentScore.Level >= 116)
		{
		SendSay(npcIndex, g_pMessageStringTable[_NN_Level_Limit2]);
		break;
		}*/
		SetAffect(conn, 41, 400, 1200);
		SetAffect(conn, 43, 400, 1200);
		SetAffect(conn, 44, 400, 1200);
		SetAffect(conn, 45, 400, 1200);


		pMob[conn].GetCurrentScore(conn);
		SendScore(conn);


		sprintf(temp, "sentindo-se mais forte %s?", pMob[conn].MOB.MobName);
		SendSay(npcIndex, temp);
		sprintf(temp, "etc,carbuncle buff name:%s conn:%d", pMob[conn].MOB.MobName, conn);
	Log( temp, 0,  pUser[conn].IP);
	} break;
#pragma endregion
#pragma region PERZEN
	case PERZEN:
	{
		int i = 0;

		for (i = 0; i < pMob[conn].MaxCarry; i++)
		{
			if (pMob[conn].MOB.Carry[i].sIndex != pMob[npcIndex].MOB.Carry[0].sIndex)
				continue;

			break;
		}

		if (i == pMob[conn].MaxCarry)
		{
			sprintf(temp, g_pMessageStringTable[_SN_BRINGITEM], g_pItemList[pMob[npcIndex].MOB.Carry[0].sIndex].Name);
			SendSay(npcIndex, temp);
			break;
		}

		BASE_ClearItem(&pMob[conn].MOB.Carry[i]);

		pMob[conn].MOB.Carry[i].sIndex = pMob[npcIndex].MOB.Carry[1].sIndex;

		BASE_SetItemDate(&pMob[conn].MOB.Carry[i], 30);

		SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);

		SendMsgExp(conn, "Você recebeu a sua troca.", TNColor::Default, false);
		sprintf(temp, "etc,premium mount started type:%d name:%s conn:%d", pMob[npcIndex].MOB.Carry[1].sIndex, pMob[conn].MOB.MobName, conn);
	Log( temp, 0,  pUser[conn].IP);
	} break;
#pragma endregion
#pragma region KIBITA
	case KIBITA:
	{
		if (pMob[conn].extra.Citizen == 0 && pMob[conn].MOB.Coin >= 4000000)
		{
			pMob[conn].MOB.Coin -= 4000000;
			pMob[conn].extra.Citizen = ServerIndex + 1;

			SendMsgExp(conn, g_pMessageStringTable[_DD_JOINTOWNPEP], TNColor::Default, false);
			int Guild = pMob[conn].MOB.Guild;

			if (Guild && pMob[conn].MOB.GuildLevel == 9)
			{
				MSG_GuildInfo sm_gi;
				memset(&sm_gi, 0, sizeof(MSG_GuildInfo));

				sm_gi.Type = _MSG_GuildInfo;
				sm_gi.Size = sizeof(MSG_GuildInfo);
				sm_gi.ID = conn;

				sm_gi.Guild = Guild;

				GuildInfo[Guild].Citizen = ServerIndex + 1;

				sm_gi.GuildInfo = GuildInfo[Guild];

				DBServerSocket.SendOneMessage((char*)&sm_gi, sizeof(MSG_GuildInfo));
			}

			sprintf(temp, "etc,set citizen server:%d name:%s a_iConn:%d", ServerIndex + 1, pMob[conn].MOB.MobName, conn);
		Log( temp, 0,  pUser[conn].IP);

			break;
		}

		struct tm when;
		time_t now;
		time(&now);
		when = *localtime(&now);
		//horário soul kibita buff
		if (when.tm_wday != 0 && when.tm_wday != 6 && when.tm_hour == 21 && pMob[conn].extra.ClassMaster == MORTAL && pMob[conn].MOB.CurrentScore.Level < 369)
		{
			int i = 0;

			for (i = 0; i < pMob[conn].MaxCarry; i++)
			{
				if (pMob[conn].MOB.Carry[i].sIndex != 420)
					continue;

				break;
			}

			if (i != pMob[conn].MaxCarry)
			{
				BASE_ClearItem(&pMob[conn].MOB.Carry[i]);
				SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);

				SendMsgExp(conn, g_pMessageStringTable[_DN_TOWN_SOUL_BUFF], TNColor::Default, false);
				int sAffect = GetEmptyAffect(conn, 29);

				if (sAffect == -1)
					return;


				pMob[conn].Affect[sAffect].Type = 29;
				pMob[conn].Affect[sAffect].Level = 0;
				pMob[conn].Affect[sAffect].Value = 0;
				pMob[conn].Affect[sAffect].Time = AFFECT_1H;

				pMob[conn].GetCurrentScore(conn);
				SendScore(conn);

				DoTeleport(conn, 2454 + rand() % 3, 1843 + rand() % 3);

				sprintf(temp, "etc,learned limit of soul mortal name:%s a_iConn:%d", pMob[conn].MOB.MobName, conn);
			Log( temp, 0,  pUser[conn].IP);
				break;
			}

			else
			{
				SendMsgExp(conn, g_pMessageStringTable[_DN_TOWN_SOUL_NOBUFF], TNColor::Default, false);
				break;
			}
		}

		if (pMob[conn].extra.ClassMaster == MORTAL && (pMob[conn].MOB.LearnedSkill & (1 << 30)) == 0 && pMob[conn].MOB.CurrentScore.Level >= 369)
		{
			int i = 0;

			int stones[4] = { 5334, 5336, 5335, 5337 };

			for (i = 0; i < pMob[conn].MaxCarry; i++)
			{
				if (pMob[conn].MOB.Carry[i].sIndex != stones[pMob[conn].MOB.Class])
					continue;

				break;
			}

			if (i != pMob[conn].MaxCarry)
			{
				BASE_ClearItem(&pMob[conn].MOB.Carry[i]);
				SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);

				pMob[conn].MOB.LearnedSkill |= 1 << 30;

				memset(&pMob[conn].MOB.Equip[15], 0, sizeof(STRUCT_ITEM));

				if (pMob[conn].MOB.Clan == 7)
					pMob[conn].MOB.Equip[15].sIndex = 3194;

				else if (pMob[conn].MOB.Clan == 8)
					pMob[conn].MOB.Equip[15].sIndex = 3195;

				else
					pMob[conn].MOB.Equip[15].sIndex = 3196;

				SendItem(conn, ITEM_PLACE_EQUIP, 15, &pMob[conn].MOB.Equip[15]);

				CharLogOut(conn);

				sprintf(temp, "etc,learned limit of soul mortal name:%s conn:%d", pMob[conn].MOB.MobName, conn);
			Log( temp, 0,  pUser[conn].IP);

				SendClientSignalParm(conn, ESCENE_FIELD, _MSG_SendArchEffect, pUser[conn].Slot);
				break;
			}
		}

		SendMsgExp(conn, g_pMessageStringTable[_DN_TOWN_SORRY], TNColor::Default, false);
	} break;
#pragma endregion
#pragma region GODGOVERNMENT
	case GODGOVERNMENT:
	{
		int curkill = GetCurKill(conn);
		int PKPoint = GetPKPoint(conn);

		if (curkill >= 100)
		{
			PKPoint += 20;

			if (PKPoint >= 150)
				PKPoint = 150;

			SetCurKill(conn, curkill - 100);
			SetPKPoint(conn, PKPoint);

			sprintf(temp, "etc,resetpk curpk:%d name:%s conn:%d", PKPoint, pMob[conn].MOB.MobName, conn);
		Log( temp, 0,  pUser[conn].IP);


			MSG_CreateMob sm_rpk;
			memset(&sm_rpk, 0, sizeof(MSG_CreateMob));
			GetCreateMob(conn, &sm_rpk);

			GridMulticast(pMob[conn].TargetX, pMob[conn].TargetY, (MSG_STANDARD*)&sm_rpk, 0);

			SendEmotion(conn, 14, 3);
			break;
		}

		SendSay(npcIndex, g_pMessageStringTable[_NN_MOREKILLPOINT]);
	} break;
#pragma endregion
#pragma region SOBREVIVENTE
	case SOBREVIVENTE:
	{
		int i = 0;
		for (i = 0; i < pMob[conn].MaxCarry; i++)
		{
			if (pMob[conn].MOB.Carry[i].sIndex != 4127)
				continue;

			break;
		}

		if (i != pMob[conn].MaxCarry)
		{
			BASE_ClearItem(&pMob[conn].MOB.Carry[i]);
			SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);

			pMob[conn].extra.KefraTicket += 100;

			sprintf(temp, "etc,kefraticket ticket:%d name:%s conn:%d", pMob[conn].extra.KefraTicket, pMob[conn].MOB.MobName, conn);
		Log( temp, 0,  pUser[conn].IP);

			sprintf(temp, g_pMessageStringTable[_DN_CHANGE_COUNT], pMob[conn].extra.KefraTicket);
			SendMsgExp(conn, temp, TNColor::Default, false);
		}

	} break;
#pragma endregion
#pragma region LIDER_APRENDIZ
	case LIDER_APRENDIZ:
	{
		if (pMob[conn].extra.ClassMaster != ARCH)
		{
			sprintf(temp, g_pMessageStringTable[_SN_NEEDCLASS], "Arch");
			SendSay(npcIndex, temp);
			break;
		}

		if (pMob[conn].MOB.BaseScore.Level < 99 || pMob[conn].MOB.BaseScore.Level > 149)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Level_Limit2]);
			break;
		}

		if (pMob[conn].MOB.Equip[15].sIndex)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Youve_Done_It_Already]);
			break;
		}

		sprintf(temp, "etc,quest_aprendiz_arch complete name:%s conn:%d", pMob[conn].MOB.MobName, conn);
	Log( temp, 0,  pUser[conn].IP);

		memset(&pMob[conn].MOB.Equip[15], 0, sizeof(STRUCT_ITEM));
		pMob[conn].MOB.Equip[15].sIndex = 4006;

		SendItem(conn, ITEM_PLACE_EQUIP, 15, &pMob[conn].MOB.Equip[15]);

		pMob[conn].GetCurrentScore(conn);
		SendScore(conn);

		SendEmotion(conn, 14, 3);

		sprintf(temp, g_pMessageStringTable[_DN_Play_Quest], "Formatura Aprendiz");

		SendMsgExp(conn, temp, TNColor::Default, false);
	} break;
#pragma endregion
#pragma region MESTREGRIFO
	case MESTREGRIFO:
	{
		if (pMob[conn].MOB.BaseScore.Level < 39)
		{
			SendMsgExp(conn, "Chegou no destino [Campo do Treino].", TNColor::Default, false);
			DoTeleport(conn, 2115, 2043);
			return;
		}
		else if (pMob[conn].MOB.BaseScore.Level >= 39 && pMob[conn].MOB.BaseScore.Level <= 114)
		{
			SendMsgExp(conn, "Chegou no destino [Defensor da Alma].", TNColor::Default, false);
			DoTeleport(conn, 2372, 2103);
			return;
		}

		else if (pMob[conn].MOB.BaseScore.Level >= 115 && pMob[conn].MOB.BaseScore.Level <= 189)
		{

			SendMsgExp(conn, "Chegou no destino [Jardim dos Deuses].", TNColor::Default, false);
			DoTeleport(conn, 2220, 1714);
			return;
		}
		else if (pMob[conn].MOB.BaseScore.Level >= 190 && pMob[conn].MOB.BaseScore.Level <= 264)
		{

			SendMsgExp(conn, "Chegou no destino [Ressu. Cav. Negro].", TNColor::Default, false);
			DoTeleport(conn, 450, 3912);
			return;
		}
		else if (pMob[conn].MOB.BaseScore.Level >= 265 && pMob[conn].MOB.BaseScore.Level <= 319)
		{

			SendMsgExp(conn, "Chegou no destino [Hidra Imortal].", TNColor::Default, false);
			DoTeleport(conn, 669, 3771);
			return;
		}
		else if (pMob[conn].MOB.BaseScore.Level >= 320 && pMob[conn].MOB.BaseScore.Level <= 349)
		{

			SendMsgExp(conn, "Chegou no destino [Inicio da Infelicidade].", TNColor::Default, false);
			DoTeleport(conn, 1301, 4038);
			return;
		}
		else if (pMob[conn].MOB.BaseScore.Level >= 350)
		{
			SendSay(npcIndex, "Não há quest disponivel para você ..");
			return;
		}
	}
#pragma endregion

#pragma region GUARDA_REAL_I
	case GUARDA_REAL_I:
	{
		/*[01] Poeira de lac
		[02]Poeira de ori
		[01] Barra de 1kk
		[01]Bau II*/

		int ItemReq = 475; //ENTREGA BAU I

		int i = 0;
		for (i = 0; i < pMob[conn].MaxCarry; i++)
		{
			if (pMob[conn].MOB.Carry[i].sIndex != ItemReq)
				continue;

			break;
		}

		if (i != pMob[conn].MaxCarry)
		{
			BASE_ClearItem(&pMob[conn].MOB.Carry[i]);
			SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);

			STRUCT_ITEM Item;
			memset(&Item, 0, sizeof(STRUCT_ITEM));

			int _rd = rand() % 100;





			if (_rd < 35)
			{
				Item.sIndex = 4150; //p;o
				Item.stEffect[0].cEffect = 0; //amount
				Item.stEffect[0].cValue = 0; //quantidade
			}


			else if (_rd < 55)
			{
				Item.sIndex = 4151; //1kk
				Item.stEffect[0].cEffect = 0; //amount
				Item.stEffect[0].cValue = 0; //quantidade
			}


			else if (_rd < 75)
			{
				Item.sIndex = 4152; //pl
				Item.stEffect[0].cEffect = 0; //amount
				Item.stEffect[0].cValue = 0; //quantidade
			}

			else if (_rd < 85)
			{
				Item.sIndex = 4153; //bau II
				Item.stEffect[0].cEffect = 0; //amount
				Item.stEffect[0].cValue = 0; //quantidade
			}

			else
			{
				Item.sIndex = 476; //Báu II


			}


			PutItem(conn, &Item);

			sprintf(temp, g_pMessageStringTable[_SN_Item_Arrived], g_pItemList[Item.sIndex].Name);

			SendMsgExp(conn, temp, TNColor::Orange, false);
			break;
		}

		sprintf(temp, g_pMessageStringTable[_SN_BRINGITEM], g_pItemList[ItemReq].Name);
		SendSay(npcIndex, temp);
	} break;
#pragma endregion




#pragma region GUARDA_REAL_II
	case GUARDA_REAL_II:
	{
		int ItemReq = 476; //ENTREGA BAU II

		int i = 0;
		for (i = 0; i < pMob[conn].MaxCarry; i++)
		{
			if (pMob[conn].MOB.Carry[i].sIndex != ItemReq)
				continue;

			break;
		}

		if (i != pMob[conn].MaxCarry)
		{
			BASE_ClearItem(&pMob[conn].MOB.Carry[i]);
			SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);

			STRUCT_ITEM Item;
			memset(&Item, 0, sizeof(STRUCT_ITEM));

			int _rd = rand() % 100;



			/*[03] Classe E
			[02]Amagos de fenrir
			[01] Barra de 2kk
			[01]Bau III*/


			if (_rd < 35)
			{
				Item.sIndex = 4154; //classe e
				Item.stEffect[0].cEffect = 61; //amount
				Item.stEffect[0].cValue = 3; //quantidade
			}


			else if (_rd < 55)
			{
				Item.sIndex = 4155; //amago de fenrir
				Item.stEffect[0].cEffect = 61; //amount
				Item.stEffect[0].cValue = 2; //quantidade
			}


			else if (_rd < 75)
			{
				Item.sIndex = 4190; //barra de 2kk
				Item.stEffect[0].cEffect = 61; //amount
				Item.stEffect[0].cValue = 2; //quantidade
			}

			else if (_rd < 85)
			{
				Item.sIndex = 4191; //Báu III
				Item.stEffect[0].cEffect = 0; //amount
				Item.stEffect[0].cValue = 0; //quantidade
			}

			else
			{
				Item.sIndex = 480; //Báu III


			}


			PutItem(conn, &Item);

			sprintf(temp, g_pMessageStringTable[_SN_Item_Arrived], g_pItemList[Item.sIndex].Name);

			SendMsgExp(conn, temp, TNColor::Orange, false);
			break;
		}

		sprintf(temp, g_pMessageStringTable[_SN_BRINGITEM], g_pItemList[ItemReq].Name);
		SendSay(npcIndex, temp);
	} break;
#pragma endregion
#pragma region GUARDA_REAL_III
	case GUARDA_REAL_III:
	{
		int ItemReq = 480; //ENTREGA BAU III

		int i = 0;
		for (i = 0; i < pMob[conn].MaxCarry; i++)
		{
			if (pMob[conn].MOB.Carry[i].sIndex != ItemReq)
				continue;

			break;
		}

		if (i != pMob[conn].MaxCarry)
		{
			BASE_ClearItem(&pMob[conn].MOB.Carry[i]);
			SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);

			STRUCT_ITEM Item;
			memset(&Item, 0, sizeof(STRUCT_ITEM));

			int _rd = rand() % 100;



			/*	[01] Bau Xp
			[01]Frango Assado
			[01] Barra de 5kk
			[01]Ovo de Fenrir*/



			if (_rd < 35)
			{
				Item.sIndex = 4140; //bau xp

			}


			else if (_rd < 55)
			{
				Item.sIndex = 4192; //barra de 5kk
				Item.stEffect[1].cEffect = 0; //magia
				Item.stEffect[1].cValue = 0; //valor
				Item.stEffect[2].cEffect = 0;
				Item.stEffect[2].cValue = 0;
			}


			else if (_rd < 75)
			{
				Item.sIndex = 4193; //frango
				Item.stEffect[0].cEffect = 0; //amount
				Item.stEffect[0].cValue = 0; //quantidade
			}

			else if (_rd < 4194)
			{
				Item.sIndex = 2316; //ovo de fenrir
				Item.stEffect[0].cEffect = 0; //amount
				Item.stEffect[0].cValue = 0; //quantidade
			}

			else
			{
				Item.sIndex = 482; //BAU IV
				Item.stEffect[0].cEffect = 0; //amount
				Item.stEffect[0].cValue = 0; //quantidade


			}


			PutItem(conn, &Item);

			sprintf(temp, g_pMessageStringTable[_SN_Item_Arrived], g_pItemList[Item.sIndex].Name);

			SendMsgExp(conn, temp, TNColor::Orange, false);
			break;
		}

		sprintf(temp, g_pMessageStringTable[_SN_BRINGITEM], g_pItemList[ItemReq].Name);
		SendSay(npcIndex, temp);
	} break;
#pragma endregion
#pragma region GUARDA_REAL_IV
	case GUARDA_REAL_IV:
	{
		int ItemReq = 482; //ENTREGA BAU IV

		int i = 0;
		for (i = 0; i < pMob[conn].MaxCarry; i++)
		{
			if (pMob[conn].MOB.Carry[i].sIndex != ItemReq)
				continue;

			break;
		}

		if (i != pMob[conn].MaxCarry)
		{
			BASE_ClearItem(&pMob[conn].MOB.Carry[i]);
			SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);

			STRUCT_ITEM Item;
			memset(&Item, 0, sizeof(STRUCT_ITEM));

			int _rd = rand() % 100;



			/*	[01]Ovo de Equipe n
			[01]Ovo de Equipe B
			[03]Amago de Equipe N
			[03]Amago de Equipe B*/


			if (_rd < 25)
			{
				Item.sIndex = 2327; //[OVO DE Equipe B
				//Item.stEffect[0].cEffect = 43; //dano
				//Item.stEffect[0].cValue = 235; //valor
				Item.stEffect[1].cEffect = 0; //dano
				Item.stEffect[1].cValue = 0; //valor
				Item.stEffect[2].cEffect = 0;
				Item.stEffect[2].cValue = 0;

			}

			else if (_rd < 25)
			{
				Item.sIndex = 2328; // ovo de Equipe n
				//Item.stEffect[0].cEffect = 43; //
				//Item.stEffect[0].cValue = 235; //
				Item.stEffect[1].cEffect = 0; //dano
				Item.stEffect[1].cValue = 0; //valor
				Item.stEffect[2].cEffect = 0;
				Item.stEffect[2].cValue = 0;

			}

			else if (_rd < 15)
			{
				Item.sIndex = 2417; //amago de Equipe N
				Item.stEffect[1].cEffect = 61;
				Item.stEffect[1].cValue = 3; //
				Item.stEffect[2].cEffect = 0;
				Item.stEffect[2].cValue = 0;
			}

			else if (_rd < 15)
			{
				Item.sIndex = 2418; //AMAGO DE ANDA B
				Item.stEffect[0].cEffect = 61; //amount
				Item.stEffect[0].cValue = 3; //quantidade
			}

			else if (_rd < 10)
			{
				Item.sIndex = 486; //AMAGO DE ANDA B
				Item.stEffect[0].cEffect = 61; //amount
				Item.stEffect[0].cValue = 3; //quantidade
			}



			//else if (_rd < 70)
			//{
			// Item.sIndex = 633; //    [01]ABS 10MG / 20MP
			// //Item.stEffect[0].cEffect = 43; //dano
			// //Item.stEffect[0].cValue = 235; //valor
			// Item.stEffect[1].cEffect = 60; //dano
			// Item.stEffect[1].cValue = 10; //valor
			// Item.stEffect[2].cEffect = 70;
			// Item.stEffect[2].cValue = 20;
			//
			//}



			PutItem(conn, &Item);

			sprintf(temp, g_pMessageStringTable[_SN_Item_Arrived], g_pItemList[Item.sIndex].Name);

			SendMsgExp(conn, temp, TNColor::Orange, false);
			break;
		}

		sprintf(temp, g_pMessageStringTable[_SN_BRINGITEM], g_pItemList[ItemReq].Name);
		SendSay(npcIndex, temp);
	} break;
#pragma endregion




#pragma region GUARDA_REAL_V
	case GUARDA_REAL_V:
	{
		int ItemReq = 486; //ENTREGA BAU IV

		int i = 0;
		for (i = 0; i < pMob[conn].MaxCarry; i++)
		{
			if (pMob[conn].MOB.Carry[i].sIndex != ItemReq)
				continue;

			break;
		}

		if (i != pMob[conn].MaxCarry)
		{
			BASE_ClearItem(&pMob[conn].MOB.Carry[i]);
			SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);

			STRUCT_ITEM Item;
			memset(&Item, 0, sizeof(STRUCT_ITEM));

			int _rd = rand() % 100;



			/*	[01]Ovo de Equipe n
			[01]Ovo de Equipe B
			[03]Amago de Equipe N
			[03]Amago de Equipe B*/


			if (_rd < 25)
			{
				Item.sIndex = 2319; //[OVO DE Equipe B
				//Item.stEffect[0].cEffect = 43; //dano
				//Item.stEffect[0].cValue = 235; //valor
				Item.stEffect[1].cEffect = 0; //dano
				Item.stEffect[1].cValue = 0; //valor
				Item.stEffect[2].cEffect = 0;
				Item.stEffect[2].cValue = 0;

			}

			else if (_rd < 25)
			{
				Item.sIndex = 2320; // ovo de Equipe n
				//Item.stEffect[0].cEffect = 43; //
				//Item.stEffect[0].cValue = 235; //
				Item.stEffect[1].cEffect = 0; //dano
				Item.stEffect[1].cValue = 0; //valor
				Item.stEffect[2].cEffect = 0;
				Item.stEffect[2].cValue = 0;

			}

			else if (_rd < 15)
			{
				Item.sIndex = 2409; //amago de Equipe N
				Item.stEffect[1].cEffect = 61;
				Item.stEffect[1].cValue = 3; //
				Item.stEffect[2].cEffect = 0;
				Item.stEffect[2].cValue = 0;
			}

			else if (_rd < 15)
			{
				Item.sIndex = 2418; //AMAGO DE ANDA B
				Item.stEffect[0].cEffect = 61; //amount
				Item.stEffect[0].cValue = 3; //quantidade
			}



			//else if (_rd < 70)
			//{
			// Item.sIndex = 633; //    [01]ABS 10MG / 20MP
			// //Item.stEffect[0].cEffect = 43; //dano
			// //Item.stEffect[0].cValue = 235; //valor
			// Item.stEffect[1].cEffect = 60; //dano
			// Item.stEffect[1].cValue = 10; //valor
			// Item.stEffect[2].cEffect = 70;
			// Item.stEffect[2].cValue = 20;
			//
			//}


			

			PutItem(conn, &Item);

			sprintf(temp, g_pMessageStringTable[_SN_Item_Arrived], g_pItemList[Item.sIndex].Name);

			SendMsgExp(conn, temp, TNColor::Orange, false);
			break;
		}

		sprintf(temp, g_pMessageStringTable[_SN_BRINGITEM], g_pItemList[ItemReq].Name);
		SendSay(npcIndex, temp);
	} break;
#pragma endregion
#pragma region BATALHA REAL
	case BATALHA_REAL:
	{  
		try
		{
			time_t rawnow = time(NULL);
			struct tm now;
			localtime_s(&now, &rawnow);

			for (int i = 0; i < 20; i++) // i = maximo de player na batalha = 20
			{
				if (p_BatalhaReal.Members[i].Id == conn && strcmp(p_BatalhaReal.Members[i].Name, pMob[conn].MOB.MobName) == 0 && p_BatalhaReal.start == false)
				{
					SendSay(npcIndex, strFmt("Aguarde [%d] minutos para o início da batalha.", 10 - now.tm_min));
					return;
				}

			}

			if (pMob[conn].Leader || pMob[conn].Leader == -1)
			{
				SendClientMessage(conn, "Não é permitido registro em grupo.");
				return;
			}

			if (now.tm_wday > 0 && now.tm_wday < 6)
			{
				if (now.tm_hour == BatalhaRealHour && now.tm_min <= 9)
				{
					if (p_BatalhaReal.NumMembers < 20)
					{
						p_BatalhaReal.NumMembers += 1;
						//p_BatalhaReal.Members[conn].Id += 1;
						SendSay(npcIndex, strFmt("%s registrou-se na Batalha Real.", pMob[conn].MOB.MobName));

						int Num;

						for (Num = 0; Num < 20; Num++)//Numero de Vagas Disponiveis
						{
							if (p_BatalhaReal.Members[Num].Id == 0x0)
							{
								p_BatalhaReal.Members[Num].Id = conn;
								memcpy(&p_BatalhaReal.Members[Num].Name, &pMob[conn].MOB.MobName, 16);
								break;
							}
						}
						return;
					}
					else
					{
						SendSay(npcIndex, "Limite de jogadores foi atingido. Desculpe.");
						return;
					}
				}
				else
				{
					SendSay(npcIndex, "O registro é permitido as 17horas.");
					return;
				}

			}
			else
			{
				SendSay(npcIndex, "Não é possível batalhar nos fins de semana.");
				return;
			}
		}
		catch (...)
		{

		}
	}
	break;
#pragma endregion
#pragma region EVENTO DROP
	case EVENTO_DROP:
	{
		if (pMob[conn].MOB.Equip[13].sIndex != 3905)
		{
			SendSay(npcIndex, "Desculpe. Para teleportar é preciso equipar a Fada VIP.");
			break;
		}

		DoTeleport(conn, 1321 + rand() % 5 - 3, 1498 + rand() % 5 - 3);

		sprintf(temp, "etc,evento area drop name:%s level:%d", pMob[conn].MOB.MobName, pMob[conn].MOB.BaseScore.Level);
	Log( temp, 0,  pUser[conn].IP);
	} break;
#pragma endregion
#pragma region CURANDEIRA
	case CURANDEIRA:
	{
		if (pMob[conn].MOB.Coin < 50000)
		{
			SendSay(npcIndex, "Você precisa de 50,000 mil de gold para curar seu HP e MP.");
			break;
		}

		pMob[conn].MOB.CurrentScore.Hp = pMob[conn].MOB.CurrentScore.MaxHp;
		pMob[conn].GetCurrentScore(conn);
		SendScore(conn);

		pMob[conn].MOB.CurrentScore.Mp = pMob[conn].MOB.CurrentScore.MaxMp;
		pMob[conn].GetCurrentScore(conn);
		SendScore(conn);

		pMob[conn].MOB.Coin -= 50000;
		SendEtc(conn);

		SendSay(npcIndex, "Seu custo foi de 50,000 mil de gold. Seu HP e MP foram curados.");

	} break;
#pragma endregion
#pragma region Upador
	case UPADOR:
	{
		/*if (pMob[conn].extra.ClassMaster >= ARCH)
		{
		SendClientMessage(conn, "Apenas a classe Mortal poderá receber o nível máximo.");
		return;
		}

		if (pMob[conn].MOB.CurrentScore.Level == MAX_LEVEL)
		{
		SendClientMessage(conn, "Você já está com o nível máximo da classe");
		return;
		}

		if (pMob[conn].extra.ClassMaster == MORTAL)
		{
		pMob[conn].MOB.BaseScore.Level = MAX_LEVEL;
		pMob[conn].MOB.Exp = 4020000000;

		pMob[conn].MOB.BaseScore.Str = BaseSIDCHM[pMob[conn].MOB.Class][0];
		pMob[conn].MOB.BaseScore.Int = BaseSIDCHM[pMob[conn].MOB.Class][1];
		pMob[conn].MOB.BaseScore.Dex = BaseSIDCHM[pMob[conn].MOB.Class][2];
		pMob[conn].MOB.BaseScore.Con = BaseSIDCHM[pMob[conn].MOB.Class][3];

		pMob[conn].MOB.BaseScore.Special[0] = 0;
		pMob[conn].MOB.BaseScore.Special[1] = 0;
		pMob[conn].MOB.BaseScore.Special[2] = 0;
		pMob[conn].MOB.BaseScore.Special[3] = 0;

		pMob[conn].MOB.BaseScore.Ac = 900;
		pMob[conn].MOB.BaseScore.Damage = 900;
		pMob[conn].MOB.BaseScore.Hp = BaseSIDCHM[pMob[conn].MOB.Class][4];
		pMob[conn].MOB.BaseScore.MaxHp = BaseSIDCHM[pMob[conn].MOB.Class][4];
		pMob[conn].MOB.BaseScore.Mp = BaseSIDCHM[pMob[conn].MOB.Class][5];
		pMob[conn].MOB.BaseScore.MaxMp = BaseSIDCHM[pMob[conn].MOB.Class][5];

		pMob[conn].MOB.SpecialBonus = 855;

		SendEtc(conn);

		CharLogOut(conn);

		SendClientSignalParm(conn, ESCENE_FIELD, _MSG_SendArchEffect, pUser[conn].Slot);


		}*/


	}break;
#pragma endregion
#pragma region KRUNO
	case KRUNO:
	{
		if (pMob[conn].extra.ClassMaster != MORTAL)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Level_Limit2]);
			break;
		}

		int minlevel = pMob[conn].extra.ClassMaster == MORTAL ? 69 : 69;
		int maxlevel = pMob[conn].extra.ClassMaster == MORTAL ? 74 : 74;

		int ItemReq = 4123; //PEDAÇO DE CHANCE

		int i = 0;
		for (i = 0; i < pMob[conn].MaxCarry; i++)
		{
			if (pMob[conn].MOB.Carry[i].sIndex != ItemReq)
				continue;
			break;
		}
		if (i != pMob[conn].MaxCarry)
		{
			BASE_ClearItem(&pMob[conn].MOB.Carry[i]);
			SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);
			STRUCT_ITEM Item;
			memset(&Item, 0, sizeof(STRUCT_ITEM));


			Item.sIndex = 4124; //COMPOSTO DE CHANCE

			PutItem(conn, &Item);

			sprintf(temp, g_pMessageStringTable[_SN_Item_Arrived], g_pItemList[Item.sIndex].Name);
			SendSay(npcIndex, temp);
			break;
		}
		sprintf(temp, "etc,questkruno ticket chance name:%s level:%d", pMob[conn].MOB.MobName, pMob[conn].MOB.BaseScore.Level);
	Log( temp, 0,  pUser[conn].IP);
		sprintf(temp, g_pMessageStringTable[_SN_BRINGITEM], g_pItemList[ItemReq].Name);
		SendSay(npcIndex, temp);
	} break;
#pragma endregion

#pragma region QUEST_EQUILIBRIO
	case QUEST_EQUILIBRIO:
	{
		if (pMob[conn].extra.ClassMaster != MORTAL)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Level_limit]);
			break;
		}

		int minlevel = pMob[conn].extra.ClassMaster == MORTAL ? 119 : 119;
		int maxlevel = pMob[conn].extra.ClassMaster == MORTAL ? 124 : 124;
		 
		SendSay(npcIndex, "Que você consiga sua salvação.");
		DoTeleport(conn, 1961 + rand() % 5 - 3, 1593 + rand() % 5 - 3);
		sprintf(temp, "etc,QUEST EQUILIBRIO ticket chance name:%s level:%d", pMob[conn].MOB.MobName, pMob[conn].MOB.BaseScore.Level);
		Log(temp, 0, pUser[conn].IP); 
	} break;
#pragma endregion 

#pragma region AMELIA
	case AMELIA:
	{
		if (pMob[conn].extra.ClassMaster != MORTAL)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Level_Limit2]);
			break;
		}

		int minlevel = pMob[conn].extra.ClassMaster == MORTAL ? 119 : 119;
		int maxlevel = pMob[conn].extra.ClassMaster == MORTAL ? 124 : 124;

		if (pMob[conn].MOB.CurrentScore.Level < minlevel || pMob[conn].MOB.CurrentScore.Level >= maxlevel)
		{
			SendSay(npcIndex, g_pMessageStringTable[_NN_Level_limit]);
			break;
		}

		int ItemReq = 4125; //PEDAÇO DE EQUILIBIRO

		int i = 0;
		for (i = 0; i < pMob[conn].MaxCarry; i++)
		{
			if (pMob[conn].MOB.Carry[i].sIndex != ItemReq)
				continue;
			break;
		}
		if (i != pMob[conn].MaxCarry)
		{
			BASE_ClearItem(&pMob[conn].MOB.Carry[i]);
			SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);
			STRUCT_ITEM Item;
			memset(&Item, 0, sizeof(STRUCT_ITEM));


			Item.sIndex = 4126; //COMPOSTO DE EQUILIBRIO
			PutItem(conn, &Item);

			sprintf(temp, g_pMessageStringTable[_SN_Item_Arrived], g_pItemList[Item.sIndex].Name);
			SendSay(npcIndex, temp);
			break;
		}
		sprintf(temp, "etc,questamelia ticket chance name:%s level:%d", pMob[conn].MOB.MobName, pMob[conn].MOB.BaseScore.Level);
		Log( temp, 0,  pUser[conn].IP);
		sprintf(temp, g_pMessageStringTable[_SN_BRINGITEM], g_pItemList[ItemReq].Name);
		SendSay(npcIndex, temp);
	} break;
#pragma endregion
#pragma region JULIARZAN
	case JULIARZAN:
	{

		if (pMob[conn].MOB.Coin < 50000)
		{
			SendSay(npcIndex, "Você precisa de 50,000 mil");
			break;
		}
		SendSay(npcIndex, "Foi teletransportado para Karden!");
		DoTeleport(conn, 3652, 3134);
		pMob[conn].MOB.Coin -= 50000;
		SendEtc(conn);
	} break;
#pragma endregion
#pragma region JULIGELO
	case JULIGELO:
	{

		if (pMob[conn].MOB.Coin < 50000)
		{
			SendSay(npcIndex, "Você precisa de 50,000 mil de gold");
			break;
		}
		SendSay(npcIndex, "Foi teletransportado para Arzan!");
		DoTeleport(conn, 2480, 1649);
		pMob[conn].MOB.Coin -= 50000;
		SendEtc(conn);
	} break;
#pragma endregion

#pragma region XAMACOLISEU
	//case XAMACOLISEU:
	//{
	//	struct tm when;
	//	time_t now;
	//	time(&now);
	//	when = *localtime(&now);

	//if (confirm == 0)
	//	return;

	//int i = 0;

	//for (i = 0; i < pMob[conn].MaxCarry; i++)
	//{
	//	if (pMob[conn].MOB.Carry[i].sIndex != 3170)
	//		continue;

	//	break;
	//}

	//if (i == pMob[conn].MaxCarry)
	//{
	//	sprintf(temp, g_pMessageStringTable[_SN_BRINGITEM], g_pItemList[3170].Name);
	//	SendSay(npcIndex, temp);
	//	return;
	//}
	////  
	//if (NewbieEventServer)
	//{
	//	 
	//	if ((when.tm_hour == 20) && when.tm_min >= 0 && when.tm_min <= 2)
	//	{
	//		DoTeleport(conn, 3522 + rand() % 5 - 3, 1471 + rand() % 5 - 3);
	//		MSG_STANDARDPARM sm;
	//		memset(&sm, 0, sizeof(MSG_STANDARDPARM));
	//		sm.Type = _MSG_StartTime;
	//		sm.ID = ESCENE_FIELD;
	//		sm.Size = sizeof(MSG_STANDARDPARM);
	//		sm.Parm = 1200;
	//		MapaMulticast(27, 11, (MSG_STANDARD*)&sm, 0);
	//	}
	//	if ((when.tm_hour == 20) && when.tm_min > 2 && when.tm_min < 16)
	//	{
	//		SendSay(npcIndex, g_pMessageStringTable[_NN_Night_Already]);
	//		return;
	//	}
	//	else
	//	{
	//		
	//		SendSay(npcIndex, "Horário indisponível.");
	//		return;
	//	} 

	//}
	//	else
	//	{
	//		SendSay(npcIndex, g_pMessageStringTable[_NN_NEWBIEEVENTSERVER]);
	//		return;
	//	}

	//	sprintf(temp, "etc,questColiseuN ticket xamã name:%s level:%d", pMob[conn].MOB.MobName, pMob[conn].MOB.BaseScore.Level);
	//	Log(temp, 0,pUser[conn].IP);

	//	BASE_ClearItem(&pMob[conn].MOB.Carry[i]);
	//	SendItem(conn, ITEM_PLACE_CARRY, i, &pMob[conn].MOB.Carry[i]);
	//	return;

	//} break;
#pragma endregion

#pragma region UNICORNIO_PURO
	case UNICORNIO_PURO:
	{
		if (pMob[conn].MOB.Equip[6].sIndex == 862)//espada curta
		{
										pMob[conn].MOB.Equip[6].sIndex = 939;//katana
										pMob[conn].MOB.Equip[6].stEffect[1].cEffect = 43;
										pMob[conn].MOB.Equip[6].stEffect[1].cValue = 5;
										pMob[conn].MOB.Equip[6].stEffect[2].cEffect = 2;
										pMob[conn].MOB.Equip[6].stEffect[2].cValue = 45;
										SendSay(npcIndex, "Tome este presente, mas não se acostume a isso...");
										SendItem(conn, ITEM_PLACE_EQUIP, 6, &pMob[conn].MOB.Equip[6]);
										return;
		}
		if (pMob[conn].MOB.Equip[6].sIndex == 923)//arco de cinzas OK
								   {
									   pMob[conn].MOB.Equip[6].sIndex = 943;//Caveira
									   pMob[conn].MOB.Equip[6].stEffect[1].cEffect = 43;
									   pMob[conn].MOB.Equip[6].stEffect[1].cValue = 5;
									   pMob[conn].MOB.Equip[6].stEffect[2].cEffect = 2;
									   pMob[conn].MOB.Equip[6].stEffect[2].cValue = 45;
									   SendSay(npcIndex, "Tome este presente, mas não se acostume a isso...");
									   SendItem(conn, ITEM_PLACE_EQUIP, 6, &pMob[conn].MOB.Equip[6]);
									   return;
								   }
		 if (pMob[conn].MOB.Equip[6].sIndex == 918)//LANÇA MAGICA OK
								   {
									   pMob[conn].MOB.Equip[6].sIndex = 940;//ORC
									   pMob[conn].MOB.Equip[6].stEffect[1].cEffect = 43;
									   pMob[conn].MOB.Equip[6].stEffect[1].cValue = 5;
									   pMob[conn].MOB.Equip[6].stEffect[2].cEffect = 60;
									   pMob[conn].MOB.Equip[6].stEffect[2].cValue = 20;
									   SendSay(npcIndex, "Tome este presente, mas não se acostume a isso...");
									   SendItem(conn, ITEM_PLACE_EQUIP, 6, &pMob[conn].MOB.Equip[6]);
									   return;
								   }
		 if (pMob[conn].MOB.Equip[6].sIndex == 917)//Florete
								   {
									   pMob[conn].MOB.Equip[6].sIndex = 942;//Argos
									   pMob[conn].MOB.Equip[6].stEffect[1].cEffect = 43;
									   pMob[conn].MOB.Equip[6].stEffect[1].cValue = 5;
									   pMob[conn].MOB.Equip[6].stEffect[2].cEffect = 2;
									   pMob[conn].MOB.Equip[6].stEffect[2].cValue = 45;
									   SendSay(npcIndex, "Tome este presente, mas não se acostume a isso...");
									   SendItem(conn, ITEM_PLACE_EQUIP, 6, &pMob[conn].MOB.Equip[6]);
									   return;
								   }
								   SendSay(npcIndex, "Troque sua arma em uma poderosa arma Sephira.");
	}
#pragma endregion
	default:
		sprintf(temp, "etc,quest %d %d", npcMerc, npcGrade);
		Log(temp, 0,  pUser[conn].IP);
		break;
	}
}