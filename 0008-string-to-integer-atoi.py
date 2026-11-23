# 8. String to Integer (atoi) (Medium)
# https://leetcode.com/problems/string-to-integer-atoi/

class Solution(object):
    def myAtoi(self, s):
        result = 0
        s = s.lstrip()
        n = s.find("-")
        start = 0
        if n == 0:
            neg = True
            start = 1
        else:
            neg = False
        n = s.find("+")
        if n == 0:
            start = 1
        for i in range(start, len(s)):
            char = s[i]
            if char == "0" and result == 0:
                continue
            elif char == " " and not result == 0:
                break
            elif char.isdigit():
                result*=10
                result += int(char)
            else:
                break

        if neg:
            result *= -1

        INT_MIN, INT_MAX = -2**31, 2**31 - 1
        if result < INT_MIN:
            return INT_MIN
        if result > INT_MAX:
            return INT_MAX
        return result
