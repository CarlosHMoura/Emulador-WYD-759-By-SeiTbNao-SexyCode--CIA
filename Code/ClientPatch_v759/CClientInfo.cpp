#include "main.h"


void CClientInfo::Init()
{
	this->Info.Cash = 0; 
	this->Info.Honra = 0;
}

void CClientInfo::ReceiveInfo(char* Packet)
{
	 

	if (auto p = reinterpret_cast<MSG_UpdateEtc2*>(Packet))
	{
		this->Info.Cash = p->Cash;

		this->Info.Honra = p->Honra;
		if (this->Info.Cash < 0)
			this->Info.Cash = 0;
		if (this->Info.Honra < 0)
			this->Info.Honra = 0;
		 
	}
}