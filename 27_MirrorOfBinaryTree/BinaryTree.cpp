#include "BinaryTree.h"
#include<cstdio>

//创建树节点
BinaryTreeNode* CreateTreeNode(int value){
    BinaryTreeNode* node = new BinaryTreeNode();
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

//连接节点
void ConnectTreeNode(BinaryTreeNode* parent, BinaryTreeNode* left, BinaryTreeNode* right){
    if(parent){
        parent->left = left;
        parent->right = right;
    }
}

//打印节点
void PrintNode(BinaryTreeNode* node){
    if(node){
        printf("the node key is %d\n", node->value);
        if(node->left){
            printf("the node's left child value is %d\n", node->left->value);
        }
        else{
            printf("the node's left child is null\n");
        }

        if(node->right){
            printf("the node's right child value is %d\n", node->right->value);
        }
        else{
            printf("the node's right child is null\n");
        }
    }else{
        printf("the node is null\n");
    }
}

//打印树
void PrintBinaryTree(BinaryTreeNode* root){
    if(root){
        PrintNode(root);
        if(root->left){
            PrintBinaryTree(root->left);
        }
        if(root->right){
            PrintBinaryTree(root->right);
        }
    }
    else{
        printf("the tree is null\n");
    }
}

//销毁树
void DestroyBinaryTree(BinaryTreeNode* root){
    if(root){
        if(root->left)
            DestroyBinaryTree(root->left);
        if(root->right)
            DestroyBinaryTree(root->right);
        delete root;
        root = nullptr;
    }
}