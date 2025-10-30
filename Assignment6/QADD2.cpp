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
int countOnes(int n) {
    int cnt = 0;
    while(n) {
        cnt += n & 1;
        n >>= 1;
    }
    return cnt;
}
void removeEvenParityDLL(Node*& head) {
    Node* temp = head;
    while (temp) {
        Node* nextNode = temp->next;
        if (countOnes(temp->data) % 2 == 0) {
            if (temp->prev)
                temp->prev->next = temp->next;
            else
                head = temp->next;
            if (temp->next)
                temp->next->prev = temp->prev;
            delete temp;
        }
        temp = nextNode;
    }
}
void displayDLL(Node* head) {
    Node* temp = head;
    cout << "Doubly Linked List: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void removeEvenParityCSLL(CSNode*& head) {
    if (!head) return;
    CSNode* curr = head;
    CSNode* prev = nullptr;
    while (head && countOnes(head->data) % 2 == 0) {
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        CSNode* tail = head;
        while (tail->next != head) tail = tail->next;
        CSNode* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }
    if (!head) return;
    prev = head;
    curr = head->next;
    while (curr != head) {
        if (countOnes(curr->data) % 2 == 0) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}
void displayCSLL(CSNode* head) {
    if (!head) { cout << "Circular List is empty.\n"; return; }
    CSNode* temp = head;
    cout << "Circular Singly Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
int main() {
    Node* dllHead = new Node(1);
    dllHead->next = new Node(2);
    dllHead->next->prev = dllHead;
    dllHead->next->next = new Node(3);
    dllHead->next->next->prev = dllHead->next;
    dllHead->next->next->next = new Node(4);
    dllHead->next->next->next->prev = dllHead->next->next;
    dllHead->next->next->next->next = new Node(5);
    dllHead->next->next->next->next->prev = dllHead->next->next->next;
    dllHead->next->next->next->next->next = new Node(6);
    dllHead->next->next->next->next->next->prev = dllHead->next->next->next->next;
    cout << "Original DLL:\n";
    displayDLL(dllHead);
    removeEvenParityDLL(dllHead);
    cout << "DLL after removing even parity nodes:\n";
    displayDLL(dllHead);
    CSNode* csHead = new CSNode(10);
    CSNode* n2 = new CSNode(15);
    CSNode* n3 = new CSNode(20);
    CSNode* n4 = new CSNode(25);
    CSNode* n5 = new CSNode(30);
    csHead->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = csHead;
    cout << "\nOriginal CSLL:\n";
    displayCSLL(csHead);
    removeEvenParityCSLL(csHead);
    cout << "CSLL after removing even parity nodes:\n";
    displayCSLL(csHead);
    return 0;
}