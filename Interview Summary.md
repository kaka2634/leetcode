## 面试1

### Excel column convert to number

1.Excel Sheet Column Title
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 

主要思路：10进制转成26进制。但需要注意先减1，因为如52 = 2*（26^1），若不减1，则为B*，而不是正确结果AZ。所以为了避免这种整除的情况，事先减一。

```
class Solution:
    # @return a string
    def convertToTitle(self, num):
        res = ''
        while num > 0:
            tmp = num
            num = (tmp-1)/26
            res += chr(65+(tmp-1)%26)
        return res[::-1]
```

2.Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    
```
class Solution {
public:
    int titleToNumber(string s) {
        int number = 0;
        int tmp = 0;
        for (int i = 0; i < s.length();i++){
            tmp = s[i] - 'A' + 1;
            number = number * 26 + tmp;
        }
        return number;
        
    }
};
```
