#include "Copy.h"
#include"ApplicationManager.h"

Copy::Copy(ApplicationManager* pApp) :Action(pApp)
{
	iscopied = false;
}

Copy::~Copy(void)
{
}

void Copy::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

    pManager->UpdateInterface();


	//Print Action Message
	pOut->PrintMsg("Copy: Click to select a component to copy.");

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
		pOut->PrintMsg("Connection can't be copied");
	}
	else
	{
		iscopied = true;
	}
}

void Copy::Execute()
{
	Output* pOut = pManager->GetOutput();

	//Get selected component from the user
	ReadActionParameters();
	if (!iscopied)
		return;
	else 
	{
		pManager->SetClipboard(pManager->GetClipboard());
		pOut->PrintMsg("Component is copied.");
	}
	
}

void Copy::Undo()
{}

void Copy::Redo()
{}