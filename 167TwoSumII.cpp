/*
 * 167. Two Sum II
 * Author: Kun
 * Date:2017-07-29
 * Solution: Binary Search
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0; i<numbers.size();i++)
        {
            int temp = target - numbers[i];
            int left = i+1;
            int right = numbers.size()-1;
            while(left<=right)
            {
                int min = left + (right-left)/2;
                if(numbers[min]==temp)
                {
                    vector<int> result;
                    result.push_back(i+1);
                    result.push_back(min+1);
                    return result;
                }
                else
                {
                    if(numbers[min]>temp)
                    {
                       right=min-1;
                    }
                    else
                    {
                        left=min+1;
                    }
                }
            }
        }
    }
};
