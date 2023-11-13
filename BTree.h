//@author Саранчин К.А.
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

    /// Виртуальный метод
    virtual ~TreeNode() {};
    
};


//промежуток между уровнями
const int indentBlock = 6;
//вставить numпробелов в текущей строке
void IndentBlanks(int num) {
    for (int i = 0; i < num; i++)
        cout << "  ";
}

//печать дерева боком,используя RNL- прохождение
template<class T>
void PrintTree(TreeNode<T>* node, int level) {
    //печатать правое дерево узла node, пока он не равет nullptr
    if (node != nullptr)
    {
        //печатать правое поддерево узла node
        PrintTree(node->Right(), level + 1);
        //выровнять текущий уровень и вывести поле данных
        IndentBlanks(indentBlock * level);
        cout << node->data << endl;
        //печатать левое поддерево узла node
        PrintTree(node->Left(), level + 1);
    }
}

//Функция внесения данных
template <class T>
TreeNode<T>* Add(TreeNode<T>* node, const T& aData)

{
    //Если ветки не существует

    if (node == nullptr)

    { //создадим ее и зададим в нее данные

        return new TreeNode<T>(aData, nullptr, nullptr);

    }

    if (aData < node->data) {
        // Рекурсивно вставляем значение в левое поддерево
        node->left = Add(node->left, aData);
    }
    else if (aData > node->data) {
        // Рекурсивно вставляем значение в правое поддерево
        node->right = Add(node->right, aData);
    }

    // Если значение уже присутствует в дереве, ничего не делаем

    return node;
}
