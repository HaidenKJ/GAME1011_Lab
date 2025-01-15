// This program illustrates the "this" keyword
#include <iostream>
using namespace std;

class Example
{
public:
	//Example(int a) { x = a; }
	Example(int x)
	{
		this->x = x;
	}
	void setValue(int);
	int getValue();
	void printAddressAndValue();
private:
	int x;
};

//functions can be defined outside of its class
int Example::getValue()
{
	return x;
}

//void Example::setValue(int a)
//{
//	x = a;
//}

//two uses for the "this" keyword
void Example::setValue(int x)
{
	//we can use "this" to differentiate parameter x and member variable x
	this->x = x;
}

void Example::printAddressAndValue()
{
	//"this" is a pointer to the obj's address, can also dereference it with * and use it aka this->x = (*this).x
	cout << "The object at address " << this << " has value " << (*this).x << endl;
}

//int main()
//{
//	Example ob1(10), ob2(20);
//	ob1.setValue(5);
//	// Print the addresses of the two objects
//	cout << " Addresses of objects are " << &ob1 << " and " << &ob2 << endl;
//
//	// Pring the address and values for within the member function
//	ob1.printAddressAndValue();
//	ob2.printAddressAndValue();
//}