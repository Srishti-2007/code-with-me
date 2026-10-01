#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    // default constructor
    node(){
        this->data=0;
        this->next=NULL;
    }
    // parameterized constructor
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
// Linked List print function
void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

// Insert at head
void insertAtHead(node* &head, node* &tail, int data){
    // अगर list खाली है
    if(head==NULL){
        node* newnode=new node(data);
        head=newnode;
        tail=newnode;
    }
    else{
        node* newnode=new node(data);
        newnode->next=head;
        head=newnode;
    }
}

// Insert at end
void insertAtEnd(node* &head, node* &tail, int data){
    // अगर list खाली है
    if(head==NULL){
        node* newnode=new node(data);
        head=newnode;
        tail=newnode;
    }
    else{
        node* newnode=new node(data);
        tail->next=newnode;
        tail=newnode;
    }
}

// Length of linked list
int lengthofnode(node* &head){
    node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

// Insert at any position
void insrtatanypos(int data,node* head, node* tail , int position){
    // अगर list खाली है
    if(head==NULL){
        node* newnode=new node(data);
        head=newnode;
        tail=newnode;
    }

    // अगर position 0 है तो head पर insert करो
    if(position==0){
        insertAtHead(head,tail,data);
    }

    int len=lengthofnode(head);

    // अगर position length से बड़ी है तो end पर insert करो
    if(position > len){
        insertAtEnd(head,tail,data);
    }

    // बीच में insert करना
    int i=1;
    node* prev=head;
    while(i<position){
        prev=prev->next;
        i++; // तुम्हारे code में ये missing था
    }
    node* curr=prev->next;
    node* newnode=new node(data);
    newnode->next=curr;
    prev->next=newnode;
}

void reveresLL(node* &head){
    node* prev=NULL;
    node* curr=head;
    while(curr!=NULL){
        node* temp=curr;
        curr=curr->next;
        temp->next=prev;
        prev=temp;
    }
    head = prev; //new head made after reversing it
}

int main(){
    node* head=NULL;
    node* tail=NULL;

    // Insert operations
    insertAtHead(head,tail,20);   // 20
    insertAtHead(head,tail,70);   // 70 -> 20
    insertAtEnd(head,tail,90);    // 70 -> 20 -> 90
    print(head);
    cout<<"reverse"<<endl;
    reveresLL(head);
    print(head);

   
}