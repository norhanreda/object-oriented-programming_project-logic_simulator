#pragma once
#include "..\Actions\Action.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Components\LED.h"
#include "..\Components\Switch.h"
#include "..\Components\Gate.h"
#include "..\Components\Connection.h"
using namespace std;

class simulate : public Action
{
private:
	
	bool mStopSimulation;
public:
	/* Constructor */
	simulate(ApplicationManager* pAppMan);

	/* Reads parameters required for action to execute */
	virtual void ReadActionParameters();

	/* Executes action */
	virtual void Execute();

	/* Tests the output on a led */
	//int Cascade(Component*cmp);

	/* Undo action */
	virtual void Undo();

	/* Redo action */
	virtual void Redo();

	/* Destructor */
	virtual ~simulate();
};

