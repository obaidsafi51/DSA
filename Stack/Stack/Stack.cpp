// Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#define MAX 10
class Stack {
	int S[MAX];
	int top;
	int count;
public:
	Stack(): top(-1), count(0) {
		S[0] = { 0 };
	}
	void PUSH(int val);
	int POP();
	int elementInStack() {return count;}
	void displayEle();
};
void Stack::displayEle() {
	cout << "Stack Contains : " << endl;
	for (int i = top; i >= 0; i--) {
		cout << S[i] << " ";
	}
	cout << endl;
}
void Stack::PUSH(int val) {
	if (top == MAX - 1){
		cout << "Stack Overflow " << endl;
		return;
	}
	top++;
	S[top] = val;
	count++;
	return;
}
int Stack::POP() {
	if (top == -1) {
		cout << "Stack Underflow " << endl;
		return -1;
	}
	int item;
	item = S[top];
	top--;
	count--;
	return item;
}
int main()
{
	Stack Stk;
	int val;
	int item;
	int c;
	
	do {
		cout <<"***************************" << endl
			<< "1.Push to Stack" << endl
			<< "2.Pop from Stack " << endl
			<< "3.Element in Stack " << endl
			<< "4.Display Elements In Stack " << endl
			<< "5.Exit " << endl<<endl
			<< "***************************" << endl <<endl;
		int ch;
		cout << "Enter the Choice :" << endl;
		cin >> ch;

		switch (ch)
		{
		case 1:
		{	cout << "Enter the Value : " << endl;
			cin >> val;
			Stk.PUSH(val);
		}
		break;
		case 2:
			item = Stk.POP();
			cout << item << endl;
			break;
		case 3:
		{	cout << "Elements in the Stack : " << endl;
			c = Stk.elementInStack();
			cout << c << endl;
		}	break;
		case 4:
			Stk.displayEle();
			break;
		case 5:
			exit(-1);
			break;
		default:
			break;
		}
	} while (true);
	
	

	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
