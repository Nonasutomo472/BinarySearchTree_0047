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
