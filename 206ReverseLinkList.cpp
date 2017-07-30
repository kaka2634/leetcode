/*
 * 206. Reverse Linked List
 * Author: Kun
 * Date:2017-07-30
 * Solution: Head Insert (Use dummy to save temp head)
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        ListNode* temp = head->next;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        while(temp)
        {
            head->next=temp->next;
            temp->next=dummy->next;
            dummy->next=temp;
            temp=head->next;
        }
        return dummy->next;
    }
};


//Learn Others Code

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = new ListNode(0);
        new_head -> next = head;
        ListNode* pre = new_head;
        ListNode* cur = head;
        while (cur && cur -> next) {
            ListNode* temp = pre -> next;
            pre -> next = cur -> next;
            cur -> next = cur -> next -> next;
            pre -> next -> next = temp;
        }
        return new_head -> next;
    }
};
