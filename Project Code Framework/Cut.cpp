#include "Cut.h"
#include"Delete.h"
#include"ApplicationManager.h"

Cut::Cut(ApplicationManager* pApp) :Action(pApp)
{
	mDeleteAction = new Delete(pManager);
	iscut = false;
}

Cut::~Cut(void)
{
}

void Cut::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pManager->UpdateInterface();

	//Print Action Message
	pOut->PrintMsg("Cut: Click to select a component to cut.");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

	pManager->SetClipboard(pManager->IsInside(Cx, Cy));

	if (pManager->GetClipboard() == NULL)
	{
		pOut->PrintMsg("No Component is selected.");
		
	}
	else if
		(dynamic_cast<Connection*>(pManager->GetClipboard()) != NULL)
	{
		pOut->PrintMsg("Connection can't be cut");
		
	}
	else
	{
		iscut = true;
	}
	
	
}

void Cut::Execute()
{
	//Get selected component from the user
	ReadActionParameters();

	Output* pOut = pManager->GetOutput();

	if (!iscut)
		return;
	else
	{
		pManager->SetClipboard(pManager->GetClipboard());
		//pManager->GetClipboard()->Delete();
		mDeleteAction->Execute();  
		pManager->UpdateInterface();
		pOut->PrintMsg("Component is cut.");
	}

	
}

void Cut::Undo()
{}

void Cut::Redo()
{}
