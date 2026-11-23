// 34. Find First and Last Position of Element in Sorted Array (Medium)
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* res = (int*)malloc(2 * sizeof(int));
    res[0] = -1;
    res[1] = -1;
    *returnSize = 2;
    if (numsSize == 0) return res;

    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            if (nums[mid] == target) res[0] = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    left = 0;
    right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) {
            if (nums[mid] == target) res[1] = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return res;
}
