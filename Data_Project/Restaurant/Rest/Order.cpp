#include "Order.h"

Order::Order(int id, ORD_TYPE r_Type,int size):Size(size)
{
	ID = (id>0&&id<1000)?id:0;	//1<ID<999
	type = r_Type;
	status = WAIT;
}

Order::~Order()
{
}

int Order::GetID()
{
	return ID;
}


ORD_TYPE Order::GetType() const
{
	return type;
}

/*
void Order::SetDistance(int d)
{
	Distance = d>0?d:0;
}

int Order::GetDistance() const
{
	return Distance;
}*/


void Order::setStatus(ORD_STATUS s)
{
	status = s;
}

ORD_STATUS Order::getStatus() const
{
	return status;
}

void Order::SetMoney(double mon)
{
	totalMoney=mon;
}

void Order::setMoney(double money)
{
	totalMoney = money;
}
double Order::getMoney()
{
	return this->totalMoney;
}
int  Order::getArrivalTime()
{
	return this->ArrTime;
}
//<<<<<<< HEAD
double Order::CalcPriority_VIP_order()
{
	return (totalMoney-double(ArrTime))/double(Size);
}
//=======
void Order::setArrivalTime(int time)
{
	ArrTime = time;
//>>>>>>> 35831b7e6c6de3824f287596f88d11f48cd1521e
}