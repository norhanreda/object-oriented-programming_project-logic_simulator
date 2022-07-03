#include "AND3.h"

AND3::AND3(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	mSelected = false;
	mDeleted = false;
	m_Label = "AND3GATE";
}


void AND3::Operate()
{
	bool out = 1;

	for (int i = 0; i < m_Inputs; i++) {
		out = out && (GetInputPinStatus(i) == STATUS::HIGH ? 1 : 0);
	}

	m_OutputPin.setStatus(out ? STATUS::HIGH : STATUS::LOW);

	//caclulate the output status as the ANANDING of the THREE input pins

	//Add you code here
}


// Function Draw
// Draws 3-input AND gate
void AND3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	if(!mDeleted)
	pOut->DrawAND3(m_GfxInfo,mSelected);
}

//returns status of outputpin
int AND3::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int AND3::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void AND3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}
// Saves the states of the component
void AND3::Save(ofstream& file,int i)
{
	file << "AND3 " << i << " " << GetLabel() << " " << (m_GfxInfo.x1) << " " << (m_GfxInfo.y1) << endl;
	setid(i);
}

void AND3::Load(ifstream& input, string label, int id)
{
	setid(id);
	SetLabel(label);
}

ActionType AND3::GetAddActionType()
{
	return ADD_AND_GATE_3;
}
