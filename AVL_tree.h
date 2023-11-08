#pragma once
///@author Саранчин К.А.

#include <iostream>
#include <iomanip>
#include <cassert>
#include "BinaryTree.h"

using namespace std;

template <class T>
struct AVL_tree: public TreeNode<T>
{
    int balanceFactor;
    int height;
    AVL_tree(const T& item, AVL_tree<T>* lptr = nullptr, AVL_tree<T>* rptr = nullptr, int balance = 0, int nodeHeight = 0)
        : TreeNode<T>(item, lptr, rptr), balanceFactor(balance), height(nodeHeight) {}
  
      
    AVL_tree<T>* Left() const { return static_cast<AVL_tree*>(this->left); };
    AVL_tree<T>* Right() const { return static_cast<AVL_tree*>(this->right); };

    int GetBalanceFactor() const { return balanceFactor; };
    

    
    void UpdateHeight()
    {
        // Обновляем высоту текущего узла на основе высот его поддеревьев
        int leftHeight = (this->left != nullptr) ? Depth(this->left) : -1;
        int rightHeight = (this->right != nullptr) ? Depth(this->right) : -1;
        this->height = std::max(leftHeight, rightHeight) + 1;
    }

    void AVL_tree<T>::Rebalance()
    {
        // Обновляем высоту текущего узла
        UpdateHeight();

        // Вычисляем баланс-фактор текущего узла
        int balanceFactor = GetBalanceFactor();

        // Если баланс-фактор больше 1, значит дерево несбалансировано влево
        if (balanceFactor > 1) {
            // Определяем, нужно ли выполнять одиночное или двойное вращение
            if (Right()->GetBalanceFactor() < 0) {
                // Необходимо сначала выполнить правое вращение для правого поддерева
                Right()->RotateRight();
            }
            // Выполняем левое вращение для текущего узла
            RotateLeft();
        }
        // Если баланс-фактор меньше -1, значит дерево несбалансировано вправо
        else if (balanceFactor < -1) {
            // Определяем, нужно ли выполнять одиночное или двойное вращение
            if (Left()->GetBalanceFactor() > 0) {
                // Необходимо сначала выполнить левое вращение для левого поддерева
                Left()->RotateLeft();
            }
            // Выполняем правое вращение для текущего узла
            RotateRight();
        }
    }

    void AVL_tree<T>::RotateLeft()
    {
        // Выполняем левое вращение для текущего узла
        AVL_tree<T>* newRoot = this->Right();
        this->right = newRoot->Left();
        newRoot->left = this;
        this->UpdateHeight();
        newRoot->UpdateHeight();

        // Обновляем указатель на текущий узел или его родителя
        if (this->parent != nullptr) {
            if (this->parent->left == this) {
                this->parent->left = newRoot;
            }
            else {
                this->parent->right = newRoot;
            }
        }
        newRoot->parent = this->parent;
        this->parent = newRoot;
    }

    template <class T>
    void AVL_tree<T>::RotateRight()
    {
        // Выполняем правое вращение для текущего узла
        AVL_tree<T>* newRoot = this->Left();
        this->left = newRoot->Right();
        newRoot->right = this;
        this->UpdateHeight();
        newRoot->UpdateHeight();

        // Обновляем указатель на текущий узел или его родителя
        if (this->parent != nullptr) {
            if (this->parent->left == this) {
                this->parent->left = newRoot;
            }
            else {
                this->parent->right = newRoot;
            }
        }
        newRoot->parent = this->parent;
        this->parent = newRoot;
    }

};

