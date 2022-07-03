#pragma once
#include "..\Actions\Action.h"
#include "..\Actions\SaveAction.h"
#include "..\ApplicationManager.h"
#include <fstream>
#include<iostream>
#include<string>
using namespace std;


class Exit : public Action
{
private:
	ofstream outputFile;
	bool i = false;
public:
	/* Constructor */
	Exit(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();

	/* Destructor */
	virtual ~Exit();
};

