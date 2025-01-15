//Static members are shared among all objects of that class
#include <iostream>
using namespace std;

class Square
{
public:
	//declaration of static variable
	static int objectCount;
	Square(double length)
	{
		this->length = length;
		cout << "Constructor called." << endl;

		// Increast objectCount every time Square object is created
		objectCount++;
	}
	double Area()
	{
		return length * length;
	}
	static void printNum(double num) { cout << "Printing number: " << num; }
	// note static functions cannot acces non-static variable such as length
	// does not work static void printNum(double num) { cout << length; }
private:
	double length;
};

// Initialize static member of class Square. creating an object of square not needed.
int Square::objectCount = 0;

void staticDemo()
{
	// static variable
	static int count = 0;
	cout << count << " ";

	// static count will be increased and carry over instead of resetting to 0
	count++;
}

void nonStaticDemo()
{	 
	int count = 0;
	cout << count << " ";

	//count is reset to 0 everytime this function is called
	count++;
}

//int main()
//{
//	for (int i = 0; i < 5; i++)
//		staticDemo();
//	cout << endl;
//	for (int i = 0; i < 5; i++)
//		nonStaticDemo();
//	cout << endl;
//
//	Square sq1(3.3);
//	Square sq2(8.5);
//
//	// Printing total number of objects. object sq1/sq1 . operation not needed!
//	cout << "Total objects: " << Square::objectCount << endl;
//
//	//for lab sake, showing the objectCount is shared for all instances of Square objects
//	Square::objectCount++;
//	sq2.objectCount++;
//	cout << "Total objects: " << sq1.objectCount << endl;
//
//	Square::printNum(1);
//}