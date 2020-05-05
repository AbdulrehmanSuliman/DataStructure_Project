#pragma once

#include "..\Defs.h"
#include "Order.h"
#pragma once
class Cook
{
	int ID;
	ORD_TYPE type;	//for each order type there is a corresponding type (VIP, Normal, Vegan)
	int speed;		//dishes it can prepare in one clock tick (in one timestep)

	//////////////ADDED/////////////////////
	const int OrdersBeforeBreak;   //Number of orders that he must complete before taking a break  //TO be Const
	const int BreakDuration;     //The duration of the break  //To be const
	Order* OrderAssignedTo;     //If in busycooks queue then which order it is assigned to
	int ServedKamOrder;    //How many orders is served. if = OrdersBeforeBreak then take a break
	int AtBreakCounter;   //count the timesteps while in atbreakcooks. if = BreakDuration then take a break
	int AvailabilityTime; //counts the time at which the cook is available
public:
	Cook(int orderbeforebreak,int breakduration);
	virtual ~Cook();
	int GetID() const;
	ORD_TYPE GetType() const;
	void setID(int);
	void setType(ORD_TYPE) ;
	void setSpeed(int);
	int getAvailabilityTime();
	void SetOrderAssignedTo(Order*);

};
