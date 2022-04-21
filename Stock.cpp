#include "Stock.h"

Stock::Stock()
{
	pNext = nullptr;
	pPrev = nullptr;

	value = 0.0f;
}

Stock::~Stock()
{

}

Stock* Stock::getNext()
{
	return pNext;
}

Stock* Stock::getPrev()
{
	return pPrev;
}

string Stock::getCompany()
{
	return company;
}

float Stock::getValue()
{
	return value;
}

void Stock::setNext(Stock* newNext)
{
	pNext = newNext;
}

void Stock::setPrev(Stock* newPrev)
{
	pPrev = newPrev;
}

void Stock::setCompany(string newCompany)
{
	company = newCompany;
}

void Stock::setValue(float newValue)
{
	value = newValue;
}
