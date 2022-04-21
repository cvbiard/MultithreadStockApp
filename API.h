#pragma once
#include "header.h"
#include "Stock.h"

//Doubly-linked list container to represent the "API" as a whole
class StockAPI
{
public:
	//Constructor
	StockAPI();

	//Destructor
	~StockAPI();

	//Getters
	Stock* getHead();

	//Setters
	void setHead(Stock* newHead);

	//List functions
	void readStocks(fstream& fileStream);
	Stock* newNode(string company, float value);
	void addFront(Stock* node);
	void printList();
	
	//Simulation functions
	void simulateUpdate();

private:

	//Head pointer of the list
	Stock* pHead;

};