#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Insert at end
void insertAtEnd(Node* &head, int data) {
    Node* newnode = new Node(data);
    if (head == NULL) {
        head = newnode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// Print linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Reverse nodes in k-group
Node* reverseKGroup(Node* head, int k) {
    Node* temp = head;

    // Check whether k nodes are present
    int count = 0;
    while (temp != NULL && count < k) {
        temp = temp->next;
        count++;
    }

    if (count < k) return head;

    // Reverse first k nodes
    Node* prev = NULL;
    Node* curr = head;
    for (int i = 0; i < k; i++) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // head is now the last node of reversed group
    head->next = reverseKGroup(curr, k);

    return prev;
}

int main() {
    Node* head = NULL;
    int n, val, k;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtEnd(head, val);
    }

    cout << "Enter k (group size for reversal): ";
    cin >> k;

    cout << "Original list: ";
    printList(head);

    head = reverseKGroup(head, k);

    cout << "List after reversing in groups of " << k << ": ";
    printList(head);

    return 0;
}
