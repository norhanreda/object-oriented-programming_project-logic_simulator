#include "NOR2.h"
#include<fstream>
NOR2::NOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	mSelected = false;
	mDeleted = false;
	m_Label = "NOR2GATE";
}
NOR2::NOR2(int r_FanOut) :Gate(2, r_FanOut)
{}
void NOR2::Operate()
{
	bool out = 0;

	for (int i = 1; i < 3; i++) {
		out = out || (GetInputPinStatus (i)== HIGH ? 1 : 0);
	}

	m_OutputPin.setStatus(out ? LOW : HIGH);
	//caclulate the output status as the NORing of the two input pins

	//Add you code here
}


// Function Draw
// Draws 2-input NOR gate
void NOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	if(!mDeleted)
	pOut->DrawNOR2(m_GfxInfo,mSelected);
}

//returns status of outputpin
int NOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
void NOR2::Save(ofstream& file, int i)
{
	file << "NOR2 " << i << " " << GetLabel() << " " << (m_GfxInfo.x1) << " " << (m_GfxInfo.y1) << endl;
	setid(i);
}
void NOR2::Load(ifstream& input, string label, int id)
{
	setid(id);
	SetLabel(label);
}

ActionType NOR2::GetAddActionType()
{
	return ADD_NOR_GATE_2;
}
