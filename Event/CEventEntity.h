#pragma once
#include <vector>

#define MAX_EVENT_ENTITIES 8

class CEventEntity
{
private:
	struct KeyPairValue
	{
		std::string strKeyName;
		void* pContent;
	};

	std::vector<KeyPairValue> m_vecDictionary;
	void Set( std::string strKey, void* pContent );
	void* Get( std::string strKey );

public:
	CEventEntity();
	~CEventEntity();

	//////////////////////////////////////////////////////////////////////////
	// Control interface
	//////////////////////////////////////////////////////////////////////////
	void SetString( std::string strKey, std::string strContent );
	std::string GetString( std::string strKey );

	void SetFloat( std::string strKey, float fContent );
	float GetFloat( std::string strKey );

	void SetBoolean( std::string strKey, bool bContent );
	bool GetBoolean( std::string strKey );

	bool HasKey( std::string strKey );
	int FindIndex( std::string strKey );
};