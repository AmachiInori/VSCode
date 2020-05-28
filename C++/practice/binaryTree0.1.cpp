/*
 * @Author: your name
 * @Date: 2020-04-15 16:30:52
 * @LastEditTime: 2020-04-25 17:18:40
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \VSCode\C++\practice\binaryTree0.1.cpp
 */
//二叉查找树
#include <iostream>

template <typename type>
class treeNode{
public:
    type data;
    treeNode<type> *left;
    treeNode<type> *right;
    
    treeNode(type x) : data(x);
};

template <typename type>
class binaryTree{
protected:
    treeNode<type> *root;
public:
    binaryTree(type);
    ~binaryTree();

    treeNode<type> *find(type);
    treeNode<type> *findMax();
    treeNode<type> *findMin();
    treeNode<type> *insert(type);
    void deleteNode(type);
    void makeEmpty();
};

template <typename type>
binaryTree<type>::binaryTree(type rootValue){
    treeNode<type> *str = new treeNode<type>(rootValue);
    str -> left = NULL;
    str -> right = NULL;
    root = str;
}

template <typename type>
binaryTree<type>::~binaryTree() {}

template <typename type>
treeNode<type> *binaryTree<type>::find(type value) {
    treeNode<type> *str = root;
    while (str && str -> data != value) {
        if (str -> data < value) str = str -> right;
        else if (str -> data > value) str = str -> left;
    }
    return str;
}

template <typename type>
treeNode<type> *binaryTree<type>::findMax() {
    treeNode<type> *str = root;
    while (str -> right) str = str -> right;
    return str;
}

template <typename type>
treeNode<type> *binaryTree<type>::findMin() {
    treeNode<type> *str = root;
    while (str -> left) str = str -> left;
    return str;
}

template <typename type>
treeNode<type> *binaryTree<type>::insert(type value) {
    treeNode<type> *str = root;
    treeNode<type> *temp(value);
    while (true) {
        if (str -> data < value) {
            if (str -> right) str = str -> right;
            else {
                str -> right = temp;
                break;
            }
        }
        else if (str -> data < value) {
            if (str -> left) str = str -> left;
            else {
                str -> left = temp;
                break;
            }
        }
    }
    return temp;
}