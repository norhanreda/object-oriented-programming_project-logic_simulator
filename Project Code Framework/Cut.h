#ifndef _CUT_H
#define _CUT_H
#include"Components/Component.h"
#include"Components/Connection.h"
//#include "Delete.h"  to do

#include"ApplicationManager.h"
#include "Action.h"
class Cut : public Action
{
private:
	int Cx, Cy;	        //user clicked point
	bool iscut;
	Action* mDeleteAction; //pointer to delete action

public:
	Cut(ApplicationManager* pApp);
	virtual ~Cut(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};
#endif