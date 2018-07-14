// -----------------------------------------------------------
// File: BookRecord.cpp
// Atchima Klomkaew
// Programming Assignment 2 - Book_Inventory
// This program is entire my own work
// -----------------------------------------------------------

#include "BookRecord.h"
#include <iostream>
#include <string>

using namespace std;

BookRecord::BookRecord()
{
	strcpy(m_sName,"");
	m_lStockNum = 0;
	m_iClassification = 0;
	m_dCost = 0.0;
	m_iCount = 0;
}

BookRecord::BookRecord(char *name, long sn, int cl, double cost)
{
	strcpy(m_sName, name);
	m_lStockNum = sn;
	m_iClassification = cl;
	m_dCost = cost;
	m_iCount = 1;
}

BookRecord::~BookRecord()
{
}

void BookRecord::getName(char *name)
{
	strcpy(name, m_sName);
}

void BookRecord::setName(char *name)
{
	strcpy(m_sName, name);
}

long BookRecord::getStockNum()
{
	return m_lStockNum;
}

void BookRecord::setStockNum(long sn)
{
	m_lStockNum = sn;
}

int BookRecord::getClassification()
{
	return m_iClassification;
}

void BookRecord::setClassification(int cl)
{
	m_iClassification = cl;
}

double BookRecord::getCost()
{
	return m_dCost;
}

void BookRecord::setCost(double c)
{
	m_dCost = c;
}

int BookRecord::getNumberInStock()
{
	return m_iCount;
}

void BookRecord::setNumberInStock(int count)
{
	m_iCount = count;
}

void BookRecord::printRecord()
{
	for(int i = 0; i < strlen(m_sName); i++)
		cout << *(m_sName + i);
	cout << "\t\t" << m_lStockNum << "\t" 
		 << m_iClassification << "\t"
		 << m_dCost << "\t"
		 << m_iCount << endl;
}