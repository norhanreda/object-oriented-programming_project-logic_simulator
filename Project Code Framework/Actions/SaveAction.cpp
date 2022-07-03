#include "SaveAction.h"
#include "..\ApplicationManager.h"

/* Constructor */
SaveAction::SaveAction(ApplicationManager* pApp) : Action(pApp) {

}

/* Reads parameters required for action to execute */
void SaveAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	pOut->PrintMsg("Saved");

}

/* Executes action */
void SaveAction::Execute()
{
	ReadActionParameters();
	Write.open("Data.txt");
	Write.clear();
	pManager->Save(Write);
	ofstream Write;
	Write.open("Data.txt", ios::app);
	Write << "-1";
}

/* Undo action */
void SaveAction::Undo()
{}

/* Redo action */
void SaveAction::Redo()
{}

/* Destructor */
SaveAction::~SaveAction()
{
	Write.close();
}