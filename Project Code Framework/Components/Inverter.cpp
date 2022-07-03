#include "Inverter.h"
#include <fstream>

Inverter::Inverter(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	mSelected = false;
	mDeleted = false;
	m_Label = "INVERTERGATE";
}
Inverter::Inverter(int r_FanOut):Gate(1,r_FanOut)
{}
void Inverter::Operate()
{
	m_OutputPin.setStatus(GetInputPinStatus(0) == LOW ? HIGH : LOW);
	//caclulate the output status as the Invertering of the two input pins

	//Add you code here
}


// Function Draw
// Draws 2-input Inverter gate
void Inverter::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	if(!mDeleted)
	pOut->DrawINV(m_GfxInfo,mSelected);
}

//returns status of outputpin
int Inverter::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int Inverter::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void Inverter::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
// Saves the states of the component
void Inverter::Save(ofstream& file,int i)
{
	file << "Inverter " << i << " " << GetLabel() << " " << (m_GfxInfo.x1) << " " << (m_GfxInfo.y1) << endl;
	setid(i);
}
void Inverter::Load(ifstream& input, string label, int id)
{
	setid(id);
	SetLabel(label);
}

ActionType Inverter::GetAddActionType()
{
	return ADD_INV;
}
