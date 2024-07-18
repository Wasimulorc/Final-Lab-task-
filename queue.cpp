#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int v) {
        data = v;
        next = NULL;
    }
};

class Queue {
private:
    node* front;
    node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    void eq(int v) {
        node* nn = new node(v);
        if (isEmpty()) {
            front = rear = nn;
        } else {
            rear->next = nn;
            rear = nn;
        }
    }

    void dq() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        node* temp = front;
        front = front->next;
        delete temp;
    }

    int first() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot first." << endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.eq(10);
    q.eq(20);
    q.eq(30);
    q.eq(55);
    q.eq(88);
    q.eq(5);
    q.eq(19);
    q.eq(66);
    q.eq(100);

    cout << "Queue elements: ";
    q.display();

    q.dq();
    q.dq();
    cout << "Queue elements after dequeue: ";
    q.display();

    q.dq();
    q.dq();
    q.dq();
    q.dq();
    q.dq();
    cout << "Queue elements after dequeue: ";
    q.display();

    return 0;
}
