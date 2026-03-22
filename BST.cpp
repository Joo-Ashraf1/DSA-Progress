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
    int minValue(){
        BST* node=this;
        while(node&& node->left){
            node=node->left;
        }
        return node->data;
    }

    bool findChain(vector<BST*> &ancestors,int target){
        ancestors.push_back(this);
        if(data==target){
            return true;
        }
        else if(data<target){
            return left&&left->findChain(ancestors,target);
        }
        else{
            return right&& right->findChain(ancestors,target);
        }
    }

    BST* getNextParent(vector<BST*> &ancestors){
        if(ancestors.size()==0){
            return nullptr;
        }
        BST* node=ancestors.back();
        ancestors.pop_back();
        return node;

    } 

    pair<int,bool> Successor(int target){
        vector<BST*> ancestors;
        if (!findChain(ancestors, target))
			return make_pair(false, -1);

		BST* child = getNextParent(ancestors);

		if (child->right)	// must have be in min of right
			return make_pair(true, child->right->minValue());

		BST* parent = getNextParent(ancestors);

		// Cancel chain of ancestors I am BIGGER than them
		while (parent && parent->right == child)
			child = parent, parent = getNextParent(ancestors);

		if (parent)	//
			return make_pair(true, parent->data);
		return make_pair(false, -1);


    }
    
};
