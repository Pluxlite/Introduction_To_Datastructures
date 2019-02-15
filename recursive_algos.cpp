#include <string>
#include <iostream>

using namespace std;

bool palindrome(string & s)
{
	return true;
}

string printReversel(string & s)
{
	return s;
}

string printIterReverse(string & s)
{
	string temp;

	int count = s.length();

	for (int i = 0; count != 0; i++)
	{
		temp[i] = s[count-1];
	}

	cout << temp << endl;

	return temp;
}

int main()
{
	string s;

	cout << "enter a phrase" << endl;
	cin >> s;

	printIterReverse(s);

	return 0;
}