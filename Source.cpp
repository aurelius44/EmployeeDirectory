// Mark Middleton
// CIS 1202 501
// October 10, 2022
// Midterm Project: Employee Directory

using namespace std;

#include<iostream>;
#include<iomanip>;
#include<string>;
#include<cstring>;

struct EmpInfo
{
	int empID;
	string empName;
};

struct Hours
{
	int hoursWrkd;
	int hoursSchld;
};

struct Pay
{
	double payRate;
};


int menu();
EmpInfo getEmpInfo();
Hours getHoursInfo();
Pay getPayInfo();
void displayEmployees(EmpInfo);
void sortEmployees(EmpInfo[][2], Hours[][2],Pay[], int);
double totalHours(Hours[][2], int);
void empInfo(EmpInfo[][2]);
void empHours(Hours[][2]);
void empPayInfo(Pay[]);
void empSearch(EmpInfo[][2], int);


int main() {

	int choice = 0, size = 0; // Choice initializes variable for menu

	struct EmpInfo employeeList[10][2]; // Holds names and IDs for employees
	struct Hours empHoursList[10][2]; // Holds hours worked/scheduled to work of employees
	struct Pay empPayList[10]; // Contains pay rate for employees

	while (choice != 6) { // while loop continues until '6' is selected by user

		choice = menu(); // tempChoice returns value to choice, allowing use to select

		switch (choice)
		{
		case 1: employeeList[size][2] = getEmpInfo(); // Stpres employee names/IDs in array
			empHoursList[size][2] = getHoursInfo(); // Stores hours worked/schedule in array
			empPayList[size] = getPayInfo(); // Stores employee pay rate in array
			size++; // Increases size of array for employees added
			break;
		case 2: for (int i = 0; i < size; i++) {
			displayEmployees(employeeList[i][2]); // Displays employees w/ respective IDs
		}; 
			break;
		case 3: //sortEmployees(employeeList, empHoursList, empPayList, size); // Sorts employees by name
			break;
		case 4: totalHours(empHoursList, size); // Shows collective hours worked/scheduled by employees
			break;
		case 5:; empSearch(employeeList, size); // Searches for employee; displays name, ID, hours worked/scheduled, and pay rate
			break;
		case 6: exit(0); // Allows user to end program
			break;
		default: cout << "Invalid selection.\n" << "Input 1 - 5. \n\n";
			break;
		}
	}

}

int menu() {
	
	int tempChoice;

	cout << "\nEmployee Directory\n\n";
	cout << "------------------";
	cout << "\t1. Enter Employee Infomation\n";
	cout << "\t2. Display All Employees\n";
	cout << "\t3. Sort Employees Alphabetically\n";
	cout << "\t4. Total Hours Worked and Scheduled\n";
	cout << "\t5. Search For An Employee\n";
	cout << "\t6. Exit Program\n\n";
	cout << "Please make a selection.\n\n";

	cin >> tempChoice;

	return tempChoice;
}

EmpInfo getEmpInfo() { // Allows user to input employee ID and name
	struct EmpInfo employee;

	cout << "\nEnter Employee ID Number: ";
	cin >> employee.empID; // User inputs employee ID; stored in array and structure
	cout << "\nEnter Employee Name: ";
	cin.ignore();
	getline(cin,employee.empName); // User inputs employee name; stored in array and structure

	return employee; // Returns info to structure/array
}

Hours getHoursInfo() { // Function allows user to input hours employee has worked and is scheduled to work
	struct Hours empHours;

	cout << "\nEnter Hours Worked This Week: ";
	cin >> empHours.hoursWrkd; // User inputs hours worked by employee; stored in array and structure
	cout << "\nEnter Hours Scheduled This Week: ";
	cin >> empHours.hoursSchld; // User inputs hours scheduled to employee; stored in array and structure

	return empHours; // Returns info to structure/array
}

Pay getPayInfo() { // Function allows user to input employee pay rate
	struct Pay empPay;

	cout << "\nPay Rate For Employee? ";
	cin >> empPay.payRate; // User inputs employee pay rate; stored in array and structure

	return empPay; // Returns info to structure/array
}

void displayEmployees(struct EmpInfo employee) { // Function displays all employee names and IDs

	cout << "Employee List: \n";
	cout << "--------------\n";
	cout << "\tEmployee ID: " << employee.empID << endl; // Displays employee IDs
	cout << "\tEmployee Name: " << employee.empName << endl; // Displays corresponding employee names
}

void sortEmployees(struct EmpInfo employeeList[][2], struct Hours empHoursList[][2], struct Pay empPayList[], int size) {
	
	int maxElement; // Holds element subscript



	for (maxElement = size - 1; maxElement > 0;  maxElement--) { // Searchs array elements
		for (int i = 0; i < maxElement; i++) { // Search array to make comparison between array elements
			
			string x = employeeList[i][1];
			string y = employeeList[i + 1][1];


			if (strcmp(x, y) > 0) { // Compares array elements
				swap(employeeList[i][0], employeeList[i + 1][0]); //Swaps employee ID
				swap(employeeList[i][1], employeeList[i + 1][1]); //Swaps employee name
				swap(empHoursList[i][0], empHoursList[i + 1][0]); //Swaps employee hours worked
				swap(empHoursList[i][1], empHoursList[i + 1][1]); //Swaps employee hours scheduled
				swap(empPayList[i], empPayList[i + 1]); // Swaps employee pay rate
			}
		}
	}
}

void totalHours(struct Hours empHoursList[][2], int size) { // Function displays collective employee hours worked/scheduled to worked

	int total1;
	int total2;

	for (int i = 0; i < size; i++) {
		total1 += empHoursList[i][0].hoursWrkd;
		total2 += empHoursList[i][1].hoursSchld;
	}
	
	cout << "Hours" << endl;
	cout << "\tTotal Hours Worked By Employees: " << endl;
	cout << total1;
	cout << "\tTotal Hours Employees Scheduled To Be Worked: " << endl;
	cout << total2;
}

void empInfo(struct EmpInfo employee) { // Function displays specific employee name and ID
	cout << "Employee Information:\n\n";
	cout << "\tEmployee ID: \n";
	cout << "\t" << employee.empID << endl; // Displays specific employee ID
	cout << "\tEmployee Name: \n";
	cout << "\t" << employee.empName << endl; // Displays specific employee name
}

void empHours(struct Hours empHours) { // Function to display hours worked/scheduled to work by specific employee
	cout << "\tHours Worked: \n";
	cout << "\t" << empHours.hoursWrkd << endl; // Displays hours worked by specfic employee
	cout << "\tHours Scheduled: \n";
	cout << "\t" << empHours.hoursSchld << endl; // Displays hours to work by specific employee
}

void empPayInfo(struct Pay empPay, struct Hours empHours) { // Function displays employee pay rate and wages earned
	cout << "\tPay Rate: \n";
	cout << "\t" << empPay.payRate << endl; // Displays pay rate
	cout << "\tWeekly Earnings: \n";
	cout << "$" << (empPay.payRate * empHours.hoursWrkd) << endl; // Displays weekly earnigns
}

void empSearch(struct EmpInfo employeeList[][2], struct Hours empHoursList[][2], struct Pay empPayList[], int size) { // Function searchs for employee in array/structure, displays details
	
	string tempName; // User input name to search

	cout << "Employee Name? ";
	cin.ignore();
	getline(cin, tempName);

	bool found = false;

	for (int i = 0; i < size; i++) { // Searches array for tempName, displays employee details
		if (employeeList[i][0].empName == tempName) {
			found = true;
			empInfo(employeeList[i][0]); // Displays employee name/ID
			empHours(empHoursList[i][0]); // Displays hours worked/scheduled
			empPayInfo(empPayList[i], empHoursList[i][0]); // Displays pay rate/weekly earnings
			break;
		}
	}

	if (found = 0) {
		cout << "Employee not found.\n"; // Displays if no employee is found
	}
}