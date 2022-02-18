// 采用前缀和思想

#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        int result = 0;
        for(int i = 1; i < nums.size();i++)
        {
            nums[i] = nums[i-1] + nums[i];         // 获取前缀和
        }
        int size = nums.size() - 1;
        if(nums[size] == nums[0]) return 0;
        for(int i = 1;i<=size;i++)
        {
            if(nums[size] - nums[i] == nums[i-1]) return i;
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    vector<int> numbers = {1,7,3,6,5,6};
    int result = solution.pivotIndex(numbers);
    cout<<result;
}