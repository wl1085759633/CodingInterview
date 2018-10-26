#include"List.h"
#include<cstdio>
 
 //删除链表节点
 void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted){
     if(pListHead == nullptr || *pListHead == nullptr || pToBeDeleted == nullptr)
         return;
    //删除中间节点
    if(pToBeDeleted->m_pNext != nullptr){
        ListNode* pNode = pToBeDeleted->m_pNext;
        pToBeDeleted->m_nValue = pNode->m_nValue;
        pToBeDeleted->m_pNext = pNode->m_pNext;
        delete pNode;
        pNode = nullptr;
    }
    //删除只有一个节点
    else if(*pListHead == pToBeDeleted){
        *pListHead = nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
    //删除尾节点
    else{
        ListNode* pNode = *pListHead;
        while(pNode && pNode->m_pNext != pToBeDeleted)
            pNode = pNode->m_pNext;
        pNode->m_pNext == nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
        if(pNode == nullptr)
            printf("节点不在链表中\n");
    }
 }

 void test(ListNode* pHead, ListNode* pNode){
     printf("The original list is: \n");
     PrintList(pHead);

     printf("The node to be deleted is:\n");
     PrintListNode(pNode);

     DeleteNode(&pHead, pNode);

     printf("The result list is:\n");
     PrintList(pHead);
 }

 //从多个节点的链表中间删除一个节点
 void test1(){
    //构造节点
    ListNode* node1 =  CreateListNode(1);
    ListNode* node2 =  CreateListNode(2);
    ConnectListNodes(node1, node2);
    ListNode* node3 =  CreateListNode(3);
    ConnectListNodes(node2, node3);
    ListNode* node4 =  CreateListNode(4);
    ConnectListNodes(node3, node4);
    test(node1, node3);
 }

 //从多个节点的链表中删除头结点
 void test2(){
    ListNode* node1 =  CreateListNode(1);
    ListNode* node2 =  CreateListNode(2);
    ConnectListNodes(node1, node2);
    ListNode* node3 =  CreateListNode(3);
    ConnectListNodes(node2, node3);
    ListNode* node4 =  CreateListNode(4);
    ConnectListNodes(node3, node4);
    test(node1, node1);
 }

 //从有多个节点的链表中删除尾节点
 void test3(){
    ListNode* node1 =  CreateListNode(1);
    ListNode* node2 =  CreateListNode(2);
    ConnectListNodes(node1, node2);
    ListNode* node3 =  CreateListNode(3);
    ConnectListNodes(node2, node3);
    ListNode* node4 =  CreateListNode(4);
    ConnectListNodes(node3, node4);
    test(node1, node4);
 }

 //从只有一个节点的链表中删除唯一的节点
 void test4(){
    ListNode* node1 =  CreateListNode(1);

    test(node1, node1);
 }

 int main(int argc, char** argv){
    // test1();
    // test2();
    test3();
    // test4();
    getchar();
    return 0;
 }