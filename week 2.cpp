#include <iostream>
#include <string>
using namespace std;

// MailService
// --Post Offices
// ----Packages

struct Package {
	string deliveryAddress = "Delivery Test Address";
	string message;
};

class PostOffice
{
public:
	PostOffice() {

	}
	~PostOffice() {

	}
	void SetAddress(string address) {
		buildingAddress = address;
	}
	void SetPackages(Package* _packages, int numPackages) {
		this->packages = _packages;
		this->packageCount = numPackages;
	}
	Package* GetPackages() {
		return packages;
	}
	string GetAddress() {
		return buildingAddress;
	}
	void PrintPackages() {
		for (int i = 0; i < packageCount; i++) {
			cout << "Package Message: " << packages[i].message;
		}
	}
private:
	string buildingAddress = "Test Address";
	int packageCount = 0;
	Package* packages;
};

class MailService {
public:
	MailService() {

	}
	~MailService() {

	}
	void SetOffices(PostOffice* _offices, int numOffices) {
		this->offices = _offices;
		this->officesCount = numOffices;
	}
	void SetName(string name) {
		businessName = name;
	}
private:
	string businessName = "";
	int officesCount = 0;
	PostOffice* offices;
};

int main()
{
	int serviceCount;
	int officeCount;
	int packageCount;
	cout << "Welcome to the ol' mail simulator." << endl;
	cout << "Please enter the amount of mail services you wish to create: " << endl;
	cin >> serviceCount;
	cout << "Please enter the amount of post offices you wish to create: " << endl;
	cin >> officeCount;
	cout << "Please enter the amount of packages you wish to create: " << endl;
	cin >> packageCount;

	Package* packages = new Package[packageCount];
	PostOffice* offices = new PostOffice[officeCount];
	MailService* services = new MailService[serviceCount];

	offices->SetPackages(packages, packageCount);
	offices[0].SetPackages(packages, packageCount);
	services->SetOffices(offices, officeCount);
	offices->PrintPackages();
}
