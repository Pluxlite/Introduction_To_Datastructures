//
//  word.cpp
//  program_4strings
//
//  Created by Taylor  Kruck on 2/27/18.
//  Copyright © 2018 Taylor  Kruck. All rights reserved.
//


#include <iostream>
#include <string>
#include "word.h"

using namespace std;

////////// length
//*************************************************************************************
//Name:  Length
//Precondition: The length of the word object has not been determined
//Postcondition: The length of the word object has been determined
//Description: This will determine the length of the word object // /
//

int WORD::Length()
{
	string s;
	cin >> s;

	if (front == 0)
	{
		return 0;
	}
	else
	{
		character *p = front;
		int count = 0;

		while (p != 0)
		{
			count++;
			p = p->next;
		}
		return count;
	}
}
/*
Name: Search
Preconditon: The key has not been found
Postcondition: The key has been found
Description: Searches the list for the key
*/
character * WORD::Search(const char & key)
{
	character *p = front;

	while (p != 0)
	{
		if (p->symbol == key)
		{
			return p;
		}
		p = p->next;
	}
	return p;
}
/////////overload
/*
Name: overloaded out
Preconditon: alist
Postcondition: contents of list have been displayed
Description: Adds characters
*/
ostream & operator <<(ostream & out, const WORD &)
{
	WORD word;
	character *p = word.front;
	while (p != NULL)
	{
		out << p->symbol << endl;
		p = p->next;
	}
	return out;
}

//////////// overload the assignment opperator
/*
Name: assignment operator
Preconditon: none
Postcondition: a copy of org list has been assigned to this object . reference is returned
Description:  copy of string
*/
void WORD :: operator=(const string &s)
{
	character *p = front;
	while (front != 0)
	{
		p = front;
		front = front->next;
		delete p;
	}

	back = front = 0;

	int len = s.length();

	for (int i = 0; i < len; i++)
	{
		if (i == 0)
		{
			front = back = new character;
			front->symbol = s[i];
			front->next = 0;
		}
		else
		{
			back->next = new character;
			back = back->next;
			back->symbol = s[i];
			back->next = 0;
		}
	}
}


////////// overload the assignment opperator with chaining
// Name: assignment operator
//Preconditon: none
//Postcondition: a copy of org list has been assigned to this object . reference is returned
//Description: assigns
WORD & WORD:: operator=(const WORD & w)
{
	character *p = front;

	while (front != 0)
	{
		p = front;
		front = front->next;
		delete p;
	}
	back = front = 0;

	p = w.front;

	while (p != 0)
	{
		AddC(p->symbol);
		p = p->next;

	}
	return *this;
}


////////// overload the insertion opperator without chaining
/*
Name: overload
Preconditon: No characters have been added
Postcondition: Characters have been added
Description: Adds characters
*/
void WORD:: operator+(const WORD & B)
{
	character *p = B.front;

	while (p != NULL)
	{
		Insert_BACK(p->symbol);
		p = p->next;
	}

}

/////////// create list
/*
Name: Create List
Preconditon: The list has not been created
Postcondition: The list has been created
Description: Creates a list while adding to the back
*/
void WORD::Create_list(const string & s, character *& aux_front, character *& aux_back)
{
	aux_front = aux_back = 0;

	if (front == 0)
	{
		for (int i = 0; i < s.length(); i++)
		{
			Insert_BACK(s[i]);
		}
	}
}


/////////// insertBack
/*
Name: Insert Back
Preconditon: New items have not been added to the back of the list
Postcondition: New items have been added to the back of the list
Description: Adds new items to the back of the list
*/
void WORD::Insert_BACK(const char & key)
{
	if (front == 0)
	{
		front = new character;
		front->symbol = key;
		front->next = 0;
		back = front;
	}
	else
	{
		character *p = new character;
		p->next = 0;
		p->symbol = key;
		back = p;
	}
}

////////// default constructor
//Name:  Default Constructor
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state has been initialized
//Description:  This is the default constructor which will be called automatically when
//an object is declared.  It will initialize the state of the class // /
//
WORD::WORD()
{
	front = new character;
	front->next = 0;
}

///////////explcit value constructor
//Name:  Explicit Value Constructor
//Precondition:  The word has not been created
//Postcondition:  The word has been created by the user's input
///Description:   // // This is the explicit-value constructor.
//
WORD::WORD(const string & s)
{

	cout << "inside Explicit value constructor" << endl;
	front = 0;
	back = 0;
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		if (i == 0)
		{
			front = back = new character;
			front->symbol = s[i];
			front->next = 0;
		}
		else
		{
			back->next = new character;
			back = back->next;
			back->symbol = s[i];
			back->next = 0;
		}



	}
}


/////////// copy constructor
//Name:  copy Constructor
//Precondition: a copy of orglist is needed
//Postcondition: a copy of org list has been constructed
//Description:  takes a deep copy of list
//*
WORD::WORD(const WORD & org)
{

	character *p = org.front;

	cout << "inside copy constructor." << endl;

	front = back = 0;

	while (p != 0)
	{
		AddC(p->symbol);
		p = p->next;
	}
}

////////// addc
/*
Name: Add
Preconditon: No characters have been added
Postcondition: Characters have been added
Description: Adds characters
*/
void WORD::AddC(char ch)
{
	character *p = new character;
	p->symbol = ch;
	p->next = 0;

	if (front == 0)
	{
		front = back = p;
	}
	else
	{
		back->next = p;
		back = p;
	}
}
///////// desctructor
//Name: assignment operator
//Preconditon: life of object is over
//Postcondition: memory allocated has been returned
//Description: deletes object
WORD:: ~WORD()
{
	cout << "destructor has been called\n";


	while (front != 0)
	{
		character *p = front;
		front = front->next;
		delete p;
	}
}

////////// remove
//Name:  Default Constructor
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state has been initialized
//Description:  This is the default constructor which will be called automatically when
//an object is declared.  It will initialize the state of the class // /
//*
void WORD::Remove(WORD &Org)
{
	cout << "remove all has been called " << endl;

	character *p = Org.front;
	character*temp = Search(p->symbol);

	if (temp == 0)
	{
		cout << Org << "\n" << "not in list";
	}
	else
	{
		if (temp == front && front == back)
		{
			delete temp;
			front = back = 0;
		}
		else if (temp == front)
		{
			front = front->next;
			delete temp;
		}
		else {
			character *back_ptr = front;

			while (back_ptr != 0 && back_ptr->next != temp)
			{
				back_ptr = back_ptr->next;

			}
			if (temp == back)
			{
				back = back_ptr;
			}
			back_ptr->next = temp->next;
			delete temp;
		}
	}

}



