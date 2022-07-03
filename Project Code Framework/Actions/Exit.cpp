#include "Exit.h"

/* Constructor */
Exit::Exit(ApplicationManager* pApp) : Action(pApp) {
	i = false;
}

void Exit::ReadActionParameters() 
{
	ifstream originalFile, backUpFile;

	originalFile.open("Data.txt");
	backUpFile.open("BackUp.txt");
	if (!originalFile.eof() && !backUpFile.eof())
	{
		originalFile.close();
		backUpFile.close();
		i = true;
	}
}

/* Executes action */
void Exit::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	outputFile.open("BackUp.txt");
	outputFile.clear();
	pManager->Save(outputFile);
	outputFile.close();

	if (i) 
	{
		string s;
		pOut->PrintMsg(" if you would like to save before exiting, enter y");
		if(s=="y")
		{
			Action* pAct = new SaveAction(this->pManager);
			pAct->Execute();
			delete pAct;
		}
	}
}

/* Undo action */
void Exit::Undo() {
}

/* Redo action */
void Exit::Redo() {
}

/* Destructor */
Exit::~Exit() {
	outputFile.close();
}