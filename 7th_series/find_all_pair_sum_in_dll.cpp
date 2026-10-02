#include<iostream>
#include<vector>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;

    node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

// insert at end
void insertAtEnd(node* &head, int data) {
    node* newnode = new node(data);
    if (head == NULL) {
        head = newnode;
        return;
    }
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

// find tail
node* findTail(node* &head) {
    node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    return temp;
}

// find all pairs with given sum
vector<pair<int,int>> findpair(node* &head, int k) {
    vector<pair<int,int>> ans;
    if (head == NULL) return ans;

    node* left = head;
    node* right = findTail(head);

    while (left != NULL && right != NULL && left->data < right->data) {
        int sum = left->data + right->data;
        if (sum == k) {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if (sum < k) {
            left = left->next;
        }
        else {
            right = right->prev;
        }
    }
    return ans;
}

int main() {
    node* head = NULL;
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);

    int k = 6;
    vector<pair<int,int>> result = findpair(head, k);

    cout << "Pairs with sum " << k << " are:\n";
    for (auto p : result) {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }
}
