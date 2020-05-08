#ifndef __RESTAURANT_H_
#define __RESTAURANT_H_

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\GUI\GUI.h"
#include "..\Generic_DS\Queue.h"
#include "..\Events\Event.h"
#include"..\Generic_DS\PriorityQueue.h"


#include "Order.h"

// it is the maestro of the project
class Restaurant
{
private:
	GUI* pGUI;
	Queue<Event*> EventsQueue;	//Queue of all events that will be loaded from file


	/// ==> 
	//	DEMO-related members. Should be removed in phases 1&2
	Queue<Order*> DEMO_Queue;	//Important: This is just for demo
	/// ==>


	///////////////////////////ADDED/////////////////////
	int TimeBeforePromotion;   //is the time for the normal order will wait until promotion
	int timestep;             //Added by zaki
	int arrived_orders;       //Added by zaki
	int finished_orders;      //Added by zaki
	int canceled_orders;      //Added by zaki
	int VIP_MaxWaitingTime;
	double InjuryProbability;

	PriorityQueue<Order*> VIP_OrdersWaitingPriorityQueue; //priority Queue to be used in phase 2
	Queue<Order*> VIP_OrdersWaiting;  //VIP orders in waiting must be assigned to cook if any
//>>>>>>> 761f61fa9fd4f98dc50d378bbc25128cc5dd3b81
	Queue<Order*> Normal_OrdersWaiting;   //Normal orders in waiting assigned to vip and normal cooks after vip is served
	Queue<Order*> Vegan_OrdersWaiting;    //Vegan orders in waiting assignd to vegan cook after vip is served


	Queue<Order*> OrdersInServing;  //ALl orders that are currently assigned to cooks
	Queue<Order*> OrdersFinished;  //All orders that are served



	Queue<Cook*>  VIP_AvailableCook;  //Vip cooks that are ready to be assigned to orders
	Queue<Cook*>  Normal_AvailableCook; //Normal cooks that are ready to be assigned to orders
	Queue<Cook*>  Vegan_AvailableCook;  //Vegan cooks that are ready to be assigned to orders

	PriorityQueue<Cook*>  BusyCooks;  //All cooks assigned to cooks
	PriorityQueue<Cook*>  CooksAtBreak;
	int O_waiting_count_VIP;//gives the count of the waiting VIP orders
	int O_waiting_count_Normal; //gives the count of the waiting Normal orders
	int O_waiting_count_Vegan; //gives the count of the waiting Vegan orders
	int C_Available_count_VIP; //gives the count of the available VIP cooks
	int C_Available_count_Normal; //gives the count of the available Normal cooks
	int C_Available_count_Vegan; //gives the count of the available Vegan cooks
public:

	Restaurant();
	~Restaurant();

	void ExecuteEvents(int TimeStep);	//executes all events at current timestep
	void RunSimulation();




	void FillDrawingList();

	//
	// TODO: Add More Member Functions As Needed
	//
	//ADDED MEMBER FUNCTIONS TO ENQUEUE IN THE NEWELLY CREATED QUEUES
	void AddtoVIP_OrdersWaitingQueue(Order* ord);  //enqueues the order in th VIP waiting queue
	void AddtoNormal_OrdersWaitingQueue(Order* ord); //enqueues the order in the Normal waiting queue
	void AddtoVegan_OrdersWaitingQueue(Order* ord); //enqueues the order in the Vegan waiting list
	void promotion(int id, double);
	/// ===================    DEMO-related functions. Should be removed in phases 1&2   ================= 
	void Just_A_Demo();	//just to show a demo and should be removed in phase1 1 & 2
	void AddtoDemoQueue(Order* po);	//adds an order to the demo queue

/// ================================================================================================== 

	void CancelOrder(int id);
	void LoadingFunction();
	void SimpleSimulator();
	void assignmentfunction();
	void WaitingOrdersToServed();
	Order* WaitingOrderVIPdequeue();  //Removes VIP orders from the waiting and returns removed order
	void WaitingOrderVIPenqueue(Order*);  //adds the vip order to the queues
};

#endif