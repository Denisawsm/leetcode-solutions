// 11. Container With Most Water (Medium)
// https://leetcode.com/problems/container-with-most-water/

int maxArea(int* height, int heightSize) {
    int max_water = 0;
    int left = 0;
    int right = heightSize - 1;
    
    while (left < right) {
        int width = right - left;
        int h = (height[left] < height[right]) ? height[left] : height[right];
        
        int current_water = width * h;
        if (current_water > max_water) {
            max_water = current_water;
        }
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    return max_water;
}
