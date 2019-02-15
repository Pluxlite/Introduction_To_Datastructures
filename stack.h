#pragma once
#include <iostream>
#include <string>

#ifndef STACK_H
#define STACK_H

using namespace std;

typedef string stack_element;

class stack_node
{
public:
	stack_element data;							// The information stored in the node
	stack_node *next;							// Pointer used to link nodes together
};

class stack
{
public:
	stack();									// This is the default Constructor
	stack(const stack & Org);					// copy constructor
	~stack();									// This being the destructor
	void push(const stack_element & item);		// Puts information onto the stack
	stack_element pop();						// Takes information off of the stack
	int size();									// Gives the size of the current stack

private:
	stack_node * s_top;							//gives the location of the very first node


};


#endif