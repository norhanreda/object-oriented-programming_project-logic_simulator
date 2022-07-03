#include "CCC.h"
#include "..\ApplicationManager.h"
#include"..\Components\Connection.h"
#include"..\Components\OutputPin.h"
#include"..\Components\InputPin.h"
#include"..\Components\Gate.h"
CCC::CCC(ApplicationManager* pApp) :Action(pApp)
{
	isConn = true;
	Load = 0;

}
CCC::CCC(ApplicationManager* pApp, Component* s, Component* d, int n) :Action(pApp)
{
	isConn = true;
	Load = 1;
	Gate* SourceG = dynamic_cast<Gate*>(s);
	Gate* DestG = dynamic_cast<Gate*>(d);
	srcccpin = SourceG->GetOutputPin();
	Dstttpin = DestG->GetInputPin(n);
	//SourceG->getCoord(Cx1, Cy1);
	//DestG->getCoord(Cx2, Cy2);
	SourceG->GetOutputPinCoordinates(Cx1, Cy1);
	DestG->GetInputPinCoordinates(Cx2, Cy2,n);
}

CCC::~CCC(void)
{

}

void CCC::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	

	//Print Action Message
	pOut->PrintMsg("Sourse Component");
	
	pIn->WaitMouseClick(Cx1, Cy1);
	Component* ComS= pManager->IsInside(Cx1, Cy1);

	if (ComS == NULL)
	{
		pOut->PrintMsg("Invalid,Click any where.");
		int x, y;
		pIn->WaitMouseClick(x, y);
		isConn = false;
	}
	else
	{
		mGfxInfo.x1 = Cx1;   mGfxInfo.y1 = Cy1;

		if (dynamic_cast<Gate*>(ComS) != NULL)
			CompSrc = ComS;
		else
			CompSrc = ((Connection*)ComS)->getSrcComp();

		pOut->PrintMsg("Destination Component");
		pIn->WaitMouseClick(Cx2, Cy2);
	
		Component* ComD = pManager->IsInside(Cx2, Cy2);

		if (ComD == NULL)
		{

			pOut->PrintMsg("Invalid,Click any where.");
			int x, y;
			pIn->WaitMouseClick(x, y);
			isConn = false;
		}
		else
		{
			mGfxInfo.x2 = Cx2;   mGfxInfo.y2 = Cy2;
			 CompDst =ComD;

			pOut->PrintMsg("Click on Status Bar To enter pin number of Destination Gate.");
			int x, y;
			pIn->WaitMouseClick(x, y);
			string index = pIn->GetSrting(pOut);
			 indx = stoi(index);
			 if (dynamic_cast<Gate*>(ComS))
			 {
				 ((Gate*)CompSrc)->GetOutputPinCoordinates(mGfxInfo.x1, mGfxInfo.y1);
				 ((Gate*)CompDst)->GetInputPinCoordinates(mGfxInfo.x2, mGfxInfo.y2, indx);
				 srcccpin = ((Gate*)CompSrc)->GetOutputPin();
				 Dstttpin = ((Gate*)CompDst)->GetInputPin(indx);
			 }
			 else 
			 {

				 //((Connection*)CompSrc)->GetOutputPinCoordinates(mGfxInfo.x1, mGfxInfo.y1);
				 ((Gate*)CompDst)->GetInputPinCoordinates(mGfxInfo.x2, mGfxInfo.y2, indx);
				 srcccpin = ((Gate*)CompSrc)->GetOutputPin();
				 Dstttpin = ((Gate*)CompDst)->GetInputPin(indx);
			 }
		}
	}

	//Clear Status Bar 
	pOut->ClearStatusBar();

}

void CCC::Execute()
{
	Output* pOut = pManager->GetOutput();

	if(!Load)
	ReadActionParameters();
	else {
		
			mGfxInfo.x1 = Cx1 ;
			mGfxInfo.x2 = Cx2 ;
			mGfxInfo.y1 = Cy1;
			mGfxInfo.y2 = Cy2 ;
		
	}
	if (!isConn)
		return;
	else
	{
		Connection* Conn = new Connection(mGfxInfo, srcccpin, Dstttpin);
		Conn->setSourcePin(srcccpin);
		
			Conn->setDestPin(Dstttpin, indx);
			Conn->setSrcComp(CompSrc);
			Conn->setDstComp(CompDst);
			pManager->AddComponent(Conn);
		
	}
	
}

void CCC::Undo()
{}

void CCC::Redo()
{}
