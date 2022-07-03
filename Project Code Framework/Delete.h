#ifndef _DELETE_H
#define _DELETE_H
#include"Components/Component.h"
#include"Components/Connection.h"
#include"ApplicationManager.h"
#include "Action.h"

class Delete : public Action
{
private:
	int Cx, Cy;	        //user clicked point
	bool isdeleted;
public:
	Delete(ApplicationManager* pApp);
	virtual ~Delete(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};
#endif
