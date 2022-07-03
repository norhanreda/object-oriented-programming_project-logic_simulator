#pragma once
#include "..\Actions\Action.h"
#include "..\ApplicationManager.h"
#include "..\Components\Gate.h"
#include "..\Components\Component.h"
class Label:public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
		string mNewLabel;					// The new label entered by the user
       // string mPrvLabel;					// The previous label of the component
		Component* mComp;					// Pointer to the edited component
		GraphicsInfo mGfxInfo;			// The parameters (coordinates) required to draw the connection
public:
	Label(ApplicationManager *pApp);
	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();




	~Label();
};

