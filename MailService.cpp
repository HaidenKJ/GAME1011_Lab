// Platform
//        Games
//            Achievements

//    MailService
//        PostOffice
//            Package

#include <iostream>
#include <string>
using namespace std;

//structs are public by default, and easy to use if you're just holding some variables
struct Package
{
	string deliveryAddress;
	string message;
};

class PostOffice
{
public:
	PostOffice()
	{

	}

	// we must keep track of the size of our dynamic array (packages* in PostOffice) otherwise 
	//impossible to figure out size for looping
	void PrintPackages()
	{
		for (int i = 0; i < packageCount; i++)
		{
			cout << "\n " << packages[i].message;
		}
	}

	void SetPackages(Package* packages, int packageCount)
	{
		this->packages = packages;
		this->packageCount = packageCount;
	}

	void SetAddress(string address)
	{
		buildingAddress = address;
	}

	string GetAddress()
	{
		return buildingAddress;
	}

private:
	string buildingAddress;
	Package* packages;
	int packageCount;
};

class MailService
{
public:
	MailService()
	{

	}
	void SetOffice(PostOffice* offices, int officesCount)
	{
		this->offices = offices;
		this->officesCount = officesCount;
	}
private:
	string businessName;
	PostOffice* offices;
	int officesCount;
};

int main()
{
	int serviceCount;
	int officeCount;
	int packageCount;
	cout << "Welcome to mail simulator 2024" << endl;
	cout << "Please enter the amount of mail services you wish to create." << endl;
	cin >> serviceCount;
	cout << "Please enter the amount of post offices you wish to create." << endl;
	cin >> officeCount;
	cout << "Please enter the amount of packages you wish to create." << endl;
	cin >> packageCount;

	//dynamically allocate memory using the "new" keyword, allowing for user to input size of array
	Package* packages = new Package[packageCount];
	PostOffice* offices = new PostOffice[officeCount];
	offices->SetPackages(packages, packageCount);
	MailService* services = new MailService[serviceCount];
	services->SetOffice(offices, officeCount);
	offices->PrintPackages();
}