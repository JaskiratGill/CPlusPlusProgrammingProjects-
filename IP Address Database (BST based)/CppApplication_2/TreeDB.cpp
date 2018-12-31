#include <deque>

#include "TreeDB.h"

//Default Constructor: 
TreeDB::TreeDB(){
       root= NULL;
   }
   
//Helper function for complete deletion of database, recursively implemented
    void TreeDB::deleteTree(TreeNode* root){
        if(root == NULL) return;
        deleteTree(root-> getLeft());
        deleteTree(root-> getRight());
        delete root;    
    }

   
   // the destructor, deletes all the entries in the database, using the deleteTree function
   TreeDB::~TreeDB(){
       deleteTree(root);
       root= NULL; 
   }

   // inserts the entry pointed to by newEntry into the database.
   // If an entry with the same key as newEntry's exists
   // in the database, it returns false. Otherwise, it returns true.
   
   //This function uses the recursive function called insertion to insert a new entry into database
   bool TreeDB::insert(DBentry* newEntry){
      
       if(find(newEntry->getName()) != NULL)
           return false;
       
       root = insertion(newEntry,root);
       return true;
   }
  
   //This function recursive inserts an entry into the database
   TreeNode* TreeDB::insertion(DBentry* p, TreeNode* r){
 
       if(r == NULL){
           return (new TreeNode(p));
       }
       if(p->getName()<r->getEntry()->getName()){
           r ->setLeft( insertion(p,r->getLeft()));
          
       }else{
            r ->setRight( insertion(p,r->getRight()));
       }
          
      
      
   }

   //Print helper function, prints the whole tree recursively, and passes to out-stream
      const void TreeDB::FullTreePrinter(const TreeNode* pointer, ostream &out) const {
   
       if(pointer != NULL) {
            
		FullTreePrinter(pointer->getLeft(), out);
		out << *(pointer-> getEntry());
		FullTreePrinter(pointer->getRight(), out);
	}
       }
   
   
   // searches the database for an entry with a key equal to name.
   // If the entry is found, a pointer to it is returned.
   // If the entry is not found, the NULL pointer is returned.
   // Also sets probesCount
   DBentry* TreeDB::find(string name){
       //probesCount must be set to zero before each count since it pertains to the probes after latest find invocation
       probesCount= 0;
       TreeNode* current = root;
       
       //Loop through database 
       while(current != NULL){
            probesCount++;

           if (current == NULL){return NULL;}
           
           if ((current -> getEntry() -> getName()) == name ){
               return current->getEntry();
           }
           else if (name < (current -> getEntry() -> getName())){
               current = current -> getLeft();
           }
           else{
               current= current -> getRight();
           }
           
       }
       
           return NULL;
   }
    
    //Removes an entry from the database called "name"
    bool TreeDB::remove(string name) {
       
    
    TreeNode* pointerTwo;
    TreeNode* pointerOne;
    TreeNode* toModify;
    
    bool entryMatched = false;
    bool left = false;
    bool right = false;
    
    pointerTwo = root;
    
    //Execute if the entry's name matches the targeted name
    if(pointerTwo->getEntry()->getName() == name){
        if(pointerTwo->getLeft() == NULL){
            if(pointerTwo->getRight() == NULL){
                root = NULL;
                delete pointerTwo;
                return true;
            }else{
                root = pointerTwo -> getRight();
                delete pointerTwo;
                return true;
            }
        }else{
            //Execute if the right pointer is NULL
            if(pointerTwo->getRight() == NULL){
                root = pointerTwo->getLeft();
                delete pointerTwo;
                return true;
            }else{
                toModify = LargestNode(pointerTwo->getLeft());
                if(toModify == NULL){
                    root = pointerTwo->getLeft();
                    root->setRight(pointerTwo->getRight());
                    delete pointerTwo;
                    return true;
                }else{
                    root = toModify->getRight();
                    root->setLeft(pointerTwo->getLeft());
                    root->setRight(toModify->getRight()->getLeft());
                    delete pointerTwo;
                    return true;
                }
            }
        }
    }
    
    //Loop while entry is not found
    while(!entryMatched){
        if(pointerTwo->getEntry()->getName() == name){
            entryMatched = true;
        }else if(name < pointerTwo->getEntry()->getName()){
            if(pointerTwo->getLeft() == NULL){
                break;
            }else{
                pointerOne = pointerTwo;
                left = true;
                right = false;
                pointerTwo = pointerTwo -> getLeft();
            }
        }else if(name > pointerTwo -> getEntry()->getName()){
            if(pointerTwo->getRight() == NULL){
                break;
            }else{
                pointerOne = pointerTwo;
                right = true;
                left = false;
                pointerTwo = pointerTwo -> getRight();
            }
        }
    }
    
    //If entry not found, return false
    if(!entryMatched){
        return false;
    }
    
    //if entry is found, do the following code block 
    if(pointerTwo->getEntry()->getName() == name){
        //if the pointer's left is NULL
        if(pointerTwo->getLeft() == NULL){
            if(pointerTwo->getRight() == NULL){
                if(right){
                    pointerOne->setRight(NULL);
                }else if(left){
                    pointerOne->setLeft(NULL);
                }
                delete pointerTwo;
                return true;
            }else{
                if(right){
                    pointerOne->setRight(pointerTwo -> getRight());
                }else if(left){
                    pointerOne->setLeft(pointerTwo -> getRight());
                }
                delete pointerTwo;
                return true;
            }
        }else{
            //if the pointer's right is NULL
            if(pointerTwo->getRight() == NULL){
                if(right){
                    pointerOne->setRight(pointerTwo -> getLeft());
                }else if(left){
                    pointerOne->setLeft(pointerTwo -> getLeft());
                }
                delete pointerTwo;
                return true;
            }else{
                toModify = LargestNode(pointerTwo->getLeft());
                if(toModify == NULL){
                    if(right){
                        pointerOne->setRight(pointerTwo -> getLeft());
                        pointerOne->getRight()->setLeft(pointerTwo -> getRight());
                    }else if(left){
                        pointerOne->setLeft(pointerTwo -> getLeft());
                        pointerOne->getLeft()->setRight(pointerTwo -> getRight());
                    }
                    delete pointerTwo;
                    return true;
                }else{
                   
                    TreeNode* temp = toModify->getRight()->getLeft();
                    if(right){
                        pointerOne->setRight(toModify->getRight());
                        pointerOne->getRight()->setLeft(pointerTwo->getLeft());
                        pointerOne->getRight()->setRight(pointerTwo->getRight());
                    }else if(left){
                        pointerOne->setLeft(toModify->getRight());
                        pointerOne->getLeft()->setLeft(pointerTwo->getLeft());
                        pointerOne->getLeft()->setRight(pointerTwo->getRight());
                    }
                    delete pointerTwo;
                    toModify->setRight(temp);
                    return true;
                    }
                }
            }
        }    
    }
    
   
    
    //Finds the node with largest domain name after the nodeEntered
    TreeNode* TreeDB::LargestNode(TreeNode* nodeEntered){
    
        if(nodeEntered->getRight() == NULL){
            return NULL;
        }
        if(nodeEntered->getRight()->getRight() == NULL){
        return nodeEntered;
        }else{
            LargestNode(nodeEntered->getRight());
        }
    }
            
   
	
   // deletes all the entries in the database.
   void TreeDB::clear(){
   deleteTree(root);
   root= NULL; 
   }
    
   // prints the number of probes stored in probesCount
   void TreeDB::printProbes() const{
       cout << probesCount << endl;
   }
   
   // computes and prints out the total number of active entries
   // in the database (i.e. entries with active==true).
   // Uses the function activeCounter
   void TreeDB::countActive () const{
       
       int count= activeCounter(root);
       cout << count << endl;
      
   }
   
   // Recursive function activeCounter to count the number of entries with active
   int TreeDB::activeCounter(TreeNode* treeRoot) const{
   
       if (treeRoot == NULL)return 0;
       
       int counter=0;
       
       if (treeRoot -> getEntry() -> getActive() == true){
           counter++;       
       }
       
       counter = counter + (activeCounter(treeRoot-> getLeft()) + activeCounter(treeRoot -> getRight()));
       return counter;
  
   }

   
   
   
   
   
   
   
  