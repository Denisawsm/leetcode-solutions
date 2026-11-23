// 86. Partition List (Medium)
// https://leetcode.com/problems/partition-list/

struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode beforeDummy, afterDummy;
    beforeDummy.next = NULL;
    afterDummy.next = NULL;
    struct ListNode* before = &beforeDummy;
    struct ListNode* after = &afterDummy;

    while (head) {
        if (head->val < x) {
            before->next = head;
            before = before->next;
        } else {
            after->next = head;
            after = after->next;
        }
        head = head->next;
    }
    after->next = NULL;
    before->next = afterDummy.next;
    return beforeDummy.next;
}
