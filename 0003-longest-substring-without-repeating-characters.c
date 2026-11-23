// 3. Longest Substring Without Repeating Characters (Medium)
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include<string.h>
int lengthOfLongestSubstring(char* s) {
    int left = 0; // tracks position of beginning of window
    int max_len = 0; // max length of subarray that matches conditon
    int l_seen[256]; // array mapping location last seen for every ascii code

    for(int i = 0; i < 256; i ++) {
        l_seen[i] = -1; // so chars are excluded by default unless they appear
    }

    int size = strlen(s);

    for(int right = 0; right < size; right ++) {
        unsigned char c = s[right];  

        if(l_seen[c] >= left) { // checks if c is repeated within the window
            left = l_seen[c] + 1; // updates left position of window accordingly, ensures no repeated chars
        }

        l_seen[c] = right; // updates last seen position of C

        int current_len = right - left + 1; // current length of window
        if(current_len > max_len) {
            max_len = current_len; // max length always >= current length
        }
    }

    return max_len; // returns max lengthD

}
