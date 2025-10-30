#include<iostream>
using namespace std;

class ListNode{
public:
    int data;
    ListNode* next;
    ListNode(int v){
        data=v;
        next=nullptr;
    }
};

class LinkedList{
public:
    ListNode* head;
    LinkedList(){
        head=nullptr;
    }
    void display(){
        ListNode* t=head;
        while(t!=nullptr){
            cout<<t->data<<" -> ";
            t=t->next;
        }
        cout<<endl;
    }
    void insertAtEnd(int val){
        ListNode* ln=new ListNode(val);
        if(head==nullptr){
            head=ln;
            return;
        }
        ListNode* t=head;
        while(t->next!=nullptr)
            t=t->next;
        t->next=ln;
        ln->next=nullptr;
    }
};
void removeLoop(ListNode* head) {
    if (!head || !head->next) return;
    ListNode* slow = head;
    ListNode* fast = head;
    // Detect loop using Floyd's Cycle Detection
    bool loopExists = false;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            loopExists = true;
            break;
        }
    }
    if(!loopExists) return;
    // Find the start of the loop
    slow = head;
    ListNode* prev = nullptr; 
    while(slow != fast) {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }

    if(prev)
        prev->next = nullptr;
}

int main() {
    LinkedList l;
    l.insertAtEnd(1);
    l.insertAtEnd(2);
    l.insertAtEnd(3);
    l.insertAtEnd(4);
    l.insertAtEnd(5);
    l.head->next->next->next->next->next = l.head->next->next;

    removeLoop(l.head);
    cout << "Linked List after removing loop:\n";
    l.display();

    return 0;
}