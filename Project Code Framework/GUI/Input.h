#pragma once

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "UI_Info.h"

class Output;
class Input		//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
	int mLastX, mLastY;		// Last point clicked
public:
	Input(window*);
	void GetPointClicked(int&, int&);	//Get coordinate where user clicks
	string GetSrting(Output*);		//Returns a string entered by the user

	ActionType GetUserAction() const; //Reads the user click and maps it to an action

	/* Waits and returns the user's mouse click coordinate */
	void WaitMouseClick(int& x, int& y);

	~Input();
};
