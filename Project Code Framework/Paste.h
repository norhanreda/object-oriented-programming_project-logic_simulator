#ifndef _PASTE_H
#define _PASTE_H
#include"Components/Component.h"
#include"Components/Connection.h"
#include"ApplicationManager.h"
#include "Action.h"
class Paste : public Action
{
private:
	int Cx, Cy;	        //user clicked point
	ActionType Acttype;
	
public:
	Paste(ApplicationManager* pApp);
	virtual ~Paste(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};
#endif
