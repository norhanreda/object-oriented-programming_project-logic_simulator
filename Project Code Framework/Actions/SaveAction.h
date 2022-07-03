#ifndef _Save_ACTION_H
#define _Save_ACTION_H
#include <fstream>
#include "action.h"
using namespace std;


class SaveAction : public Action
{
private:
	ofstream Write; //object of class ofstream that create a file
public:
	SaveAction(ApplicationManager* pApp);
	virtual ~SaveAction(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif
