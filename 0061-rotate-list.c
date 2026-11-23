// 61. Rotate List (Medium)
// https://leetcode.com/problems/rotate-list/

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;
    int len = 1;
    struct ListNode* tail = head;
    while (tail->next) {
        tail = tail->next;
        len++;
    }
    k %= len;
    if (k == 0) return head;

    tail->next = head;
    int steps = len - k;
    struct ListNode* newTail = tail;
    while (steps--) {
        newTail = newTail->next;
    }
    struct ListNode* newHead = newTail->next;
    newTail->next = NULL;
    return newHead;
}
