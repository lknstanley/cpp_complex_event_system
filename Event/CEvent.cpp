#include "stdafx.h"

#include "IEventListener.h"
#include "CEventEntity.h"

#include "CEvent.h"

void CEvent::AddListener( IEventListener* pEventListener )
{
	m_acEventListeners[ m_iListenerCount++ ] = pEventListener;
}

void CEvent::RemoveListener( IEventListener * pEventListener )
{
	for( int iLoop = 0; iLoop < m_iListenerCount; ++iLoop )
	{
		if( m_acEventListeners[ iLoop ] == pEventListener )
		{
			m_acEventListeners[ iLoop ] = nullptr;
			break;
		}
	}
}

void CEvent::Send( CEventEntity* pcEventData )
{
	for( int iLoop = 0; iLoop < m_iListenerCount; ++iLoop )
	{
		if( m_acEventListeners[ iLoop ] )
		{
			m_acEventListeners[ iLoop ]->VOnEvent( this, pcEventData );
		}
	}
}
