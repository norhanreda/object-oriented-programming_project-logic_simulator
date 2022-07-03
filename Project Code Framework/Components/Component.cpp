#include "Component.h"
Component::Component()
{

}
Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;
	mSelected = false;
	mDeleted = false;
	m_Label="Gate";
}

Component* Component::InsideArea(int x, int y)
{
	//Component* mComp;
	if(x>=m_GfxInfo.x1 && x<=m_GfxInfo.x2 && y >= m_GfxInfo.y1 && y <= m_GfxInfo.y2)
	    return this;
	else
	    return NULL;
	
}
Component* Component::insidreArea(double x, double y)
{
	if (x >= (m_GfxInfo.x1) + 3 && x <= (m_GfxInfo.x2) + 3 && y >= (m_GfxInfo.y1) + 3 && y <= (m_GfxInfo.y2) + 3)
		return  this;
	else
		return NULL;
}

GraphicsInfo Component::GetGraphicsInfo()
{
	return m_GfxInfo;
}

void Component::SetSelected(bool s)
{
	mSelected = s;
}

void Component::SetDeleted(bool d)
{
	mDeleted = d;
}

bool Component::IsSelected()
{
	return mSelected;
}
bool Component::IsDeleted()
{
	return mDeleted;
}

/*Sets the label of the component*/ 
void Component::SetLabel(const string & label) {
	//if (!label.empty())
	{
		m_Label = label;
	}
}

/* Returns the label of the component */
string Component::GetLabel() const 
{
	return m_Label;
}
int Component::getid()
{
	return id;
}
void Component::setid(int i)
{
	id = i;
}



Component::~Component()
{}

