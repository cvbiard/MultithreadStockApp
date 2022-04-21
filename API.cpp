#include "API.h"

StockAPI::StockAPI()
{
	pHead = nullptr;
}

StockAPI::~StockAPI()
{
}

Stock* StockAPI::getHead()
{
	return pHead;
}

void StockAPI::setHead(Stock* newHead)
{
	pHead = newHead;
}

void StockAPI::readStocks(fstream& fileStream)
{
	while (!fileStream.eof())
	{
		string tempCompany;
		float tempValue;

		fileStream >> tempCompany;
		fileStream >> tempValue;
		
		this->addFront(newNode(tempCompany, tempValue));
	}

}

Stock* StockAPI::newNode(string company, float value)
{

	Stock* newStock = new Stock;
	
	if (newStock)
	{
		newStock->setCompany(company);
		newStock->setValue(value);
		return newStock;
	}

	return nullptr;
}

void StockAPI::addFront(Stock* node)
{

	if (node)
	{
		if (pHead == nullptr)
		{
			pHead = node;
		}
		else
		{
			node->setNext(pHead);
			pHead->setPrev(node);
			pHead = node;
		}
	
	}

}

void StockAPI::printList()
{
	Stock* tempStock = pHead;

	//Get to the end of the list
	while (tempStock->getNext() != nullptr)
	{
		tempStock = tempStock->getNext();
	}

	//Work backwards so the list is printed forwards
	while (tempStock != nullptr)
	{
		cout << tempStock->getCompany() << endl;
		cout << tempStock->getValue() << endl;
		cout << endl;

		tempStock = tempStock->getPrev();
	}

}

void StockAPI::simulateUpdate()
{
	Stock* tempStock = pHead;
	
	//Never-ending loop for the thread to work off
	while (true)
	{

		while (tempStock != nullptr)
		{
			//Amount the "stock's" value has changed by since last update
			float deltaValue = float(rand() % 100);

			//Generate an even or odd number, even we add the deltaValue, odd we subtract
			int operatorToUse = rand() % 2;

			if (operatorToUse == 0)
			{
				tempStock->setValue(tempStock->getValue() + deltaValue);
			}
			else
			{
				//For "realism" sake if the change would result in a stock being worth $0 or negative dollars, just add instead
				if (tempStock->getValue() - deltaValue <= 0)
				{
					tempStock->setValue(tempStock->getValue() + deltaValue);
				}
				else
				{
					tempStock->setValue(tempStock->getValue() - deltaValue);
				}
			}

			tempStock = tempStock->getNext();
		}

		//Reset the temp pointer to the list head;
		tempStock = pHead;

		//Print the list with new changes
		this->printList();
		cout << endl;

		//Sleep this thread for two seconds
		std::this_thread::sleep_for(2000ms);
	}
}
