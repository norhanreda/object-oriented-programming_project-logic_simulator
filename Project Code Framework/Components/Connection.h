#pragma once
#include "component.h"
#include "InputPin.h"
#include "OutputPin.h"
#include"InputPin.h"
#include"OutputPin.h"
#include<fstream>
#include"../ApplicationManager.h"
#include"Gate.h"
#include"SaveAction.h"

class Connection :	public Component
{
	Component*	SrcCmpnt;	//Connection source component
	Component*	DstCmpnt;	//Connection Destination component
	int		DstPinn;		//The Input pin to which this connection is linked
	OutputPin* SrcPin;	//The Source pin of this connection (an output pin of certain Component)
	InputPin* DstPin;	//The Destination pin of this connection (an input pin of certain Component)
	ApplicationManager* p;
	

public:
	//Connection(const GraphicsInfo &r_GfxInfo, Component *pS=NULL,Component *pD=NULL, int Pin=0);
	Connection();
	Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin);

	virtual void Operate() ;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut);	//for each component to Draw itself

	
	void setSourcePin(OutputPin *pSrcPin);
	void setDestPin(InputPin* pDstPin, int mDstPinIndex);
		OutputPin* getSourcePin();
	InputPin* getDestPin();


	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

	virtual Connection* InsideArea(int x, int y);
	void setSrcComp(Component* cmp);
	void setDstComp(Component* cmp);
	Component* getSrcComp();
	Component* getDstComp();
	void SetPinNo(int i);
	int GetPinNo();

	void Load(ifstream& read, int s, int d, int n);
	void Load(ifstream& read, string label, int id);
	void Save(ofstream& file);
	//virtual int getpinnumber(InputPin*);



	virtual void Delete();
	ActionType GetAddActionType();


};