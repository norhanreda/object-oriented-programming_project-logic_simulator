#ifndef _AND3_H
#define _AND3_H

/*
  Class AND3
  -----------
  represent the 3-input NAND gate
*/

#include "Gate.h"
#include <fstream>

class AND3:public Gate
{
public:
	AND3(const GraphicsInfo &r_GfxInfo, int r_FanOut);


	virtual void Operate();	//Calculates the output of the NAND gate
	virtual void Draw(Output* pOut);	//Draws 3-input gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual void Save(ofstream& file,int i);// Saves the states of the component
	virtual void Load(ifstream& input, string label, int id);// Saves the states of the component
	virtual ActionType GetAddActionType();

};

#endif