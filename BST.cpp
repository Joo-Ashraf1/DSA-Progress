#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
class BST
{
private:
    int data;
    BST* left;
    BST* right;
public:
    BST(int data){
        data=data;
        this->left=nullptr;
        this->right=nullptr;

    }
    bool searchBST(int target){
        //Happy Eid Go Play
    }

    void printInOrder(BST* node){
        if(node ==nullptr){
            return;
        }
        printInOrder(node->left);
        cout<< node->data << " ";
        printInOrder(node->right);


    }
    
};
