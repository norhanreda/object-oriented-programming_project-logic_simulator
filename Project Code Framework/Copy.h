#ifndef _COPY_H
#define _COPY_H
#include"Components/Component.h"
#include"Components/Connection.h"
#include"ApplicationManager.h"
#include "Action.h"

class Copy : public Action
{
private:
	int Cx, Cy;	        //user clicked point
	bool iscopied;
public:
	Copy(ApplicationManager* pApp);
	virtual ~Copy(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};
#endif

