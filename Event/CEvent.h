#pragma once
#include <string>

class IEventListener;
class CEventEntity;

class CEvent
{
public:
	enum { EMaxListeners = 8 };

	IEventListener* m_acEventListeners[ EMaxListeners ];
	int				m_iListenerCount;
	std::string		m_strName;

	CEvent( void )
		: m_iListenerCount( 0 )
	{}
	~CEvent() { };

	void AddListener( IEventListener* pEventListener );
	void RemoveListener( IEventListener* pEventListener );
	void Send( CEventEntity* pcEventData );
};

