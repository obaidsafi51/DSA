#include <iostream>
#include <string>

using namespace std;

#define MAX_SIZE 5 // Maximum size of the circular queue

class CircularQueue {
private:
    int front, rear, count;
    string queue[MAX_SIZE];

public:
    CircularQueue() {
        front = rear = -1;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == MAX_SIZE;
    }
    int getCount() {
        return count;
    }
    void editRear(string newPatient);
    void enqueue(string patient);
    void dequeue();
    void viewQueue();
    void clearQueue();
    void editFront(string newPatient);
};
    void CircularQueue::enqueue(string patient) {
        if (isFull()) {
            cout << "Queue is full. Cannot add more patients.\n";
            return;
        }
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = patient;
        if (front == -1) {
            front = rear;
        }
        count++;
    }

    void CircularQueue::dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No patient to delete.\n";
            return;
        }
        cout << "Deleted patient record: " << queue[front] << endl;
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % MAX_SIZE;
        }
        count--;
    }

    void CircularQueue::viewQueue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Patient records in the Circular Queue:\n";
        int i = front;
        do {
            cout << queue[i] << endl;
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
    }

   

    void CircularQueue::clearQueue() {
        front = rear = -1;
        count = 0;
        cout << "Circular Queue has been cleared.\n";
    }

    void CircularQueue::editFront(string newPatient) {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot edit front value.\n";
            return;
        }
        queue[front] = newPatient;
        cout << "Front patient record has been updated.\n";
    }

    void CircularQueue::editRear(string newPatient) {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot edit rear value.\n";
            return;
        }
        queue[rear] = newPatient;
        cout << "Rear patient record has been updated.\n";
    }


int main() {
    CircularQueue queue;
    int choice;
    string patientName;

    cout << "Welcome to the Queue menu!\n";
    do {
        cout << "Press 1 To insert a new patient record in the Circular Queue\n";
        cout << "Press 2 To delete a patient record from the Circular Queue\n";
        cout << "Press 3 View patient record in the Circular Queue\n";
        cout << "Press 4 Number of patients in the Circular Queue\n";
        cout << "Press 5 Delete all elements from the Circular Queue\n";
        cout << "Press 6 Edit front value of a Circular Queue\n";
        cout << "Press 7 Edit rear value of a Circular Queue\n";
        cout << "Press 8 Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter patient name: ";
            cin >> patientName;
            queue.enqueue(patientName);
            break;
        case 2:
            queue.dequeue();
            break;
        case 3:
            queue.viewQueue();
            break;
        case 4:
            cout << "Number of patients in the Circular Queue: " << queue.getCount() << endl;
            break;
        case 5:
            queue.clearQueue();
            break;
        case 6:
            cout << "Enter new patient name for front: ";
            cin >> patientName;
            queue.editFront(patientName);
            break;
        case 7:
            cout << "Enter new patient name for rear: ";
            cin >> patientName;
            queue.editRear(patientName);
            break;
        case 8:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please enter a valid option.\n";
            break;
        }
    } while (choice != 8);

    return 0;
}

