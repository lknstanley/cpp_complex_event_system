#include "stdafx.h"
#include <string>
#include <iostream>
#include "CEventEntity.h"


CEventEntity::CEventEntity()
{
}


CEventEntity::~CEventEntity()
{
}

void CEventEntity::Set( std::string strKey, void * pContent )
{
	int iIndexOfList = FindIndex( strKey );
	if( iIndexOfList != -1 )
	{
		m_vecDictionary.at( iIndexOfList ).pContent = pContent;
	}
	else
	{
		KeyPairValue kvp;
		kvp.strKeyName = strKey;
		kvp.pContent = pContent;
		m_vecDictionary.push_back( kvp );
	}
}

void * CEventEntity::Get( std::string strKey )
{
	int iIndexOfList = FindIndex( strKey );
	if( iIndexOfList != -1 )
	{
		return m_vecDictionary.at( iIndexOfList ).pContent;
	}
}

void CEventEntity::SetString( std::string strKey, std::string strContent )
{
	Set( strKey, static_cast< void* >( &strContent ) );
}

std::string CEventEntity::GetString( std::string strKey )
{
	std::string& pStr = *( static_cast< std::string* >( Get( strKey ) ) );
	std::cout << pStr << std::endl;
	return "";
}

void CEventEntity::SetFloat( std::string strKey, float fContent )
{
	Set( strKey, static_cast< void* >( &fContent ) );
}

float CEventEntity::GetFloat( std::string strKey )
{
	return *static_cast< float* >( Get( strKey ) );
}

void CEventEntity::SetBoolean( std::string strKey, bool bContent )
{
	Set( strKey, static_cast< void* >( &bContent ) );
}

bool CEventEntity::GetBoolean( std::string strKey )
{
	return *static_cast< bool* >( Get( strKey ) );
}

bool CEventEntity::HasKey( std::string strKey )
{
	for( int i = 0; i < m_vecDictionary.size(); i++ )
	{
		if( m_vecDictionary.at(i).strKeyName == strKey )
		{
			return true;
		}
	}
	return false;
}

int CEventEntity::FindIndex( std::string strKey )
{
	for( int i = 0; i < m_vecDictionary.size(); i++ )
	{
		if( m_vecDictionary.at( i ).strKeyName == strKey )
		{
			return i;
		}
	}
	return -1;
}
