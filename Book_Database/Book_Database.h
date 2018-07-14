// -----------------------------------------------------------
// File: Book_Database.h
// Atchima Klomkaew
// Programming Assignment 3 - Book_Database
// This program is entire my own work
// -----------------------------------------------------------
#pragma once;

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "BookRecord.h"

using namespace std;

class Book_Database
{
private:
	BookRecord *m_pRoot;
	ifstream m_InFile;

public:
	Book_Database();
	~Book_Database();
	bool readDatabase(char *filename);
	bool addBook(BookRecord *br);
	BookRecord *removeBook(long stockNum);
	BookRecord *searchByStockNumber(long stockNum);
	void searchByClassification(int cl);
	void searchByCost(double min, double max);
	int getNumInStock(long sn);
	void PrintAll();

private:
	void ClearList(BookRecord *rt);
	bool getNextLine(char *line, int lineLen);
	void searchByClassification(int cl, BookRecord *rt);
	void searchByCost(double min, double max, BookRecord *rt);
	void PrintAll(BookRecord *rt);
};