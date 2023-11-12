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
    // указатели левого и правого дочерних узлов
    TreeNode<T>* left;
    TreeNode<T>* right;
    //TreeNode<T>* parent;

    // открытый элемент, допускающий обновление
    T data;

    // конструктор инициализирует поля данных и указателей
    // значение NULL соответствует пустому поддереву
    TreeNode(const T& item, TreeNode<T>* lptr, TreeNode<T>* rptr/*, TreeNode<T>* pptr*/)
    {
        data = item;
        left = lptr;
        right = rptr;
        //parent = pptr;
    }
    // методы доступа к полям указателей
    TreeNode<T>* Left() const { return left; }
    TreeNode<T>* Right() const { return right; }
    //TreeNode<T>* Parent() const { return parent; }
    
};
