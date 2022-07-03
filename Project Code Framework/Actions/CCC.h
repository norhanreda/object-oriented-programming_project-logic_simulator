#ifndef _CCC_H
#define _CCC_H

#include "action.h"
#include "Action.h"
#include"../Components/Connection.h"

class CCC : public Action
{
private:
	
	GraphicsInfo mGfxInfo;			// The parameters (coordinates) required to draw the connection
	Connection* mConnection;
	bool isConn;
	int Cx1, Cy1, Cx2, Cy2;
	OutputPin* srcccpin;
	InputPin* Dstttpin;
	Component* CompDst;
	Component* CompSrc;
	int indx;
	int Load;
	int menna;

public:
	CCC(ApplicationManager* pApp);
	CCC(ApplicationManager* pApp,Component* s,Component* d, int n);

	virtual ~CCC(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif