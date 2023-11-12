//#pragma once
/////@author �������� �.�.
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

 

    //���������� ����� ��������
    const int indentBlock = 6;
    //�������� num�������� � ������� ������
    void IndentBlanks(int num) {
        for (int i = 0; i < num; i++)
            cout << "  ";
    }

    //������ ������ �����,��������� RNL- �����������
    template<class T>
    void PrintTree(AVLTree<T>* node, int level) {
        //�������� ������ ������ ���� node, ���� �� �� ����� nullptr
        if (node != nullptr)
        {
            //�������� ������ ��������� ���� node
            PrintTree(node->right, level + 1);
            //��������� ������� ������� � ������� ���� ������
            IndentBlanks(indentBlock * level);
            cout << node->data << endl;
            //�������� ����� ��������� ���� node
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

        // ���������� ������ � ������� ����
        node->height = std::max(Height(node->left), Height(node->right)) + 1;
        node->balanceFactor = Height(node->left) - Height(node->right);

        // ������������ ������
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
    //        // ���������� ������ � ������� ����
    //        node->height = std::max(Height(node->left), Height(node->right)) + 1;
    //        node->balanceFactor = Height(node->left) - Height(node->right);

    //        // ������������ ������
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
    //        // ���������� ������ � ������� ����
    //        node->height = std::max(Height(node->left), Height(node->right)) + 1;
    //        node->balanceFactor = Height(node->left) - Height(node->right);

    //        // ������������ ������
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

    //    // ���������� ����� ��������� �� pivot �� ������ ������� �������� ����
    //    this->right = pivot->left;
    //    if (pivot->left != nullptr)
    //        pivot->left->parent = this;

    //    // �������� �������� ���� ���������� ��������� pivot
    //    pivot->parent = this->parent;
    //    if (this->parent != nullptr) {
    //        if (this->parent->left == this)
    //            this->parent->left = pivot;
    //        else
    //            this->parent->right = pivot;
    //    }

    //    // ������� ���� ���������� ����� �������� pivot
    //    pivot->left = this;
    //    this->parent = pivot;

    //    // ��������� ������ �����
    //    this->UpdateHeight();
    //    pivot->UpdateHeight();
    //}

    //void RotateRight()
    //{
    //    AVLTree<T>* pivot = this->left;
    //    if (pivot == nullptr)
    //        return;

    //    // ���������� ������ ��������� �� pivot �� ����� ������� �������� ����
    //    this->left = pivot->right;
    //    if (pivot->right != nullptr)
    //        pivot->right->parent = this;

    //    // �������� �������� ���� ���������� ��������� pivot
    //    pivot->parent = this->parent;
    //    if (this->parent != nullptr) {
    //        if (this->parent->left == this)
    //            this->parent->left = pivot;
    //        else
    //            this->parent->right = pivot;
    //    }

    //    // ������� ���� ���������� ������ �������� pivot
    //    pivot->right = this;
    //    this->parent = pivot;

    //    // ��������� ������ �����
    //    this->UpdateHeight();
    //    pivot->UpdateHeight();
    //}

    //void UpdateHeight()
    //{
    //    // ��������� ������ �������� ���� �� ������ ����� ��� �����������
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
//        // ��������� ������ �������� ���� �� ������ ����� ��� �����������
//        int leftHeight = (this->left != nullptr) ? this->left->height : -1;
//        int rightHeight = (this->right != nullptr) ? this->right->height : -1;
//        this->height = std::max(leftHeight, rightHeight) + 1;
//    }
//
//    template <class T>
//    void RotateLeft()
//    {
//        // ��������� ����� �������� ��� �������� ����
//        AVL_tree<T>* newRoot = this->Right();
//        this->right = newRoot->Left();
//        newRoot->left = this;
//        this->UpdateHeight();
//        newRoot->UpdateHeight();
//
//        // ��������� ��������� �� ������� ���� ��� ��� ��������
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
//        // ��������� ������ �������� ��� �������� ����
//        AVL_tree<T>* newRoot = this->Left();
//        this->left = newRoot->Right();
//        newRoot->right = this;
//        this->UpdateHeight();
//        newRoot->UpdateHeight();
//
//        // ��������� ��������� �� ������� ���� ��� ��� ��������
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
//        // ��������� ������ �������� ����
//        UpdateHeight();
//
//        // ��������� ������-������ �������� ����
//        int balanceFactor = GetBalanceFactor();
//
//        // ���� ������-������ ������ 1, ������ ������ ���������������� �����
//        if (balanceFactor > 1) {
//            // ����������, ����� �� ��������� ��������� ��� ������� ��������
//            if (Right()->GetBalanceFactor() < 0) {
//                // ���������� ������� ��������� ������ �������� ��� ������� ���������
//                Right()->RotateRight();
//            }
//            // ��������� ����� �������� ��� �������� ����
//            //RotateLeft();
//        }
//        // ���� ������-������ ������ -1, ������ ������ ���������������� ������
//        else if (balanceFactor < -1) {
//            // ����������, ����� �� ��������� ��������� ��� ������� ��������
//            if (Left()->GetBalanceFactor() > 0) {
//                // ���������� ������� ��������� ����� �������� ��� ������ ���������
//                Left()->RotateLeft();
//            }
//            // ��������� ������ �������� ��� �������� ����
//            //RotateRight();
//        }
//    }
//
   



//// ��������� �� C++ ��� ������ AVL  
//using namespace std;
//
//// ���� ������ AVL 
//template <class T>
//struct AVLNode:public TreeNode<T>
//{
//    int key;
//    TreeNode<T>* left;
//    TreeNode<T>* right;
//    int depth;
//};
//
////�������� �������� ��� ����� ����� 
//int max(int a, int b) {
//    return (a > b) ? a : b;
//}
//
////������� ��� ��������� ������ ������
//template <class T>
//int depth(AVLNode<T>* n)
//{
//    if (n == NULL)
//        return 0;
//    return n->Depth();
//}
//// �������� ����� ���� � ���������� ������
//template <class T>
//AVLNode<T>* newNode(int key)
//{
//    AVLNode<T>* node = new AVLNode<T>();
//    node->key = key;
//    node->left = NULL;
//    node->right = NULL;
//    node->depth = 1; // ����� ���� �������� ��� ����
//    return(node);
//}
//// ��������� ������ ��������� � ������ y
//template <class T>
//AVLNode<T>* rightRotate(AVLNode<T>* y)
//{
//    AVLNode* x = y->left;
//    AVLNode* T2 = x->right;
//
//    // ��������� �������� 
//    x->right = y;
//    y->left = T2;
//
//    // ������ ����������  
//    y->depth = max(depth(y->left),
//        depth(y->right)) + 1;
//    x->depth = max(depth(x->left),
//        depth(x->right)) + 1;
//
//    // ������� ����� ������ 
//    return x;
//}
//
//// ������� ����� ��������� ������ � ������ x 
//template <class T>
//AVLNode<T>* leftRotate(AVLNode<T>* x)
//{
//    AVLNode* y = x->right;
//    AVLNode* T2 = y->left;
//
//    // ��������� �������� 
//    y->left = x;
//    x->right = T2;
//    // ������ ����������
//    x->depth = max(depth(x->left),
//        depth(x->right)) + 1;
//    y->depth = max(depth(y->left),
//        depth(y->right)) + 1;
//
//    // ������� ����� ������  
//    return y;
//}
//
//// �������� ����������� ������� ���� N 
//template <class T>
//int getBalance(AVLNode<T>* N)
//{
//    if (N == NULL)
//        return 0;
//    return depth(N->left) -
//        depth(N->right);
//}
////�������� ������� ��� ���� � ������ AVL
//template <class T>
//AVLNode<T>* insert(AVLNode<T>* node, int key) {
//    //�������� �� BST
//    if (node == NULL)
//        return(newNode<T>(key));
//
//    if (key < node->key)
//        node->left = insert(node->left, key);
//    else if (key > node->key)
//        node->right = insert(node->right, key);
//    else // ���������� ����� �� �����������  
//        return node;
//
//    //�������� ������ ����-������
//    node->depth = 1 + max(depth(node->left), depth(node->right));
//
//    int balance = getBalance(node);        //�������� ����������� �������
//
//    // �������, ���� ���������������
//
//    // ���� ����
//    if (balance > 1 && key < node->left->key)
//        return rightRotate(node);
//
//    // ����� �����
//    if (balance < -1 && key > node->right->key)
//        return leftRotate(node);
//    // ���� �����
//    if (balance > 1 && key > node->left->key)
//    {
//        node->left = leftRotate(node->left);
//        return rightRotate(node);
//    }
//
//    // ����� ����  
//    if (balance < -1 && key < node->right->key)
//    {
//        node->right = rightRotate(node->right);
//        return leftRotate(node);
//    }
//    return node;
//}
//
//// ����� ���� � ����������� ��������� 
//template <class T>
//AVLNode<T>* minValueNode(AVLNode<T>* node)
//{
//    AVLNode* current = node;
//
//    // ����� ������� ����� ���� */
//    while (current->left != NULL)
//        current = current->left;
//
//    return current;
//}
//// ������� ���� �� ������ AVL � �������� ������  
//template <class T>
//AVLNode<T>* deleteNode(AVLNode<T>* root, int key)
//{
//    if (root == NULL)
//        return root;
//
//    //������� �� BST 
//    if (key < root->key)
//        root->left = deleteNode(root->left, key);
//
//    else if (key > root->key)
//        root->right = deleteNode(root->right, key);
//
//    else
//    {
//        // ���� ������ � ����� �������� ��������� ��� ��� ��������� ��������  
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
//            // ������� ��������� �� ������� 
//            root->right = deleteNode(root->right,
//                temp->key);
//        }
//    }
//
//    if (root == NULL)
//        return root;
//
//    // ������� ����������  
//    root->depth = 1 + max(depth(root->left),
//        depth(root->right));
//
//    // �������� ����������� ������� 
//    int balance = getBalance(root);
//
//    //��������� ������, ���� ��� ����������������
//
//    // ���� ����  
//    if (balance > 1 &&
//        getBalance(root->left) >= 0)
//        return rightRotate(root);
//
//    // ���� �����  
//    if (balance > 1 && getBalance(root->left) < 0) {
//        root->left = leftRotate(root->left);
//        return rightRotate(root);
//    }
//    // ����� �����  
//    if (balance < -1 && getBalance(root->right) <= 0)
//        return leftRotate(root);
//
//    // ����� ����  
//    if (balance < -1 && getBalance(root->right) > 0) {
//        root->right = rightRotate(root->right);
//        return leftRotate(root);
//    }
//    return root;
//}
//// �������� ����� ������ AVL �� �������
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
