#include<cstdio>
#include<iostream>
#include<exception>
using namespace std;
struct BinaryTreeNode{
    BinaryTreeNode* left;
    int value;
    BinaryTreeNode* right;
};
void PrintTreeNode(const BinaryTreeNode* root){
    if(root){
        printf("value of this node is:%d\n",root->value);
        if(root->left)
            printf("value of its left child is:%d\n",root->left->value);
        else
            printf("left child is nullptr.\n");
        
        if(root->right)
            printf("value of its right child is:%d\n",root->right->value);
        else
            printf("right child is nullptr.\n");
    }else{
        printf("this node is nullptr.\n");
    }
}
void printTree(const BinaryTreeNode* root){
    PrintTreeNode(root);
    
    if(root != nullptr){
        if(root->left)
            printTree(root->left);
        if(root->right)
            printTree(root->right);
    }
}
BinaryTreeNode* ConstructBinaryTreeCore(int* preOrderStart, int* preOrderEnd, int* inOrderStart, int* inOrderEnd){
    BinaryTreeNode* root = new BinaryTreeNode();
    root->left = root->right = nullptr;
    root->value = preOrderStart[0];

    if(preOrderStart == preOrderEnd){
        if(inOrderStart == inOrderEnd && *inOrderStart == root->value){
            return root;
        }
        else{
            logic_error ex("Invalid Input!");
            throw std::exception(ex);
        }
    }

    //找到根节点在中序遍历的位置
    int* inOrderroot = inOrderStart;
    while(inOrderroot <= inOrderEnd && *inOrderroot != root->value){
        inOrderroot++;
    }
    if(inOrderroot == inOrderEnd && *inOrderroot != root->value){
            logic_error ex("Invalid Input!");
            throw std::exception(ex);
    }
    int left_length = inOrderroot - inOrderStart;
    if(left_length > 0){
        root->left = ConstructBinaryTreeCore(preOrderStart+1, preOrderStart+left_length, inOrderStart, inOrderroot-1);
    }
    if(inOrderEnd-inOrderroot > 0){
        root->right = ConstructBinaryTreeCore(preOrderStart+left_length+1, preOrderEnd, inOrderroot+1, inOrderEnd);
    }

    return root;

}

BinaryTreeNode* ConstructBinaryTree(int* preOrder, int* inOrder, int length){
    if(preOrder == nullptr || inOrder == nullptr || length <= 0){
        return nullptr;
    }

    return ConstructBinaryTreeCore(preOrder, preOrder+length-1, inOrder, inOrder+length-1);
}

void test(char* name, int* preOder, int* inOrder, int length){
    printf("%s:start\n", name);
    BinaryTreeNode* root = ConstructBinaryTree(preOder, inOrder, length);
    printTree(root);
    printf("%s:end\n", name);
}

//完全二叉树
void test1(){
    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    test("test1", preorder, inorder, 7);
}

//不完全二叉树
void test2(){
    int preorder[] = {1, 2, 4, 5, 3, 6};
    int inorder[] = {4, 2, 5, 1, 6, 3};
    test("test2", preorder, inorder, 6);
}

//所有节点都没有左子节点的二叉树
void test3(){
    int preorder[] = {1, 2, 3, 4};
    int inorder[] = {1, 2, 3, 4};
    test("test3", preorder, inorder, 4);
}

//所有节点都没有右子节点的二叉树
void test4(){
    int preorder[] = {1, 2, 3, 4};
    int inorder[] = {4, 3, 2, 1};
    test("test4", preorder, inorder, 4);
}

//只有一个节点的二叉树
void test5(){
    int preorder[] = {1};
    int inorder[] = {1};
    test("test5", preorder, inorder, 1);
}

//二叉树的根节点指针为null
void test6(){
    test("test6", nullptr, nullptr, 0);
}

//输入前序遍历和中序遍历不匹配
void test7(){
    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[] = {1, 2, 3, 4, 5, 6, 7};
    test("test7", preorder, inorder, 7);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    getchar();
    return 0;
}