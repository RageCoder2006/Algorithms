#include <iostream>
using namespace std;

// push_front, push_back, pop_front, pop_back, insert, reverse, middle_ele

class Node {
public:
    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Linked {
    Node *head;
    Node *tail;

public:
    Linked() {
        head = tail = nullptr;
    }

    void display() {
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void push_front(int val) {
        Node *newNode = new Node(val); // assigns new node value dynamically
        if (head == nullptr) {
            head = tail = newNode;
            return;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node *newNode = new Node(val);
        if (tail == nullptr) {
            head = tail = newNode;
            return;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {
        if (head == nullptr) {
            cout << "The linked list is empty" << endl;
            return;
        } else {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void pop_back() {
        if (head == nullptr) {
            cout << "The linked list is empty" << endl;
            return;
        } else if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        } else {
            Node *temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
    }

    void insert(int val, int pos) {
        if (pos == 0) {
            push_front(val);
        } else if (pos < 0) {
            cout << "Invalid Position" << endl;
            return;
        } else {
            Node *newNode = new Node(val);
            Node *temp = head;
            for (int i = 0; i < pos - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void search(int key) {
        int idx = 0;
        if (head == nullptr) {
            cout << "The linked list is empty" << endl;
        } else {
            Node *temp = head;
            while (temp != nullptr) {
                if (temp->data == key) {
                    cout << key << "  found at index " << idx << endl;
                    return;
                }
                temp = temp->next;
                idx++;
            }
        }
        cout << key << "not found" << endl;
    }

    void reverse() {
        if (head == nullptr) {
            cout << "The linked list is empty" << endl;
        } else {
            Node *curr = head;
            Node *prev = nullptr;
            Node *next = nullptr;
            while (curr != nullptr) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head = prev;
        }
    }

    // alternative method is brute-force to find the total no. of elements & mid = size/2 or ((size/2)+1)
    // this method uses slow-fast pointer approach. Logically fast moves with double speed and hence when
    // it reaches the nullptr, slow will be at mid of linked list
    void middle() {
        if (head == nullptr) {
            cout << "The linked list is empty" << endl;
        } else {
            Node *slow = head;
            Node *fast = head;
            while (fast != nullptr && fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }
            cout << slow->data << endl;
        }
    }
};

int main() {
    Linked ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.display();
    ll.middle();
}
