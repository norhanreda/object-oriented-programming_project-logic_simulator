#pragma once
#include "..\Actions\Action.h"
#include "..\Actions\CCC.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include "..\Components\Connection.h"


class Edit : public Action
{
private:
	int Cx, Cy;							// The point clicked by the user
	int mNewDstPinIndex;				// The new index of the destination pin
	int mPrvDstPinIndex;				// The previous index of the destination pin
	string mNewLabel;					// The new label entered by the user
	string mPrvLabel;					// The previous label of the component
	OutputPin* mNewSrcPin;					// The new source pin for the connection
	OutputPin* mPrvSrcPin;					// The previous source pin of the connection
	InputPin* mNewDstPin;					// The new destination pin for the connection
	InputPin* mPrvDstPin;					// The previous destination pin of the connection
	GraphicsInfo mNewGfxInfo;			// The parameters (coordinates) required to draw the connection
	GraphicsInfo mPrvGfxInfo;			// The parameters (coordinates) required to draw the connection
	Component* mComp;	              // Pointer to the edited component
	bool isGateEdited;
	bool isConnectionEdited;


public:
	/* Constructor */
	Edit(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	virtual ~Edit();

private:
	bool DetectSourceComponent();  /* Detects the source component of the connection */
	bool DetectDestinationComponent(); /* Detects the destination component of the connection */
};



