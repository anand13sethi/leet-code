/*
Link - https://leetcode.com/problems/add-two-numbers/
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0, a, b, sum;
    ListNode* head = new ListNode(0);
    ListNode* temp = head;
    while(l1 != NULL && l2 != NULL){
        ListNode* node = new ListNode(0);
        temp->next = node;
        temp = temp->next;
        a = l1->val;
        b = l2->val;
        sum = a + b + carry;
        temp->val = sum %10;
        carry = sum/10;
        l1 = l1->next;
        l2 = l2->next;
    }
    if(l1 == NULL && l2 != NULL){
        while(l2 != NULL){
            ListNode* node = new ListNode(0);
            temp->next = node;
            temp = temp->next;
            b = l2->val;
            sum = b + carry;
            temp->val = sum %10;
            carry = sum/10;
            l2 = l2->next;
        }
    }
    if(l1 != NULL && l2 == NULL){
        while(l1 != NULL){
            ListNode* node = new ListNode(0);
            temp->next = node;
            temp = temp->next;
            b = l1->val;
            sum = b + carry;
            temp->val = sum %10;
            carry = sum/10;
            l1 = l1->next;
        }
    }
    if(carry){
        while(carry){
            ListNode* node = new ListNode(0);
            temp->next = node;
            temp = temp->next;
            sum = carry;
            temp->val = sum %10;
            carry = sum/10;
        }
    }
    return head->next;
}