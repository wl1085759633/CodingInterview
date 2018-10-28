struct BinaryTreeNode{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};
//创建树节点
BinaryTreeNode* CreateTreeNode(int value);
//连接节点
void ConnectTreeNode(BinaryTreeNode* parent, BinaryTreeNode* left, BinaryTreeNode* right);
//打印节点
void PrintNode(BinaryTreeNode* node);
//打印树
void PrintBinaryTree(BinaryTreeNode* root);
//销毁树
void DestroyBinaryTree(BinaryTreeNode* root);