// Name: Taylor Kruck z: 23339603
//Class: data struct
//professor: Bullard
// project: Word linked lists
//
//
//


#include <iostream>
#include <string>
#include "word.h"

using namespace std;

int main()
{

	WORD you;
	cout << "************TEST#1*******************************\n";
	cout << "Testing the default constructor and printing empty word\n";
	cout << you << endl;
	cout << "The length of you is " << you.Length() << " = 0\n";
	cout << "*************************************************\n";
	cout << endl << endl;


	cout << "************TEST#2*******************************\n";
	WORD me("AAAA0000AAA0000AAA");
	cout << "Testing the explicit-value constructor\n";
	cout << me << endl;
	cout << "me is \n" << me << "= AAAA0000AAA0000AAA\n";
	cout << "*************************************************\n";
	cout << endl << endl;


	cout << "************TEST#3*******************************\n";
	WORD them = me;
	cout << "Testing the copy constructor\n";
	cout << "them is \n" << them << "= AAAA0000AAA0000AAA\n";
	cout << "*************************************************\n";
	cout << endl << endl;

	cout << "************TEST#4*******************************\n";
	cout << "Testing length\n";
	cout << "The length of me is " << me.Length() << " = 18 " << endl;
	cout << "The length of them is " << them.Length() << " = 18 " << endl;
	cout << "The length of you is " << you.Length() << " = 0 " << endl;
	cout << "*************************************************\n";
	cout << endl << endl;

	cout << "************TEST#5*******************************\n";
	WORD us;
	us = "AA";
	cout << "Testing operator= by assignment the value of \"AA\" to use\n";
	cout << "The word us is \n" << us << " = AA" << endl;
	cout << "*************************************************\n";
	cout << endl << endl;



	cout << "************TEST#7*******************************\n";
	WORD our, him;

	our = "AAA000AAA000";
	us = "XXXX";

	cout << "Testing IsEqual by testing to see inf us is equal to our \n";
	if (our.IsEqual(us))
		cout << "The 2 words are equal\n";
	else
		cout << "The 2 words are not equal\n";

	cout << "TEST SHOULD REVEAL THAT our AND us are not equal\n";

	cout << "*************************************************\n";
	cout << endl << endl;

	cout << "************TEST#8*******************************\n";
	cout << "Adding 2 words by adding us to the back of their.  Their is the current object \n";
	WORD their("AAAA0000AAA0000AAA");
	their + us;
	cout << "their followed by us is \n" << their << " = AAAA0000AAA0000AAAXXXX" << endl;
	cout << "*************************************************\n";
	cout << endl << endl;

	cout << "************TEST#9*******************************\n";
	cout << "Adding 2 words, their2 is empty, by adding us to the back of their.  Their is the current object \n";
	WORD their2("");
	their2 + us;
	cout << "their followed by us is \n" << their << " = XXXX" << endl;
	cout << "*************************************************\n";

	cout << "************TEST#10*******************************\n";
	cout << "Adding 2 words, their3 is empty, by adding us to the back of their.  Their is the current object \n";
	WORD their3("");
	us + their3;
	cout << "us followed by empty their3 is \n" << us << " = XXXX" << endl;
	cout << "*************************************************\n";
	cout << endl << endl;
	cout << endl << endl;

	cout << "************TEST#11*******************************\n";
	them = "123abc123abc1234567";
	us = "123";
	them.Remove(us);
	cout << "Testing Remove by removing the first occurrence of us"
		<< " from them \n";
	cout << "The word them is " << them << endl;
	//them = abc123abc123567; after removing first occurrence of us"
	cout << "*************************************************\n";
	cout << endl << endl;
	cout << endl << endl;

	cout << "************TEST#12*******************************\n";
	them = "123abc123abc1234567";
	us = "123";
	them.Remove(us);
	cout << "Testing RemoveAll by removing all occurrences of us from them \n";
	cout << "The word them is " << them << endl;
	//them = abcabc567 after removing all occurrences of us are removed
	cout << "*************************************************\n";
	cout << "*************************************************\n";
	cout << endl << endl;
	cout << endl << endl;

	return 0;
}

