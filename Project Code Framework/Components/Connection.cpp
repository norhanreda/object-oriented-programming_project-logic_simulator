#include "Connection.h"

Connection::Connection()
{

}
Connection::Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin):Component(r_GfxInfo)	
{
	//SrcPin = pSrcPin;
	//DstPin = pDstPin;
	SrcPin = NULL;
	DstPin = NULL;

}
void Connection::setSourcePin(OutputPin *pSrcPin)
{	
	
	SrcPin = pSrcPin;
    SrcPin->ConnectTo(this);  

}

OutputPin* Connection::getSourcePin()
{	return SrcPin;	}


void Connection::setDestPin(InputPin* pDstPin, int mDstPinIndex)
{
	DstPinn = mDstPinIndex;
	DstPin = pDstPin;
	DstPin->ConnectTo(this);


}
InputPin* Connection::getDestPin()
{	return DstPin;	}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

void Connection::Draw(Output* pOut)
{
	if (!mDeleted)
	    pOut->DrawConnection(m_GfxInfo,mSelected);
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}

void Connection::Delete()
{
	mSelected = false;
	mDeleted = true;
	SrcPin->DeleteConnection(this);
	DstPin->DeleteConnection(this);
}


Connection* Connection::InsideArea(int x, int y)
{
	//Component* mComp;
	if (x >= m_GfxInfo.x1 && x <= (m_GfxInfo.x1 + m_GfxInfo.x2) / 2 && y >= m_GfxInfo.y1 - 10 && y <= m_GfxInfo.y1 + 10)
		return this;
	else if (x >= (m_GfxInfo.x1 + m_GfxInfo.x2) / 2-10 && x <= (m_GfxInfo.x1 + m_GfxInfo.x2) / 2+10 )
		return this;
	else if (x >= (m_GfxInfo.x1 + m_GfxInfo.x2) / 2 && x <= m_GfxInfo.x2  && y >= m_GfxInfo.y2 -10 && y <= m_GfxInfo.y2 +10)
		return this;
	return NULL;

}

void Connection::setSrcComp(Component* cmp)
{
	SrcCmpnt = cmp;
}

void Connection::setDstComp(Component* cmp)
{
	DstCmpnt = cmp;
}

Component* Connection::getSrcComp()
{
	return SrcCmpnt;
}

Component* Connection::getDstComp()
{
	return DstCmpnt;
}
 void Connection::Load(ifstream& read, string label, int id)
 {}
void Connection::Load(ifstream& file,int s, int d, int n)
{

	SrcCmpnt = p->LoadConnection(s);
	DstCmpnt = p->LoadConnection(d);
	DstPin = ((Gate*)DstCmpnt)->GetInputPin(DstPinn);
	SrcPin = ((Gate*)SrcCmpnt)->GetOutputPin();
	DstPinn = n;
}
void Connection::SetPinNo(int i)
{
	DstPinn = i;
}
int Connection::GetPinNo()
{
	return DstPinn;
}//aywa m7na b3ml constructor 34an y5od 2 component w y3ml elconnection lw7do mn 8er read action parameters

void Connection::Save(ofstream& file)
{
	ofstream the_added_connection;
	the_added_connection.open("Data.txt", ios::app);
	the_added_connection << SrcCmpnt->getid() << " " << DstCmpnt->getid() << " " << DstPinn<<endl;
	//int Dstid = DstCmpnt->getid(); //input pin
	//int Srcid = SrcCmpnt->getid(); //output pin
	//DstPinn =((Gate *)DstCmpnt)->getpinnumber(DstPin);
	//file << Srcid << Dstid << DstPinn;
}


ActionType Connection::GetAddActionType()
{
	return ADD_CONNECTION;
}
