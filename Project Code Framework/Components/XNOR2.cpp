#include "XNOR2.h"

XNOR2::XNOR2(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	mSelected = false;
	mDeleted = false;
	m_Label = "XNOR2GATE";
}
XNOR2::XNOR2(int r_FanOut) :Gate(2, r_FanOut)
{}

void XNOR2::Operate()
{

	bool out = 0;

	for (int i = 0; i < m_Inputs; i++) {
		out = out ^ ( GetInputPinStatus(i)== STATUS::HIGH ? 1 : 0);
	}

	m_OutputPin.setStatus(out ? STATUS::LOW :STATUS::HIGH);




	//caclulate the output status as the xnoring of the two input pins

	//Add you code here
}


// Function Draw
// Draws 2-input XNOR gate
void XNOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	if(!mDeleted)
	pOut->DrawXNOR2(m_GfxInfo,mSelected);
}

//returns status of outputpin
int XNOR2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XNOR2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XNOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}
// Saves the states of the component
void XNOR2::Save(ofstream& file, int i)
{
	file << "XNOR2 " << i << " " << GetLabel() << " " << (m_GfxInfo.x1) << " " << (m_GfxInfo.y1) << endl;
	setid(i);
}
void XNOR2::Load(ifstream& input, string label, int id)
{
	setid(id);
	SetLabel(label);
}

ActionType XNOR2::GetAddActionType()
{
	return ADD_XNOR_GATE_2;
}
