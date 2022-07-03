#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Output.h"



//Base class for classes Gate, Switch, and LED.
class Component
{
private:
protected:
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	bool mSelected;
	bool mDeleted;
	int id;
	string m_Label;


public:
	Component();
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself
	
	
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.

	virtual Component* InsideArea(int x, int y);
	virtual Component* insidreArea(double x, double y);

	GraphicsInfo GetGraphicsInfo();

	void SetSelected(bool s);
	void SetDeleted(bool d);
	bool IsSelected();
	bool IsDeleted();

	virtual ActionType GetAddActionType()=0;
	virtual void Delete() = 0;

	/* Sets the label of the component */
	void SetLabel(const string& label);
	/* Returns the label of the component */
	string GetLabel() const;

	//virtual void Delete() = 0;
	virtual void Load(ifstream& input, string label, int id) = 0;
//	virtual int getpinnumber(InputPin*) = 0;
	virtual int getid();
	void setid(int i);
		
	
	//Destructor must be virtual
	virtual ~Component();
};

#endif
