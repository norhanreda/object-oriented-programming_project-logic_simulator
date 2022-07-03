#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include<fstream>

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	Component* Clipboard;  //
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)

	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface


public:


public:
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();

	//Creates an action and executes it
	void ExecuteAction(ActionType);

	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);

	void SetClipboard(Component* pComp);
	Component* GetClipboard();

	Component* IsInside(int x, int y);
	Component* insidreArea(double xi, double yi);
	void DeleteComponent();
	void Save(ofstream& file);
	// Loads the circuit from the file 
	Component* LoadConnection(int i);

	Component* GetLeds();
	Component* GetSwitchs();
	void SelectSimulation();
	void OperateConnctionSimulation();
	void OperateGatesSimulation();
	void OperateLedSimulation();




	int getCompCount();
	void Assigncomp(Component* l,Component* d,int N);
	//destructor
	~ApplicationManager();
};

#endif