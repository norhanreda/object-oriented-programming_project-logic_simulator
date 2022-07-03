#include "AND2.h"


AND2::AND2(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	mSelected = false;
	mDeleted = false;
	m_Label = "AND2Gate";
}
void AND2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	
		bool out = 1;

		for (int i = 0; i < m_Inputs; i++) {
			out = out && (GetInputPinStatus(i) == STATUS::HIGH ? 1 : 0);
		}

		m_OutputPin.setStatus(out ? STATUS::HIGH:STATUS::LOW);

	//Add you code here
}


// Function Draw
// Draws 2-input AND gate
void AND2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	if(!mDeleted)
	pOut->DrawAND2(m_GfxInfo, mSelected);
		

}

//returns status of outputpin
int AND2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int AND2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void AND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}

ActionType AND2::GetAddActionType()
{
	return ADD_AND_GATE_2;
}
void AND2::Load(ifstream& input,string label,int id)
{
	setid(id);
	SetLabel(label);
}
void AND2::Save(ofstream& file, int i)
{
	file << "AND2 " << i << " " << GetLabel() << " " << (m_GfxInfo.x1) << " " << (m_GfxInfo.y1) << endl;
	setid(i);
}
/*int Gate::getpinnumber(InputPin* p)
{
	for (int i = 0; i < m_Inputs; i++)
		if (&m_InputPins[i] == p)
			return (i + 1);
}*/