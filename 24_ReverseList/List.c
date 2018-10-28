#include "List.h"
#include<cstdio>
#include<cstdlib>

//创建节点
ListNode* CreateNode(int value){
    ListNode* node = new ListNode();
    node->value = value;
    node->next = nullptr;
    return node;
}

//连接节点
bool ConncetNode(ListNode* node1, ListNode* node2){
    if(node1 == nullptr || node2 == nullptr)
        return false;
    node1->next = node2;
}

//打印节点
void PrintNode(ListNode* node){
    if(node == nullptr)
        return;
    printf("the node value is %d\n", node->value);
}

//打印链表
void PrintList(ListNode* head){
    if(head == nullptr){
        printf("链表为空\n");
        return;
    }
    ListNode* pNode = head;
    while(pNode){
        printf("%d\t", pNode->value);
        pNode = pNode->next;
    }
    printf("\n");
}

//销毁链表
void DestroyList(ListNode* head){
    if(head == nullptr){
        printf("链表为空\n");
        return;
    }
    ListNode* pNode = head;
    while(pNode){
        head = pNode->next;
        delete pNode;
        pNode = head;
    }
}

//添加节点
void addToTail(ListNode** phead, int value){
    if(phead == nullptr)
        return;
    ListNode* node = new ListNode();
    if(node == nullptr){
        printf("内存申请错误\n");
        return;
    }
    node->value = value;
    node->next = nullptr;

    if(*phead == nullptr){
        *phead = node;
    }
    else{
        ListNode* pNode = *phead;
        while(pNode->next != nullptr)
            pNode = pNode->next;
        pNode->next = node;
    }
}

//删除节点
void RemoveNode(ListNode** phead, int value){
    if(phead == nullptr || *phead == nullptr)
        return;
    ListNode* pDelete = nullptr;
    if((*phead)->value == value){
        pDelete = *phead;
        *phead = (*phead)->next;
        delete pDelete;
        pDelete = nullptr;
    }
    else{
        ListNode* pNode = *phead;
        while(pNode->next != nullptr && pNode->next->value != value)
            pNode = pNode->next;
        if(pNode->next == nullptr)
            return;
        pDelete = pNode->next;
        pNode->next = pNode->next->next;
        delete pDelete;
        pDelete = nullptr;
    }        
}