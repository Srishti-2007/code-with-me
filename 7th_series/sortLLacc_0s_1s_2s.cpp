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
node* sortLL(node* head){
    node* count_zero=new node(-1);
    node* count_one=new node(-1);
    node* count_two=new node(-1);

    node* zero_head=count_zero;
    node* one_head=count_one;
    node* two_head=count_two;

    node* temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            count_zero->next=temp;
            count_zero=count_zero->next;
           
        }
        else if(temp->data==1){
            count_one->next=temp;
            count_one=count_one->next;
        }
        else{
            count_two->next=temp;
            count_two=count_two->next;
        }
        temp=temp->next;
    }

    count_zero->next=one_head->next;
    count_one->next=two_head->next;
    count_two->next=NULL;

    return zero_head->next;
    
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

    node* result = sortLL(num1);
    printList(result);
}




// 2nd approach
// Node* sortList(Node* head)
// {
//     int cnt0 = 0;
//     int cnt1 = 0;
//     int cnt2 = 0;

//     Node* temp = head;

//     // Step 1: Count 0, 1 and 2
//     while(temp != NULL)
//     {
//         if(temp->data == 0)
//             cnt0++;
//         else if(temp->data == 1)
//             cnt1++;
//         else
//             cnt2++;

//         temp = temp->next;
//     }

//     // Step 2: Put 0s
//     temp = head;

//     while(cnt0--)
//     {
//         temp->data = 0;
//         temp = temp->next;
//     }

//     // Step 3: Put 1s
//     while(cnt1--)
//     {
//         temp->data = 1;
//         temp = temp->next;
//     }

//     // Step 4: Put 2s
//     while(cnt2--)
//     {
//         temp->data = 2;
//         temp = temp->next;
//     }

//     return head;
// }