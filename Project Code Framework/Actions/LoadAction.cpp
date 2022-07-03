#include "LoadAction.h"

#include "..\ApplicationManager.h"
#include<fstream>
#include "AddANDgate2.h"
#include"CCC.h"
#include"..\Components\Connection.h"
void LoadAction::ReadActionParameters() {
	read.open("Data.txt");

	if (read.is_open()) 
	{
		i = true;
	}
	else i = false;
}
LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp)
{
}

LoadAction::~LoadAction(void)
{
}

void LoadAction::Execute()
{
	ReadActionParameters();
	if (i)
	{
		Output* pOut = pManager->GetOutput();
		pOut->ClearDrawingArea();
		Component* c[200];
		string s = "";
		string ss = "";
		string sss = "";
		string ssss = "";
		string sssss = "";
		int id;
		int x;
		int y;
		int CompCountt;
		getline(read, CT);
		CompCountt = stoi(CT);
		for (int i = 0; i < CompCountt; i++)
		{
				s = "";
			ss = "";
				sss = "";
				ssss = "";
			sssss = "";
			getline(read, CT);
			int n = 0;
			for (; n < CT.length();n++)
			{
				if (CT[n] != ' ')
					s += CT[n];
				else break;
			}
			n++;
			for (; n < CT.length();n++)
			{
				if (CT[n] != ' ')
					ss += CT[n];
				else break;

			}
			n++;
			for (; n < CT.length();n++)
			{
				if (CT[n] != ' ')
					sss += CT[n];
				else break;
			}
			n++;
			for (; n < CT.length();n++)
			{
				if (CT[n] != ' ')
					ssss += CT[n];
				else break;
			}
			n++;
			for (; n < CT.length();n++)
			{
				if (CT[n] != ' ')
					sssss += CT[n];
				else break;
			}
			id = stoi(ss);
			x = stoi(ssss);
			y = stoi(sssss);
			GraphicsInfo the_location;
			the_location.x1 = x;
			the_location.x2 = x + 50;
			the_location.y1 = y;
			the_location.y2 = y + 50;

			if (s == "AND2")
			{
				c[i] = new AND2(the_location, AND2_FANOUT);
				c[i]->Load(read, sss, id);

			}
			else if (s == "OR2")
			{
				c[i] = new AND2(the_location, AND2_FANOUT);
				c[i]->Load(read, sss, id);

			}
			else if (s == "NOT")
			{
				c[i] = new AND2(the_location, AND2_FANOUT);
				c[i]->Load(read, sss, id);

			}
			else if (s == "NAND2")
			{
				c[i] = new AND2(the_location, AND2_FANOUT);
				c[i]->Load(read, sss, id);

			}
			else if (s == "NOR2")
			{
				c[i] = new AND2(the_location, AND2_FANOUT);
				c[i]->Load(read, sss, id);

			}
			else if (s == "XOR2")
			{
				c[i] = new AND2(the_location, AND2_FANOUT);
				c[i]->Load(read, sss, id);

			}
			else if (s == "XNOR2")
			{
				c[i] = new AND2(the_location, AND2_FANOUT);
				c[i]->Load(read, sss, id);

			}
			else if (s == "AND3")
			{
				c[i] = new AND2(the_location, AND2_FANOUT);
				c[i]->Load(read, sss, id);

			}
			else if (s == "NOR3")
			{
				c[i] = new AND2(the_location, AND2_FANOUT);
				c[i]->Load(read, sss, id);

			}
			else if (s == "XOR3")
			{
				c[i] = new AND2(the_location, AND2_FANOUT);
				c[i]->Load(read, sss, id);

			}
			else if (s == "BUFFER")
			{
				c[i] = new AND2(the_location, AND2_FANOUT);
				c[i]->Load(read, sss, id);

			}
			else if (s == "SWITCH")
			{
				c[i] = new AND2(the_location, AND2_FANOUT);
				c[i]->Load(read, sss, id);

			}
			else if (s == "LED")
			{
				c[i] = new AND2(the_location, AND2_FANOUT);
				c[i]->Load(read, sss, id);

			}
			pManager->AddComponent(c[i]);
			
		}
		getline(read, CT);
		CT = "";
		while (getline(read, CT), CT != "-1")
		{
			string Srcid = "";
			string Dstid = "";
			string pinnum = "";
			int SrcID;
			int DstID;
			int PINnum;
			{
				int n = 0;
				for (; n < CT.length();n++)
				{
					if (CT[n] != ' ')
						Srcid += CT[n];
					else break;
				}
				n++;
				for (; n < CT.length();n++)
				{
					if (CT[n] != ' ')
						Dstid += CT[n];
					else break;

				}
				n++;
				for (; n < CT.length();n++)
				{
					if (CT[n] != ' ')
						pinnum += CT[n];
					else break;

				}
				SrcID = stoi(Srcid);
				DstID = stoi(Dstid);
				PINnum = stoi(pinnum);
				Component* SrcComp = pManager->LoadConnection(SrcID);
				GraphicsInfo Srcgr = SrcComp->GetGraphicsInfo();
				GraphicsInfo Con;
				Con.x1 = Srcgr.x1;
				Con.y1 = Srcgr.y1; 
				Component* DstComp = pManager->LoadConnection(DstID);
				GraphicsInfo Dstgr = DstComp->GetGraphicsInfo();
				Con.x2 = Dstgr.x2;
				Con.y2 = Dstgr.y2;
				OutputPin* SrcPin = ((Gate*)SrcComp)->GetOutputPin();
				InputPin* DstPin = ((Gate*)SrcComp)->GetInputPin(PINnum);
				Action* pAct = NULL;
				//34an kda lazm n7tha hnk aw ngrb kda hena
				pAct = new CCC(pManager, SrcComp, DstComp, PINnum);
				pAct->Execute();
				delete pAct;
				//c[i] = new Connection(Con, SrcPin, DstPin);
				//((Connection*)c[i])->Load(read, SrcID, DstID, PINnum);
				
				Srcid = ""; //mmoken
				Dstid = "";
				pinnum = "";
			}
		}
		pOut->PrintMsg("Loaded");

	}
}
void LoadAction::Undo()
{}

void LoadAction::Redo()
{}