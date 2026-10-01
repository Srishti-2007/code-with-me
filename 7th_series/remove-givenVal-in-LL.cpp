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

node* removeVal(node* &head, int num) {
      
    // Step 1: Remove nodes from the beginning if they match val
    while(head!=NULL && head->data==num){
        node* temp=head;
        head=head->next;
        delete temp;
    }
    node* curr=head;
    while(curr!=NULL && curr->next!=NULL){
        if(curr->next->data==num){
            node* temp=curr->next;
            curr->next=temp->next;
            delete temp;
        }
        else{
            curr=curr->next;
        }
    }
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

   node* result= removeVal(num1,6);
    printList(result);
}
