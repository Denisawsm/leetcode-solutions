// 2. Add Two Numbers (Medium)
// https://leetcode.com/problems/add-two-numbers/

#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // Create a dummy head to simplify building the result linked list
    struct ListNode dummyHead;
    dummyHead.next = NULL;
    struct ListNode* current = &dummyHead;
    
    int carry = 0;

    // Loop until both lists are fully traversed and there is no carry left
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;

        // Add value from l1 if available
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        // Add value from l2 if available
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        // Calculate the new carry (0 or 1)
        carry = sum / 10;

        // Create a new node for the resulting digit
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;

        // Attach the new node to the result list
        current->next = newNode;
        current = current->next;
    }

    return dummyHead.next;
}
