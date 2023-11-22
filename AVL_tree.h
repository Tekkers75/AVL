#pragma once
//@author �������� �.�.
#include <iostream>
#include <iomanip>
#include <cassert>
#include "BTree.h"
#include "AVLTreeNode.h"

using namespace std;

template <class T>
class AVLTree
{
private:
    //��������� �� ������
    AVLTreeNode<T>* root;


public:
    //�����������
    AVLTree(const T& item) : root(new AVLTreeNode<T>(item, nullptr, nullptr)) {}
    AVLTree() : root(nullptr)
    {
    }


    // ������� ������ ����
    void Insert(const T& item)
    {
        root = root->AddNodeAVL(item);

    }
    //�������� ����
    void Remove(const T& item) {
        root = root->Remove(item);
    }

    //������ ������
    void PrintTreeAVL() {
        PrintTree(root, 0);
    }
    //����� �� ��������
    int Find(const T& item) {
        return Search(root, item, 0);
    }
    //������� ������� (�������) ������
    int Height() {
        return Depth(root);
    }
    //������� ����� ������
    int CountNode() {
        return CountNodes(root);
    }
    //�������� ������
    void DeleteAVLTree() {
        DeleteTree(root);
    }

    //������ ������ � ������ � ������� LNR
    void AddNodesToArray(T arr[]) {
        PrintArr(root, arr);
    }
};

































//template <class T>
//class AVLTreeNode:public TreeNode<T> {
//public:
//    int balanceFactor;
//    int height;
//
//    AVLTreeNode(const T& value, TreeNode<T>* leftChild = nullptr, TreeNode<T>* rightChild = nullptr)
//        : TreeNode<T>(value, leftChild, rightChild), balanceFactor(0), height(0)
//    {
//    }
//
//       
//};


//template <class T>
//class AVLTree {
//public:
//
//    AVLTreeNode<T>* root;
//
//    AVLTree() : root(nullptr)
//    {
//    }
//
//
//    int Height(AVLTreeNode<T>* node)
//    {
//        if (node == nullptr) {
//            return -1;
//        }
//        else {
//            node->height = std::max(Height(dynamic_cast<AVLTreeNode<T>*>(node->left)), Height(dynamic_cast<AVLTreeNode<T>*>(node->right))) + 1;
//            return node->height;
//        }
//    }
//
//    void InsertNode(AVLTreeNode<T>*& node, const T& value)
//    {
//        if (node == nullptr) {
//            node = new AVLTreeNode<T>(value);
//        }
//        else if (value < node->data) {
//            InsertNode(node->left, value);
//        }
//        else if (value > node->data) {
//            InsertNode(dynamic_cast<AVLTreeNode<T>*>(node->right), value);
//        }
//
//        Balance(node);
//    }
//
//    void Balance(AVLTreeNode<T>* node)
//    {
//        if (node == nullptr) {
//            return;
//        }
//
//        int balanceFactor = bFactor(node);
//
//        if (balanceFactor > 1) {
//            if (bFactor(dynamic_cast<AVLTreeNode<T>*>(node->left)) >= 0) {
//                // Left-Left case
//                RotateRight(node);
//            }
//            else {
//                // Left-Right case
//                RotateLeft(dynamic_cast<AVLTreeNode<T>*>(node->left));
//                RotateRight(node);
//            }
//        }
//        else if (balanceFactor < -1) {
//            if (bFactor(dynamic_cast<AVLTreeNode<T>*>(node->right)) <= 0) {
//                // Right-Right case
//                RotateLeft(node);
//            }
//            else {
//                // Right-Left case
//                RotateRight(dynamic_cast<AVLTreeNode<T>*>(node->right));
//                RotateLeft(node);
//            }
//        }
//
//        FixHeight(node);
//    }
//
//    int bFactor(AVLTreeNode<T>* node)
//    {
//        return Height(dynamic_cast<AVLTreeNode<T>*>(node->left)) - Height(dynamic_cast<AVLTreeNode<T>*>(node->right));
//    }
//
//    void FixHeight(AVLTreeNode<T>* node)
//    {
//        int leftHeight = Height(dynamic_cast<AVLTreeNode<T>*>(node->left));
//        int rightHeight = Height(dynamic_cast<AVLTreeNode<T>*>(node->right));
//        node->height = std::max(leftHeight, rightHeight) + 1;
//    }
//
//    void RotateLeft(AVLTreeNode<T>* node)
//    {
//        AVLTreeNode<T>* pivot = (dynamic_cast<AVLTreeNode<T>*>(node->right));
//        node->right = pivot->left;
//        pivot->left = node;
//        FixHeight(node);
//        FixHeight(pivot);
//        node = pivot;
//    }
//
//    void RotateRight(AVLTreeNode<T>* node)
//    {
//        AVLTreeNode<T>* pivot = (dynamic_cast<AVLTreeNode<T>*>(node->left));
//        node->left = pivot->right;
//        pivot->right = node;
//        FixHeight(node);
//        FixHeight(pivot);
//        node = pivot;
//    }
//
//   
//    void PrintTree(AVLTreeNode<T>* root, int indent = 0)
//    {
//        if (root == nullptr) {
//            return;
//        }
//
//        PrintTree((dynamic_cast<AVLTreeNode<T>*>(root->right)), indent + 4);
//        cout << setw(indent) << root->data << endl;
//        PrintTree((dynamic_cast<AVLTreeNode<T>*>(root->left)), indent + 4);
//    }


    ////���������� ����� ��������
    //const int indentBlock = 6;
    ////�������� num�������� � ������� ������
    //void IndentBlanks(int num) {
    //    for (int i = 0; i < num; i++)
    //        cout << "  ";
    //}

    ////������ ������ �����,��������� RNL- �����������
    //template<class T>
    //void PrintTree(TreeNode<T>* node, int level) {
    //    //�������� ������ ������ ���� node, ���� �� �� ����� nullptr
    //    if (node != nullptr)
    //    {
    //        //�������� ������ ��������� ���� node
    //        PrintTree(node->Right(), level + 1);
    //        //��������� ������� ������� � ������� ���� ������
    //        IndentBlanks(indentBlock * level);
    //        cout << node->data << endl;
    //        //�������� ����� ��������� ���� node
    //        PrintTree(node->Left(), level + 1);
    //    }
    //}

//};



    //AVLTreeNode<T>* RotateLeft(AVLTreeNode<T>* node);
    //AVLTreeNode<T>* RotateRight(AVLTreeNode<T>* node);
    //int Height(AVLTreeNode<T>* node);
    //void InsertNode(AVLTreeNode<T>*& node, const T& value);
    //void Balance(AVLTreeNode<T>* node);
    //int bFactor(AVLTreeNode<T>* p);
    //void FixHeight(AVLTreeNode<T>* p);
//};

    //template <class T>
    //int AVLTree<T>::Height(AVLTreeNode<T>* node)
    //{
    //    if (node == nullptr) {
    //        return -1;
    //    }
    //    else {
    //        node->height = std::max(Height(dynamic_cast<AVLTreeNode<T>*>(node->left)), Height(dynamic_cast<AVLTreeNode<T>*>(node->right))) + 1;
    //        return node->height; /*static_cast<AVLTreeNode<int>*>(node)->height;*/
    //    }

    //    //return node ? node->height: 0;
    //}

    //template <class T>
    //int AVLTree<T>::bFactor(AVLTreeNode<T>* p)
    //{
    //    return Height(dynamic_cast<AVLTreeNode<T>*>(p->Right())) - Height(dynamic_cast<AVLTreeNode<T>*>(p->Left()));
    //}

    //template <class T>
    //void AVLTree<T>::FixHeight(AVLTreeNode<T>* p)
    //{
    //    unsigned char hl = Height(dynamic_cast<AVLTreeNode<T>*>(p->Left()));
    //    unsigned char hr = Height(dynamic_cast<AVLTreeNode<T>*>(p->Right()));
    //    //p->height = (hl > hr ? hl : hr) + 1;
    //    p->height = std::max(hl, hr) + 1;
    //}



    ////template <class T>
    ////void AVLTree<T>::RotateLeft(AVLTreeNode<T>** node)
    ////{
    ////    if (*node == nullptr || *node->right == nullptr) 
    ////    {
    ////        return;
    ////    }
    ////    /*AVLTreeNode<T>* pivot = node->right;*/
    ////    AVLTreeNode<T>* pivot = static_cast<AVLTreeNode<T>*>(*node->right);
    ////    *node->right = pivot->left;
    ////    pivot->left = *node;
    ////    node = pivot;
    ////}

    //template <class T>
    //AVLTreeNode<T>* AVLTree<T>::RotateLeft(AVLTreeNode<T>* node)
    //{
    //    if (node == nullptr || node->right == nullptr)
    //    {
    //        return nullptr;
    //    }
    //    /*AVLTreeNode<T>* pivot = node->right;*/
    //    AVLTreeNode<T>* pivot = dynamic_cast<AVLTreeNode<T>*>(node->right);
    //    node->right = pivot->left;
    //    pivot->left = node;
    //    FixHeight(node);
    //    FixHeight(pivot);
    //    node = pivot;
    //    return pivot;
    //}


    ////template <class T>
    ////void AVLTree<T>::RotateRight(AVLTreeNode<T>*& node)
    ////{
    ////    if (node == nullptr || node->left == nullptr)
    ////    {
    ////        return;
    ////    }
    ////    AVLTreeNode<T>* pivot = dynamic_cast<AVLTreeNode<T>*>(node->left);
    ////    node->left = pivot->right;
    ////    pivot->right = node;
    ////    node = pivot;
    ////}

    //template <class T>
    //AVLTreeNode<T>* AVLTree<T>::RotateRight(AVLTreeNode<T>* node)
    //{
    //    if (node == nullptr || node->left == nullptr)
    //    {
    //        return nullptr;
    //    }
    //    AVLTreeNode<T>* pivot = dynamic_cast<AVLTreeNode<T>*>(node->left);
    //    node->left = pivot->right;
    //    pivot->right = node;
    //    FixHeight(node);
    //    FixHeight(pivot);
    //    node = pivot;
    //    return pivot;
    //}
 
    ////template <class T>
    ////void AVLTree<T>::Balance(AVLTreeNode<T>* node)
    ////{
    ////    node->height = std::max(Height(dynamic_cast<AVLTreeNode<T>*>(node->left)), Height(dynamic_cast<AVLTreeNode<T>*>(node->right))) + 1;
    ////    node->balanceFactor = Height(dynamic_cast<AVLTreeNode<T>*>(node->right)) - Height(dynamic_cast<AVLTreeNode<T>*>(node->left));
    ////}


    ////template <class T>
    ////void AVLTree<T>::InsertNode(AVLTreeNode<T>*& node, const T& value)
    ////{
    ////    if (node == nullptr) {
    ////        node = new AVLTreeNode<T>(value);
    ////    }
    ////    else if (value < node->data) {
    ////        InsertNode(static_cast<AVLTreeNode<T>*>(node->left), value);
    ////    }
    ////    else if (value > node->data) {
    ////        InsertNode(static_cast<AVLTreeNode<T>*>(node->right), value);
    ////    }

    ////    // ���������� ������ � ������� ����
    ////    node->height = std::max(Height(static_cast<AVLTreeNode<T>*>(node->left)), Height(static_cast<AVLTreeNode<T>*>(node->right))) + 1;
    ////    node->balanceFactor = Height(static_cast<AVLTreeNode<T>*>(node->left)) - Height(static_cast<AVLTreeNode<T>*>(node->right));

    ////    //// ������������ ������
    ////    //if (node->balanceFactor > 1) {
    ////    //    if (value < node->left->data) {
    ////    //        RotateRight(node);
    ////    //    }
    ////    //    else {
    ////    //        RotateLeft(static_cast<AVLTreeNode<T>*>(node->left));
    ////    //        RotateRight(node);
    ////    //    }
    ////    //}
    ////    //else if (node->balanceFactor < -1) {
    ////    //    if (value > node->right->data) {
    ////    //        RotateLeft(node);
    ////    //    }
    ////    //    else {
    ////    //        RotateRight(static_cast<AVLTreeNode<T>*>(node->right));
    ////    //        RotateLeft(node);
    ////    //    }
    ////    //}
    ////}


    //template <class T>
    //void AVLTree<T>::Balance(AVLTreeNode<T>* node)
    //{
    //    if (node == nullptr) {
    //        return;
    //    }

    //    int balanceFactor = bFactor(node);

    //    if (balanceFactor > 1) {
    //        if (bFactor(dynamic_cast<AVLTreeNode<T>*>(node->left)) >= 0) {
    //            // Left-Left case
    //            RotateRight(node);
    //        }
    //        else {
    //            // Left-Right case
    //            RotateLeft(dynamic_cast<AVLTreeNode<T>*>(node->left));
    //            RotateRight(node);
    //        }
    //    }
    //    else if (balanceFactor < -1) {
    //        if (bFactor(dynamic_cast<AVLTreeNode<T>*>(node->right)) <= 0) {
    //            // Right-Right case
    //            RotateLeft(node);
    //        }
    //        else {
    //            // Right-Left case
    //            RotateRight(dynamic_cast<AVLTreeNode<T>*>(node->right));
    //            RotateLeft(node);
    //        }
    //    }

    //    FixHeight(node);
    //}



    //template <class T>
    //void AVLTree<T>::InsertNode(AVLTreeNode<T>*& node, const T& value)
    //{
    //    Add(node, value);
    //    // ���������� ������ � ������� ����
    //    Balance(node);
    //    /*node->height = std::max(Height(dynamic_cast<AVLTreeNode<T>*>(node->left)), Height(dynamic_cast<AVLTreeNode<T>*>(node->right))) + 1;
    //    node->balanceFactor = Height(dynamic_cast<AVLTreeNode<T>*>(node->left)) - Height(dynamic_cast<AVLTreeNode<T>*>(node->right));*/
    //    //FixHeight(node);
    //    //bFactor(node);

    //    //// ������������ ������
    //    //if (node->balanceFactor > 1) {
    //    //    if (value < node->left->data) {
    //    //        node = RotateRight(node);
    //    //    }
    //    //    else {
    //    //        node->left = RotateRight(dynamic_cast<AVLTreeNode<T>*>(node->left));
    //    //        //RotateLeft(dynamic_cast<AVLTreeNode<T>*>(node->left));
    //    //        //RotateLeft(static_cast<AVLTreeNode<T>*>(node->left));
    //    //        node = RotateRight(node);
    //    //        
    //    //    }
    //    //}
    //    //else if (node->balanceFactor < -1) {
    //    //    if (value > node->right->data) {
    //    //        node = RotateLeft(node);
    //    //    }
    //    //    else {
    //    //        node->right = RotateRight(dynamic_cast<AVLTreeNode<T>*>(node->right));
    //    //        //RotateRight(dynamic_cast<AVLTreeNode<T>*>(node->right));
    //    //        node = RotateLeft(node);
    //    //    }
    //    //}

    //}




    ////���������� ����� ��������
    //const int indentBlock = 6;
    ////�������� num�������� � ������� ������
    //void IndentBlanks(int num) {
    //    for (int i = 0; i < num; i++)
    //        cout << "  ";
    //}

    ////������ ������ �����,��������� RNL- �����������
    //template<class T>
    //void PrintTree(AVLTreeNode<T>* node, int level) {
    //    //�������� ������ ������ ���� node, ���� �� �� ����� nullptr
    //    if (node != nullptr)
    //    {
    //        //�������� ������ ��������� ���� node
    //        PrintTree(node->right, level + 1);
    //        //��������� ������� ������� � ������� ���� ������
    //        IndentBlanks(indentBlock * level);
    //        cout << node->data << endl;
    //        //�������� ����� ��������� ���� node
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


