struct BinaryTreeNode{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

//创建节点
BinaryTreeNode* CreateBinaryTreeNode(int value);
//连接节点
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight);
//打印节点
void PrintTreeNode(const BinaryTreeNode* pNode);
//打印树
void PrintTree(const BinaryTreeNode* pRoot);
//销毁树
void DestroyTree(BinaryTreeNode* pRoot);