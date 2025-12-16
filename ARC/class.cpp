#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

class Node {
public:
    int value;
    Node* next;

    Node(int v) {
        value = v;
        next = nullptr;
    }
};

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    Node* curr = head;
    while(curr != nullptr) {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;

    curr = head;
    while(curr != nullptr) {
        Node* tmp = curr;
        curr = curr->next;
        delete tmp;
    }

    return 0;
}