#ifndef _LED_H
#define _LED_H

/*
  Class LED
  -----------
  represent the LED
*/

#include "Gate.h"
#include <fstream>

class LED :public Gate
{
	bool sim;
public:
	LED(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	LED(int r_FanOut);
	virtual void Operate();	//Calculates the output of the LED
	virtual void Draw(Output* pOut);	//Draws LED

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual void Save(ofstream& file,int i);// Saves the states of the component
	virtual void Load(ifstream& input, string label, int id);// Saves the states of the component
	virtual ActionType GetAddActionType();
};

#endif