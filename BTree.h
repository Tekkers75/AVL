//@author �������� �.�.
#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <cassert>
#include <queue>

using namespace std;

template <class T>
struct TreeNode
{
    // ��������� ������ � ������� �������� �����
    TreeNode<T>* left;
    TreeNode<T>* right;
    //TreeNode<T>* parent;

    // �������� �������, ����������� ����������
    T data;

    // ����������� �������������� ���� ������ � ����������
    // �������� NULL ������������� ������� ���������
    TreeNode(const T& item, TreeNode<T>* lptr, TreeNode<T>* rptr/*, TreeNode<T>* pptr*/)
    {
        data = item;
        left = lptr;
        right = rptr;
        //parent = pptr;
    }
    // ������ ������� � ����� ����������
    TreeNode<T>* Left() const { return left; }
    TreeNode<T>* Right() const { return right; }
    //TreeNode<T>* Parent() const { return parent; }

    /// ����������� �����
    virtual ~TreeNode() {};
    
};


//���������� ����� ��������
const int indentBlock = 6;
//�������� num�������� � ������� ������
void IndentBlanks(int num) {
    for (int i = 0; i < num; i++)
        cout << "  ";
}

//������ ������ �����,��������� RNL- �����������
template<class T>
void PrintTree(TreeNode<T>* node, int level) {
    //�������� ������ ������ ���� node, ���� �� �� ����� nullptr
    if (node != nullptr)
    {
        //�������� ������ ��������� ���� node
        PrintTree(node->Right(), level + 1);
        //��������� ������� ������� � ������� ���� ������
        IndentBlanks(indentBlock * level);
        cout << node->data << endl;
        //�������� ����� ��������� ���� node
        PrintTree(node->Left(), level + 1);
    }
}

//������� �������� ������
template <class T>
TreeNode<T>* Add(TreeNode<T>* node, const T& aData)

{
    //���� ����� �� ����������

    if (node == nullptr)

    { //�������� �� � ������� � ��� ������

        return new TreeNode<T>(aData, nullptr, nullptr);

    }

    if (aData < node->data) {
        // ���������� ��������� �������� � ����� ���������
        node->left = Add(node->left, aData);
    }
    else if (aData > node->data) {
        // ���������� ��������� �������� � ������ ���������
        node->right = Add(node->right, aData);
    }

    // ���� �������� ��� ������������ � ������, ������ �� ������

    return node;
}
