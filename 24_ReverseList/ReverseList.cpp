#include<cstdio>
#include "List.h"

ListNode* ReverseList(ListNode* pHead){
    ListNode* pReversedHead = nullptr;
    ListNode* pNode = pHead;
    ListNode* pPrev = nullptr;
    ListNode* pNext = nullptr;
    while(pNode){
        pNext = pNode->next;
        if(pNext == nullptr)
            pReversedHead = pNode;
        pNode->next = pPrev;
        pPrev = pNode;
        pNode = pNext;
    }
    return pReversedHead;
}

void test(){
    ListNode* node1 = CreateNode(1);
    ListNode* node2 = CreateNode(2);
    ListNode* node3 = CreateNode(3);
    ListNode* node4 = CreateNode(4);

    ConncetNode(node1, node2);
    ConncetNode(node2, node3);
    ConncetNode(node3, node4);

    ListNode* reversedhead = ReverseList(node1);
    PrintNode(reversedhead);
}

int main(int argc, char** argv){
    test();
    getchar();
    return 0;
}