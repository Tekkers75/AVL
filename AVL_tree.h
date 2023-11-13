#pragma once
//@author Саранчин К.А.
#include <iostream>
#include <iomanip>
#include <cassert>
#include "BTree.h"

using namespace std;

template <class T>
class AVLTreeNode:public TreeNode<T> {
public:
    int balanceFactor;
    int height;

    AVLTreeNode(const T& value, TreeNode<T>* leftChild = nullptr, TreeNode<T>* rightChild = nullptr)
        : TreeNode<T>(value, leftChild, rightChild), balanceFactor(0), height(0)
    {
    }
};


template <class T>
class AVLTree {
public:


    AVLTreeNode<T>* root;

    AVLTree() : root(nullptr)
    {
    }

    void RotateLeft(AVLTreeNode<T>*& node);
    void RotateRight(AVLTreeNode<T>*& node);
    int  Height(AVLTreeNode<T>* node);
    void InsertNode(AVLTreeNode<T>*& node, const T& value);
    void Balance(AVLTreeNode<T>*& node);
};

    template <class T>
    int AVLTree<T>::Height(AVLTreeNode<T>* node)
    {
        if (node == nullptr) {
            return -1;
        }
        else {
            node->height = std::max(Height(dynamic_cast<AVLTreeNode<T>*>(node->left)), Height(dynamic_cast<AVLTreeNode<T>*>(node->right))) + 1;
            return node->height; /*static_cast<AVLTreeNode<int>*>(node)->height;*/
        }
    }


    //template <class T>
    //void AVLTree<T>::RotateLeft(AVLTreeNode<T>** node)
    //{
    //    if (*node == nullptr || *node->right == nullptr) 
    //    {
    //        return;
    //    }
    //    /*AVLTreeNode<T>* pivot = node->right;*/
    //    AVLTreeNode<T>* pivot = static_cast<AVLTreeNode<T>*>(*node->right);
    //    *node->right = pivot->left;
    //    pivot->left = *node;
    //    node = pivot;
    //}

    template <class T>
    void AVLTree<T>::RotateLeft(AVLTreeNode<T>*& node)
    {
        if (node == nullptr || node->right == nullptr)
        {
            return;
        }
        /*AVLTreeNode<T>* pivot = node->right;*/
        AVLTreeNode<T>* pivot = dynamic_cast<AVLTreeNode<T>*>(node->right);
        node->right = pivot->left;
        pivot->left = node;
        node = pivot;
    }

    template <class T>
    void AVLTree<T>::RotateRight(AVLTreeNode<T>*& node)
    {
        if (node == nullptr || node->left == nullptr)
        {
            return;
        }
        AVLTreeNode<T>* pivot = dynamic_cast<AVLTreeNode<T>*>(node->left);
        node->left = pivot->right;
        pivot->right = node;
        node = pivot;
    }
 
    template <class T>
    void AVLTree<T>::Balance(AVLTreeNode<T>*& node)
    {
        node->height = std::max(Height(dynamic_cast<AVLTreeNode<T>*>(node->left)), Height(dynamic_cast<AVLTreeNode<T>*>(node->right))) + 1;
        node->balanceFactor = Height(dynamic_cast<AVLTreeNode<T>*>(node->right)) - Height(dynamic_cast<AVLTreeNode<T>*>(node->left));
    }


    //template <class T>
    //void AVLTree<T>::InsertNode(AVLTreeNode<T>*& node, const T& value)
    //{
    //    if (node == nullptr) {
    //        node = new AVLTreeNode<T>(value);
    //    }
    //    else if (value < node->data) {
    //        InsertNode(static_cast<AVLTreeNode<T>*>(node->left), value);
    //    }
    //    else if (value > node->data) {
    //        InsertNode(static_cast<AVLTreeNode<T>*>(node->right), value);
    //    }

    //    // Обновление высоты и баланса узла
    //    node->height = std::max(Height(static_cast<AVLTreeNode<T>*>(node->left)), Height(static_cast<AVLTreeNode<T>*>(node->right))) + 1;
    //    node->balanceFactor = Height(static_cast<AVLTreeNode<T>*>(node->left)) - Height(static_cast<AVLTreeNode<T>*>(node->right));

    //    //// Балансировка дерева
    //    //if (node->balanceFactor > 1) {
    //    //    if (value < node->left->data) {
    //    //        RotateRight(node);
    //    //    }
    //    //    else {
    //    //        RotateLeft(static_cast<AVLTreeNode<T>*>(node->left));
    //    //        RotateRight(node);
    //    //    }
    //    //}
    //    //else if (node->balanceFactor < -1) {
    //    //    if (value > node->right->data) {
    //    //        RotateLeft(node);
    //    //    }
    //    //    else {
    //    //        RotateRight(static_cast<AVLTreeNode<T>*>(node->right));
    //    //        RotateLeft(node);
    //    //    }
    //    //}
    //}

    template <class T>
    void AVLTree<T>::InsertNode(AVLTreeNode<T>*& node, const T& value)
    {
        Add(node, value);
        // Обновление высоты и баланса узла
        node->height = std::max(Height(dynamic_cast<AVLTreeNode<T>*>(node->left)), Height(dynamic_cast<AVLTreeNode<T>*>(node->right))) + 1;
        node->balanceFactor = Height(dynamic_cast<AVLTreeNode<T>*>(node->left)) - Height(dynamic_cast<AVLTreeNode<T>*>(node->right));
        
        // Балансировка дерева
        if (node->balanceFactor > 1) {
            if (value < node->left->data) {
                RotateRight(node);
            }
            else {
                RotateLeft(dynamic_cast<AVLTreeNode<T>*>(node->left));
                //RotateLeft(static_cast<AVLTreeNode<T>*>(node->left));
                RotateRight(node);
            }
        }
        else if (node->balanceFactor < -1) {
            if (value > node->right->data) {
                RotateLeft(&node);
            }
            else {
                RotateRight(dynamic_cast<AVLTreeNode<T>*>(node->right));
                RotateLeft(&node);
            }
        }

    }




    ////промежуток между уровнями
    //const int indentBlock = 6;
    ////вставить numпробелов в текущей строке
    //void IndentBlanks(int num) {
    //    for (int i = 0; i < num; i++)
    //        cout << "  ";
    //}

    ////печать дерева боком,используя RNL- прохождение
    //template<class T>
    //void PrintTree(AVLTreeNode<T>* node, int level) {
    //    //печатать правое дерево узла node, пока он не равет nullptr
    //    if (node != nullptr)
    //    {
    //        //печатать правое поддерево узла node
    //        PrintTree(node->right, level + 1);
    //        //выровнять текущий уровень и вывести поле данных
    //        IndentBlanks(indentBlock * level);
    //        cout << node->data << endl;
    //        //печатать левое поддерево узла node
    //        PrintTree(node->left, level + 1);
    //    }
    //}

    //void InOrderTraversal(AVLTreeNode<T>* node)
    //{
    //    if (node != nullptr) {
    //        InOrderTraversal(node->left);
    //        std::cout << node->data << " ";
    //        InOrderTraversal(node->right);
    //    }
    //}

    /////////////////////////////////////////////


