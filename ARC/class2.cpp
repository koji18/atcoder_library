#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int v) : value(v), next(nullptr) {}
};

void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
}

// n番目にvalを追加
void insertAt(Node*& head, int n, int val) {
    Node* newNode = new Node(val);
    if (n == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* curr = head;
    for (int i = 0; i < n - 1; ++i) {
        if (!curr) return;
        curr = curr->next;
    }
    if (!curr) return;
    newNode->next = curr->next;
    curr->next = newNode;
}

int main() {
    // 最初は空のリスト
    Node* head = nullptr;

    // 初期値をいくつか追加
    insertAt(head, 0, 10); // 10
    insertAt(head, 1, 20); // 10 20
    insertAt(head, 2, 30); // 10 20 30
    printList(head);

    int pos, val;
    cout << "追加したい位置（0から）と値を入力してください: ";
    cin >> pos >> val;

    insertAt(head, pos, val);
    cout << "追加後のリスト: ";
    printList(head);

    // メモリ解放
    Node* curr = head;
    while (curr) {
        Node* tmp = curr;
        curr = curr->next;
        delete tmp;
    }
}
