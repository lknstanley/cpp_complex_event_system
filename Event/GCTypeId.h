////////////////////////////////////////////////////////////////////////////////////////////////////////////
// (C) Gamer Camp / Alex Darby 2011 
// This document should not be distributed or reproduced in part or in whole without obtaining written 
// permission from the copyright holders.
////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _GCTYPEID_H_
#define _GCTYPEID_H_

//////////////////////////////////////////////////////////////////////////
// this header is full of (simple) template magic to make auto-generated class IDs


//////////////////////////////////////////////////////////////////////////
// typedef for our typeID value
typedef unsigned int GCTypeID;


//////////////////////////////////////////////////////////////////////////
// type specialised templated TypeID class
//
// This generates a typeid using the address of a static variable.
//
// Since 2 variables can't occupy the same memory address they will be unique.
//
template< typename T >
class TGCTypeIDGenerator
{
public:
	// this generates a typeID for each class that instantiates the template
	static GCTypeID GetTypeID()
	{
		static char s_chTheAdressOfThisIsTheClassID;
		return reinterpret_cast< GCTypeID >( &s_chTheAdressOfThisIsTheClassID );
	}

	// no instance of this class can be created.
private:
	TGCTypeIDGenerator()
	{
	}
};

// macro for getting hold of a type's ID
#define GetGCTypeIDOf( TYPENAME )		( TGCTypeIDGenerator< TYPENAME >::GetTypeID() )

// since all GCTypeIDs are essentially valid memory addresses the only safe thing to 
// use for the invalid ID is the system invalid pointer default: NULL - i.e. 0
#define GCTYPEID_INVALID	0


//////////////////////////////////////////////////////////////////////////
// template function that resolves to the correct form of 
// CReflectionData< T >::GetTypeID() based on the input type
template< typename T >
GCTypeID GetTypeIDOfVariable( T instance )
{
	return TGCTypeIDGenerator< T >::GetTypeID();
}

#endif//#ifndef _GCTYPEID_H_