#include "stdafx.h"

#include "CEvent.h"
#include "CEventEntity.h"
#include "IEventListener.h"

#include "CEventRegistry.h"

void CEventRegistry::RegisterEvent( CEvent* pcEvent )
{
	m_acEvents[ m_iEventCount++ ] = pcEvent;
}

void CEventRegistry::UnRegisterEvent( const char* pszName )
{
	for( int iLoop = 0; iLoop < m_iEventCount; ++iLoop )
	{
		if( m_acEvents[ iLoop ] && 0 == m_acEvents[ iLoop ]->m_strName.compare( pszName ) )
		{
			m_acEvents[ iLoop ] = nullptr;
			break;
		}
	}
}

void CEventRegistry::ListenToEvent( const char* pszName, IEventListener* pcListener )
{
	for( int iLoop = 0; iLoop < m_iEventCount; ++iLoop )
	{
		if( m_acEvents[ iLoop ] && 0 == m_acEvents[ iLoop ]->m_strName.compare( pszName ) )
		{
			m_acEvents[ iLoop ]->AddListener( pcListener );
		}
	}
}

void CEventRegistry::UnlistenToEvent( const char* pszName, IEventListener* pcListener )
{
	for( int iLoop = 0; iLoop < m_iEventCount; ++iLoop )
	{
		if( m_acEvents[ iLoop ] && 0 == m_acEvents[ iLoop ]->m_strName.compare( pszName ) )
		{
			m_acEvents[ iLoop ]->RemoveListener( pcListener );
		}
	}
}

CEvent* CEventRegistry::GetEvent( const char * pszName )
{
	for( int iLoop = 0; iLoop < m_iEventCount; ++iLoop )
	{
		if( m_acEvents[ iLoop ] && 0 == m_acEvents[ iLoop ]->m_strName.compare( pszName ) )
		{
			return m_acEvents[ iLoop ];
		}
	}
	return nullptr;
}

void CEventRegistry::SendEvent( const char * pszName, CEventEntity* pcEventData )
{
	for( int iLoop = 0; iLoop < m_iEventCount; ++iLoop )
	{
		if( m_acEvents[ iLoop ] && 0 == m_acEvents[ iLoop ]->m_strName.compare( pszName ) )
		{
			m_acEvents[ iLoop ]->Send( pcEventData );
		}
	}
}