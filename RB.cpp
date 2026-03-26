#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
class RB{
private:
    int value;
    bool color; //f>black r=R>red
    RB* left;
    RB* right;
    RB* parent;
public:
    RB* root;

    void LeftRotation(RB* node){
         if (node == nullptr || node->right == nullptr)
            return;
        RB* res=node->right;
        node->right=res->left;
        if(res->left!=nullptr){
            res->left->parent=node;
        }
        res->parent=node->parent;
        if(node->parent==nullptr){
            root=res;
        }
        else if(node->parent->left==node){
            node->parent->left=res;
        }
        else{
            node->parent->right=res;
        }
        res->left=node;
        node->parent=res;
        
    }


    void RightRotation(RB* node){
    if (node == nullptr || node->left == nullptr)
        return;
    RB* res = node->left;
    node->left = res->right;
    if (res->right != nullptr){
        res->right->parent = node;
    }
    res->parent = node->parent;
    if (node->parent == nullptr){
        root = res;
    }
    else if (node->parent->right == node){
        node->parent->right = res;
    }
    else{
        node->parent->left = res;
    }
    res->right = node;
    node->parent = res;
}

};