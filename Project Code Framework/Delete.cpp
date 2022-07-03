#include "Delete.h"
#include"ApplicationManager.h"

Delete::Delete(ApplicationManager* pApp) :Action(pApp)
{
	isdeleted = false;
}

Delete::~Delete(void)
{
}

void Delete::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pManager->UpdateInterface();


	//Print Action Message
	pOut->PrintMsg("Delete: Click to select a component to delete.");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();


	pManager->SetClipboard(pManager->IsInside(Cx, Cy));

	if (pManager->GetClipboard() == NULL)
	{
		pOut->PrintMsg("No Component is selected.");
	}
	else
	{
		isdeleted = true;
		pManager->GetClipboard()->SetDeleted(true);
	}
	
}

void Delete::Execute()
{
	Output* pOut = pManager->GetOutput();

	//Get selected component from the user
	ReadActionParameters();
	if (!isdeleted)
		return;
	else
	{
		//pManager->SetClipboard(pManager->GetClipboard());
		
		pManager->GetClipboard()->Delete();
		pManager->DeleteComponent();
		pManager->UpdateInterface();
		pOut->ClearDrawingArea();
		pOut->PrintMsg("Component is deleted.");
	}

}

void Delete::Undo()
{}

void Delete::Redo()
{}