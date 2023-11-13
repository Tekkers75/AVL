///@author Саранчин К.А.

#include <iostream>
#include "AVL_tree.h"
#include "BTree.h"


// основной код 
int main()
{

    AVLTreeNode<int>* root1 = new AVLTreeNode<int>(15);
    root1->left = new AVLTreeNode<int>(4);
    root1->left->left = new AVLTreeNode<int>(4);
    root1->left->left->left = new AVLTreeNode<int>(4);
    root1->right = new AVLTreeNode<int>(5);
    root1->right->right = new AVLTreeNode<int>(54);
    PrintTree(root1, 0);
    std::cout << endl;
    AVLTree<int>* root = new AVLTree<int>();
    //root->RotateLeft(root1);
    
    //cout << endl;
    //root->RotateRight(root1);
    //root->RotateRight(root1);
    //root->RotateLeft(root1);
    root->Balance(root1);
    //root->InsertNode(root1, 20);
    //root->InsertNode(root1, 50);
    //root->InsertNode(root1, 5);
    //root->InsertNode(root1, 40);
    //root->InsertNode(root1, 52);
    //root->InsertNode(root1, 76);
    PrintTree(root1, 0);
    std::cout << endl;
    std::cout << root1->height;
    std::cout << endl;
    std::cout << root1->balanceFactor;

    //AVLTree<int>* root = new AVLTree<int>();
    //root->InsertNode(root, 5);
    //root->InsertNode(root, 6);
    //root->InsertNode(root, 89);
    //root->InsertNode(root, 56);
    //root->InsertNode(root, 2);
    //root->InsertNode(root, 58);
    //root->InsertNode(root, 7);
    //root->InsertNode(root, 23);
    //root->InOrderTraversal(root);
    //std::cout << endl;
    //std::cout << endl;
    //root->PrintTree(root, 0);
    //root->RotateLeft(root);


    return 0;
}
