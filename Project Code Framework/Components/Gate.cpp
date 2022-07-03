#include "Gate.h"

//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(int r_Inputs, int r_FanOut):m_OutputPin(r_FanOut)
{
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;	//set no. of inputs of that gate
	
	//Associate all input pins to this gate
	for(int i=0; i<m_Inputs; i++)
		m_InputPins[i].setComponent(this);
}
void Gate::Delete()
{
	mSelected = false;
	mDeleted = true;
	m_OutputPin.Delete();
	for (int i = 0; i < m_Inputs; i++)
	{
		m_InputPins[i].Delete();
	}
	
}
/* Returns the input pin coordiantes of the gate according to its index */
void Gate::GetInputPinCoordinates(int& x, int& y, int n) 
{
	x = m_GfxInfo.x1;
	if (m_Inputs == 1)
		y = m_GfxInfo.y1 + (UI.AND2_Height / 2);
	else if (m_Inputs == 2)
	y = m_GfxInfo.y1 + n * (UI.AND2_Height / 4) + (n - 1)*(UI.AND2_Height / 4);
	else if (m_Inputs == 3)
	y = m_GfxInfo.y1 + n * (UI.AND2_Height / 4);
}

/* Returns the output pin coordiantes of the gate */
void Gate::GetOutputPinCoordinates(int& x, int& y) {
	
	x = m_GfxInfo.x2;
	y = m_GfxInfo.y1 + (m_GfxInfo.y2 - m_GfxInfo.y1) / 2;
}
// Returns the selected input pin index
int Gate::GetInputPinIndex(int x, int y) {
	int h = (m_GfxInfo.y2 - m_GfxInfo.y1);
	int n = (y - m_GfxInfo.y1) * m_Inputs / h;
	return n;
}

/* Returns the input pin number n (0-indexed) of the component */
InputPin* Gate::GetInputPin(int n) 
{
	return &m_InputPins[n];
}

void Gate::getCoord(int& x1, int& y1)
{
	x1 = m_GfxInfo.x1 + UI.AND2_Width / 2;
	y1 = m_GfxInfo.y1 + UI.AND2_Width / 2;

}

/* Returns the output pin of the component */
OutputPin* Gate::GetOutputPin() {
	return &m_OutputPin;
}
int Gate::getpinnumber(InputPin* p)
{
	for (int i = 0; i < m_Inputs; i++)
		if (&m_InputPins[i] == p)
			return (i + 1);
}

int Gate::getNOofInputs()
{
	return m_Inputs;
}

Gate::~Gate()
{
	delete[]m_InputPins;
	
}
