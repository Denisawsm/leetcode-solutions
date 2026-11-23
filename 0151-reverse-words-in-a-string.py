# 151. Reverse Words in a String (Medium)
# https://leetcode.com/problems/reverse-words-in-a-string/

class Solution(object):
    def reverseWords(self, s):
        return ' '.join(reversed(s.split()))
