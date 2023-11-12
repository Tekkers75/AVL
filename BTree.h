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
    
};
