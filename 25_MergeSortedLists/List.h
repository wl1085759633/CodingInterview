struct ListNode{
    int value;
    ListNode* next;
};

//创建节点
ListNode* CreateNode(int value);
//连接节点
bool ConncetNode(ListNode* node1, ListNode* node2);
//打印节点
void PrintNode(ListNode* node);
//打印链表
void PrintList(ListNode* head);
//销毁链表
void DestroyList(ListNode* head);
//添加节点
void addToTail(ListNode** phead, int value);
//删除节点
void RemoveNode(ListNode** phead, int value);