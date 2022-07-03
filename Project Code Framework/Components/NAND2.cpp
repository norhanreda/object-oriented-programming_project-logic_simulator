#include "NAND2.h"
#include<fstream>
NAND2::NAND2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	mSelected = false;
	mDeleted = false;
	m_Label = "NAND2GATE";
}
NAND2::NAND2(int r_FanOut):Gate(2,r_FanOut)
{}
void NAND2::Operate()
{
	bool out = 1;

	for (int i = 1; i <3; i++) {
		out = out && (GetInputPinStatus(i) == HIGH ? 1 : 0);
	}

	m_OutputPin.setStatus(out ? STATUS::LOW : STATUS::HIGH);
	//caclulate the output status as the NANDing of the two input pins

	//Add you code here
}


// Function Draw
// Draws 2-input NAND gate
void NAND2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	if(!mDeleted)
	pOut->DrawNAND2(m_GfxInfo,mSelected);
}

//returns status of outputpin
int NAND2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NAND2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NAND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
//Saves the states of the component
void NAND2::Save(ofstream & file, int i) 
{
	file << "NAND2" << i << " " << GetLabel() << " " << (m_GfxInfo.x1) << " " << (m_GfxInfo.y1) << endl;
	setid(i);

}
void NAND2::Load(ifstream& input, string label, int id)
{
	setid(id);
	SetLabel(label);
}

ActionType NAND2::GetAddActionType()
{
	return ADD_NAND_GATE_2;
}
