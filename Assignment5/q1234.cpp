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
    int deleteFromEnd(){
        if(head==nullptr){
            cout<<"Empty List\n";
            return -1;
        }
        ListNode* t=head;
        while((t->next)->next!=nullptr)
            t=t->next;
        int v=(t->next)->data;
        t->next=nullptr;
        return v;
    }
    int deleteFromStart(){
        if(head==nullptr){
            cout<<"Empty List\n";
            return -1;
        }
        int v=head->data;
        head=head->next;
        return v;
    }
    void insertAtStart(int val){
        ListNode* ln=new ListNode(val);
        if(head==nullptr){
            head=ln;
            return;
        }
        ln->next=head;
        head=ln;
    }
    ListNode* midOfList(){
        ListNode* s=head;
        ListNode* f=head;
        while(f->next!=nullptr){
            s=s->next;
            f=(f->next)->next;
        }
        return s;
    }
    void reverseList(){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode* next;
        while(curr!=nullptr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
    }
    int searchNode(int k){
        ListNode* t=head;
        int pos=1;
        while(t!=nullptr){
            if(t->data==k)
                return pos;
            t=t->next;
            pos++;
        }
    }
    void deleteNode(int k){
        if(head->data==k){
            deleteFromStart();
            return;
        }
        ListNode* c=head->next;
        ListNode* p=head;
        while(c->data!=k){
            p=c;
            c=c->next;
        }
        p->next=c->next;
    }
    void removeAllOccurences(int k){
        ListNode* t=head;
        while(t!=nullptr){
            if(t->data==k)
                deleteNode(k);
            t=t->next;
        }
    }
    void insertBeforeNode(int k,int l){
        ListNode* ln=new ListNode(k);
        if(head->data==l){
            insertAtStart(k);
            return;
        }
        ListNode* c=head->next;
        ListNode* p=head;
        while(c->data!=l){
            p=c;
            c=c->next;
        }
        p->next=ln;
        ln->next=c;
    }
    void insertAfterNode(int k,int l){
        if(head==nullptr) return;
        ListNode* c=head;
        while(c!=nullptr && c->data!=l) 
            c=c->next;
        if(c!=nullptr){
            ListNode* newNode=new ListNode(k);
            newNode->next=c->next;
            c->next=newNode;
        }
    }
};
int main(){
    LinkedList list;
    int ch;
    while(1){
        cout << "===========================" <<endl;
        cout << "1.  Insert at the beginning" <<endl;
        cout << "2.  Insert at the end" <<endl;
        cout << "3.  Insert before a specific node" <<endl;
        cout << "4.  Insert after a specific node" <<endl;
        cout << "5.  Delete from the beginning" <<endl;
        cout << "6.  Delete from the end" <<endl;
        cout << "7.  Delete a specific node" <<endl;
        cout << "8.  Search for a node and Its Position" <<endl;
        cout << "9.  Display all nodes" <<endl;
        cout << "10. Reverse The List" <<endl;
        cout << "11. Find Middle Node" <<endl;
        cout << "12. Remove all Occurences" <<endl;
        cout << "-1. Exit" <<endl;
        cout << "===========================" <<endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch(ch){
            case 1:{
                int k;
                cout<<"Enter Value To Insert : "<<endl;
                cin>>k;
                list.insertAtStart(k);
                break;
            }case 2:{
                int k;
                cout<<"Enter Value To Insert : "<<endl;
                cin>>k;
                list.insertAtEnd(k);
                break;
            }case 3:{
                int k;
                cout<<"Enter Value To Insert : "<<endl;
                cin>>k;
                int l;
                cout<<"Enter Value of Node(before which it will be inserted): "<<endl;
                cin>>l;
                list.insertBeforeNode(k,l);
                break;
            }case 4:{
                int k;
                cout<<"Enter Value To Insert : "<<endl;
                cin>>k;
                int l;
                cout<<"Enter Value of Node(after which it will be inserted): "<<endl;
                cin>>l;
                list.insertAfterNode(l,k);
                break;
            }case 5:{
                int del=list.deleteFromStart();
                cout<<"Deleted Node had DATA : "<<del<<endl;
                break;
            }case 6:{
                int del=list.deleteFromEnd();
                cout<<"Deleted Node had DATA : "<<del<<endl;
                break;
            }case 7:{
                int k;
                cout<<"Enter Value To Delete : "<<endl;
                cin>>k;
                list.deleteNode(k);
                break;
            }case 8:{
                int k;
                cout<<"Enter Value To Search : "<<endl;
                cin>>k;
                k=list.searchNode(k);
                cout<<"Found at Position "<<k<<" from HEAD "<<endl;
                break;
            }case 9:{
                list.display();
                break;
            }case 10:{
                list.reverseList();
                break;
            }case 11:{
                ListNode* mid=list.midOfList();
                cout<<"Value at Mid is : "<<mid->data<<endl;
                break;
            }case 12:{
                int k;
                cout<<"Enter Value To Delete : "<<endl;
                cin>>k;
                list.removeAllOccurences(k);
                break;
            }case -1:{
                cout<<"\nEXITING!!";
                break;
            }default:{
                cout<<"\nWrong-Choice!!";
                break;
            }
        }
        if(ch==0) break;
    }
    return 0;
}