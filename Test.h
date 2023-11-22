#pragma once

//@author Саранчин К.А.

#include"AVL_tree.h"
#include <cassert>
#include <iostream>
// тестовое дерево
template <class T>
AVLTreeNode<T>* CreateAVLTree() {

    //     4
    //    / \
    //  2     5
    // / \
    //1   3
    // Создаем узлы для тестирования
    AVLTreeNode<T>* node1 = new AVLTreeNode<T>(1);
    AVLTreeNode<T>* node2 = new AVLTreeNode<T>(2);
    AVLTreeNode<T>* node3 = new AVLTreeNode<T>(3);
    AVLTreeNode<T>* node4 = new AVLTreeNode<T>(4);
    AVLTreeNode<T>* node5 = new AVLTreeNode<T>(5);

    // Строим дерево
    node2->SetLeft(node1);
    node2->SetRight(node3);
    node4->SetLeft(node2);
    node4->SetRight(node5);

    return node4; // Возвращаем корневой узел дерева
}
//тестовое вырожденное вправо дерево
template <class T>
AVLTreeNode<T>* CreateRightAVLTree() {
    // Создаем узлы для тестирования
    AVLTreeNode<int>* node1 = new AVLTreeNode<int>(1);
    AVLTreeNode<int>* node2 = new AVLTreeNode<int>(2);
    AVLTreeNode<int>* node3 = new AVLTreeNode<int>(3);

    // Строим дерево
    node1->SetRight(node2);
    node2->SetRight(node3);
    return node1;
}
//тестовое вырожденное влево дерево
template <class T>
AVLTreeNode<T>* CreateLeftAVLTree() {
    // Создаем узлы для тестирования
    AVLTreeNode<int>* node1 = new AVLTreeNode<int>(3);
    AVLTreeNode<int>* node2 = new AVLTreeNode<int>(2);
    AVLTreeNode<int>* node3 = new AVLTreeNode<int>(1);

    // Строим дерево
    node1->SetLeft(node2);
    node2->SetLeft(node3);
    return node1;
}
//тестирование получения высоты
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

    //освобождаем память
    DeleteTree(r);
    DeleteTree(r1);
    DeleteTree(r2);

    cout << "Тест получения высоты пройден" << endl;
}
//тестирование получения баланса
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

    //освобождаем память
    DeleteTree(r);
    DeleteTree(r1);
    DeleteTree(r2);

    cout << "Тест получения баланса пройден" << endl;
}
//тестирование левого поворота
void TestRotateLeft() {
    AVLTreeNode<int>* r1 = CreateRightAVLTree<int>();
    //Поворачиваем дерево влево
    AVLTreeNode<int>* newRoot = r1->RotateLeft(r1);

    // Проверяем новую структуру дерева
    assert(newRoot->data == 2);
    assert(newRoot->Left()->data == 1);
    assert(newRoot->Right()->data == 3);
    //освобождаем память
    DeleteTree(r1);

    cout << "Тест левого поворота пройден" << endl;
}
//тестирование правого поворота
void TestRotateRight() {
    AVLTreeNode<int>* r1 = CreateLeftAVLTree<int>();
    //Поворачиваем дерево вправо
    AVLTreeNode<int>* newRoot = r1->RotateRight(r1);

    // Проверяем новую структуру дерева
    assert(newRoot->data == 2);
    assert(newRoot->Left()->data == 1);
    assert(newRoot->Right()->data == 3);
    //освобождаем память
    DeleteTree(r1);

    cout << "Тест правого поворота пройден" << endl;
}
//тестирование балансировки дерева
void TestBalanceTree() {
    // Проверка перебалансировки на правом дереве
    AVLTreeNode<int>* rightTree = CreateRightAVLTree<int>();
    //Поворачиваем дерево влево
    AVLTreeNode<int>* newRoot = rightTree->BalanceTree(rightTree);


    // Проверяем структуру дерева после перебалансировки
    assert(newRoot->data == 2);
    assert(newRoot->Left()->data == 1);
    assert(newRoot->Right()->data == 3);


    // Проверка перебалансировки на левом дереве
    AVLTreeNode<int>* leftTree = CreateLeftAVLTree<int>();
    AVLTreeNode<int>* newRoot1 = leftTree->BalanceTree(leftTree);

    // Проверяем структуру дерева после перебалансировки
    assert(newRoot1->data == 2);
    assert(newRoot1->Left()->data == 1);
    assert(newRoot1->Right()->data == 3);
    //освобождаем память
    DeleteTree(rightTree);
    DeleteTree(leftTree);

    cout << "Тест перебалансировки пройден" << endl;
}
//тестирование добавления новых узлов
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
       // Создаем корень дерева
    AVLTreeNode<int>* root = new AVLTreeNode<int>(7);

    // Добавляем узлы в дерево
    root->AddNodeAVL(4);
    root->AddNodeAVL(8);
    root->AddNodeAVL(2);
    root->AddNodeAVL(9);
    root->AddNodeAVL(10);
    root->AddNodeAVL(11);
    //root->BalanceTree(root);

    // Проверяем структуру дерева и балансировку
    assert(root->data == 7);
    assert(root->Left()->data == 4);
    assert(root->Right()->data == 9);
    assert(root->Left()->Left()->data == 2);
    assert(root->Right()->Right()->data == 10);
    assert(root->Right()->Left()->data == 8);
    assert(root->Right()->Right()->Right()->data == 11);
    //освобождаем память
    DeleteTree(root);

    // Тестирование добавления на пустом дереве
    AVLTreeNode<int>* emptyTree = nullptr;
    emptyTree = emptyTree->AddNodeAVL(1);

    assert(emptyTree != nullptr); // Если узел добавился=>дерево не пустое
    //освобождаем память
    DeleteTree(emptyTree);

    cout << "Тест добавления новых узлов пройден" << endl;
}
//тестирование удаления
void TestRemove() {
    //     4
    //    / \
    //  2     5
    // / \
    //1   3
     // Создаем AVL-дерево
    AVLTreeNode<int>* avlTree = CreateAVLTree<int>();
    // Удаляем узtk из дерева
    AVLTreeNode<int>* newRoot1 = avlTree->Remove(3);


    // Проверяем структуру дерева после удаления
    assert(newRoot1->data == 4);
    assert(newRoot1->Left()->data == 2);
    assert(newRoot1->Right()->data == 5);


    // Удаляем узел из дерева
    AVLTreeNode<int>* newRoot2 = avlTree->Remove(5);

    // Проверяем структуру дерева после удаления
    assert(newRoot2->data == 2);
    assert(newRoot2->Left()->data == 1);
    assert(newRoot2->Right()->data == 4);
    // Освобождаем память
    DeleteTree(avlTree);

    // Тестирование удаления на пустом дереве
    AVLTreeNode<int>* emptyTree = nullptr;
    emptyTree = emptyTree->Remove(1); // Удаление на пустом дереве

    assert(emptyTree == nullptr); // Должно быть nullptr


    //освобождаем память
    DeleteTree(emptyTree);

    cout << "Тест удаления узлов пройден" << endl;
}

