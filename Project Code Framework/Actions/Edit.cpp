#include "Edit.h"
/* Constructor */
Edit::Edit(ApplicationManager* pApp) : Action(pApp) {
	mNewDstPinIndex = 0;
	mPrvDstPinIndex = 0;
	mNewSrcPin = NULL;
	mPrvSrcPin = NULL;
	mNewDstPin = NULL;
	mPrvDstPin = NULL;
	mComp = NULL;
	isConnectionEdited = false;
	isGateEdited = false;
}

/* Reads parameters required for action to execute */
void Edit::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();


	pManager->UpdateInterface();
	pOut->PrintMsg("Please select a component to edit");
	pIn->GetPointClicked(Cx, Cy);
	pOut->ClearStatusBar();

    pManager->SetClipboard(pManager->IsInside(Cx, Cy));
	mComp = pManager->GetClipboard();

	if (pManager->GetClipboard() == NULL)
	{
		pOut->PrintMsg("No Component is selected.");
	}
	else if (dynamic_cast<Connection*>(pManager->GetClipboard()) != NULL)
	{
		isConnectionEdited=true;

	}
	else if (dynamic_cast<Gate*>(pManager->GetClipboard()) != NULL)
	{
		isGateEdited = true;
	}
}

	void Edit::Execute()
	{
		//Get selected component from the user
		ReadActionParameters();

		Output* pOut = pManager->GetOutput();
		Input* pIn = pManager->GetInput();

		if (isGateEdited)
		{

			mPrvLabel = mComp->GetLabel();
			mNewLabel = pIn->GetSrting(pOut);
			pManager->SetClipboard(pManager->IsInside(Cx, Cy));//
			Component* c = pManager->GetClipboard();//
			c->SetLabel(mNewLabel);//
			pOut->DrawLabel(Cx,Cy, mNewLabel);

			/*pOut->PrintMsg("please click to enter a new label");
			pIn->WaitMouseClick(Cx, Cy);
			mNewLabel = pIn->GetSrting(pOut);
			pOut->ClearStatusBar();*/
		}
		else if (isConnectionEdited)
		{
			
			pOut->PrintMsg("Do you want to edit connection label, source pin or destination pin? please click ");
			pIn->WaitMouseClick(Cx, Cy);

			pOut->PrintMsg("if you want to edit connection label, enter a. source pin enter b. destnation pin enter c");
			pIn->WaitMouseClick(Cx, Cy);
			string i= pIn->GetSrting(pOut);
			if (i == "a")
			{
				
				pOut->PrintMsg("please click to enter a new label");
				pIn->WaitMouseClick(Cx, Cy);
				mNewLabel = pIn->GetSrting(pOut);
				Component* c = pManager->GetClipboard();//
				c->SetLabel(mNewLabel);//
				pOut->DrawLabel(Cx, Cy, mNewLabel);
				pOut->ClearStatusBar();
			}
			else if (i == "b")
			{
				pOut->PrintMsg("Connection: select the source pin");
				pIn->WaitMouseClick(Cx,Cy);
				pOut->ClearStatusBar();
				if (!DetectSourceComponent())
				{
					pOut->PrintMsg("Invalid source pin. Operation was cancelled");
				}
				else
				{
					Connection* Conn = new Connection(mNewGfxInfo, mNewSrcPin, mPrvDstPin);
					Conn->setSourcePin(mNewSrcPin);
				}
			}
				
			
			else if (i == "b")
			{
				pOut->PrintMsg("Connection: select the destinaton pin");
				pIn->WaitMouseClick(Cx, Cy);
				pOut->ClearStatusBar();
				if (!DetectDestinationComponent())
				{
					pOut->PrintMsg("Invalid destination pin. Operation was cancelled");
				}
				else
				{
					Connection* Conn = new Connection(mNewGfxInfo, mPrvSrcPin, mNewDstPin);
					Conn->setDestPin(mNewDstPin, mNewDstPinIndex);
				}
			}
		}
	}
	void Edit::Undo()
	{
		/*mComp->SetLabel(mPrvLabel);
		Connection* Conn = (Connection*)mComp;
		Conn->setSourcePin(mPrvSrcPin);
		Conn->setDestPin(mPrvDstPin, mPrvDstPinIndex);
		pManager->GetOutput()->ClearDrawingArea();*/
	}

	void Edit::Redo()
	{
	/*	mComp->SetLabel(mNewLabel);
		Connection* Conn = (Connection*)mComp;
		Conn->setSourcePin(mNewSrcPin);
		Conn->setDestPin(mNewDstPin, mNewDstPinIndex);
		pManager->GetOutput()->ClearDrawingArea();*/
	}

	Edit::~Edit()
	{
	}

	/* Detects the source component of the connection */
	bool Edit::DetectSourceComponent() {
		Component* comp = pManager->IsInside(mNewGfxInfo.x1, mNewGfxInfo.y1);

		if (comp == NULL) {
			return false;
		}
		else {
			Gate* gate;

			if (dynamic_cast<Gate*>(comp) != NULL)
				gate = (Gate*)comp;
			else
				gate = ((Connection*)comp)->getSourcePin()->GetGate();

			gate->GetOutputPinCoordinates(mNewGfxInfo.x1, mNewGfxInfo.y1);
			mNewSrcPin = gate->GetOutputPin();

			if (mNewSrcPin == NULL || mNewSrcPin->IsFull()) {
				return false;
			}
		}

		return true;
	}

	/* Detects the destination component of the connection */
	bool Edit::DetectDestinationComponent() {
		Component* comp = pManager->IsInside(mNewGfxInfo.x2, mNewGfxInfo.y2);

		if (comp == NULL || comp == mNewSrcPin->GetGate()) {
			return false;
		}
		else if (dynamic_cast<Gate*>(comp) != NULL) {
			Gate* gate = (Gate*)comp;
			mNewDstPinIndex = gate->GetInputPinIndex(mNewGfxInfo.x2, mNewGfxInfo.y2);
			gate->GetInputPinCoordinates(mNewGfxInfo.x2, mNewGfxInfo.y2, mNewDstPinIndex);
			mNewDstPin = gate->GetInputPin(mNewDstPinIndex);

			if (mNewDstPin == NULL || mNewDstPin->IsFull()) {
				return false;
			}
			return true;
		}
		return false;
	}
	