#include "Cook.h"


Cook::Cook(int orderbeforebreak,int breakduration):BreakDuration(breakduration),OrdersBeforeBreak(orderbeforebreak)
{
	ServedKamOrder=0;
	AvailabilityTime = 0;
	OrderAssignedTo=nullptr;
}


Cook::~Cook()
{
}


int Cook::GetID() const
{
	return ID;
}


ORD_TYPE Cook::GetType() const
{
	return type;
}


void Cook::setID(int id)
{
	ID = id;
}

void Cook::setType(ORD_TYPE t)
{
	type = t;
}

void Cook::setSpeed(int s)
{
	speed=s;
}

int Cook::getAvailabilityTime()
{
	return AvailabilityTime;
}

void Cook::SetOrderAssignedTo(Order* ORD)
{
	OrderAssignedTo=ORD;
}
