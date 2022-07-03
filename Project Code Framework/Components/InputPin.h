#ifndef _INPUTPIN_H
#define _INPUTPIN_H

#include "Pin.h"
class Component; //Forward class declaration
class Connection;

class InputPin: public Pin	//inherited from class Pin
{
	Component* pComp; //Component at which this pin is associated
	Connection* m_conn;
public:
	InputPin();
	void setComponent(Component* pCmp);	//sets the component of this input pin
	Component* getComponent();	//returns the component of this input pin
	
	
	void DeleteConnection(Connection* r_conn);
	void Delete();
	bool ConnectTo(Connection* r_Conn);
	Connection* GetConnection(int i);

	


};

#endif