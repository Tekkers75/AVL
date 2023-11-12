///@author Саранчин К.А.

#include <iostream>
#include "AVL_tree.h"


// основной код 
int main()
{
    
    AVLTree<int>* root = new AVLTree<int>(10);
    root->InsertNode(root, 5);
    root->InsertNode(root, 6);
    root->InsertNode(root, 89);
    root->InsertNode(root, 56);
    root->InsertNode(root, 2);
    root->InsertNode(root, 58);
    root->InsertNode(root, 7);
    root->InsertNode(root, 23);
    root->InOrderTraversal(root);
    std::cout << endl;
    std::cout << endl;
    root->PrintTree(root, 0);
    root->RotateLeft(root);


    return 0;
}
