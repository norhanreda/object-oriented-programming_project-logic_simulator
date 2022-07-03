#include "Buffer.h"
#include<fstream>
Buffer::Buffer(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	mSelected = false;
	mDeleted = false;
	m_Label = "BUFFERGATE";
}
Buffer::Buffer(int r_FanOut) :Gate(1, r_FanOut)

{}

void Buffer::Operate()
{
	//the output is as input

	m_OutputPin.setStatus(m_InputPins[0].getStatus());
	//caclulate the output status as the Buffering of one input pin

	//Add you code here
}


// Function Draw
// Draws 2-input Buffer gate
void Buffer::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	if(!mDeleted)
	pOut->DrawBUF(m_GfxInfo);
}

//returns status of outputpin
int Buffer::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int Buffer::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void Buffer::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
// Saves the states of the component
void Buffer::Save(ofstream& file, int i)
{
	file << "BUFFER " << i << " " << GetLabel() << " " << (m_GfxInfo.x1) << " " << (m_GfxInfo.y1) << endl;
	setid(i);
}
void Buffer::Load(ifstream& input, string label, int id)
{
	setid(id);
	SetLabel(label);
}

ActionType Buffer::GetAddActionType()
{
	return ADD_Buff;
}
