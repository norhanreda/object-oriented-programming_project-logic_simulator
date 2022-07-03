
#ifndef _GATE_H
#define _GATE_H

/*
  Class Gate
  -----------
  - Base class for all types of gates
  - Each gate has n inputs pins and one output pin
*/


#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"
#include"SaveAction.h"

class Gate:public Component
{
protected:
	InputPin* m_InputPins;	//Array of input pins of the Gate
	OutputPin m_OutputPin;	//The Gate output pin
	int m_Inputs;		//No. of input pins of that Gate.
public:
	Gate(int r_Inputs, int r_FanOut);
	virtual void Delete();

	/* Returns the selected input pin index */
	virtual int GetInputPinIndex(int x, int y); 

	/* Returns the input pin coordiantes of the gate according to its index */
	virtual void GetInputPinCoordinates(int& x, int& y, int n);

	/* Returns the output pin coordiantes of the gate */
	virtual void GetOutputPinCoordinates(int& x, int& y);

	/* Returns the input pin number n (0-indexed) of the component */
	virtual InputPin* GetInputPin(int n);
	void getCoord(int& x1, int& y1); 
	/* Returns the output pin of the component */
	virtual OutputPin* GetOutputPin();
	virtual void Save(ofstream& file, int i) = 0;
	int getpinnumber(InputPin* p);

	int getNOofInputs();


	~Gate();


};

#endif
