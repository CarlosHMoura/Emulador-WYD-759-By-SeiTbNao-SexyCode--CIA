#pragma once
class CClientInfo
{
public:
	static CClientInfo& Instance() {
		static CClientInfo _Instance;
		return _Instance;
	}
private:
	CClientInfo() = default;
	CClientInfo(const CClientInfo&) = delete;
	CClientInfo& operator=(const CClientInfo&) = delete;
	struct ST_INFO
	{
		//colocar aqui oque quer q venha do servidor
		int Cash;
		int Honra;
	};
public:
	ST_INFO Info;
	void Init();
	void ReceiveInfo(char* Packet);
};

static CClientInfo* g_pClientInfo = &CClientInfo::Instance();

