// 01_Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int srearchArr(int myArray[], int n) {

	// Search a Number and its Location

	int sn;

	cout << "Enter the number : ";

	cin >> sn;
	int  i;
	for (i = 0; i < n; i++) {
		if (sn == myArray[i]) {
			cout << "Number is Found at the Location : " << i + 1 << endl << endl;
			return i;
		}
	}
	return -1;

}
void deleteRec(int myArray[], int &n ) {

	int pos = srearchArr(myArray, n);

	for (int i = pos; i < n; i++) {
		myArray[i] = myArray[i+1];
	}
	cout << "Value has been Deleted ." << endl;
	n--;
}

void deleteFirstRec(int myArray[], int& n) {
	for (int i = 0; i < n; i++) {
		myArray[i] = myArray[i + 1];
	}
	n--;
}

void display(int myArray[], int n) {
	for (int i = 0; i < n; i++) {
		cout << myArray[i] << " ";
	}
	cout << endl;
}
int main()
{
	int myArray[10];
	int n = 10;
	int nn;
	int ch;

	//cout << "Enter the number to fill the array :" << endl;
	for (int i = 0; i < n; i++) {

		
		myArray[i] = i;
		//nn = i;
	}
	do {
		cout << "1. Search the Number. " << endl
			<< "2. Display the Number. " << endl
			<< "3. Insert the Element in the Start. " << endl
			<< "4. Delete the First Element ." << endl
			<< "5. Delete User Defined Number. " << endl << endl;

		cout << "Chose the Option : " << endl;
		cin >> ch;


		switch (ch)
		{
		case 1:
			srearchArr(myArray, n);
			break;
		case 2:
			display(myArray, n);
			break;
		case 3:

		case 4:
			deleteFirstRec(myArray, n);
			break;

		case 5:
			deleteRec(myArray, n);
			break;
		
		default:
			break;
		}

	} while (true);
	return  0;
}
	// Count the repetition of the user defined number from a Array
//
//	int myArray[10];
//	int n;
//	cout << "Enter the number to fill the array :" << endl;
//	for (int i = 0; i < 10; i++) {
//
//		cin >> n;
//		myArray[i] = n;
//	}
//	int sn;
//	cout << "Enter the number to be searched in the Array: ";
//
//	cin >> sn;
//	int c = 0;
//	for (int i = 0; i < 10; i++) {
//		if (sn == myArray[i]) 
//			c++;
//		if(c == 0)
//			cout << "Number is found! " << endl;
//		else
//			cout << "Number is Not Found! " << endl;
//	}
//	cout << "The repetition of Number " << sn << " is " << c;
//
//
//	// Insert an element in the start of the array
//
//	int myArray[10]{};
//	int n;
//	int nA;
//	do {
//		cout << "How much Number you want to add in the Array : " << endl;
//		cin >> nA;
//	} while (nA > 9 || nA < 0);
//	cout << "Enter the number to fill the array :" << endl;
//	for (int i = 0; i < nA; i++) {
//
//		cin >> n;
//		myArray[i] = n;
//	}
//	int sn;
//	cout << "Enter the number to be inserted in the Array: ";
//
//	cin >> sn;
//
//	for (int i = nA - 1; i >= 0; i--) {
//		myArray[i+1] = myArray[i];
//	}
//	myArray[0] = sn;
//	
//	
//	cout << "New Array is : " << endl;
//	for (int i = 0; i < nA; i++) {
//		cout << myArray[i] << endl;
//	}
//
//	return 0;
//
//}
