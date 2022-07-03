#include "Paste.h"
#include"AddANDgate2.h"
#include"ApplicationManager.h"

Paste::Paste(ApplicationManager* pApp) :Action(pApp)
{

}

Paste::~Paste(void)
{
}

void Paste::ReadActionParameters()
{

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Paste: Click to paste the copied component.");
	pIn->GetPointClicked(Cx, Cy);

	pManager->SetClipboard(pManager->GetClipboard());

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Paste::Execute()
{
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();
	//paste the copied component
	if (pManager->GetClipboard())
	{
		Acttype = pManager->GetClipboard()-> GetAddActionType();
		pManager->ExecuteAction(Acttype);
	}
	else
		pOut->PrintMsg("No Component is selected.");

}

void Paste::Undo()
{}

void Paste::Redo()
{}