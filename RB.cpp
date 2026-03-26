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

void insertFixUp(RB* z){
    while(z->parent != nullptr &&z->parent->color==true){
        if(z->parent==z->parent->parent->left){ // lw el dad shmal
            RB* uncle=z->parent->parent->right;

            if(uncle&&uncle->color ==true){ //case 1
                uncle->color=false;
                z->parent->color=false;
                z->parent->parent->color=true;
                z=z->parent->parent; //note ent hna fixed violation for two levels

            }

            else if(z->parent->right==z){ //case 2 trinangle rotate parent
                z=z->parent;
                LeftRotation(z);
                // no advance tany 5ly balk hya lma tlf el z bt advance nfsha

            }
            else{  //case 3
                z->parent->color=false;
                z->parent->parent->color=true;
                RightRotation(z->parent->parent);
                break;

            }
        }
        else{ // lw dad ymen
            RB* uncle=z->parent->parent->left;
            if(uncle&&uncle->color==true){
                z->parent->color=false;
                z->parent->parent->color=true;
                uncle->color=false;
                z=z->parent->parent;

            }
            else if(z==z->parent->left){
                z=z->parent;
                RightRotation(z);


            }
            else{
                z->parent->color=false;
                z->parent->parent->color=true;
                LeftRotation(z->parent->parent);
                break;
            }

        }
    }

    root->color=false; //case 0


}

void insert(RB* z){
    RB* x=root;
    RB * y=x;
    while(x!=nullptr){
        y=x;
        if(z->value<x->value){
            x=x->left;
        }
        else{
            x=x->right;
        }
    }
    z->parent=y;
    if(y==nullptr){
        root=z;
    }
    else if(z->value<y->value){
        y->left=z;
    }
    else{
        y->right=z;
    }
    z->left=nullptr;
    z->right=nullptr;
    z->color=true;
    insertFixUp(z);



}

};