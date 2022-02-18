#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int sum = 0;
        int result = 0;

        unordered_map<int,int> hash;

        hash.insert({0,1});
        for(int i = 0;i<nums.size();i++)
        {
            sum = i == 0 ? nums[0] : nums[i-1] + nums[i];
            nums[i] = sum;
            if(hash.find(sum -k) != hash.end()) // 找到子数组
            {
                result += hash[sum - k];
            }
            if(hash.find(sum) != hash.end()) // 找到sum前缀和
            {
                hash[sum] ++;
            }
            else
            {
                hash.insert({sum,1});
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> numbers = {1,2,3};
    int result = solution.subarraySum(numbers,3);
    cout<<result;
}
