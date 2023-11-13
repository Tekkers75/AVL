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

    // конструктор инициализирует пол€ данных и указателей
    // значение NULL соответствует пустому поддереву
    TreeNode(const T& item, TreeNode<T>* lptr, TreeNode<T>* rptr/*, TreeNode<T>* pptr*/)
    {
        data = item;
        left = lptr;
        right = rptr;
        //parent = pptr;
    }
    // методы доступа к пол€м указателей
    TreeNode<T>* Left() const { return left; }
    TreeNode<T>* Right() const { return right; }
    //TreeNode<T>* Parent() const { return parent; }

    /// ¬иртуальный метод
    virtual ~TreeNode() {};
    
};


//промежуток между уровн€ми
const int indentBlock = 6;
//вставить numпробелов в текущей строке
void IndentBlanks(int num) {
    for (int i = 0; i < num; i++)
        cout << "  ";
}

//печать дерева боком,использу€ RNL- прохождение
template<class T>
void PrintTree(TreeNode<T>* node, int level) {
    //печатать правое дерево узла node, пока он не равет nullptr
    if (node != nullptr)
    {
        //печатать правое поддерево узла node
        PrintTree(node->Right(), level + 1);
        //выровн€ть текущий уровень и вывести поле данных
        IndentBlanks(indentBlock * level);
        cout << node->data << endl;
        //печатать левое поддерево узла node
        PrintTree(node->Left(), level + 1);
    }
}

//‘ункци€ внесени€ данных
template <class T>
TreeNode<T>* Add(TreeNode<T>* node, const T& aData)

{
    //≈сли ветки не существует

    if (node == nullptr)

    { //создадим ее и зададим в нее данные

        return new TreeNode<T>(aData, nullptr, nullptr);

    }

    if (aData < node->data) {
        // –екурсивно вставл€ем значение в левое поддерево
        node->left = Add(node->left, aData);
    }
    else if (aData > node->data) {
        // –екурсивно вставл€ем значение в правое поддерево
        node->right = Add(node->right, aData);
    }

    // ≈сли значение уже присутствует в дереве, ничего не делаем

    return node;
}
