/*
 * 27. Remove Element
 * Author: Kun
 * Date:2017-07-29
 * Solution: Use two variable i,j as index for nums. i record after-removed index, j record compare index.
 */
class Solution {
public:
int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0) return 0;
        int i=0;
        int j=0;
        while(j<nums.size())
        {
                if(nums[j]!=val)
                        nums[i++]=nums[j];
                j++;
        }
        return i;
}
};
