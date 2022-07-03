#include "Select.h"
#include"ApplicationManager.h"

Select::Select(ApplicationManager* pApp) :Action(pApp)
{
	isselected = false;
}

Select::~Select(void)
{
}

void Select::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pManager->UpdateInterface();


	//Print Action Message
	pOut->PrintMsg("Select: Click to select a component.");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

	pManager->SetClipboard(pManager->IsInside(Cx, Cy));

	if (pManager->GetClipboard() == NULL)
	{

		pOut->PrintMsg("No Component is selected.");
		isselected = false;
		
	}
	else
	{
		isselected = true;
	}
}

void Select::Execute()
{
	Output* pOut = pManager->GetOutput();

	//Get selected component from the user
	ReadActionParameters();
	if (!isselected)
	{
		return;
	}
	else 
	{
		if(pManager->GetClipboard()->IsSelected())
		    pManager->GetClipboard()->SetSelected(false);
		else
			pManager->GetClipboard()->SetSelected(true);
	}
}

void Select::Undo()
{}

void Select::Redo()
{}