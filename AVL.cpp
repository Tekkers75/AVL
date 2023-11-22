///@author Саранчин К.А.

#include <iostream>
#include "AVL_tree.h"
#include "BTree.h"
#include "Test.h"
#include "AVLTreeNode.h"


// основной код 
int main()
{
    setlocale(LC_ALL, "ru");

    AVLTree<int>* avlTree = new AVLTree<int>(25);
    // AVLTreeNode<int>* a = new AVLTreeNode<int>(5,nullptr,nullptr);
    //
    // Вставка элементов в AVL-дерево
    avlTree->Insert(20);
    avlTree->Insert(30);

    avlTree->Insert(40);
    avlTree->Insert(56);
    avlTree->Insert(32);
    avlTree->PrintTreeAVL();
    avlTree->Insert(54);
    avlTree->Remove(40);

    avlTree->PrintTreeAVL();
    //    //     4
    //   //    / \
    //    //  2     5
    //    // / \
    //    //1   3

    //AVLTree<int>* avlTree1 = new AVLTree<int>(4);
    //avlTree1->Insert(2);
    //avlTree1->Insert(5);

    //avlTree1->Insert(1);
    //avlTree1->Insert(3);

    //avlTree1->Remove(3);
    //avlTree1->Remove(5);
    //avlTree1->PrintTreeAVL();
    avlTree->Remove(30);
    // a->left = new AVLTreeNode<int>(10,nullptr,nullptr);
    // //avlTree->Insert(3);
    // //avlTree->Insert(7);
    //// avlTree->RemoveNode(7);
    // 
    // avlTree->RotateRight(a);
    avlTree->PrintTreeAVL();
    cout << "Искомый элемент находится на уровне: " << avlTree->Find(25) << endl;
    cout << endl;
    cout << "Высота дерева = " << avlTree->Height() << endl;
    cout << "Количество узлов в дереве = " << avlTree->CountNode() << endl;

    cout << "LNR обход: " << endl;
    int* arr = new int[avlTree->CountNode()];
    avlTree->AddNodesToArray(arr);
    for (int i = 0; i < avlTree->CountNode(); i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;

    TestGetHeight();
    TestGetBalanceFactor();
    TestRotateLeft();
    TestRotateRight();
    TestAddNodeAVL();
    TestBalanceTree();
    TestRemove();
    //AVLTreeNode<int>* root1 = new AVLTreeNode<int>(15);
    //root1->left = new AVLTreeNode<int>(4);
    //root1->left->left = new AVLTreeNode<int>(4);
    //root1->left->left->left = new AVLTreeNode<int>(4);
    //root1->right = new AVLTreeNode<int>(5);

    //PrintTree(root1, 0);
    //cout<< endl;
    //cout << endl;
    //cout << endl;
    //cout << endl;

  //  AVLTree<int>* root = new AVLTree<int>();
  //  //root->RotateRight(root1);
  //  //PrintTree(root1, 0);


  //  AVLTreeNode<int>* root2 = new AVLTreeNode<int>(15);
  //  root2->right = new AVLTreeNode<int>(20);
  //  root2->right->right = new AVLTreeNode<int>(25);
  //  PrintTree(root2, 0);

  ////  cout << root->GetHeight(root2);
  //  cout << endl; cout << endl; cout << endl; cout << endl;
  //  //root->RotateLeft(root2);
  //  PrintTree(root2, 0);

    //AVLTree<int>* ROOT = new AVLTree<int>();
    //AVLTreeNode<int>* root3 = new AVLTreeNode<int>(15);
    //root3->left = new AVLTreeNode<int>(4);
    //root3->left->left = new AVLTreeNode<int>(2);
    //root3->left->right = new AVLTreeNode<int>(8);
    //root3->right = new AVLTreeNode<int>(20);
    //root3->right->left = new AVLTreeNode<int>(17);
    //root3->right->right = new AVLTreeNode<int>(25);
    //PrintTree(root3, 0);
    //cout<<ROOT->GetBalanceFactor(root3);
   /// AVLTreeNode<int>* root1 = new AVLTreeNode<int>(15,nullptr,nullptr);
   //// PrintTree(root1, 0);

    return 0;
}




//  AVLTreeNode<int>* root1 = new AVLTreeNode<int>(15);
///*  root1->left = new AVLTreeNode<int>(6);
//  root1->left->left = new AVLTreeNode<int>(8);
//  root1->left->left->left = new AVLTreeNode<int>(9);
//  root1->right = new AVLTreeNode<int>(5);
//  root1->right->right = new AVLTreeNode<int>(54);*/
//  PrintTree(root1, 0);
//  std::cout << endl;
//  //AVLTree<int>* root = new AVLTree<int>();

//  AVLTree<int> root;
//  //root->RotateLeft(root1);
//  
//  //cout << endl;
//  //root->RotateRight(root1);
//  //root->RotateRight(root1);
//  //root->RotateLeft(root1);
//  //root->Balance(root1);
// 
//  root.InsertNode(root.root, 10);
//  root.InsertNode(root.root, 52);
//  //root->InsertNode(root1, 31);
//  //root->InsertNode(root1, 12);
//  //root->InsertNode(root1, 11);
//  //root->InsertNode(root1, 16);
//  //root->Balance((dynamic_cast<AVLTreeNode<int>*>(root1->right)));
//  //root->InsertNode(root1, 50);
//  //root->InsertNode(root1, 5);
//  //root->InsertNode(root1, 40);
//  //root->InsertNode(root1, 52);
//  //root->InsertNode(root1, 76);
//  //std::cout << root->Height(root1);
//  PrintTree(root1, 0);
//  std::cout << endl;
//  std::cout << root1->height;
//  std::cout << endl;
//  std::cout << root1->balanceFactor;

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

  //AVLTree<int> avlTree;
  //avlTree.InsertNode(avlTree.root, 5);
  //avlTree.InsertNode(avlTree.root, 3);
  //avlTree.InsertNode(avlTree.root, 7);
  //avlTree.InsertNode(avlTree.root, 2);
  //avlTree.InsertNode(avlTree.root, 4);
  //avlTree.InsertNode(avlTree.root, 6);
  //avlTree.InsertNode(avlTree.root, 8);

  //avlTree.PrintTree(avlTree.root);
