#include "InputPin.h"
#include"Connection.h"
InputPin::InputPin()
{
	m_conn = NULL;
	pComp = NULL;
}

void InputPin::setComponent(Component *pCmp)
{
	this->pComp = pCmp;
}

Component* InputPin::getComponent()
{
	return pComp;
}

void InputPin::DeleteConnection(Connection* r_conn)
{
	if (r_conn == NULL)
		return;
	else
	    m_conn = NULL;
}
void InputPin::Delete()
{
	if (m_conn == NULL)
		return;
	else
	   m_conn->Delete();
}
bool InputPin::ConnectTo(Connection* r_Conn)
{  
	if (r_Conn == NULL)
		return false;

	if (m_conn == NULL)
	{
		m_conn = r_Conn;
		return true;
	}
	else
	    return false;
	
}
Connection* InputPin::GetConnection(int i)
{
	if (m_conn != NULL)
	{
		return m_conn;
	}
	return 0;
}
