#include <iostream>

using std::cout;
using std::endl;

class Node {
    Node *right;
    int value;

public:
    explicit Node(int value, Node *ptr = nullptr) : value(value), right(ptr) {}
    friend class List;
};

class List {
    Node* root;
    size_t size;

    void del_node(Node *ptr) {
        Node *temp = ptr->right;
        ptr->right = ptr->right->right;
        size--;
        delete temp;
    }

public:
    List() : root(nullptr), size(0) {}
    ~List() { clear(); }

    void push_back(int value) {
        if (root == nullptr) {
            root = new Node(value);
        } else {
            Node *ptr = root;
            while (ptr->right != nullptr) {
                ptr = ptr->right;
            }
            ptr->right = new Node(value);
        }
        size++;
    }

    void clear_odd_index() {
        if (root == nullptr) {
            return;
        }
        Node* ptr = root;
        while (ptr != nullptr && ptr -> right != nullptr) {
                del_node(ptr);
                ptr = ptr->right;

        }
    }

    void show() {
        Node *ptr = root;
        while (ptr != nullptr) {
            cout << ptr->value << " ";
            ptr = ptr -> right;
        } cout << endl;
    }

    void pop() {
        Node *ptr = root;
        root = root -> right;
        delete ptr;
        size--;
    }

    void clear() {
        while (size) {
            pop();
        }
    }

};

int main() {
    List list;
    for (int i = 1; i <= 10; i++) {
        list.push_back(i);
    }
    list.show();
    list.clear_odd_index();
    list.show();
}
