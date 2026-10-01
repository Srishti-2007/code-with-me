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

// insert at end
void insertATEnd(node* &head, int data){
    node* newnode=new node(data);
    if(head==NULL){
        head=newnode;
    }
    else{
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

// print
void printList(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

// function
node* oddEvenList(node* head){
    node* odd=head;
    node* even=odd->next;
    node* evenhead=even;
    while(even!=NULL && even->next!=NULL){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=evenhead;
    return head;
}

int main(){
    node* num1=NULL;
    int n;
    int val;

     cout << "Enter number of digits in LL number: "<<endl;
     cin>>n;

     cout << "Enter digits";
     for(int i=0;i<n;i++){
        cin>>val;
        insertATEnd(num1,val);
     }

     cout << "First number (LL): ";
    printList(num1);

    node* result = oddEvenList(num1);
    printList(result);
}