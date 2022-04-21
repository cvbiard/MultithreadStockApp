#pragma once
#include "header.h"

//Doubly-linked list node class to represent an individual stock
class Stock
{
public:
	//Constructor
	Stock();

	//Destructor
	~Stock();

	//Getters
	Stock* getNext();
	Stock* getPrev();

	string getCompany();
	float getValue();

	//Setters
	void setNext(Stock* newNext);
	void setPrev(Stock* newPrev);

	void setCompany(string newCompany);
	void setValue(float newValue);

private:

	//List pointers
	Stock* pNext;
	Stock* pPrev;

	//Data values
	string company;
	float value;
};
