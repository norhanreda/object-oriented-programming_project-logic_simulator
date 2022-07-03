#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions\AddANDgate3.h"
#include"Actions\AddBUFFERgate.h"
#include"Actions\AddLED.h"
#include"Actions\AddNANDgate2.h"
#include"Actions\AddNORgate2.h"
#include"Actions\AddNORgate3.h"
#include"Actions\AddNotgate.h"
#include"Actions\AddORgate2.h"
#include"Actions\AddSwitch.h"
#include"Actions\AddXNORgate2.h"
#include"Actions\AddXORgate2.h"
#include"Actions\AddXORgate3.h"

#include "Actions\Label.h"
#include"Copy.h"
#include"Cut.h"
#include"Paste.h"
#include"Select.h"
#include"Delete.h"
#include"AddConnection.h"
#include"AddConnection.h"
#include"..\Components\Connection.h"
#include"Actions/CCC.h"
#include"SaveAction.h"
#include"simulate.h"
#include"CCC.h"
#include"Actions/Edit.h"
#include"LoadAction.h"
#include<fstream>
#include"Exit.h"

ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for (int i = 0; i < MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;
}
void ApplicationManager::SetClipboard(Component* pComp)
{
	Clipboard = pComp;
}
Component* ApplicationManager::GetClipboard()
{
	return Clipboard;
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction();
}
////////////////////////////////////////////////////////////////////



void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Output* pOut = GetOutput();
	Action* pAct = NULL;
	switch (ActType)
	{
	case ADD_AND_GATE_2:
		pAct = new AddANDgate2(this);
		break;
	case ADD_AND_GATE_3:
		pAct = new AddANDgate3(this);
		break;
	case ADD_NAND_GATE_2:
		pAct = new AddNANDgate2(this);
		break;
	case ADD_OR_GATE_2:
		pAct = new AddORgate2(this);
		break;
	case ADD_NOR_GATE_2:
		pAct = new AddNORgate2(this);
		break;
	case ADD_NOR_GATE_3:
		pAct = new AddNORgate3(this);
		break;
	case ADD_XOR_GATE_2:
		pAct = new AddXORgate2(this);
		break;
	case ADD_XOR_GATE_3:
		pAct = new AddXORgate3(this);
		break;
	case ADD_XNOR_GATE_2:
		pAct = new AddXNORgate2(this);
		break;
	case ADD_Buff:
		pAct = new AddBUFFERgate(this);
		break;
	case ADD_INV:
		pAct = new AddNOTgate(this);
		break;
	case ADD_LED:
		pAct = new AddLED(this);
		break;
	case ADD_Switch:
		pAct = new AddSwitch(this);
		break;
	case ADD_CONNECTION:
		//pAct = new AddConnection(this);
		pAct = new CCC(this);
		break;

	case COPY:
		pAct = new Copy(this);
		break;
	case CUT:
		pAct = new Cut(this);
		break;
	case PASTE:
		pAct = new Paste(this);
		break;
	case SELECT:
		pAct = new Select(this);
		break;
	case DEL:
		pAct = new Delete(this);
		break;
	case ADD_Label:
		pAct = new Label(this);
		break;
	case EDIT:
		pAct = new Edit(this);
		break;
	case SAVE:
		pAct = new SaveAction(this);
		break;
	case LOAD:
		pAct = new LoadAction(this);
		break;
	case SIMULATE:
		pAct = new simulate(this);
		break;
	case EXIT:
		pAct = new Exit(this);
		break;
	}
	if (pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{

	for (int i = 0; i < CompCount; i++)
		if(CompList[i]!=NULL)
		CompList[i]->Draw(OutputInterface);

}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}
/////////////////////////////////////////////////////////////////////
Component* ApplicationManager::IsInside(int x, int y)
{
	Component* Comp = NULL;
	for (int i = 0; i < CompCount; i++)
	{
		Comp = CompList[i]->InsideArea(x, y);
		if (Comp != NULL)
			//return Comp;
			break;
	}
	return Comp;
}
// is inside area
Component * ApplicationManager::insidreArea(double xi, double yi)
{

	for (int i = 0; i < CompCount; i++)
	{

		if (CompList[i]->insidreArea(xi, yi) != NULL)
		{
			Component* c = dynamic_cast<Gate*>(CompList[i]);
			if (c != NULL)
				return c;
			else return NULL;
		}

	}
}
void ApplicationManager::DeleteComponent()
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->IsDeleted())
		{
			Component* temp = CompList[i];
			CompList[i] = CompList[CompCount];
			CompList[CompCount] = temp;
			CompList[CompCount] = NULL;
			CompCount--;
		}
	}
}
void ApplicationManager::Save(ofstream& file)
{
	int gatecount = 0;
	for (int i = 0; i < CompCount; i++)
	{
		Gate* p = dynamic_cast<Gate*>(CompList[i]);
		if (p != NULL)
			gatecount++;
	}
	file << gatecount << endl;
	for (int i = 0; i < CompCount; i++)
	{
		Gate* p = dynamic_cast<Gate*>(CompList[i]);
		if (p != NULL)
			if (!(p->IsDeleted()))
			{
				p->Save(file, i);
			}
	}
	file << "Connections" << endl;
	for (int i =0; i < CompCount; i++)
	{
		Connection* p = dynamic_cast<Connection*>(CompList[i]);
		if (p != NULL)
			if (!(p->IsDeleted()))
			{
				p->Save(file);
			}
	}
	

}
Component* ApplicationManager::LoadConnection(int x)
{
	
	for (int i = 0; i < CompCount; i++) 
	{
		Gate* p = dynamic_cast<Gate*>(CompList[i]);
		if (p != NULL) 
			if ((p->getid()) == x)
				return p;
	}
}
/*Component* ApplicationManager::GetLeds()
{
	for (int i = 0; i < CompCount; i++)
	{
		if (dynamic_cast<LED*>(CompList[i]) != NULL)
		{
			return CompList[i];
		}
	}
}
Component* ApplicationManager::GetSwitchs()
{
	for (int i = 0; i < CompCount; i++)
	{
		if (dynamic_cast<Switch*>(CompList[i]) != NULL)
		{
			return CompList[i];
		}
	}
}*/
void ApplicationManager::SelectSimulation()
{

	for (int i = 0; i < CompCount; i++)
	{
		if (dynamic_cast<Switch*>(CompList[i]) != NULL)
		{
			((Switch*)CompList[i])->SelectSimulation();
		}
	}

}
void ApplicationManager::OperateConnctionSimulation()
{

	for (int i = 0; i < CompCount; i++)
	{
		if (dynamic_cast<Connection*>(CompList[i]) != NULL)
		{
			if(((Connection*)CompList[i])->getSourcePin()->getIsSet())
			         ((Connection*)CompList[i])->Operate();
		}
	}

}
void ApplicationManager::OperateGatesSimulation()
{

	for (int i = 0; i < CompCount; i++)
	{
		if (dynamic_cast<Gate*>(CompList[i]) != NULL && dynamic_cast<Switch*>(CompList[i]) == NULL&& dynamic_cast<LED*>(CompList[i]) == NULL)
		{
			for (int i = 0; i < ((Gate*)CompList[i])->getNOofInputs(); i++)
			{
				if (((Gate*)CompList[i])->GetInputPin(i)->getIsSet())
					   ((Gate*)CompList[i])->Operate();
			}
			
		}
	}

}
void ApplicationManager::OperateLedSimulation()
{

	for (int i = 0; i < CompCount; i++)
	{
		if ( dynamic_cast<LED*>(CompList[i]) != NULL)
		{
			
				if (((LED*)CompList[i])->GetInputPin(i)->getIsSet())
					((LED*)CompList[i])->Operate();
		}
	}

}
int ApplicationManager::getCompCount()
{
	return CompCount;
}

void ApplicationManager::Assigncomp(Component* l,Component* d, int N)
{
	//ApplicationManager* pAct = NULL;
//	pAct = new CCC(this, l, d,N);
	//Component* Pcomp;
	//Pcomp = l;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;

}