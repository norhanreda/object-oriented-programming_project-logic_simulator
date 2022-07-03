#include "OR2.h"
#include<fstream>
OR2::OR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	mSelected = false;
	mDeleted = false;
	m_Label = "OR2GATE";
}
; OR2::OR2(int r_FanOut) :Gate(2, r_FanOut)
{}

void OR2::Operate()
{
	bool out = 0;

	for (int i = 1; i < 3; i++) {
		out = out || (GetInputPinStatus(i) ==HIGH ? 1 : 0);
	}

	m_OutputPin.setStatus(out ? HIGH : LOW);
	//caclulate the output status as the ORing of the two input pins

	//Add you code here
}


// Function Draw
// Draws 2-input OR gate
void OR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	if(!mDeleted)
	pOut->DrawOR2(m_GfxInfo,mSelected);
}

//returns status of outputpin
int OR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int OR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void OR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
void OR2::Save(ofstream& file, int i)
{
	file << "OR2 " << i << " " << GetLabel() << " " << (m_GfxInfo.x1) << " " << (m_GfxInfo.y1) << endl;
	setid(i);
}
void OR2::Load(ifstream& input, string label, int id)
{
	setid(id);
	SetLabel(label);
}

ActionType OR2::GetAddActionType()
{
	return ADD_OR_GATE_2;
}
