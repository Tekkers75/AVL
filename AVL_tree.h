#pragma once
///@author �������� �.�.

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
        // ��������� ������ �������� ���� �� ������ ����� ��� �����������
        int leftHeight = (this->left != nullptr) ? Depth(this->left) : -1;
        int rightHeight = (this->right != nullptr) ? Depth(this->right) : -1;
        this->height = std::max(leftHeight, rightHeight) + 1;
    }

    void AVL_tree<T>::Rebalance()
    {
        // ��������� ������ �������� ����
        UpdateHeight();

        // ��������� ������-������ �������� ����
        int balanceFactor = GetBalanceFactor();

        // ���� ������-������ ������ 1, ������ ������ ���������������� �����
        if (balanceFactor > 1) {
            // ����������, ����� �� ��������� ��������� ��� ������� ��������
            if (Right()->GetBalanceFactor() < 0) {
                // ���������� ������� ��������� ������ �������� ��� ������� ���������
                Right()->RotateRight();
            }
            // ��������� ����� �������� ��� �������� ����
            RotateLeft();
        }
        // ���� ������-������ ������ -1, ������ ������ ���������������� ������
        else if (balanceFactor < -1) {
            // ����������, ����� �� ��������� ��������� ��� ������� ��������
            if (Left()->GetBalanceFactor() > 0) {
                // ���������� ������� ��������� ����� �������� ��� ������ ���������
                Left()->RotateLeft();
            }
            // ��������� ������ �������� ��� �������� ����
            RotateRight();
        }
    }

    void AVL_tree<T>::RotateLeft()
    {
        // ��������� ����� �������� ��� �������� ����
        AVL_tree<T>* newRoot = this->Right();
        this->right = newRoot->Left();
        newRoot->left = this;
        this->UpdateHeight();
        newRoot->UpdateHeight();

        // ��������� ��������� �� ������� ���� ��� ��� ��������
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
        // ��������� ������ �������� ��� �������� ����
        AVL_tree<T>* newRoot = this->Left();
        this->left = newRoot->Right();
        newRoot->right = this;
        this->UpdateHeight();
        newRoot->UpdateHeight();

        // ��������� ��������� �� ������� ���� ��� ��� ��������
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

