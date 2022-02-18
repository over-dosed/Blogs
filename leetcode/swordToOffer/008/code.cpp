#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT16_MAX;

        int start = 0;
        int end = 0;

        int temp;

        for(;end<nums.size();end++)
        {
            temp += nums[end];
            while (start<=end && temp >= target)
            {
                result = min(result,end-start+1);
                temp = temp - nums[start];
                start ++;
            }
        }
        if(temp < target && start == 0) result = 0;
        return result; 
    }
};

int main()
{
    Solution solution;
    vector<int> numbers = {2,3,1,2,4,3};
    int result = solution.minSubArrayLen(7,numbers);
    cout<<result;
}
