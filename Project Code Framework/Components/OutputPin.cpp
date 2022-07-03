#include "OutputPin.h"
#include "Connection.h"

OutputPin::OutputPin(int r_FanOut)
{
	m_Conn = 0;		//initially Pin is not connected to anything.
	
	m_FanOut = r_FanOut > MAX_CONNS ? MAX_CONNS : r_FanOut;	//set the fan out of the pin.
	for (int i = 0; i < MAX_CONNS; i++)
	{
		m_Connections[i] = NULL;
	}

}

//Functionn ConnectTo:
//Connects the ouput pin the the passed connection if the fan out permits
//if the no. of connections is already equals to the fan out, no more connections can be created.
bool OutputPin::ConnectTo(Connection *r_Conn)
{
	if(m_Conn < m_FanOut)
	{
		m_Connections[m_Conn++] = r_Conn;	//add a new connection to the the array of connections
		return true;
	}
	
	return false;	//can't connect to any more connections
}

void OutputPin::DeleteConnection(Connection* r_Conn)
{
	if (r_Conn == NULL)
		return;
	bool isConnected = false;
	for (int i = 0; i < m_Conn; i++)
	{
		if (m_Connections[i] != NULL)
			isConnected = true;
	}
	if (!isConnected)
		return; 

		//search for the connection
		int index = -1;
		for (int i = 0; i < m_Conn; i++)    
		{
			if (m_Connections[i] == r_Conn)
			{
				index = i;
				return;
			}
		}

		if (index == -1)   //if connection is not found
			return;
		else               //if connection is found -> remove it 
		{
			m_Connections[index] = NULL;
			for (int i = index; i < m_Conn; i++)
			{
				m_Connections[i] = m_Connections[i + 1];
			}
			m_Connections[m_Conn] = NULL;
			m_Conn--;
		}
	
}
void OutputPin::Delete()
{
	bool isConnected = false;
	for (int i = 0; i < m_Conn; i++)
	{
		if (m_Connections[i] != NULL)
			isConnected = true;
	}
	if (!isConnected)
		return;

	for (int i = 0; i < m_Conn; i++)
	{
		m_Connections[i]->Delete();
	}
}
