#ifndef _SELECT_H
#define _SELECT_H
#include"Components/Component.h"
#include"Components/Connection.h"
#include"ApplicationManager.h"
#include "Action.h"
class Select : public Action
{
private:
	int Cx, Cy;	        //user clicked point
	bool isselected;
public:
	Select(ApplicationManager* pApp);
	virtual ~Select(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
#endif