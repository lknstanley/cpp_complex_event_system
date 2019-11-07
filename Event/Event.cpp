// Event.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

#include "CEvent.h"
#include "CEventEntity.h"
#include "CEventRegistry.h"
#include "IEventListener.h"
#include "CDemoGame.h"

//////////////////////////////////////////////////////////////////////////
// Things to add for homework:
// 
// done 1) separate into different .cpp and .h files, clean this up, make it robust, add comments 
// 
// 2) this uses local (stack) variables you should ensure your code
//	  which in no way guarantees that the events will be 'alive' when sent
//    consider how to make this work outside of main()? 
//    * interface? 
//    * memory management?
//    * don't forget to deallocate anything you allocate!!
// 
// done 3) must be able to handle listener registering to listen to events 
//    that aren't yet registered
// 
// 4) would be nice to have some sort of type safety in the sending of data
//    (see 'sample complex event' for use of typeId etc.)
//
// done 5) add unregister and unlisten functionality
// 
// 6) your code must demonstrate use of all features you add to show you 
//    have tested them
//    
// 7) suggestion: discrete startup, update, and shutdown functions will 
//    probably help you show this all works
//    
// 8) consider using cout to print what you're doing to the command line
//    as you do it if you feel it helps you show what you're doing
//    
// 9) it must be possible to register, listen to, and send messages by 
// name - this would allow external tools to be used to edit messages
//    
//////////////////////////////////////////////////////////////////////////
int _tmain( int argc, _TCHAR* argv[] )
{
	CEventRegistry cEventRegistry;

	// Create a new event
	CEvent cEvent;
	cEvent.m_strName = "Dave";
	CEvent cUnregisterEvent;
	cUnregisterEvent.m_strName = "ToUnregister";
	CEvent cUnlistenEvent;
	cUnlistenEvent.m_strName = "ToUnlisten";

	// (3) Register the Dave event to event registry to make it ready to be triggered
	cEventRegistry.RegisterEvent( &cEvent );
	cEventRegistry.RegisterEvent( &cUnregisterEvent );
	cEventRegistry.RegisterEvent( &cUnlistenEvent );

	// Demonstrate it with a class which implemented the IEventListener interface
	CDemoGame cDemoGame;

	// Register the Demo class to listen an event which is called "Dave"
	cEventRegistry.ListenToEvent( "Dave", &cDemoGame );
	cEventRegistry.ListenToEvent( "ToUnregister", &cDemoGame );
	cEventRegistry.ListenToEvent( "ToUnlisten", &cDemoGame );

	// Create message content
	CEventEntity* cDaveEventEntity = new CEventEntity();
	cDaveEventEntity->SetString( "message", "this is the content" );

	// Send a "Dave" event
	cEventRegistry.SendEvent( "Dave", cDaveEventEntity );
	cEventRegistry.SendEvent( "ToUnregister", cDaveEventEntity );
	cEventRegistry.SendEvent( "ToUnlisten", cDaveEventEntity );
	
	// (5) UnregisterEvent and UnlistenEvent
	cEventRegistry.UnRegisterEvent( "ToUnregister" );
	cEventRegistry.SendEvent( "ToUnregister", cDaveEventEntity );

	cEventRegistry.UnlistenToEvent( "ToUnlisten", &cDemoGame );
	cEventRegistry.SendEvent( "ToUnlisten", cDaveEventEntity );

	// Pause console
	std::cin.get();

	return 0;
}

