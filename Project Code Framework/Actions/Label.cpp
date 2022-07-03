#include "Label.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include<iostream>
using namespace std;
Label::Label(ApplicationManager *pApp):Action(pApp)
{
}


/* Reads parameters required for action to execute */
void Label::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut =pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Print Action Message
	pOut->PrintMsg("ADD label");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

	// Edit label
	mNewLabel = pIn->GetSrting(pOut);//
	pManager->SetClipboard(pManager->IsInside(Cx, Cy));//
	Component* c = pManager->GetClipboard();//
	c->SetLabel(mNewLabel);//
	pOut->DrawLabel(x1, y1, mNewLabel);//
	pOut->ClearStatusBar();


}


/* Executes action */
void Label::Execute() 
{
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();
	
	pOut->DrawLabel(Cx,Cy, mNewLabel);

	pManager->UpdateInterface();
	
}


/* Undo action */
void Label::Undo() 
{
	
}

/* Redo action */
void Label::Redo() 
{
	

}










Label::~Label()
{
}
