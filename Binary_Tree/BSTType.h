///////////////////////////////////////////////////////////////////////////////
//
//  Vatsal Patel
//
//  Description:
//  This header file contains the function of the binary tree. Also, this
//  header files creates and performs function on the binary tree. Example,
//  insert item, find item, erase item, copy a binary tree to other tree,
//  gives size of the tree, and prints different traverse sequence (Inorder,
//  Postorder, Preorder) of the binary tree.
//
//  Input:
//  Inputs are taken from the driver program created by the user. which can be
//  string, char, double, int.
//
//  Output:
//  All outputs are returned to the driver program.
//
//  Assumptions: None
//
//  Special Processing Requirements: None
//
///////////////////////////////////////////////////////////////////////////////
#ifndef BSTTYPE_H
#define BSTTYPE_H

#include<iostream>
#include <string>
#include "BTNodeType.h"

enum TravType {PRE, POST, IN};

template<class T>
class BSTType{
    public:
        // Prototypes
        BSTType();
        BSTType(const BSTType<T>&);
        const BSTType<T>& operator=(const BSTType<T>&);
        virtual ~BSTType();
        bool empty() const;
        void erase(const T&);
        bool find(const T&) const;
        void insert(const T&);
        size_t size() const;
        void traverse(std::ostream&, TravType) const;
    protected:
        BTNodeType<T> *root;
        size_t count;
    private:
        void copy(BTNodeType<T>*& node, BTNodeType<T>* source);
        void destory(BTNodeType<T>*& node);
        void erase(const T& item, BTNodeType<T>*& node);
        bool find(const T& item, BTNodeType<T>* node) const;
        void inorder(std::ostream& out, BTNodeType<T>* node) const;
        void insert(const T& item, BTNodeType<T>*&  node);
        void postorder(std::ostream& out, BTNodeType<T>* node) const;
        const T& predecessor(BTNodeType<T>* node);
        void preorder(std::ostream& out, BTNodeType<T>* node) const;
};

///////////////////////////////////////////////////////////////////////////////
//
//  Function: BSTType();
//
//  Description:
//  The is a default constructor function.
//
//  Preconditions:
//  None
//
//  Postconditions:
//  The binary search tree size is initialized.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
BSTType<T>::BSTType(){
    root = nullptr;
    count = 0;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: BSTType(const BSTType<T>& src);
//
//  Description:
//  The is a copy constructor function.
//
//  Preconditions:
//  None
//
//  Postconditions:
//  The source Binary seach tree is copied to the original binary search tree.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
BSTType<T>::BSTType(const BSTType<T>& src){
    copy(root, src);
    count = src.count;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: operator=(const BSTType<T>& src);
//
//  Description:
//  Overloading the assigment operator.
//
//  Preconditions:
//  The binary search tree passed in must not equal to the existing tree.
//
//  Postconditions:
//  The original tree is destoryed and the tree passed is copied to the
//  original tree.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
const BSTType<T>&BSTType<T>::operator=(const BSTType<T>& src){
    if(this != &src){
        destory(root);
        count = src.count;
        copy(root, src.root);
    }
    return *this;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: ~BSTType();
//
//  Description:
//  This is the destructor.
//  
//  Preconditions:
//  None
//
//  Postconditions:
//  The tree is destoryed when the program exits.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
BSTType<T>::~BSTType(){
    destory(root);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: empty();
//
//  Description:
//  This function determine if the binary tree is empty.
//  
//  Preconditions:
//  None
//
//  Postconditions:
//  it return true if the binary tree is empty and false if it is not empty.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
bool BSTType<T>::empty() const{
    return root==nullptr;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: erase(const T& item);
//
//  Description:
//  This the public erase function which calls the private erase function,
//  which then erases the item.
//  
//  Preconditions:
//  None
//
//  Postconditions:
//  the item passed in is erased from binary tree.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void BSTType<T>::erase(const T& item){
    erase(item, root);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: find(const T& item) const;
//
//  Description:
//  This is the public find function which calls the private find function,
//  which then finds the item in the binary tree.
//  
//  Preconditions:
//  None
//
//  Postconditions:
//  Return true if the item is found and false if the item is not found.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
bool BSTType<T>::find(const T& item) const{
    return find(item, root);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: insert(const T& item);
//
//  Description:
//  Public insert function, which calls the private insert function with the
//  the item to insert and the root node.
//  
//  Preconditions:
//  None
//
//  Postconditions:
//  The item is inserted in the binary tree.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void BSTType<T>::insert(const T& item){
    insert(item, root);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: size()const;
//
//  Description:
//  This function return the size of the binary tree.
//  
//  Preconditions:
//  None
//
//  Postconditions:
//  Returns the number of items present in the binary tree.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
size_t BSTType<T>::size()const{
    return count;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: traverse(std::ostream& out, TravType traverse) const;
//
//  Description:
//  This function get the traverse type to be printed and uses switch 
//  statement determine which traverse type to print.
//  
//  Preconditions:
//  None
//
//  Postconditions:
//  The traverse type called by the user is printed.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void BSTType<T>::traverse(std::ostream& out, TravType traverse) const{
    switch(traverse){
        case PRE: preorder(out, root);
                break;
        case IN: inorder(out, root);
                break;
        case POST: postorder(out, root);
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: copy(BTNodeType<T>*& node, BTNodeType<T>* source);
//
//  Description:
//  This is function copies the source binary tree to the existing binary tree.
//  
//  Preconditions:
//  None
//
//  Postconditions:
//  The source tree is copied to the existing tree.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void BSTType<T>::copy(BTNodeType<T>*& node, BTNodeType<T>* source){
    if(source != nullptr){
        node = new BTNodeType<T>;
        node->item = source->item;
        copy(node->left, source->left);
        copy(node->right, source->right);
    }
    else{
        node = nullptr;
    }

}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: destory(BTNodeType<T>*& node);
//
//  Description:
//  This function destory the binary tree.
//  
//  Preconditions:
//  Value must exist in the tree.
//
//  Postconditions:
//  The menory space occupied by the binary tree is deallocated. Also, the 
//  node is set to nullptr.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void BSTType<T>::destory(BTNodeType<T>*& node){
    if(node != nullptr){
        destory(node->left);
        destory(node->right);
        delete node;
        count = 0;
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: erase(const T& item, BTNodeType<T>*& node);
//
//  Description:
//  Function to deleted a node from the binary tree.
//  
//  Preconditions:
//  None
//
//  Postconditions:
//  If the item is found in the binary tree then it is deleted from the tree.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void BSTType<T>::erase(const T& item, BTNodeType<T>*&node){
    if(node != nullptr){
        if(item == node->item){
            if(node->right == nullptr){
                BTNodeType<T> *temp = node;
                node = node->left;
                delete temp;
                --count;
            }
            else if(node->left == nullptr){
                BTNodeType<T> *temp = node;
                node = node->right;
                delete temp;
                --count;
            }
            else{
                node->item = predecessor(node->left);
                erase(node->item, node->left);
            }
        }
        else if(item < node->item){
            erase(item, node->left);
        }
        else{
            erase(item, node->right);
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: find(const T& item, BTNodeType<T>* node) const;
//
//  Description:
//  This function determeines if the item to find is in binary tree.
//  
//  Preconditions:
//  None
//
//  Postconditions:
//  Returns true if the item is found in the binary tree. Or return false if
//  the item is not found in the binary tree.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
bool BSTType<T>::find(const T& item, BTNodeType<T>* node) const{
    bool found;
    if(node == nullptr){
        return false;
    }else{
        while(node != nullptr && !found){
            if(node->item == item){
                found = true;
            }else if(node->item > item){
                node = node->left;
            }else{
                node = node->right;
            }
        }
    }
    return found;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: inorder(std::ostream& out, BTNodeType<T>* node) const;
//
//  Description:
//  This function prints the binary tree in Inorder Traversal.
//  
//  Preconditions:
//  None
//
//  Postconditions:
//  The binary tree is printed in Inorder sequence.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void BSTType<T>::inorder(std::ostream& out, BTNodeType<T>* node) const{
    if(node != nullptr){
        inorder(out, node->left);
        out<<node->item<<" ";
        inorder(out, node->right);
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: insert(const T& item, BTNodeType<T>*&  node);
//
//  Description:
//  This function gets the item to insert and root node from the public
//  public function. Then inserts the item.
//  
//  Preconditions:
//  None
//
//  Postconditions:
//  A new node is created with the item to insert and that node is inserted
//  is in the binary tree.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void BSTType<T>::insert(const T& item, BTNodeType<T>*& node){
    if(node == nullptr){
        node = new BTNodeType<T>;
        node->item = item;
        node->left = nullptr;
        node->right = nullptr;
        ++count;
    }else{
        if(item < node->item){
            insert(item, node->left);
        }else{
            insert(item, node->right);
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: postorder(std::ostream& out, BTNodeType<T>* node) const;
//
//  Description:
//  This function does postorder traversal of the binary tree.
//  
//  Preconditions:
//  None
//
//  Postconditions:
//  The nodes of the binary tree are printed in postorder sequence.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void BSTType<T>::postorder(std::ostream& out, BTNodeType<T>* node) const{
    if(node != nullptr){
        postorder(out, node->left);
        postorder(out, node->right);
        out<<node->item<<" ";
    }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: predecessor(BTNodeType<T>* node);
//
//  Description:
//  This function goes to the last node of the right side of the binary tree.
//  
//  Preconditions:
//  None
//
//  Postconditions:
//  The last node on the right side of the binary tree is returned.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
const T& BSTType<T>::predecessor(BTNodeType<T>* node){
    while(node->right != nullptr){
        node = node->right;
    }
    return node->item;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Function: preorder(std::ostream& out, BTNodeType<T>* node) const;
//
//  Description:
//  This function does Preorder traversal of the binary tree.
//  
//  Preconditions:
//  None
//
//  Postconditions:
//  The nodes of the binary tree are printed in Preorder sequence.
//
///////////////////////////////////////////////////////////////////////////////
template<class T>
void BSTType<T>::preorder(std::ostream& out, BTNodeType<T>* node) const{
    if(node != nullptr){
        out<<node->item<<" ";
        preorder(out, node->left);
        preorder(out, node->right);
    }
}
#endif