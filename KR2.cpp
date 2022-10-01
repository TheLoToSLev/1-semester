#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Node {
    Node *left;
    Node *right;
    int value;

public:
    friend class BST;
    explicit Node(int value, Node* left = nullptr, Node* right = nullptr)
        : value(value), left(left), right(right) {}
};

class BST {
    Node* root;


    void show_help(Node* ptr) {
        if (ptr->left != nullptr) {
            show_help(ptr->left);
        }
        cout << ptr->value << " ";
        if (ptr->right != nullptr) {
            show_help(ptr->right);
        }
    }

    void clear_help(Node* ptr) {
        if (ptr == nullptr) {
            return;
        }
        clear_help(ptr->left);
        clear_help(ptr->right);
        delete ptr;
    }

    void sort_BST_help(Node* ptr, vector<int>& array) {
        if (ptr->left != nullptr) {
            sort_BST_help(ptr->left, array);
        }
        array.push_back(ptr->value);
        if (ptr->right != nullptr) {
            sort_BST_help(ptr->right, array);
        }
    }

public:
    explicit BST(const vector<int>& array) : root(nullptr) {
        if (array.empty()) {
            return;
        }
        for (auto &it : array) {
            push_back(it);
        }
    }

    ~BST() { clear(); }

    void push_back(int value) {
        if (root == nullptr) {
            root = new Node(value);
            return;
        }
        Node* ptr = root;
        while (true) {
            if (value > ptr->value) {
                if (ptr->right == nullptr) {
                    ptr->right = new Node(value);
                    break;
                }
                ptr = ptr->right;
            } else {
                if (ptr->left == nullptr) {
                    ptr->left = new Node(value);
                    break;
                }
                ptr = ptr->left;
            }
        }
    }

    void show() {
        if (root == nullptr) {
            return;
        }
        show_help(root);
    }


    void clear() {
        if (root == nullptr) {
            return;
        }
        clear_help(root);
    }

    vector<int> sort_BST() {
        vector<int> array;
        if (root == nullptr) {
            return array;
        }
        sort_BST_help(root, array);
        return array;
    }

};

void output_array(const vector <int> &array) {
    for (auto &it : array) {
        cout << it << " ";
    } cout << endl;
}

void sort_BST(vector <int> &array) {
    BST tree(array);
    array = tree.sort_BST();
}

int main() {
    vector <int> array;
    for (int i = 0; i < 10; i++) {
        array.push_back(rand() % 100 + 1);
    }
    cout << "Start array: ";
    output_array(array);
    sort_BST(array);
    cout << "Result array: ";
    output_array(array);
    return 0;
}
