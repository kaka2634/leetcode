/*
   Author:     Kun
   Date:       Aug 10, 2017
   Update:     Aug 10, 2017
   Problem:    229. Majority Element II
   Difficulty: Medium
   Source:     https://leetcode.com/problems/majority-element-ii/description/
   Notes:

   Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

   The algorithm should run in linear time and in O(1) space.

   Solution: Find most two marjority element n,m, refer to Proble marjority element I
             Time: O(n), Space: O(1).
 */

class Solution {
public:
vector<int> majorityElement(vector<int>& nums) {
        int cn=0,cm=0,n=0,m=0;
        vector<int> res;
        for(auto a : nums)
        {
                //assume that a[0] and a[1] is not 0;
                if(a==n) cn++;
                else if(a==m) cm++;
                else if(cn==0) {n=a; cn=1; }
                else if(cm==0) {m=a; cm=1; }
                // a is different from both m and n
                else {cn--; cm--; }

        }
        //double check if n,m appears larger than [nums.size()/3] example [3,2,3] ->expect [3]
        cn=cm=0;
        for(auto a : nums)
        {
                if(a==n) cn++;
                else if(a==m) cm++;
        }
        if(cn>nums.size()/3) res.push_back(n);
        if(cm>nums.size()/3) res.push_back(m);
        return res;
}
};
