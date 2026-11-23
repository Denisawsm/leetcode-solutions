// 82. Remove Duplicates from Sorted List II (Medium)
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;
    struct ListNode* curr = head;

    while (curr) {
        if (curr->next && curr->val == curr->next->val) {
            int dupVal = curr->val;
            while (curr && curr->val == dupVal) {
                curr = curr->next;
            }
            prev->next = curr;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return dummy.next;
}
