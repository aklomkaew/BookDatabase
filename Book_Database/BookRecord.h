// -----------------------------------------------------------
// File: BookRecord.h
// Atchima Klomkaew
// Programming Assignment 2 - Book_Inventory
// This program is entire my own work
// -----------------------------------------------------------
#pragma once;

class BookRecord
{
private:
	char m_sName[128];
	long m_lStockNum;
	int m_iClassification;
	double m_dCost;
	int m_iCount;
	
public:
	BookRecord();
	BookRecord(char *name, long sn, int cl, double cost);
	~BookRecord();
	void getName(char *name);
	void setName(char *name);
	long getStockNum();
	void setStockNum(long sn);
	int getClassification();
	void setClassification(int cl);
	double getCost();
	void setCost(double c);
	int getNumberInStock();
	void setNumberInStock(int count);
	void printRecord();
	BookRecord *m_pLeft;
	BookRecord *m_pRight;
};