#pragma once
#include "..\Actions\Action.h"
#include "..\ApplicationManager.h"
#include "..\Components\Gate.h"
#include "..\Components\Connection.h"

class AddConnection : public Action
{
private:
	int mDstPinIndex;				// The index of the destination pin
	GraphicsInfo mGfxInfo;			// The parameters (coordinates) required to draw the connection
	string mLabel;					// The label of the component
	OutputPin * mSrcPin;			// Pointer to the source pin
	InputPin  * mDstPin;			// Pointer to the destination pin
	Connection* mConnection;		// Pointer to the added connection
	
	
	public:
	/* Constructor */
	AddConnection(ApplicationManager* pAppMan);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	
	//Execute action (code depends on action type)
	virtual void Execute();

	/* Undo action */
	virtual void Undo();

	/* Redo action */
	virtual void Redo();

	/* Detects the source component of the connection */
	bool DetectSourceComponent();

	/* Detects the destination component of the connection */
	bool DetectDestinationComponent();
	/* Destructor */  
	virtual ~AddConnection();


};