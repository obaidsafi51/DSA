#include <iostream>

using namespace std;

const int MAX_STUDENTS = 15;

class Deque {
private:
    int dequeArray[MAX_STUDENTS];
    int front, rear;

public:
    Deque() {
        front = -1;
        rear = -1;
        dequeArray[0] = { 0 };
    }

    bool isFull() {
        return (front == 0 && rear == MAX_STUDENTS - 1) || front == rear + 1;
    }

    bool isEmpty() {
        return front == -1;
    }

    void insertFront(int marks);
    void insertRear(int marks);
    void deleteFront();
    void deleteRear();
    void traverseFront();
    void traverseRear();
    void searchFront(int marks);
    void searchRear(int marks);

};
    void Deque::insertFront(int marks) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert more marks at front.\n";
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        }
        else if (front == 0) {
            front = MAX_STUDENTS - 1;
        }
        else {
            front--;
        }
        dequeArray[front] = marks;
        cout << "Marks inserted at the front.\n";
    }

    void Deque::insertRear(int marks) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert more marks at rear.\n";
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        }
        else if (rear == MAX_STUDENTS - 1) {
            rear = 0;
        }
        else {
            rear++;
        }
        dequeArray[rear] = marks;
        cout << "Marks inserted at the rear.\n";
    }

    void Deque::deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. No marks to delete from front.\n";
            return;
        }
        cout << "Deleted marks from front: " << dequeArray[front] << endl;
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else if (front == MAX_STUDENTS - 1) {
            front = 0;
        }
        else {
            front++;
        }
    }

    void Deque::deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. No marks to delete from rear.\n";
            return;
        }
        cout << "Deleted marks from rear: " << dequeArray[rear] << endl;
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else if (rear == 0) {
            rear = MAX_STUDENTS - 1;
        }
        else {
            rear--;
        }
    }

    void Deque::traverseFront() {
        if (isEmpty()) {
            cout << "Deque is empty. No marks to traverse from front.\n";
            return;
        }
        cout << "Marks traversal from front:\n";
        int i = front;
        do {
            cout << dequeArray[i] << " ";
            i = (i + 1) % MAX_STUDENTS;
        } while (i != (rear + 1) % MAX_STUDENTS);
        cout << endl;
    }

    void Deque::traverseRear() {
        if (isEmpty()) {
            cout << "Deque is empty. No marks to traverse from rear.\n";
            return;
        }
        cout << "Marks traversal from rear:\n";
        int i = rear;
        do {
            cout << dequeArray[i] << " ";
            i = (i - 1 + MAX_STUDENTS) % MAX_STUDENTS;
        } while (i != (front - 1 + MAX_STUDENTS) % MAX_STUDENTS);
        cout << endl;
    }

    void Deque::searchFront(int marks) {
        if (isEmpty()) {
            cout << "Deque is empty. No marks to search from front.\n";
            return;
        }
        for (int i = front; i != (rear + 1) % MAX_STUDENTS; i = (i + 1) % MAX_STUDENTS) {
            if (dequeArray[i] == marks) {
                cout << "Marks found from front.\n";
                return;
            }
        }
        cout << "Marks not found from front.\n";
    }

    void Deque::searchRear(int marks) {
        if (isEmpty()) {
            cout << "Deque is empty. No marks to search from rear.\n";
            return;
        }
        for (int i = rear; i != (front - 1 + MAX_STUDENTS) % MAX_STUDENTS; i = (i - 1 + MAX_STUDENTS) % MAX_STUDENTS) {
            if (dequeArray[i] == marks) {
                cout << "Marks found from rear.\n";
                return;
            }
        }
        cout << "Marks not found from rear.\n";
    }


int main() {
    Deque marksDeque;
    int choice;
    int marks;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insertion at front\n";
        cout << "2. Insertion at rear\n";
        cout << "3. Deletion at front\n";
        cout << "4. Deletion at rear\n";
        cout << "5. Traversal from front\n";
        cout << "6. Traversal from rear\n";
        cout << "7. Searching from front\n";
        cout << "8. Searching from rear\n";
        cout << "9. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter marks: ";
            cin >> marks;
            marksDeque.insertFront(marks);
            break;
        case 2:
            cout << "Enter marks: ";
            cin >> marks;
            marksDeque.insertRear(marks);
            break;
        case 3:
            marksDeque.deleteFront();
            break;
        case 4:
            marksDeque.deleteRear();
            break;
        case 5:
            marksDeque.traverseFront();
            break;
        case 6:
            marksDeque.traverseRear();
            break;
        case 7:
            cout << "Enter marks to search from front: ";
            cin >> marks;
            marksDeque.searchFront(marks);
            break;
        case 8:
            cout << "Enter marks to search from rear: ";
            cin >> marks;
            marksDeque.searchRear(marks);
            break;
        case 9:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please enter a valid option.\n";
            break;
        }
    } while (choice != 9);

    return 0;
}
