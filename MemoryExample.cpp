#include <iostream>
#include <string>

using namespace std;

struct Test
{
	Test()
	{
		counter++;
		number = counter;
		cout << "Object " << number << " created" << endl;
	}
	//destructor
	~Test()
	{
		cout << "Object " << number << " destroyed" << endl;
	}

	int number;
	static int counter;
};

// initialize static variable
int Test::counter = 0;

//int main()
//{
//	// use the default constructor
//	//Test test1; // same as Test test1();
//
//	// arrays of Class/Struct type (in this case Test) can only be constructed with the default constructor
//	//Test stackTests[100];
//
//	/*Exact same principles hold true when using dynamic memory
//	for every new[] we must have delete[] */
//	Test* arrayTest = new Test[100];
//	delete[] arrayTest;
//
//	//for non array new must be accompanied by delete as well
//	Test* scalarTest = new Test();
//	delete scalarTest;
//
//	return 0;
//}