#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};
class CSNode {
public:
    int data;
    CSNode* next;
    CSNode(int val) {
        data = val;
        next = nullptr;
    }
};
class DoublyLinkedList {
public:
    Node* head;
    DoublyLinkedList() { head = nullptr; }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAfter(int target, int val) {
        Node* temp = head;
        while (temp && temp->data != target) temp = temp->next;
        if (!temp) {
            cout << "Node " << target << " not found.\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
    }

    void insertBefore(int target, int val) {
        Node* temp = head;
        if (!temp) return;
        if (temp->data == target) {
            insertAtBeginning(val);
            return;
        }
        while (temp && temp->data != target) temp = temp->next;
        if (!temp) {
            cout << "Node " << target << " not found.\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(int val) {
        Node* temp = head;
        while (temp && temp->data != val) temp = temp->next;
        if (!temp) {
            cout << "Node " << val << " not found.\n";
            return;
        }
        if (temp->prev) temp->prev->next = temp->next;
        else head = temp->next;  // deleting head
        if (temp->next) temp->next->prev = temp->prev;
        delete temp;
        cout << "Node " << val << " deleted.\n";
    }

    void searchNode(int val) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == val) {
                cout << "Node " << val << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << val << " not found.\n";
    }

    void display() {
        Node* temp = head;
        if (!temp) { cout << "List is empty.\n"; return; }
        cout << "Doubly Linked List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
class CircularSinglyLinkedList {
public:
    CSNode* head;
    CircularSinglyLinkedList() { head = nullptr; }

    void insertAtBeginning(int val) {
        CSNode* newNode = new CSNode(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        CSNode* tail = head;
        while (tail->next != head) tail = tail->next;
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }

    void insertAtEnd(int val) {
        CSNode* newNode = new CSNode(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        CSNode* tail = head;
        while (tail->next != head) tail = tail->next;
        tail->next = newNode;
        newNode->next = head;
    }

    void insertAfter(int target, int val) {
        if (!head) return;
        CSNode* temp = head;
        do {
            if (temp->data == target) {
                CSNode* newNode = new CSNode(val);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << target << " not found.\n";
    }

    void deleteNode(int val) {
        if (!head) return;
        CSNode* curr = head;
        CSNode* prev = nullptr;

        // Special case: head node
        if (head->data == val) {
            if (head->next == head) { // only one node
                delete head;
                head = nullptr;
                cout << "Node " << val << " deleted.\n";
                return;
            }
            CSNode* tail = head;
            while (tail->next != head) tail = tail->next;
            CSNode* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
            cout << "Node " << val << " deleted.\n";
            return;
        }

        // Deleting non-head node
        prev = head;
        curr = head->next;
        while (curr != head) {
            if (curr->data == val) {
                prev->next = curr->next;
                delete curr;
                cout << "Node " << val << " deleted.\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "Node " << val << " not found.\n";
    }

    void searchNode(int val) {
        if (!head) { cout << "List is empty.\n"; return; }
        CSNode* temp = head;
        int pos = 1;
        do {
            if (temp->data == val) {
                cout << "Node " << val << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Node " << val << " not found.\n";
    }

    void display() {
        if (!head) { cout << "List is empty.\n"; return; }
        CSNode* temp = head;
        cout << "Circular Singly Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};
void displayCircularList(CSNode* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    CSNode* temp = head;
    cout << "Circular Singly Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data << " (head)" << endl;  
}
//Calculate size of Doubly Linked List
int sizeDoublyLinkedList(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}
//Calculate size of Circular Singly Linked List
int sizeCircularLinkedList(CSNode* head) {
    if (!head) return 0;
    int count = 0;
    CSNode* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}
//Check is Palindrome or Not
bool isPalindrome(Node* head) {
    if (!head) return true;  

    Node* tail = head;
    while (tail->next) tail = tail->next;

    Node* start = head;
    Node* end = tail;
    while (start != end && start->prev != end) { 
        if (start->data != end->data)
            return false;
        start = start->next;
        end = end->prev;
    }
    return true;
}
// Function to check if a linked list is circular
bool isCircular(Node* head) {
    if (!head) return false; 
    Node* temp = head->next;
    // Traverse until we reach back to head or nullptr
    while (temp != nullptr && temp != head) {
        temp = temp->next;
    }
    return (temp==head);
}
int main() {

    DoublyLinkedList dll;
    CircularSinglyLinkedList csll;

    int choice, type, val, target;
    while (true) {
        cout << "\nChoose List Type:\n1. Doubly Linked List\n2. Circular Singly Linked List\n3. Exit\nChoice: ";
        cin >> type;
        if (type == 3) break;

        cout << "\nOperations:\n1. Insert at Beginning\n2. Insert at End\n3. Insert After Node\n";
        if (type == 1) cout << "4. Insert Before Node\n";
        cout << "5. Delete Node\n6. Search Node\n7. Display List\n8. Back to List Type Menu\nChoice: ";
        cin >> choice;

        if (type == 1) { // DLL
            switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; dll.insertAtBeginning(val); break;
            case 2: cout << "Enter value: "; cin >> val; dll.insertAtEnd(val); break;
            case 3: cout << "Enter target node: "; cin >> target; cout << "Enter value: "; cin >> val; dll.insertAfter(target, val); break;
            case 4: cout << "Enter target node: "; cin >> target; cout << "Enter value: "; cin >> val; dll.insertBefore(target, val); break;
            case 5: cout << "Enter node to delete: "; cin >> val; dll.deleteNode(val); break;
            case 6: cout << "Enter node to search: "; cin >> val; dll.searchNode(val); break;
            case 7: dll.display(); break;
            case 8: continue;
            default: cout << "Invalid choice!\n"; break;
            }
        } else if (type == 2) { // CSLL
            switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; csll.insertAtBeginning(val); break;
            case 2: cout << "Enter value: "; cin >> val; csll.insertAtEnd(val); break;
            case 3: cout << "Enter target node: "; cin >> target; cout << "Enter value: "; cin >> val; csll.insertAfter(target, val); break;
            case 5: cout << "Enter node to delete: "; cin >> val; csll.deleteNode(val); break;
            case 6: cout << "Enter node to search: "; cin >> val; csll.searchNode(val); break;
            case 7: csll.display(); break;
            case 8: continue;
            default: cout << "Invalid choice!\n"; break;
            }
        }
    }
    return 0;
}