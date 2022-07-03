#ifndef _PIN_H
#define _PIN_H
class Gate;
#include "..\Defs.h"

class Pin
{
protected:
	STATUS m_Status;	//Status of the Pin
	Gate* mGate;
	int mConnectionsCount;						// Actual number of connections connected to that pin
	int m_FanOut;								// Maximum number of connections that can be connected to that pin
	bool isset;
public:
	Pin();
	void setStatus(STATUS r_Status);
	STATUS getStatus();
	/* Sets the associated gate of this pin */
	void SetGate(Gate* pGate);

	/* Returns the gate of this pin */
	Gate* GetGate() const;

	/* Checks if this pin is full or not */

	bool IsFull() const;
	bool getIsSet();






};

#endif