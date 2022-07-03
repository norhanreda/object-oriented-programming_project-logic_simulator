#include "AddConnection.h"

bool l=true;
/* Constructor */
AddConnection::AddConnection(ApplicationManager* pAppMan) : Action(pAppMan)
{
	
}




/* Reads parameters required for action to execute */
void AddConnection::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	
		pOut->PrintMsg("Connection: select the source pin");
		pIn->WaitMouseClick(mGfxInfo.x1, mGfxInfo.y1);
		pOut->ClearStatusBar();
		if (!DetectSourceComponent())
		{
		pOut->PrintMsg("Invalid source pin. Operation was cancelled");
		l=false;
		}
		pOut->PrintMsg("Connection: select the destination pin");
		pIn->WaitMouseClick(mGfxInfo.x2, mGfxInfo.y2);
		if (!DetectDestinationComponent()) 
		 pOut->PrintMsg("Invalid destination pin. Operation was cancelled");
		pOut->ClearStatusBar();
	
		/*pOut->PrintMsg("Connection: select the source pin");
		pIn->WaitMouseClick(mGfxInfo.x1, mGfxInfo.y1);
		pOut->ClearStatusBar();
	if(pManager->insidreArea(mGfxInfo.x1, mGfxInfo.y1)!=NULL)
	{
		
		mConnection->setSourcePin((&((Gate *)(pManager->insidreArea(mGfxInfo.x1, mGfxInfo.y1)))->get_m_OutputPin()));
		//((Gate *)(pManager->insidreArea(mGfxInfo.x1, mGfxInfo.y1)))->get_m_OutputPin();
	}
	else 
		 pOut->PrintMsg("Invalid source pin. Operation was cancelled");
		pOut->PrintMsg("Connection: select the destination pin");
		pIn->WaitMouseClick(mGfxInfo.x2, mGfxInfo.y2);
		if(pManager->insidreArea(mGfxInfo.x1, mGfxInfo.y1)!=NULL)
		{
		
		
		
		}*/


		pOut->ClearStatusBar();
}


/* Executes action */
void AddConnection::Execute() 
{
	ReadActionParameters();
	if(l==true)
	{
	mConnection = new Connection(mGfxInfo,mSrcPin,mDstPin);
	mConnection->setSourcePin(mSrcPin);
	mConnection->setDestPin(mDstPin, mDstPinIndex);
	mConnection->SetLabel(mLabel);
    pManager->AddComponent(mConnection);
	}
}


/* Undo action */
void AddConnection::Undo() 
{
	
}

/* Redo action */
void AddConnection::Redo() 
{
	

}

		/* Detects the source component of the connection */
bool AddConnection::DetectSourceComponent()
{
	//Component* comp = pManager->insidreArea(mGfxInfo.x1, mGfxInfo.y1);
		Component* comp = pManager->IsInside(mGfxInfo.x1, mGfxInfo.y1);

	if (comp == NULL) {
		return false;
	}
	else {
	
		Gate* gate;
		gate=dynamic_cast<Gate*>(comp);
		if (gate != NULL)  //&&&&&&&&&&&&&
		{	
			
		//	gate = (Gate*)comp;
		gate->GetOutputPinCoordinates(mGfxInfo.x1, mGfxInfo.y1);
      mSrcPin = gate->GetOutputPin();
	  return true;
		}
		else
		return false;
		//gate = ((Connection*)comp)->getSourcePin()->GetGate();

		

		if (mSrcPin == NULL|| mSrcPin->IsFull()) //|| 
		{
			return false;
		}
		return true;
	}

	return false;
}

/* Detects the destination component of the connection */
bool AddConnection::DetectDestinationComponent() {
	//Component* comp = pManager->insidreArea(mGfxInfo.x2, mGfxInfo.y2);
		Component* comp = pManager->IsInside(mGfxInfo.x2, mGfxInfo.y2);

	Gate* gate;
	gate = dynamic_cast<Gate*>(comp);

	if (comp == NULL || comp == mSrcPin->GetGate()) {
		return false;
	}
	
	else if (gate != NULL)
	{
		//Gate* gate = (Gate*)comp;
		mDstPinIndex = gate->GetInputPinIndex(mGfxInfo.x2, mGfxInfo.y2);
		gate->GetInputPinCoordinates(mGfxInfo.x2, mGfxInfo.y2, mDstPinIndex);
		mDstPin = gate->GetInputPin(mDstPinIndex);

		if (mDstPin == NULL || mDstPin->IsFull()) //
		{
			return false;
		}

		return true;
	}

	return false;
}

AddConnection::~AddConnection()
{

}