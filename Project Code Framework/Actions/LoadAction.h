#ifndef _LOAD_ACTION_H
#define _LOAD_ACTION_H
#include <fstream>
#include "action.h"
#include "..\Components\Connection.h"
#include"..\Components\AND2.h"
#include"..\Components\OR2.h"
#include"..\Components\Inverter.h"
#include"..\Components\NAND2.h"
#include"..\Components\NOR2.h"
#include"..\Components\XOR2.h"
#include"..\Components\XNOR2.h"
#include"..\Components\AND3.h"
#include"..\Components\NOR3.h"
#include"..\Components\XOR3.h"
#include"..\Components\Buffer.h"
#include"..\Components\Switch.h"
#include"..\Components\LED.h"

using namespace std;


class LoadAction : public Action
{
	string CT;
	int id;
	string label;
	int x;
	int y;
	bool i;
	ifstream read; //object of class ifstream that show data in file "file"
public:
	LoadAction(ApplicationManager* pApp);
	
	virtual ~LoadAction(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	void Undo();

	void Redo();

};

#endif