#ifndef _Switch_H
#define _Switch_H

/*
  Class Switch
  -----------
  represent the switch
*/

#include "Gate.h"
#include <fstream>

class Switch:public Gate
{
	bool sim;
public:
	Switch(const GraphicsInfo &r_GfxInfo, int r_FanOut);
	Switch(int r_FanOut);

	virtual void Operate();	//Calculates the output of the wsitch gate
	virtual void Draw(Output* pOut);	//Draws switch gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual void Save(ofstream& file,int i);// Saves the states of the component
	virtual void Load(ifstream& input, string label, int id);// Saves the states of the component
	virtual ActionType GetAddActionType();
	void SelectSimulation();

};

#endif