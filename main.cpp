/*
MultithredStockApp
An application that simulates a stock market API updating, to demonstrate multithreading monitoring API changes
By Clark Biard, 2022
cvbiard@hotmail.com, 425-595-7903
*/

#include "header.h"
#include "API.h"

//A global function to run on the thread
void runStocks(StockAPI* API)
{
	API->simulateUpdate();
}

int main(void)
{
	//Instantiate the stockAPI
	StockAPI API;

	//Create a filestream
	fstream stockList;

	//Open the file
	stockList.open("stockList.txt", ios::in | ios::out);

	//Read the file's contents into the linked list
	API.readStocks(stockList);

	//Close the file
	stockList.close();

	//Create the new thread and pass in the API class
	std::thread backgroundWorker(runStocks, &API);

	system("pause>nul");
}