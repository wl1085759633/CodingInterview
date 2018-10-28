#include<cstdio>
#include "List.h"
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k){
    if(pListHead == nullptr || k == 0)
        return nullptr;
    ListNode* first = pListHead;
    ListNode* second = pListHead;
    for(int i = 0; i < k-1; i++){
        if(first->next)
            first = first->next;
        else{
             printf("链表长度小于k\n");
             return nullptr;
        }
    }
    while(first->next){
        first = first->next;
        second = second->next;
    }
    return second;
}

void test(){
    //构建链表
    ListNode* node1 = CreateNode(1);
    ListNode* node2 = CreateNode(2);
    ListNode* node3 = CreateNode(3);
    ListNode* node4 = CreateNode(4);
    ListNode* node5 = CreateNode(5);

    ConncetNode(node1, node2);
    ConncetNode(node2, node3);
    ConncetNode(node3, node4);
    ConncetNode(node4, node5);  

    //调用函数
    ListNode* kNode = FindKthToTail(node1, 6);
    //打印节点
    PrintNode(kNode);
}

int main()
{
    test();
    getchar();
    return 0;
}