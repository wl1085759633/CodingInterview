#include<cstdio>
#include "BinaryTree.h"

void MirrorOfBinaryTree(BinaryTreeNode* root){
    if(root == nullptr)
        return;
    if(root->left == nullptr && root->right == nullptr)
        return;
    BinaryTreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    if(root->left)
        MirrorOfBinaryTree(root->left);
    if(root->right)
        MirrorOfBinaryTree(root->right);
}

//普通二叉树
void test1(){
    BinaryTreeNode* node1 = CreateTreeNode(1);
    BinaryTreeNode* node2 = CreateTreeNode(2);
    BinaryTreeNode* node3 = CreateTreeNode(3);
    BinaryTreeNode* node4 = CreateTreeNode(4);
    BinaryTreeNode* node5 = CreateTreeNode(5);

    ConnectTreeNode(node1, node2, node3);
    ConnectTreeNode(node2, node4, node5);

    printf("test1 start\n");
    PrintBinaryTree(node1);
    MirrorOfBinaryTree(node1);
    PrintBinaryTree(node1);
    printf("test1 end\n");
}

//所有节点没有左子树
void test2(){

}

//所有节点没有右子树
void test3(){

}

//只有一个节点的二叉树
void test4(){

}

//空树
void test5(){

}

int main(int argc, char** argv){

    test1();
    //test2();
    //test3();
    //test4();
    //test5();

    getchar();
    return 0;
}