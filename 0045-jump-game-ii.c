// 45. Jump Game II (Medium)
// https://leetcode.com/problems/jump-game-ii/

int jump(int* nums, int numsSize) {
    if (numsSize <= 1) return 0;
    int jumps = 0, currentEnd = 0, farthest = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        if (i + nums[i] > farthest) {
            farthest = i + nums[i];
        }
        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;
        }
    }
    return jumps;
}
