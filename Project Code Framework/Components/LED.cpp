#include "LED.h"

LED::LED(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	mSelected = false;
	mDeleted = false;
	m_Label = "LED";
	sim = false;
}
LED::LED(int r_FanOut) :Gate(1, r_FanOut)
{}
void LED::Operate() 
{
	if (GetInputPinStatus(1)==1)
	{
		sim = true;
	}
		return;
	//caclulate the output status of the LED
	//Add you code here
}


// Function Draw
// Draws LED
void LED::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	if(!mDeleted)
	pOut->DrawLED(m_GfxInfo,mSelected,sim);

}

//returns status of outputpin
int LED::GetOutPinStatus()
{
	return -1;
}


//returns status of Inputpin #n
int LED::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void LED::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
// Saves the states of the component
void LED::Save(ofstream& file,int i)
{
	file << "LED " << i << " " << GetLabel() << " " << (m_GfxInfo.x1) << " " << (m_GfxInfo.y1) << endl;
	setid(i);
}
void LED::Load(ifstream& input, string label, int id)
{
	setid(id);
	SetLabel(label);
}

ActionType LED::GetAddActionType()
{
	return ADD_LED;
}

