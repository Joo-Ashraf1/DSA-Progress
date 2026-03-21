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
        if(target==data){
            return true;
        }
        else if(target<data&& left!=nullptr){
           
            return left->searchBST(target);
        }
        else if (target>data && right!= nullptr){
            return right->searchBST(target);
        }

    }

    void printInOrder(BST* node){
        if(node ==nullptr){
            return;
        }
        printInOrder(node->left);
        cout<< node->data << " ";
        printInOrder(node->right);


    }

    void insert(int target){
        if(target<data){
            if(!left){
                left=new BST(target);
            }
            else{
                left->insert(target);
            }
        }

        else if(target>data){
            if(!right){
                right=new BST(target);
            }
            else{
                right->insert(target);
            }
        }
    }
    
};
