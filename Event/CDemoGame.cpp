#include "stdafx.h"
#include <iostream>

#include "CEvent.h"
#include "CEventEntity.h"
#include "IEventListener.h"

#include "CDemoGame.h"


CDemoGame::CDemoGame()
{
}


CDemoGame::~CDemoGame()
{
}

void CDemoGame::VOnEvent( CEvent* pEvent, CEventEntity* pcEventData )
{
	std::cout << "event name: " << pEvent->m_strName << std::endl;
	std::cout << "event content (key: message): " << pcEventData->GetString( "message" ) << std::endl;
}
