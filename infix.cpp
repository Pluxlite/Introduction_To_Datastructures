#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

stack_element infix(stack_element exp);

int main()
{
	stack_element post;

	cout << "type # to end the program" << endl << endl;

	while (true)
	{
		cout << "insert your expression here" << endl;
		cout << "> ";
		getline(cin, post);

		if (post == "#")
		{
			break;
		}
		cout << endl << "The expression is" << infix(post) << endl << endl;
	}

	return 0;
}


stack_element infix(stack_element exp)
{

	stack numStack;
	stack_element result;
	stack_element placeholder;
	stack_element a;
	stack_element b;

	for (int i = 0; i < exp.length(); i++)
	{
		placeholder = exp[i];

		if (exp.length() == 1)
		{
			return exp;
		}


		if (placeholder == " ")
		{

		}
		else if (placeholder == "+")
		{
			if (numStack.size() < 2)
			{
				result = "Not enough operands\n";
				break;
			}
			else
			{
				a = numStack.pop();
				b = numStack.pop();
				result = "(" + b + "+" + a + ")";
				numStack.push(result);
			}

		}
		else if (placeholder == "-")
		{
			if (numStack.size() < 2)
			{
				result = "Not enough operands\n";
				break;
			}
			else
			{
				a = numStack.pop();
				b = numStack.pop();
				result = "(" + b + "-" + a + ")";
				numStack.push(result);
			}
		}
		else if (placeholder == "*")
		{
			if (numStack.size() < 2)
			{
				result = "Not enough operands \n";
				break;
			}
			else
			{
				a = numStack.pop();
				b = numStack.pop();
				result = "(" + b + "*" + a + ")";
				numStack.push(result);
			}
		}
		else if (placeholder == "/")
		{
			if (numStack.size() < 2)
			{
				result = "ERROR: Not enough operands\n\n";
				break;
			}
			else
			{
				a = numStack.pop();
				b = numStack.pop();
				result = "(" + b + "/" + a + ")";
				numStack.push(result);
			}
		}
		else
		{
			numStack.push(placeholder);
		}
	}

	if (numStack.size() == 1)
	{
		return result;
	}
	else
	{
		return "Not enough operands \n";
	}
}