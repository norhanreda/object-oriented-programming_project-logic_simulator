#include"simulate.h"


simulate::simulate(ApplicationManager* pAppMan) : Action(pAppMan) {
	mStopSimulation = false;
}

/* Reads parameters required for action to execute */
void simulate::ReadActionParameters() 
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMsg("Simulate");

}

/* Executes action */
void simulate::Execute()
{
	ReadActionParameters();
	pManager->SelectSimulation();
	pManager->OperateConnctionSimulation();
	pManager->OperateGatesSimulation();
	pManager->OperateLedSimulation();


	
}





	/* Undo action */
	 void simulate::Undo()
	 {}

	/* Redo action */
  void simulate::Redo()
  {}

	/* Destructor */
	simulate::~simulate()
	{
	
	}
