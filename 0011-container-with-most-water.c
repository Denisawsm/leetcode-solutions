// 11. Container With Most Water (Medium)
// https://leetcode.com/problems/container-with-most-water/

int maxArea(int* height, int heightSize) {
    int max_water = 0;
    int left = 0;
    int right = heightSize - 1;
    
    while (left < right) {
        // 1. Calculate width (distance between indices)
        int width = right - left;
        
        // 2. Height is limited by the shorter of the two lines
        int h = (height[left] < height[right]) ? height[left] : height[right];
        
        // 3. Calculate area and update max if it's larger
        int current_water = width * h;
        if (current_water > max_water) {
            max_water = current_water;
        }
        
        // 4. Move the pointer of the shorter line inward
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    return max_water;
}
