/*
*   Copyright (C) {2015}  {Victor Klafke, Charles TheHouse}
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see [http://www.gnu.org/licenses/].
*
*   Contact at: victor.klafke@ecomp.ufsm.br
*/
#include "ProcessClientMessage.h"

void Exec_MSG_Rebuy(int conn, char *pMsg)
{
	MSG_Rebuy *m = (MSG_Rebuy*)pMsg;

	if (m->ID != conn)
	{
		CloseUser(conn);

		return;
	}

	if (pUser[conn].Mode != USER_PLAY) 
		return;

	for (int i = 0; i < MAX_ITEM_REBUY; i++)
		m->Rebuy[i] = pMob[conn].Rebuy[i];

	pUser[conn].cSock.AddMessage((char*)m, m->Size);
}