///////////////////////////////////////////////////////////////////////////////
//
//  Vatsal Patel
//
//  Description:
//  This driver program test the functions of the binary tree. like insert,
//  erase, and find nodes. Also, test traverse through the tree using 
//  different methods. And test the copy function.
//
//  Input:
//  Inputs are taken from the driver program created by the user. which can be
//  string, char, double, int.
//
//  Output:
//  Outputs are displayed in the command line. The output format will give 
//  result of the function being tested.
//
//  Assumptions: None
//
//  Special Processing Requirements: None
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include "BSTType.h"

using namespace std;

int main(){
    BSTType<int> b;
    BSTType<int> a;

    if(b.empty()){
        cout<<"Tree is empty"<<endl;
    }else{
        cout<<"Tree is not empty"<<endl;
    }

    cout << "Inserted some nodes in tree" << endl;

    b.insert(37);
    b.insert(30);
    b.insert(50);
    b.insert(25);
    b.insert(34);
    b.insert(32);
    b.insert(28);
    b.insert(15);
    b.insert(14);
    b.insert(18);
    b.insert(19);
    b.insert(9);
    b.insert(40);
    b.insert(55);
    b.insert(54);
    b.insert(85);
    b.insert(95);


    cout << "current size of tree: " << b.size() << endl;

    if(b.empty()){
        cout<<"Tree is empty"<<endl;
    }else{
        cout<<"Tree is not empty"<<endl;
    }

    cout << endl;
    cout << "Traversal of Tree: " << endl;
    cout<<"INORDER: ";
    b.traverse(cout, IN);
    cout << endl;

    cout << "PREORDER: ";
    b.traverse(cout, PRE);
    cout << endl;

    cout << "POSTORDER: ";
    b.traverse(cout, POST);
    cout << endl;

    cout << endl << "find items in tree: " << endl;
    for(int i = 0; i < 61; i+=3){
        if(b.find(i))
            cout << i << ": found" << endl;
        else
            cout << i << ": Not found"  << endl;
    }

    cout << endl;

    cout << "\nErase some nodes:"<< endl;
    b.erase(37);
    for(int i = 1; i < 61; i+=4){
        b.erase(i);
        cout << "erase " << i << endl; 
    }

    cout << "Traversal of Tree: " << endl;

    cout<<"INORDER: ";
    b.traverse(cout, IN);
    cout << endl;

    cout << "PREORDER: ";
    b.traverse(cout, PRE);
    cout << endl;

    cout << "POSTORDER: ";
    b.traverse(cout, POST);
    cout << endl;

    cout << "size of Tree: " << b.size() << endl;

    cout << endl << "Insert some node in Tree A" << endl;
    a.insert(25);
    a.insert(12);
    a.insert(47);
    a.insert(6);
    a.insert(30);
    a.insert(60);
    a.insert(18);
    if(a.empty()){
        cout<<"Tree A is empty"<<endl;
    }else{
        cout<<"Tree A is not empty"<<endl;
    }

    cout << "The size of Tree A: " << a.size() << endl;
    cout << endl << "Traversal of Tree A:" << endl;
    cout<<"INORDER: ";
    a.traverse(cout, IN);
    cout << endl;

    cout << "PREORDER: ";
    a.traverse(cout, PRE);
    cout << endl;

    cout << "POSTORDER: ";
    a.traverse(cout, POST);
    cout << endl;

    b=a;
    cout << endl << "copied tree A to B" << endl;
    cout <<"The size of tree A: " << a.size() << endl;
    cout <<"The size of tree B: " << b.size() << endl;

    cout << endl << "Traversal of Tree A:" << endl;
    cout<<"INORDER: ";
    a.traverse(cout, IN);
    cout << endl;

    cout << "PREORDER: ";
    a.traverse(cout, PRE);
    cout << endl;

    cout << "POSTORDER: ";
    a.traverse(cout, POST);
    cout << endl;

    cout << endl << "Traversal of Tree B:" << endl;
    cout<<"INORDER: ";
    b.traverse(cout, IN);
    cout << endl;

    cout << "PREORDER: ";
    b.traverse(cout, PRE);
    cout << endl;

    cout << "POSTORDER: ";
    b.traverse(cout, POST);
    cout << endl;

    return 0;
}