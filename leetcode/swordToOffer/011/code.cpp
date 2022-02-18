// 采用前缀和思想

#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        int result = 0;
        unordered_map<int,int> hash;

        nums[0] = nums[0] == 0? -1 : 1;
        hash.insert({nums[0],0});
        for(int i = 1; i< nums.size();i++)
        {
            nums[i] = nums[i] == 0? -1 : 1;
            nums[i] = nums[i-1] + nums[i];       // 获得前缀和数组
            
            if(nums[i] == 0) result = i + 1;
            else
            {
                if(hash.find(nums[i]) != hash.end())
                {
                    int temp = i - hash[nums[i]];
                    result = result < temp ? temp : result;
                }
                else
                {
                    hash.insert({nums[i],i});
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> numbers = {0,1};
    int result = solution.findMaxLength(numbers);
    cout<<result;
}