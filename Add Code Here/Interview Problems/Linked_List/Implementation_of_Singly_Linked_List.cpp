#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insertAtBegin(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int data) {
        insert(data);
    }

    void insertAtPosition(int data, int position) {
        if (position <= 0) {
            cout << "Invalid position for insertion." << endl;
            return;
        }

        if (position == 1) {
            insertAtBegin(data);
        } else {
            Node* newNode = new Node(data);
            Node* temp = head;

            for (int i = 1; i < position - 1; i++) {
                if (temp == nullptr) {
                    cout << "Invalid position for insertion." << endl;
                    return;
                }
                temp = temp->next;
            }

            if (temp == nullptr) {
                cout << "Invalid position for insertion." << endl;
                return;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleteAtBegin() {
        if (head == nullptr) {
            cout << "Linked List is empty." << endl;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "Linked List is empty." << endl;
        } else if (head->next == nullptr) {
            deleteAtBegin();
        } else {
            Node* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
    }

    void deleteAtPosition(int position) {
        if (position <= 0) {
            cout << "Invalid position for deletion." << endl;
            return;
        }

        if (position == 1) {
            deleteAtBegin();
        } else {
            Node* temp = head;

            for (int i = 1; i < position - 1; i++) {
                if (temp == nullptr || temp->next == nullptr) {
                    cout << "Invalid position for deletion." << endl;
                    return;
                }
                temp = temp->next;
            }

            if (temp == nullptr || temp->next == nullptr) {
                cout << "Invalid position for deletion." << endl;
                return;
            }

            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList linkedList;

    int choice, data, position;
    while (true) {
        cout << "\nChoose an operation:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Insert At Begin" << endl;
        cout << "3. Insert At End" << endl;
        cout << "4. Insert At Position" << endl;
        cout << "5. Delete At Begin" << endl;
        cout << "6. Delete At End" << endl;
        cout << "7. Delete At Position" << endl;
        cout << "8. Display" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                linkedList.insert(data);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data;
                linkedList.insertAtBegin(data);
                break;
            case 3:
                cout << "Enter data: ";
                cin >> data;
                linkedList.insertAtEnd(data);
                break;
            case 4:
                cout << "Enter data: ";
                cin >> data;
                cout << "Enter position: ";
                cin >> position;
                linkedList.insertAtPosition(data, position);
                break;
            case 5:
                linkedList.deleteAtBegin();
                break;
            case 6:
                linkedList.deleteAtEnd();
                break;
            case 7:
                cout << "Enter position: ";
                cin >> position;
                linkedList.deleteAtPosition(position);
                break;
            case 8:
                linkedList.display();
                break;
            case 9:
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
