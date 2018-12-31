#include "TreeNode.h"

    TreeNode::TreeNode(DBentry* _entryPtr){
        entryPtr = _entryPtr;
        left= NULL;
        right= NULL;
    }

    // the destructor
    TreeNode::~TreeNode(){
        if(entryPtr != NULL){
            delete entryPtr;
            entryPtr= NULL;

        }
    }

    // sets the left child of the TreeNode.
    void TreeNode::setLeft(TreeNode* newLeft){
        left= newLeft;
    }

    // sets the right child of the TreeNode
    void TreeNode::setRight(TreeNode* newRight){
        right= newRight;
    }

    // gets the left child of the TreeNode.
    TreeNode* TreeNode::getLeft() const{
        return(left);
    }

    // gets the right child of the TreeNode
    TreeNode* TreeNode::getRight() const{
        return(right);
    }

    // returns a pointer to the DBentry the TreeNode contains. 
    DBentry* TreeNode::getEntry() const{
        return(entryPtr);
    }
