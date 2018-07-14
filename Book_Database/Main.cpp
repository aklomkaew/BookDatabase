// -----------------------------------------------------------
// File: Main.cpp
// Atchima Klomkaew
// Programming Assignment 3 - Book_Database
// This program is entire my own work
// -----------------------------------------------------------
#pragma once;

//#define DEBUG_1
//#define DEBUG_2
//#define DEBUG_3
//#define DEBUG_4
//#define DEBUG_5
//#define DEBUG_6

#include "Book_Database.h"
#include "BookRecord.h"
#include <iostream>
using namespace std;

int main()
{
	Book_Database *db = new Book_Database();
	db->readDatabase("BookData.txt");
	db->PrintAll();
	cout << "********************************" << endl;
	BookRecord *bk = NULL;

#ifdef DEBUG_1
	bk = db->searchByStockNumber(567);
	if((bk != NULL) && (bk->getStockNum() == 567))
		cout << "Search successful" << endl;

	bk = db->searchByStockNumber(9999);
	if(bk == NULL)
		cout << "Search successful" << endl;
#endif

#ifdef DEBUG_2
	db->searchByClassification(613);
	db->searchByClassification(999);
#endif

#ifdef DEBUG_3
	db->searchByCost(20.0, 40.0);
	cout << "********************************" << endl;
	db->searchByCost(90.0, 100.0);
	cout << "********************************" << endl;
	db->searchByCost(50.0, 55.0);
#endif

#ifdef DEBUG_4
	int numInStock;
	numInStock = db->getNumInStock(567);
	if(numInStock == 25);
		cout << "Search successful" << endl;
	numInStock = db->getNumInStock(999);
	if(numInStock == 0);
		cout << "Search successful" << endl;
#endif

#ifdef DEBUG_5
	cout << "Removing 876" << endl;
	db->removeBook(876);
	db->PrintAll();
	cout << "********************************" << endl;

	cout << "Removing 890" << endl;
	db->removeBook(890);
	db->PrintAll();
	cout << "********************************" << endl;

	cout << "Removing 234" << endl;
	db->removeBook(234);
	db->PrintAll();
	cout << "********************************" << endl;

	cout << "Removing 765" << endl;
	db->removeBook(765);
	db->PrintAll();
	cout << "********************************" << endl;

	cout << "Removing 567" << endl;
	db->removeBook(567);
	db->PrintAll();
	cout << "********************************" << endl;

	cout << "Removing 123, 345, and 987" << endl;
	db->removeBook(123);
	bk = db->removeBook(345);		// to add back later
	db->removeBook(987);
	db->PrintAll();
	cout << "********************************" << endl;

	cout << "Removing 456" << endl;
	db->removeBook(456);
	db->PrintAll();
	cout << "********************************" << endl;

	cout << "Adding 345 back" << endl;
	db->addBook(bk);

	cout << "Removing 678" << endl;
	db->removeBook(678);
	db->PrintAll();
	cout << "********************************" << endl;

	cout << "Removing 345" << endl;
	db->removeBook(345);
	db->PrintAll();
	cout << "********************************" << endl;
#endif

#ifdef DEBUG_6
	delete db;
#endif

	system("pause");
}