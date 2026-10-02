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
node* removell(node* &head){
    node* temp=head;
    node* curr=head->next;
    while(curr!=NULL){
        if(temp->data!=curr->data){
            temp->next=curr;
            temp=curr;
           
        }
         curr=curr->next;
    }
    temp->next=NULL;
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

    node* result = removell(num1);
    printList(result);
}