// 4. Median of Two Sorted Arrays (Hard)
// https://leetcode.com/problems/median-of-two-sorted-arrays/


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int size = nums1Size + nums2Size;
    int merged[size];

    for(int i = 0; i < nums1Size; i++) {
        merged[i] = nums1[i];
    }
    for(int j = nums1Size; j < size; j ++) {
        merged[j] = nums2[ j - nums1Size];
    }

    for(int i = 0; i < size; i ++){
        for(int j = 0; j < size - i - 1; j++){
            if(merged[j]>merged[j+1]) {
                int temp = merged[j];
                merged[j] = merged[j+1];
                merged[j+1] = temp;
            }
        }
    }
    double median;
    if(size%2 == 0){
        median = (merged[size/2] + merged[size/2 - 1])/(float)2;
    }
    else{
        median = merged[size/2];
    }

    return median;
}
