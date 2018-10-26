#include<cstdio>
#include<iostream>
#include<stack>

struct ListNode{
    int value;
    ListNode* m_pNext;
};

//使用栈逆序打印单链表
void printListReverse(ListNode* pHead){
    std::stack<ListNode*> nodes;
    ListNode* pNode = pHead;

    while(pNode != nullptr){
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }

    while(!nodes.empty()){
        pNode = nodes.top();
        printf("%d ", pNode->value);
        nodes.pop();
    }
}

//使用递归逆序打印单链表
void printListReverse2(ListNode* pHead){
    if(pHead == nullptr)
        return;
    if(pHead->m_pNext){
        printListReverse2(pHead->m_pNext);
    }
    printf("%d ", pHead->value);
}

//插入节点
void insertNode(ListNode* pHead, int v){
    ListNode* node = new ListNode();
    node->m_pNext = nullptr;
    node->value = v;
    if(pHead == nullptr)
        return;
    ListNode* pNode = pHead;
    while(pNode->m_pNext != nullptr)
        pNode = pNode->m_pNext;
    pNode->m_pNext = node;
}

void test(char* name, ListNode* pHead){
    printf("%s start\n", name);
    printListReverse(pHead);
    printf("%s end\n", name);
    printf("%s start\n", name);
    printListReverse2(pHead);
    printf("%s end\n", name);
}

//输入有多个节点
void test1(){
    int values[] = {1, 2, 3, 4, 5};
    ListNode* pHead = new ListNode();
    pHead->m_pNext == nullptr;
    pHead->value = 1;
    for(int i = 1; i < 5; i++){
        //插入节点
        insertNode(pHead, values[i]);
    }
    test("test1", pHead);
}

//输入有一个节点
void test2(){
    int values[] = {1};
    ListNode* pHead = new ListNode();
    pHead->m_pNext == nullptr;
    pHead->value = 1;
    test("test2", pHead);
}

//输入单链表为空
void test3(){
    ListNode* pHead = nullptr;
    test("test3", pHead);
}

int main()
{
    test1();
    test2();
    test3();
    getchar();
    return 0;
}