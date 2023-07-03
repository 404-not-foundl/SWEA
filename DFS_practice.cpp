#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class BinaryNode{
protected:
    int data;
    BinaryNode* left;
    BinaryNode* right;
public:
    BinaryNode(int data = 0, BinaryNode* left = NULL, BinaryNode* right = NULL){
        this->data = data;
        this->left = left;
        this->right = right;
    }
    
    void setData(int data) { this->data = data; }
    int getData(){ return this->data; }

    void setLeft(BinaryNode* left){ this->left = left; }
    BinaryNode* getLeft(){ return this-> left; }

    void setRight(BinaryNode* right){ this->right = right; }
    BinaryNode* getRight(){ return this-> right; }

    bool isLeaf(){
        return this->left == NULL && this->right == NULL;
    }
};

class BinaryTree{
private:
    BinaryNode* root;
public:
    BinaryTree(){ this->root = NULL; }
    bool isEmpty(){ return this->root == NULL; }
    void setRoot(BinaryNode* node){ this->root = node; }
    BinaryNode* getRoot(){ return this->root; }
};


int main(void){
    BinaryTree tree;
    BinaryNode *d = new BinaryNode('D', NULL, NULL);
    BinaryNode *e = new BinaryNode('E', NULL, NULL);
    BinaryNode *b = new BinaryNode('B', d, e);
    BinaryNode *f = new BinaryNode('F', NULL, NULL);
    BinaryNode *c = new BinaryNode('C', f, NULL);
    BinaryNode *a = new BinaryNode('A', b, c);
    tree.setRoot(a);

    stack<BinaryNode*> list;
    list.push(a);
    while(list.size() > 0){
        BinaryNode *current = list.top();
        list.pop();
        cout << char(current->getData()) << " ";

        if(current->getRight() != NULL) list.push(current->getRight());
        if(current->getLeft() != NULL) list.push(current->getLeft());
    }
    cout << endl;
    
    return 0;
}