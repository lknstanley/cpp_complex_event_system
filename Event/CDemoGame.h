#pragma once
class CEvent;
class CEventEntity;
class IEventListener;

class CDemoGame
: public IEventListener
{
private:
public:
	CDemoGame();
	~CDemoGame();

	//////////////////////////////////////////////////////////////////////////
	// Callback for event listeners
	//////////////////////////////////////////////////////////////////////////
	virtual void VOnEvent( CEvent* pcEvent, CEventEntity* pcData ) override;
};

