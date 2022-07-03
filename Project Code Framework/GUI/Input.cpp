//#include "Input.h"
#include "Output.h"
#include<iostream>
using namespace std;
#include<cstring>
#include <string>


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}
/* Waits and returns the user's mouse click coordinate */
void Input::WaitMouseClick(int& x, int& y) {
	pWind->WaitMouseClick(x, y);
	mLastX = x;
	mLastY = y;
}

string Input::GetSrting(Output* pOut)
{
	///TODO: Implement this Function
	//Read a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" should be also supported
	//User should see what he is typing at the status bar

	pOut->PrintMsg("Set Component Label:");
	// ASCII Codes
	const int ESCAPE = 27;
	const int ENTER = 13;
	const int BACKSPACE = 8;

	char c;
	string s;
	do {
		//cin >> s;
		pWind->FlushKeyQueue();
		pOut->PrintMsg(s);
		pWind->WaitKeyPress(c);

		switch (c) {
		case BACKSPACE:
			if (!s.empty()) s.pop_back();
			break;
		case ESCAPE:
			s.clear();
			break;
		case ENTER:
			// Nothing to be done here
			break;
		default:
			s.push_back(c);
		}
		pOut->PrintMsg(s);
	} while (c != ESCAPE && c != ENTER);
	return s;
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_AND2:   return ADD_AND_GATE_2;
			case ITM_OR2:    return ADD_OR_GATE_2;
			case ITM_INV:    return ADD_INV;
			case ITM_NAND2:  return ADD_NAND_GATE_2;
			case ITM_NOR2:   return ADD_NOR_GATE_2;
			case ITM_BUF:    return ADD_Buff;
			case ITM_XOR2:   return ADD_XOR_GATE_2;
			case ITM_XNOR2:  return ADD_XNOR_GATE_2;
			case ITM_AND3:   return ADD_AND_GATE_3;
			case ITM_NOR3:   return ADD_NOR_GATE_3;
			case ITM_XOR3:   return ADD_XOR_GATE_3;
			case ITM_LED:    return ADD_LED;
			case ITM_SWITCH: return ADD_Switch;
			case ITM_CONNECTION: return ADD_CONNECTION;

			case ITM_SIMULATE:return SIMULATE;
			case ITM_COPY:    return COPY;
			case ITM_CUT:     return CUT;
			case ITM_PASTE:   return PASTE;
			case ITM_DELETE:  return DEL;
			case ITM_SAVE:    return SAVE;
			case ITM_LOAD:    return LOAD;

			case ITM_EDIT:    return EDIT;
			case ITM_REDO:    return ADD_Label;
			case ITM_EXIT:   return EXIT;
			case ITM_UNDO: return SIM_MODE;

			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
	}
	if (UI.AppMode == SIMULATION)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{

			case ITM_EXIT:   return EXIT;

			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}
	}
}


Input::~Input()
{
}