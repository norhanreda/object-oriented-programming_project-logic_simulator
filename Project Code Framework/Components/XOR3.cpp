#include "XOR3.h"

XOR3::XOR3(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	mSelected = false;
	mDeleted = false;
	m_Label = "XOR3GATE";
}
XOR3::XOR3(int r_FanOut) :Gate(3, r_FanOut)
{}

void XOR3::Operate()
{

	bool out = 0;

	for (int i = 0; i < m_Inputs; i++) {
		out = out ^ (GetInputPinStatus(i) == STATUS::HIGH ? 1 : 0);
	}

	m_OutputPin.setStatus(out ? STATUS::HIGH : STATUS::LOW);
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
}


// Function Draw
// Draws 3-input XOR gate
void XOR3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	if(!mDeleted)
	pOut->DrawXOR3(m_GfxInfo,mSelected);
}

//returns status of outputpin
int XOR3::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR3::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}
// Saves the states of the component
void XOR3::Save(ofstream& file, int i)
{
	file << "XOR3 " << i <<" "<< GetLabel() << " " << (m_GfxInfo.x1) << " " << (m_GfxInfo.y1) << endl;
	setid(i);
}
void XOR3::Load(ifstream& input, string label, int id)
{
	setid(id);
	SetLabel(label);
}

ActionType XOR3::GetAddActionType()
{
	return ADD_XOR_GATE_3;
}
