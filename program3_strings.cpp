////////////////////////////////////////////////////////////////////////////////////////////
//Remember to include a program header
///////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

using namespace std;
bool palindrome(const string & s);
string replace_all(const string & original_string, const string & old_substring, const string &
	new_substring);
////////////////////////////////////////////////////////////////////////////////////////////
//Remember to include a function header
//Function name: Palindrome
//Precondition: Tells if the phrase is a palindrome
//Postcondition: it maktches the first set element with the last element and check all teh way through if it is a palindrome.
//Description
///////////////////////////////////////////////////////////////////////////////////////
bool palindrome(const string & s)
{
	int count = 0;
	count = s.length();
	bool detect = true;

	//your code goes here
	for (int i = 0; i < count; i++)
	{
		if (s[i] == s[count - 1])
		{
			count--;
		}
		else
		{
			detect = false;
		}
	}
	return detect;
}
////////////////////////////////////////////////////////////////////////////////////////////
//Remember to include a function header
//Function name:Replace_all
//Precondition:  insert a substring into a string
//Postcondition: it takes the substring and inserts it at a location in the string from the pre existing one.
//Description
///////////////////////////////////////////////////////////////////////////////////////
string replace_all(const string & original_string, const string & old_substring, const string & new_substring)
{

	int new_substring_count = new_substring.length();
	int adding_number;
	int beginning_number;
	int count = original_string.length();


	//your code goes here
	//find the location it matches
	for (int i = 0; i < count; i++)
	{
		if (old_substring[0] == original_string[i])
		{
			beginning_number = i;
		}
	}


	

	adding_number = beginning_number + old_substring.length();

	//This particular statement would finish the program, but i could not get it to work for some time.
	//original_string.insert(adding_number,new_substring);
	return new_substring;
}
int main()
{
	string s, n, f;
	bool detect2;

	cout << "Enter a word" << endl;
	cin >> s;

	detect2 = palindrome(s);

	cout << "enter the string you would like to change" << endl;
	cin >> s;
	cout << "Enter the part of the string you would like to alter" << endl;
	cin >> n;
	cout << "What would you like the new string to be replaced with?" << endl;
	cin >> f;

	replace_all(s, n, f);

	//driver should have a loop prompting user for input. For example, (1) user wants to run the function
	//palindrome or
	//replace_all and (2) prompt the user for the appropriate input once the function has been determine (one
	//string for
	//palindrome and 3 for replace_all).
	return 0;
}