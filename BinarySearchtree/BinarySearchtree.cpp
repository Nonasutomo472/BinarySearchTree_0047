#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string info;
    Node* leftchild;
    Node* rightchild;

    Node(string element, Node* left, Node* right) {
        info = element;
        leftchild = left;
        rightchild = right;
    }
};

class BinaryTree {
public:
    Node* ROOT;

    BinaryTree() {
        ROOT = nullptr; //initializing ROOT to null
    }

    void insert(string element) { // insert a node in the binary search tree
        Node* newNode = new Node(element, nullptr, nullptr); // allocate memory for the new node
        newNode->info = element; //assign value to the data field of the new node
        newNode->leftchild = nullptr; //make the left child of the new node point to null
        newNode->rightchild = nullptr; // make the right child of the new node point to NULL

        Node* parent = nullptr;
        Node* currentNode = nullptr;
        search(element, parent, currentNode); //locate the node which will be the parent of the node to be inserted

        if (parent == nullptr) { //if the parent is NULL (tree is empty)
            ROOT = newNode; //mark the new Node as ROOT
            return; //exit
        }
        if (element < parent->info) { //if the value in the data field of the new node is less than that of the parent
            parent->leftchild = newNode; //make the left child of the parent point to the new node
        }
        else if (element > parent->info) { //if the value in the data field of the new node is greater than that of the parent
            parent->rightchild = newNode; //make the right child of the parent point to the new node
        }
    } 

    void inorder(Node* ptr) {
        if (ROOT == nullptr) {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr != nullptr) {
            inorder(ptr->leftchild);
            cout << ptr->info << " ";
            inorder(ptr->rightchild);
        }
    } 
    void preorder(Node* ptr) {
        if (ROOT == nullptr) {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr != nullptr) {
            cout << ptr->info << " ";
            preorder(ptr->leftchild);
            preorder(ptr->rightchild);
        }
    }
    if (ptr != nullptr) {
        postorder(ptr->leftchild);
        postorder(ptr->rightchild);
        cout << ptr->info << " ";
    }
}
};

int main() {
    BinaryTree x;
    while (true) {
        cout << "\nMenu" << endl;
        cout << "1. Implement insert operation" << endl;
        cout << "2. Perform inorder traversal" << endl;
        cout << "3. Perform preorder traversal" << endl;
        cout << "4. Perform postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice (1-5): ";
        char ch;
        cin >> ch;
        cout << endl;

        switch (ch) {
        case '1': {
            cout << "Enter a word: ";
            string word;
            cin >> word;
            x.insert(word);
            break;
        }
        case '2': {
            x.inorder(x.ROOT);
            break;
        }
        case '3': {
            x.preorder(x.ROOT);
            break;
        }
        case '4': {
            x.postorder(x.ROOT);
            break;
        }
        case '5': {
            return 0;
        }
        default: {
            cout << "Invalid choice! Please enter a number between 1 and 5." << endl;
            break;
        }
        }
    }
    return 0;
}

    