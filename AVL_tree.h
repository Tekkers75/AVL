//#pragma once
/////@author Саранчин К.А.
//
#include <iostream>
#include <iomanip>
#include <cassert>
#include "BTree.h"

using namespace std;

template <class T>
class AVLTree {
public:
    T data;
    AVLTree<T>* left;
    AVLTree<T>* right;
    int balanceFactor;
    int height;

    AVLTree(const T& value, AVLTree<T>* leftChild = nullptr, AVLTree<T>* rightChild = nullptr)
        : data(value), left(leftChild), right(rightChild), balanceFactor(0), height(0)
    {
    }

    int Height(AVLTree* node)
    {
        if (node == nullptr) {
            return -1;
        }
        else {
            return node->height;
        }
    }


    void RotateLeft(AVLTree*& node)
    {
        if (node == nullptr || node->right == nullptr) 
        {
            return;
        }
        AVLTree* pivot = node->right;
        node->right = pivot->left;
        pivot->left = node;
        node = pivot;
    }

    void RotateRight(AVLTree<T>*& node)
    {
        if (node == nullptr || node->left == nullptr)
        {
            return;
        }
        AVLTree* pivot = node->left;
        node->left = pivot->right;
        pivot->right = node;
        node = pivot;
    }

 

    //промежуток между уровнями
    const int indentBlock = 6;
    //вставить numпробелов в текущей строке
    void IndentBlanks(int num) {
        for (int i = 0; i < num; i++)
            cout << "  ";
    }

    //печать дерева боком,используя RNL- прохождение
    template<class T>
    void PrintTree(AVLTree<T>* node, int level) {
        //печатать правое дерево узла node, пока он не равет nullptr
        if (node != nullptr)
        {
            //печатать правое поддерево узла node
            PrintTree(node->right, level + 1);
            //выровнять текущий уровень и вывести поле данных
            IndentBlanks(indentBlock * level);
            cout << node->data << endl;
            //печатать левое поддерево узла node
            PrintTree(node->left, level + 1);
        }
    }

    void InOrderTraversal(AVLTree* node)
    {
        if (node != nullptr) {
            InOrderTraversal(node->left);
            std::cout << node->data << " ";
            InOrderTraversal(node->right);
        }
    }


    void InsertNode(AVLTree*& node, const T& value)
    {
        if (node == nullptr) {
            node = new AVLTree(value);
        }
        else if (value < node->data) {
            InsertNode(node->left, value);
        }
        else if (value > node->data) {
            InsertNode(node->right, value);
        }

        // Обновление высоты и баланса узла
        node->height = std::max(Height(node->left), Height(node->right)) + 1;
        node->balanceFactor = Height(node->left) - Height(node->right);

        // Балансировка дерева
        if (node->balanceFactor > 1) {
            if (value < node->left->data) {
                RotateRight(node);
            }
            else {
                RotateLeft(node->left);
                RotateRight(node);
            }
        }
        else if (node->balanceFactor < -1) {
            if (value > node->right->data) {
                RotateLeft(node);
            }
            else {
                RotateRight(node->right);
                RotateLeft(node);
            }
        }
    }

    //void DeleteNode(TreeNode*& node, const T& value)
    //{
    //    if (node == nullptr) {
    //        return;
    //    }
    //    else if (value < node->data) {
    //        DeleteNode(node->left, value);
    //    }
    //    else if (value > node->data) {
    //        DeleteNode(node->right, value);
    //    }
    //    else {
    //        if (node->left == nullptr && node->right == nullptr) {
    //            delete node;
    //            node = nullptr;
    //        }
    //        else if (node->left == nullptr) {
    //            TreeNode* temp = node;
    //            node = node->right;
    //            delete temp;
    //        }
    //        else if (node->right == nullptr) {
    //            TreeNode* temp = node;
    //            node = node->left;
    //            delete temp;
    //        }
    //        else {
    //            TreeNode* successor = FindMinimum(node->right);
    //            node->data = successor->data;
    //            DeleteNode(node->right, successor->data);
    //        }
    //    }

    //    if (node != nullptr) {
    //        // Обновление высоты и баланса узла
    //        node->height = std::max(Height(node->left), Height(node->right)) + 1;
    //        node->balanceFactor = Height(node->left) - Height(node->right);

    //        // Балансировка дерева
    //        if (node->balanceFactor > 1) {
    //            if (Height(node->left->left) >= Height(node->left->right)) {
    //                RotateRight(node);
    //            }
    //            else {
    //                RotateLeft(node->left);
    //                RotateRight(node);
    //            }
    //        }
    //        else if (node->balanceFactor < -1) {
    //            if (Height(node->right->right) >= Height(node->right->left)) {
    //                RotateLeft(node);
    //            }
    //            else {
    //                RotateRight(node->right);
    //                RotateLeft(node);
    //            }
    //        }
    //    }
    //}

    //TreeNode* SearchNode(TreeNode* node, const T& value)
    //{
    //    if (node == nullptr || node->data == value) {
    //        return node;
    //    }
    //    else if (value < node->data) {

    //            return SearchNode(node->left, value);
    //    }
    //    else {
    //        return SearchNode(node->right, value);
    //    }
    //}



    //TreeNode* FindMinimum(TreeNode* node)
    //{
    //    if (node == nullptr) {
    //        return nullptr;
    //    }
    //    else if (node->left == nullptr) {
    //        return node;
    //    }
    //    else {
    //        return FindMinimum(node->left);
    //    }
    //}

    //void DeleteNode(TreeNode<T>*& node, const T& value)
    //{
    //    if (node == nullptr) {
    //        return;
    //    }
    //    else if (value < node->data) {
    //        DeleteNode(node->left, value);
    //    }
    //    else if (value > node->data) {
    //        DeleteNode(node->right, value);
    //    }
    //    else {
    //        if (node->left == nullptr && node->right == nullptr) {
    //            delete node;
    //            node = nullptr;
    //        }
    //        else if (node->left == nullptr) {
    //            TreeNode* temp = node;
    //            node = node->right;
    //            delete temp;
    //        }
    //        else if (node->right == nullptr) {
    //            TreeNode* temp = node;
    //            node = node->left;
    //            delete temp;
    //        }
    //        else {
    //            TreeNode* successor = FindMinimum(node->right);
    //            node->data = successor->data;
    //            DeleteNode(node->right, successor->data);
    //        }
    //    }
    //        if (node != nullptr) {
    //        // Обновление высоты и баланса узла
    //        node->height = std::max(Height(node->left), Height(node->right)) + 1;
    //        node->balanceFactor = Height(node->left) - Height(node->right);

    //        // Балансировка дерева
    //        if (node->balanceFactor > 1) {
    //            if (Height(node->left->left) >= Height(node->left->right)) {
    //                RotateRight(node);
    //            }
    //            else {
    //                RotateLeft(node->left);
    //                RotateRight(node);
    //            }
    //        }
    //        else if (node->balanceFactor < -1) {
    //            if (Height(node->right->right) >= Height(node->right->left)) {
    //                RotateLeft(node);
    //            }
    //            else {
    //                RotateRight(node->right);
    //                RotateLeft(node);
    //            }
    //        }
    //    }
    //}

    //TreeNode<T>* SearchNode(TreeNode<T>* node, const T& value)
    //{
    //    if (node == nullptr || node->data == value) {
    //        return node;
    //    }
    //    else if (value < node->data) {
    //            return SearchNode(node->left, value);
    //    }
    //    else {
    //        return SearchNode(node->right, value);
    //    }
    //}

    //void InOrderTraversal(TreeNode<T>* node)
    //{
    //    if (node != nullptr) {
    //        InOrderTraversal(node->left);
    //        std::cout << node->data << " ";
    //        InOrderTraversal(node->right);
    //    }
    //}


    //TreeNode<T>* FindMinimum(TreeNode<T>* node)
    //{
    //    if (node == nullptr) {
    //        return nullptr;
    //    }
    //    else if (node->left == nullptr) {
    //        return node;
    //    }
    //    else {
    //        return FindMinimum(node->left);
    //    }
    //}

    ////////////////////////////////////////////////////////////////
    
    //void RotateLeft()
    //{
    //    AVLTree<T>* pivot = this->right;
    //    if (pivot == nullptr)
    //        return;

    //    // Перемещаем левое поддерево от pivot на правую позицию текущего узла
    //    this->right = pivot->left;
    //    if (pivot->left != nullptr)
    //        pivot->left->parent = this;

    //    // Родитель текущего узла становится родителем pivot
    //    pivot->parent = this->parent;
    //    if (this->parent != nullptr) {
    //        if (this->parent->left == this)
    //            this->parent->left = pivot;
    //        else
    //            this->parent->right = pivot;
    //    }

    //    // Текущий узел становится левым потомком pivot
    //    pivot->left = this;
    //    this->parent = pivot;

    //    // Обновляем высоты узлов
    //    this->UpdateHeight();
    //    pivot->UpdateHeight();
    //}

    //void RotateRight()
    //{
    //    AVLTree<T>* pivot = this->left;
    //    if (pivot == nullptr)
    //        return;

    //    // Перемещаем правое поддерево от pivot на левую позицию текущего узла
    //    this->left = pivot->right;
    //    if (pivot->right != nullptr)
    //        pivot->right->parent = this;

    //    // Родитель текущего узла становится родителем pivot
    //    pivot->parent = this->parent;
    //    if (this->parent != nullptr) {
    //        if (this->parent->left == this)
    //            this->parent->left = pivot;
    //        else
    //            this->parent->right = pivot;
    //    }

    //    // Текущий узел становится правым потомком pivot
    //    pivot->right = this;
    //    this->parent = pivot;

    //    // Обновляем высоты узлов
    //    this->UpdateHeight();
    //    pivot->UpdateHeight();
    //}

    //void UpdateHeight()
    //{
    //    // Обновляем высоту текущего узла на основе высот его поддеревьев
    //    int leftHeight = (this->left != nullptr) ? this->left->height : -1;
    //    int rightHeight = (this->right != nullptr) ? this->right->height : -1;
    //    this->height = std::max(leftHeight, rightHeight) + 1;
    //}
};

//
//template <class T>
//struct AVL_tree : public TreeNode<T>
//{
//    int balanceFactor;
//    int height;
//    AVL_tree(const T& item, AVL_tree<T>* lptr = nullptr, AVL_tree<T>* rptr = nullptr, AVL_tree<T>* pptr = nullptr, int balance = 0, int nodeHeight = 0)
//        : TreeNode<T>(item, lptr, rptr, pptr), balanceFactor(balance), height(nodeHeight) 
//    {
//        if (lptr != nullptr)
//            lptr->parent = this;
//        if (rptr != nullptr)
//            rptr->parent = this;
//        if (pptr != nullptr)
//            this->parent = pptr;
//    }
//
//
//    AVL_tree<T>* Left() const { return static_cast<AVL_tree*>(this->left); };
//    AVL_tree<T>* Right() const { return static_cast<AVL_tree*>(this->right); };
//    AVL_tree<T>* Parent() const { return static_cast<AVL_tree*>(this->parent); };
//
//    int GetBalanceFactor() const { return balanceFactor; };
//
//
//
//    void UpdateHeight()
//    {
//        // Обновляем высоту текущего узла на основе высот его поддеревьев
//        int leftHeight = (this->left != nullptr) ? this->left->height : -1;
//        int rightHeight = (this->right != nullptr) ? this->right->height : -1;
//        this->height = std::max(leftHeight, rightHeight) + 1;
//    }
//
//    template <class T>
//    void RotateLeft()
//    {
//        // Выполняем левое вращение для текущего узла
//        AVL_tree<T>* newRoot = this->Right();
//        this->right = newRoot->Left();
//        newRoot->left = this;
//        this->UpdateHeight();
//        newRoot->UpdateHeight();
//
//        // Обновляем указатель на текущий узел или его родителя
//        if (this->parent != nullptr) {
//            if (this->parent->left == this) {
//                this->parent->left = newRoot;
//            }
//            else {
//                this->parent->right = newRoot;
//            }
//        }
//        newRoot->parent = this->parent;
//        this->parent = newRoot;
//    }
//
//
//    void RotateRight()
//    {
//        // Выполняем правое вращение для текущего узла
//        AVL_tree<T>* newRoot = this->Left();
//        this->left = newRoot->Right();
//        newRoot->right = this;
//        this->UpdateHeight();
//        newRoot->UpdateHeight();
//
//        // Обновляем указатель на текущий узел или его родителя
//        if (this->parent != nullptr) {
//            if (this->parent->left == this) {
//                this->parent->left = newRoot;
//            }
//            else {
//                this->parent->right = newRoot;
//            }
//        }
//        newRoot->parent = this->parent;
//        this->parent = newRoot;
//    }
//
//
//};

//    void Rebalance()
//    {
//        // Обновляем высоту текущего узла
//        UpdateHeight();
//
//        // Вычисляем баланс-фактор текущего узла
//        int balanceFactor = GetBalanceFactor();
//
//        // Если баланс-фактор больше 1, значит дерево несбалансировано влево
//        if (balanceFactor > 1) {
//            // Определяем, нужно ли выполнять одиночное или двойное вращение
//            if (Right()->GetBalanceFactor() < 0) {
//                // Необходимо сначала выполнить правое вращение для правого поддерева
//                Right()->RotateRight();
//            }
//            // Выполняем левое вращение для текущего узла
//            //RotateLeft();
//        }
//        // Если баланс-фактор меньше -1, значит дерево несбалансировано вправо
//        else if (balanceFactor < -1) {
//            // Определяем, нужно ли выполнять одиночное или двойное вращение
//            if (Left()->GetBalanceFactor() > 0) {
//                // Необходимо сначала выполнить левое вращение для левого поддерева
//                Left()->RotateLeft();
//            }
//            // Выполняем правое вращение для текущего узла
//            //RotateRight();
//        }
//    }
//
   



//// Программа на C++ для дерева AVL  
//using namespace std;
//
//// Узел дерева AVL 
//template <class T>
//struct AVLNode:public TreeNode<T>
//{
//    int key;
//    TreeNode<T>* left;
//    TreeNode<T>* right;
//    int depth;
//};
//
////получить максимум два целых числа 
//int max(int a, int b) {
//    return (a > b) ? a : b;
//}
//
////функция для получения высоты дерева
//template <class T>
//int depth(AVLNode<T>* n)
//{
//    if (n == NULL)
//        return 0;
//    return n->Depth();
//}
//// выделите новый узел с переданным ключом
//template <class T>
//AVLNode<T>* newNode(int key)
//{
//    AVLNode<T>* node = new AVLNode<T>();
//    node->key = key;
//    node->left = NULL;
//    node->right = NULL;
//    node->depth = 1; // новый узел добавлен как лист
//    return(node);
//}
//// поверните вправо поддерево с корнем y
//template <class T>
//AVLNode<T>* rightRotate(AVLNode<T>* y)
//{
//    AVLNode* x = y->left;
//    AVLNode* T2 = x->right;
//
//    // Выполнить вращение 
//    x->right = y;
//    y->left = T2;
//
//    // Высоты обновления  
//    y->depth = max(depth(y->left),
//        depth(y->right)) + 1;
//    x->depth = max(depth(x->left),
//        depth(x->right)) + 1;
//
//    // Вернуть новый корень 
//    return x;
//}
//
//// поворот влево дочернего дерева с корнем x 
//template <class T>
//AVLNode<T>* leftRotate(AVLNode<T>* x)
//{
//    AVLNode* y = x->right;
//    AVLNode* T2 = y->left;
//
//    // Выполнить вращение 
//    y->left = x;
//    x->right = T2;
//    // Высоты обновления
//    x->depth = max(depth(x->left),
//        depth(x->right)) + 1;
//    y->depth = max(depth(y->left),
//        depth(y->right)) + 1;
//
//    // Вернуть новый корень  
//    return y;
//}
//
//// Получить коэффициент баланса узла N 
//template <class T>
//int getBalance(AVLNode<T>* N)
//{
//    if (N == NULL)
//        return 0;
//    return depth(N->left) -
//        depth(N->right);
//}
////операция вставки для узла в дереве AVL
//template <class T>
//AVLNode<T>* insert(AVLNode<T>* node, int key) {
//    //вращение по BST
//    if (node == NULL)
//        return(newNode<T>(key));
//
//    if (key < node->key)
//        node->left = insert(node->left, key);
//    else if (key > node->key)
//        node->right = insert(node->right, key);
//    else // Одинаковые ключи не допускаются  
//        return node;
//
//    //обновить высоту узла-предка
//    node->depth = 1 + max(depth(node->left), depth(node->right));
//
//    int balance = getBalance(node);        //получить коэффициент баланса
//
//    // вращать, если несбалансирован
//
//    // Лево лево
//    if (balance > 1 && key < node->left->key)
//        return rightRotate(node);
//
//    // Право право
//    if (balance < -1 && key > node->right->key)
//        return leftRotate(node);
//    // Лево право
//    if (balance > 1 && key > node->left->key)
//    {
//        node->left = leftRotate(node->left);
//        return rightRotate(node);
//    }
//
//    // Право лево  
//    if (balance < -1 && key < node->right->key)
//    {
//        node->right = rightRotate(node->right);
//        return leftRotate(node);
//    }
//    return node;
//}
//
//// найти узел с минимальным значением 
//template <class T>
//AVLNode<T>* minValueNode(AVLNode<T>* node)
//{
//    AVLNode* current = node;
//
//    // найти крайний левый лист */
//    while (current->left != NULL)
//        current = current->left;
//
//    return current;
//}
//// удалить узел из дерева AVL с заданным ключом  
//template <class T>
//AVLNode<T>* deleteNode(AVLNode<T>* root, int key)
//{
//    if (root == NULL)
//        return root;
//
//    //удалить по BST 
//    if (key < root->key)
//        root->left = deleteNode(root->left, key);
//
//    else if (key > root->key)
//        root->right = deleteNode(root->right, key);
//
//    else
//    {
//        // узел только с одним дочерним элементом или без дочернего элемента  
//        if ((root->left == NULL) ||
//            (root->right == NULL))
//        {
//            AVLNode* temp = root->left ?
//                root->left :
//                root->right;
//
//            if (temp == NULL)
//            {
//                temp = root;
//                root = NULL;
//            }
//            else
//                *root = *temp;
//            free(temp);
//        }
//        else
//        {
//            AVLNode* temp = minValueNode(root->right);
//
//            root->key = temp->key;
//
//            // Удалить преемника по порядку 
//            root->right = deleteNode(root->right,
//                temp->key);
//        }
//    }
//
//    if (root == NULL)
//        return root;
//
//    // глубина обновления  
//    root->depth = 1 + max(depth(root->left),
//        depth(root->right));
//
//    // получить коэффициент баланса 
//    int balance = getBalance(root);
//
//    //повернуть дерево, если оно несбалансировано
//
//    // Лево лево  
//    if (balance > 1 &&
//        getBalance(root->left) >= 0)
//        return rightRotate(root);
//
//    // Лево право  
//    if (balance > 1 && getBalance(root->left) < 0) {
//        root->left = leftRotate(root->left);
//        return rightRotate(root);
//    }
//    // Право право  
//    if (balance < -1 && getBalance(root->right) <= 0)
//        return leftRotate(root);
//
//    // Право лево  
//    if (balance < -1 && getBalance(root->right) > 0) {
//        root->right = rightRotate(root->right);
//        return leftRotate(root);
//    }
//    return root;
//}
//// печатает обход дерева AVL по порядку
//template <class T>
//void inOrder(AVLNode<T>* root)
//{
//    if (root != NULL)
//    {
//        inOrder(root->left);
//        cout << root->key << " ";
//        inOrder(root->right);
//    }
//}
//
