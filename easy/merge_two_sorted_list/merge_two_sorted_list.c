#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode {
    int val;
    struct ListNode *next;
}Node;

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);

int main (void){
    
    struct ListNode ListNode1 , ListNode2;
    struct ListNode *merge;
    ListNode1.val = 1;
    ListNode1.next = NULL;
    ListNode2.val = 2;
    ListNode2.next = NULL;

    merge = mergeTwoLists(&ListNode1, &ListNode2);

    return 0;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode mergeList; //dummy start of the merge array list
    struct ListNode *mergePtr = &mergeList;

    mergeList.next = NULL;

    while (l1 || l2){
        if (!l1){
            mergePtr->next = l2;
            break;
        } 
        else if (!l2){
            mergePtr->next = l1;
            break;
        } 
        else {
            if ( l1->val < l2->val ){
                mergePtr->next = l1;
                l1 = l1->next;
            } 
            else{
                mergePtr->next = l2;
                l2 = l2->next;
            }
            mergePtr = mergePtr->next;
        }
    }
    return mergeList.next;
}