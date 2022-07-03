#include "Pin.h"
#include "Connection.h"

Pin::Pin()
{
	m_Status = LOW;	//Default Status is LOW
	m_FanOut = MAX_CONNS;	//set the fan out of the pin.
	isset = false;
}

void Pin::setStatus(STATUS r_Status)
{
	m_Status = r_Status;
	isset = true;
}
bool Pin::getIsSet()
{
	return isset;
}

STATUS Pin::getStatus()
{
	return m_Status;
}

/* Checks if this pin is full or not */
bool Pin::IsFull() const
{
	return (mConnectionsCount == m_FanOut);
}
/* Sets the associated gate of this pin */
void Pin::SetGate(Gate* pGate) {
	mGate = pGate;
}

/* Returns the gate of this pin */
Gate* Pin::GetGate() const {
	return mGate;
}