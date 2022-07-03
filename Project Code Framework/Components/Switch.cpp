#include "Switch.h"

Switch::Switch(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(0, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	mSelected = false;
	mDeleted = false;
	m_Label = "SWITCH";
	sim = false;
}
Switch::Switch( int r_FanOut) :Gate(0, r_FanOut)
{
}

void Switch::Operate()
{
	m_OutputPin.setStatus(GetOutPinStatus() == HIGH ? HIGH : LOW);

	//Add you code here
}


// Function Draw
// Draws switch gate
void Switch::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	if(!mDeleted)
	pOut->DrawSwitch(m_GfxInfo,mSelected,sim);
}

//returns status of outputpin
int Switch::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}

void Switch::SelectSimulation()
{
	if (UI.AppMode == MODE::SIMULATION) 
	{
		m_OutputPin.setStatus(m_OutputPin.getStatus() == HIGH ? LOW : HIGH);
	}
}


//returns status of Inputpin #n
int Switch::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void Switch::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}
// Saves the states of the component
void Switch::Save(ofstream& file, int i)
{
	file << "SWITCH " << i << " " << GetLabel() << " " << (m_GfxInfo.x1) << " " << (m_GfxInfo.y1) << endl;
	setid(i);
}
void Switch::Load(ifstream& input, string label, int id)
{
	setid(id);
	SetLabel(label);
}

ActionType Switch::GetAddActionType()
{
	return ADD_Switch;
}
