#include<cstdio>
#include "List.h"

ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
    if(pHead1 == nullptr)
        return pHead2;
    if(pHead2 == nullptr)
        return pHead1;
    ListNode* mergeHead = nullptr;
    if(pHead1->next < pHead2){
        mergeHead = pHead1;
        mergeHead->next = Merge(pHead1->next, pHead2);
    }
    else{
        mergeHead = pHead2;
        mergeHead->next = Merge(pHead1, pHead2->next);
    }
    return mergeHead;
}