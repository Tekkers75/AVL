#pragma once

//@author �������� �.�.

#include"AVL_tree.h"
#include <cassert>
#include <iostream>
// �������� ������
template <class T>
AVLTreeNode<T>* CreateAVLTree() {

    //     4
    //    / \
    //  2     5
    // / \
    //1   3
    // ������� ���� ��� ������������
    AVLTreeNode<T>* node1 = new AVLTreeNode<T>(1);
    AVLTreeNode<T>* node2 = new AVLTreeNode<T>(2);
    AVLTreeNode<T>* node3 = new AVLTreeNode<T>(3);
    AVLTreeNode<T>* node4 = new AVLTreeNode<T>(4);
    AVLTreeNode<T>* node5 = new AVLTreeNode<T>(5);

    // ������ ������
    node2->SetLeft(node1);
    node2->SetRight(node3);
    node4->SetLeft(node2);
    node4->SetRight(node5);

    return node4; // ���������� �������� ���� ������
}
//�������� ����������� ������ ������
template <class T>
AVLTreeNode<T>* CreateRightAVLTree() {
    // ������� ���� ��� ������������
    AVLTreeNode<int>* node1 = new AVLTreeNode<int>(1);
    AVLTreeNode<int>* node2 = new AVLTreeNode<int>(2);
    AVLTreeNode<int>* node3 = new AVLTreeNode<int>(3);

    // ������ ������
    node1->SetRight(node2);
    node2->SetRight(node3);
    return node1;
}
//�������� ����������� ����� ������
template <class T>
AVLTreeNode<T>* CreateLeftAVLTree() {
    // ������� ���� ��� ������������
    AVLTreeNode<int>* node1 = new AVLTreeNode<int>(3);
    AVLTreeNode<int>* node2 = new AVLTreeNode<int>(2);
    AVLTreeNode<int>* node3 = new AVLTreeNode<int>(1);

    // ������ ������
    node1->SetLeft(node2);
    node2->SetLeft(node3);
    return node1;
}
//������������ ��������� ������
void TestGetHeight() {
    AVLTreeNode<int>* r = CreateAVLTree<int>();
    int height = r->GetHeight(r);
    assert(height == 2);

    AVLTreeNode<int>* r1 = CreateRightAVLTree<int>();
    height = r1->GetHeight(r1);
    assert(height == 2);

    AVLTreeNode<int>* r2 = CreateLeftAVLTree<int>();
    height = r2->GetHeight(r2);
    assert(height == 2);

    //����������� ������
    DeleteTree(r);
    DeleteTree(r1);
    DeleteTree(r2);

    cout << "���� ��������� ������ �������" << endl;
}
//������������ ��������� �������
void TestGetBalanceFactor() {
    AVLTreeNode<int>* r = CreateAVLTree<int>();
    int bf = r->GetBalanceFactor(r);
    assert(bf == -1);


    AVLTreeNode<int>* r1 = CreateRightAVLTree<int>();
    bf = r1->GetBalanceFactor(r1);
    assert(bf == 2);


    AVLTreeNode<int>* r2 = CreateLeftAVLTree<int>();
    bf = r2->GetBalanceFactor(r2);
    assert(bf == -2);

    //����������� ������
    DeleteTree(r);
    DeleteTree(r1);
    DeleteTree(r2);

    cout << "���� ��������� ������� �������" << endl;
}
//������������ ������ ��������
void TestRotateLeft() {
    AVLTreeNode<int>* r1 = CreateRightAVLTree<int>();
    //������������ ������ �����
    AVLTreeNode<int>* newRoot = r1->RotateLeft(r1);

    // ��������� ����� ��������� ������
    assert(newRoot->data == 2);
    assert(newRoot->Left()->data == 1);
    assert(newRoot->Right()->data == 3);
    //����������� ������
    DeleteTree(r1);

    cout << "���� ������ �������� �������" << endl;
}
//������������ ������� ��������
void TestRotateRight() {
    AVLTreeNode<int>* r1 = CreateLeftAVLTree<int>();
    //������������ ������ ������
    AVLTreeNode<int>* newRoot = r1->RotateRight(r1);

    // ��������� ����� ��������� ������
    assert(newRoot->data == 2);
    assert(newRoot->Left()->data == 1);
    assert(newRoot->Right()->data == 3);
    //����������� ������
    DeleteTree(r1);

    cout << "���� ������� �������� �������" << endl;
}
//������������ ������������ ������
void TestBalanceTree() {
    // �������� ���������������� �� ������ ������
    AVLTreeNode<int>* rightTree = CreateRightAVLTree<int>();
    //������������ ������ �����
    AVLTreeNode<int>* newRoot = rightTree->BalanceTree(rightTree);


    // ��������� ��������� ������ ����� ����������������
    assert(newRoot->data == 2);
    assert(newRoot->Left()->data == 1);
    assert(newRoot->Right()->data == 3);


    // �������� ���������������� �� ����� ������
    AVLTreeNode<int>* leftTree = CreateLeftAVLTree<int>();
    AVLTreeNode<int>* newRoot1 = leftTree->BalanceTree(leftTree);

    // ��������� ��������� ������ ����� ����������������
    assert(newRoot1->data == 2);
    assert(newRoot1->Left()->data == 1);
    assert(newRoot1->Right()->data == 3);
    //����������� ������
    DeleteTree(rightTree);
    DeleteTree(leftTree);

    cout << "���� ���������������� �������" << endl;
}
//������������ ���������� ����� �����
void TestAddNodeAVL() {

    //            7
    //          / \
    //         4   8
    //        /     \
    //      2         9
   //                   \             
   //                   10
   //                     \
   //                       11
       // ������� ������ ������
    AVLTreeNode<int>* root = new AVLTreeNode<int>(7);

    // ��������� ���� � ������
    root->AddNodeAVL(4);
    root->AddNodeAVL(8);
    root->AddNodeAVL(2);
    root->AddNodeAVL(9);
    root->AddNodeAVL(10);
    root->AddNodeAVL(11);
    //root->BalanceTree(root);

    // ��������� ��������� ������ � ������������
    assert(root->data == 7);
    assert(root->Left()->data == 4);
    assert(root->Right()->data == 9);
    assert(root->Left()->Left()->data == 2);
    assert(root->Right()->Right()->data == 10);
    assert(root->Right()->Left()->data == 8);
    assert(root->Right()->Right()->Right()->data == 11);
    //����������� ������
    DeleteTree(root);

    // ������������ ���������� �� ������ ������
    AVLTreeNode<int>* emptyTree = nullptr;
    emptyTree = emptyTree->AddNodeAVL(1);

    assert(emptyTree != nullptr); // ���� ���� ���������=>������ �� ������
    //����������� ������
    DeleteTree(emptyTree);

    cout << "���� ���������� ����� ����� �������" << endl;
}
//������������ ��������
void TestRemove() {
    //     4
    //    / \
    //  2     5
    // / \
    //1   3
     // ������� AVL-������
    AVLTreeNode<int>* avlTree = CreateAVLTree<int>();
    // ������� ��tk �� ������
    AVLTreeNode<int>* newRoot1 = avlTree->Remove(3);


    // ��������� ��������� ������ ����� ��������
    assert(newRoot1->data == 4);
    assert(newRoot1->Left()->data == 2);
    assert(newRoot1->Right()->data == 5);


    // ������� ���� �� ������
    AVLTreeNode<int>* newRoot2 = avlTree->Remove(5);

    // ��������� ��������� ������ ����� ��������
    assert(newRoot2->data == 2);
    assert(newRoot2->Left()->data == 1);
    assert(newRoot2->Right()->data == 4);
    // ����������� ������
    DeleteTree(avlTree);

    // ������������ �������� �� ������ ������
    AVLTreeNode<int>* emptyTree = nullptr;
    emptyTree = emptyTree->Remove(1); // �������� �� ������ ������

    assert(emptyTree == nullptr); // ������ ���� nullptr


    //����������� ������
    DeleteTree(emptyTree);

    cout << "���� �������� ����� �������" << endl;
}

