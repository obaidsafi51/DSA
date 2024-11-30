// Circular Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#define S 6

class CQueue {
	int CQue[S];
	int front = -1;
	int rear = -1;
	int val;

public:
	void insert();
	void deletion();
	void display();
};

void CQueue::insert() {
	cout << "Give the Value to insert " << endl;

	cin >> val;

	if (front == -1 && rear == -1) {
		front++;
		goto Set_Rear;
	}
	if ((front == 0) && (rear == (S - 1)) || (front == rear + 1)) {
		cout << "Circular Queue Overflow" << endl;
		return;
	}
	if (rear == S - 1) {
		rear = 0;
	}

Set_Rear:
	rear += 1;
	CQue[rear] = val;
}

void CQueue::display() {
	cout << "Queue :" << endl;

	for (int i = front; i <= rear; i++) {
		cout << CQue[i] << endl;
	}
}

void CQueue::deletion() {

	CQue[front] = CQue[front++];
	cout << "You have Successfully Deleted an Item " << endl;

}

int main()
{

	CQueue Que;
	do {
		cout << "**************************" << endl;
		cout << "1.Insert Value " << endl
			<< "2.Delete Value " << endl
			<< "3.Display" << endl << endl;
		cout << "**************************" << endl<< endl;
		int ch;
		cout << "Enter the Task : " << endl;
		cin >> ch;

		switch (ch)
		{
		case 1:
			Que.insert();
			break;
		case 2:
			Que.deletion();
			break;
		case 3:
			Que.display();
			break;
		default:
			break;
		}


	} while (true);



	
	return 0;

}
