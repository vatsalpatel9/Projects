///////////////////////////////////////////////////////////////////////////////
//
//  Vatsal Patel
//
//  Description:
//  The header files creates the binary search tree linked list and initatizes 
//  the variables used for the binary search tree linked list. It creats left
//  and right pointers. 
//
//  Input:
//  The input variable can be int, float, char, string.
//
//  Output:
//  Nothing is outputed.
//
//  Assumptions: None
//
//  Special Processing Requirements: None
//
///////////////////////////////////////////////////////////////////////////////
#ifndef BTNODETYPE_H
#define BTNODETYPE_H

#include<iostream>

template <class T>
struct BTNodeType{
    T item;
    BTNodeType<T> *left, *right;
};

#endif