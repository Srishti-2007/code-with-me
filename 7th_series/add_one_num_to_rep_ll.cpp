#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insertATEnd(node* &head, int data){
    node* newnode=new node(data);
    if(head==NULL){
        head=newnode;
    } else {
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void printList(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

node* reverse(node* head){
    node* curr=head;
    node* prev=NULL;
    while(curr!=NULL){
        node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

void addone(node* &head){
    head=reverse(head);
    node* temp=head;
    int carry=1;
    while(temp!=NULL){
        temp->data += carry;
        if(temp->data < 10){
            carry=0;
            break;
        }
        temp->data=0;
        carry=1;
        if(temp->next==NULL && carry==1){
            temp->next=new node(1);
            carry=0;
            break;
        }
        temp=temp->next;
    }
    head=reverse(head);
}

int main(){
    node* num1=NULL;
    int n,val;
    cout << "Enter number of digits in LL number: ";
    cin>>n;
    cout << "Enter digits: ";
    for(int i=0;i<n;i++){
        cin>>val;
        insertATEnd(num1,val);
    }

    cout << "First number (LL): ";
    printList(num1);

    addone(num1);
    cout << "After adding one: ";
    printList(num1);
}
