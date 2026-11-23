// 13. Roman to Integer (Easy)
// https://leetcode.com/problems/roman-to-integer/


int getv(char c) {
switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
}
return 0;
}

int romanToInt(char* s) {

    int size = strlen(s);
    int num = 0;
    int right = 0, current;

    for(int i = size - 1; i >= 0; i --) {
        current = getv(s[i]);
        if(current >= right) {
            num += current;
        }
        else {
            num -= current;
        }
        right = current;

    }

    return num;

}
