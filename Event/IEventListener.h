#pragma once
class CEvent;
class CEventEntity;

class IEventListener
{
public:
	virtual void VOnEvent( CEvent* pEvent, CEventEntity* pcEventData ) = 0;
};