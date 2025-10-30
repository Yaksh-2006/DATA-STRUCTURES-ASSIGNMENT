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
ListNode* rotateLeft(ListNode* head, int k) {
    if(!head || !head->next || k==0) return head;
    // Count length
    ListNode* t = head;
    int n = 1;
    while(t->next){
        t = t->next;
        n++;
    }

    k = k % n; 
    if(k == 0) return head;

    t->next = head;

    ListNode* newTail = head;
    for(int i = 1; i < k; i++)
        newTail = newTail->next;

    ListNode* newHead = newTail->next;
    newTail->next = nullptr;

    return newHead;
}
int main() {
    LinkedList l;
    l.insertAtEnd(1);
    l.insertAtEnd(2);
    l.insertAtEnd(3);
    l.insertAtEnd(4);
    l.insertAtEnd(5);

    int k = 2;
    l.head = rotateLeft(l.head, k);

    cout << "Linked List after rotating left by " << k << " positions:\n";
    l.display();

    return 0;
}