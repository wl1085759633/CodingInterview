#include<cstdio>
#include "Tree.h"
//创建节点
BinaryTreeNode* CreateBinaryTreeNode(int value){
    BinaryTreeNode* node = new BinaryTreeNode();
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;

    return node;
}

//连接节点
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight){
    if(pParent == nullptr)
        return;
    pParent->left = pLeft;
    pParent->right = pRight;
}

//打印节点
void PrintTreeNode(const BinaryTreeNode* pNode){
    if(pNode != nullptr){
        printf("the node value is %d\n", pNode->value);
        if(pNode->left)
            printf("the left child value is %d\n", pNode->left->value);
        if(pNode->right)
            printf("the right child value is %d\n", pNode->right->value);
    }
    else
        printf("the node is null\n");
}

//打印树
void PrintTree(const BinaryTreeNode* pRoot){
    PrintTreeNode(pRoot);
    if(pRoot){
        if(pRoot->left)
            PrintTree(pRoot->left);
        if(pRoot->right)
            PrintTree(pRoot->right);    
    }
}

//销毁树
void DestroyTree(BinaryTreeNode* pRoot){
    if(pRoot != nullptr){
        DestroyTree(pRoot->left);
        DestroyTree(pRoot->right);

        delete pRoot;
        pRoot = nullptr;
    }
}