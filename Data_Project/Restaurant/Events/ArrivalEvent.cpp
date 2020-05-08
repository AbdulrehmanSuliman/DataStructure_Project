#include "ArrivalEvent.h"
#include "..\Rest\Restaurant.h"


ArrivalEvent::ArrivalEvent(int eTime, int oID, ORD_TYPE oType):Event(eTime, oID)
{
	OrdType = oType;
}

ArrivalEvent::ArrivalEvent(ORD_TYPE otyp,int atime,int id,int size,double money):Event(atime,id)
{
	OrdType=otyp;
	Size=size;
	OrdMoney=money;
}
void ArrivalEvent::Execute(Restaurant* pRest)
{
	//This function should create an order and fills its data 
	// Then adds it to normal, vegan, or VIP order lists that you will create in phase1
	Order* Ord = new Order(OrderID, OrdType, Size);
	Ord->SetMoney(OrdMoney);
	Ord->setArrivalTime(EventTime);
	if (OrdType==TYPE_VIP)
	{
		pRest->WaitingOrderVIPenqueue(Ord);
	}
	else if(OrdType == TYPE_NRM)
	{
		pRest->AddtoNormal_OrdersWaitingQueue(Ord);
	}
	else if (OrdType == TYPE_VGAN)
	{
		pRest->AddtoVegan_OrdersWaitingQueue(Ord);
	}

	
	///For the sake of demo, this function will just create an order and add it to DemoQueue
	///Remove the next code lines in phases 1&2
	/*Order* pOrd = new Order(OrderID,OrdType,Size);
	pRest->AddtoDemoQueue(pOrd);*/
}
