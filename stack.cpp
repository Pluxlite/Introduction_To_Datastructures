#include "stack.h"
#include <string>
#include <iostream>


//This function is responsible for making the postfix expression into infix
stack::stack()
{
	s_top = 0;
}

//this expression is used to change the postfix to infix
stack::stack(const stack & Org)
{
	stack_node *p = Org.s_top;

	(*this).s_top = 0;

	while (p != 0)
	{
		(*this).push(p->data);
		p = p->next;
	}
}

//This function will also change from postfix to infix
stack::~stack()
{
	while (s_top != 0)
	{
		pop();
	}
}

//Function responsible for changing from postfix to infix
void stack::push(const stack_element & item)
{

	stack_node *p = new stack_node;

	p->data = item;
	p->next = s_top;
	s_top = p;
}

//Responsible for taking the content out of a stack
stack_element stack::pop()
{

	stack_node *p;
	stack_element info;

	if (s_top != 0)
	{
		p = s_top;
		info = p->data;
		s_top = s_top->next;
		delete p;

		return info;
	}

}


//This function is responsible for making sure that the number of stacks are known
int stack::size()
{
	int sum = 0;
	stack_node *p = s_top;

	while (p != NULL)
	{
		sum++;
		p = p->next;
	}

	return sum;
}