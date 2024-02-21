// 01_Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
	/*
	int myArray[10];
	int n;
	cout << "Enter the number to fill the array :" << endl;
	for (int i = 0; i < 10; i++) {

		cin >> n;
		myArray[i] = n;
	}

	int sn;

	cout << "Enter the number to be searched in the Array: ";

	cin >> sn;

	for (int i = 0; i < 10; i++) {
		if (sn == myArray[i]) {
			cout << "Number is Found and the Number is : " << sn << endl;
			cout << "Location of the Number is : " << i +1 << endl;
		}
	}*/

	/*int myArray[10];
	int n;
	cout << "Enter the number to fill the array :" << endl;
	for (int i = 0; i < 10; i++) {

		cin >> n;
		myArray[i] = n;
	}
	int sn;
	cout << "Enter the number to be searched in the Array: ";

	cin >> sn;
	int c = 0;
	for (int i = 0; i < 10; i++) {
		if (sn == myArray[i]) 
			c++;
		if(c == 0)
			cout << "Number is found! " << endl;
		else
			cout << "Number is Not Found! " << endl;
	}
	cout << "The repetition of Number " << sn << " is " << c;
	*/

	int myArray[10]{};
	int n;
	int nA;
	do {
		cout << "How much Number you want to add in the Array : " << endl;
		cin >> nA;
	} while (nA > 9 || nA < 0);
	cout << "Enter the number to fill the array :" << endl;
	for (int i = 0; i < nA; i++) {

		cin >> n;
		myArray[i] = n;
	}
	int sn;
	cout << "Enter the number to be inserted in the Array: ";

	cin >> sn;

	for (int i = nA - 1; i >= 0; i--) {
		myArray[i+1] = myArray[i];
	}
	myArray[0] = sn;
	
	/*cout << "The Number Inserted in the Start of the Array is : " << myArray[0];*/
	
	cout << "New Array is : " << endl;
	for (int i = 0; i < nA; i++) {
		cout << myArray[i] << endl;
	}

	return 0;

}
