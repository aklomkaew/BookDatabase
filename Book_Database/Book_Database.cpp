// -----------------------------------------------------------
// File: Book_Database.cpp
// Atchima Klomkaew
// Programming Assignment 3 - Book_Database
// This program is entire my own work
// -----------------------------------------------------------
#include "Book_Database.h"
#include <iostream>

using namespace std;

Book_Database::Book_Database()
{
	m_pRoot = NULL;
}

Book_Database::~Book_Database()
{
	ClearList(m_pRoot);
}

bool Book_Database::readDatabase(char *filename)
{
	char line[128];
	int numBooks;

	m_InFile.open(filename, ifstream::in);
	if(!m_InFile.is_open())
	{
		cout << "Unable to open file" << filename << "\nProgram terminating...\n";
		return false;
	}

	getNextLine(line, 128);
	numBooks = atoi(line);
	for(int i = 0; i < numBooks; i++)
	{
		BookRecord *book = new BookRecord();
		// book ID
		getNextLine(line, 128);
		book->setStockNum(atoi(line));

		// title
		getNextLine(line, 128);
		book->setName(line);

		// classification
		getNextLine(line, 128);
		book->setClassification(atoi(line));

		// cost
		getNextLine(line, 128);
		book->setCost(atof(line));

		// number in stock
		getNextLine(line, 128);
		book->setNumberInStock(atoi(line));

		addBook(book);
	}
}

bool Book_Database::addBook(BookRecord *br)
{
	BookRecord *temp = m_pRoot;
	BookRecord *back = NULL;

	if(temp == NULL)			// empty
		m_pRoot = br;
	while(temp != NULL)
	{
		back = temp;
		if(br->getStockNum() < temp->getStockNum())
			temp = temp->m_pLeft;
		else
			temp = temp->m_pRight;
	}

	if(back == NULL)			// add at head
		m_pRoot = br;
	else
	{
		if(br->getStockNum() < back->getStockNum())
			back->m_pLeft = br;
		else
			back->m_pRight = br;
	}
	return true;
}

BookRecord *Book_Database::removeBook(long stockNum)
{
	BookRecord *temp = m_pRoot;
	BookRecord *back = NULL;
	BookRecord *delNode = NULL;
	BookRecord *delParent = NULL;

	// case 1: find node to delete
	while((temp != NULL) && (temp->getStockNum() != stockNum))
	{
		back = temp;
		if(stockNum < temp->getStockNum())
			temp = temp->m_pLeft;
		else
			temp = temp->m_pRight;
	}

	if(temp == NULL)		// not found
		return NULL;
	else
	{
		delNode = temp;
		delParent = back;
	}

	// case 2: no children or one child on the left
	if(delNode->m_pRight == NULL)
	{
		if(delParent == NULL)
		{
			m_pRoot = delNode->m_pLeft;
			delNode->m_pLeft = NULL;
			return delNode;
		}
		else
		{
			if(delParent->m_pLeft == delNode)
				delParent->m_pLeft = delNode->m_pLeft;
			else
				delParent->m_pRight = delNode->m_pLeft;
			delNode->m_pLeft = NULL;
			return delNode;
		}
	}

	// case 3: one child on the right
	else if(delNode->m_pLeft == NULL)
	{
		if(delParent == NULL)
		{
			m_pRoot = delNode->m_pRight;
			delNode->m_pRight = NULL;
			return delNode;
		}
		else
		{
			if(delParent->m_pLeft == delNode)
				delParent->m_pLeft = delNode->m_pRight;
			else
				delParent->m_pRight = delNode->m_pRight;
			delNode->m_pRight = NULL;
			return delNode;
		}
	}

	// case 4: two children
	else
	{
		BookRecord *ret = new BookRecord();
		*ret = *delNode;
		ret->m_pLeft = NULL;
		ret->m_pRight = NULL;

		temp = delNode->m_pLeft;
		back = delNode;

		while(temp->m_pRight != NULL)
		{
			back = temp;
			temp = temp->m_pRight;
		}
		char name[128];
		temp->getName(name);
		delNode->setName(name);
		delNode->setStockNum(temp->getStockNum());
		delNode->setClassification(temp->getClassification());
		delNode->setCost(temp->getCost());
		delNode->setNumberInStock(temp->getNumberInStock());

		if(back == delNode)
			back->m_pLeft = temp->m_pLeft;
		else
			back->m_pRight = temp->m_pLeft;
		
		delete temp;
		return ret;
	}
}

BookRecord *Book_Database::searchByStockNumber(long stockNum)
{
	BookRecord *temp = m_pRoot;

	while((temp != NULL) && (temp->getStockNum() != stockNum))
	{
		if(stockNum < temp->getStockNum())
			temp = temp->m_pLeft;
		else
			temp = temp->m_pRight;
	}

	if(temp == NULL)
		return NULL;
	else
		return temp;
}

void Book_Database::searchByClassification(int cl)
{
	searchByClassification(cl, m_pRoot);
}

void Book_Database::searchByCost(double min, double max)
{
	searchByCost(min, max, m_pRoot);
}

int Book_Database::getNumInStock(long sn)
{
	BookRecord *temp = searchByStockNumber(sn);
	if(temp != NULL)
		return temp->getNumberInStock();
	return 0;
}

void Book_Database::PrintAll()
{
	PrintAll(m_pRoot);
}

void Book_Database::ClearList(BookRecord *rt)
{
	if(rt == NULL)
	{
		return;
	}
	if(rt->m_pLeft != NULL)
	{
		ClearList(rt->m_pLeft);
	}
	if(rt->m_pRight != NULL)
	{
		ClearList(rt->m_pRight);
	}
	delete rt;
}

bool Book_Database::getNextLine(char *line, int lineLen)
{
	int done = false;
	while(!done)
	{
		m_InFile.getline(line, 128);

		if(m_InFile.good())
		{
			if(strlen(line) == 0)
				continue;
			else if(line[0] == '#')
				continue;
			else return true;
		}
		else
		{
			strcpy(line, "");
			return false;
		}
	}
	return false;
}

void Book_Database::searchByClassification(int cl, BookRecord *rt)
{
	BookRecord *temp = rt;

	if(temp != NULL)
	{
		searchByClassification(cl, temp->m_pLeft);
		if(temp->getClassification() == cl)
			temp->printRecord();
		searchByClassification(cl, temp->m_pRight);
	}
}

void Book_Database::searchByCost(double min, double max, BookRecord *rt)
{
	BookRecord *temp = rt;

	if(temp != NULL)
	{
		searchByCost(min, max, rt->m_pLeft);
		if((temp->getCost() >= min) && (temp->getCost() <= max))
			temp->printRecord();
		searchByCost(min, max, rt->m_pRight);
	}
}

void Book_Database::PrintAll(BookRecord *rt)
{
	if(rt != NULL)
	{
		PrintAll(rt->m_pLeft);
		rt->printRecord();
		PrintAll(rt->m_pRight);
	}
}
