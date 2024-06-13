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

    }