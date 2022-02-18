#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());

        if(nums.size() < 3) return result;
        if(nums[0] > 0) return result;

        set<vector<int>> myset;

        int need;                                // 匹配的值
        int left;                                // 匹配的左端
        int right;                               // 匹配的左端

        for(int i = 0;i<nums.size()-2;i++)
        {
            need = -(nums[i]);
            left = i+1;
            right = nums.size()-1;               // 赋左值右值

            while(left<right)
            {
                if(nums[left] + nums[right] == need)
                {
                    while(left < right && nums[left] == nums[left + 1]) left++;
                    while(left < right && nums[right] == nums[right - 1]) right--;

                    result.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                }
                else if(nums[left] + nums[right] > need) right--;
                else left ++;
            }
            while (nums[i+1] == nums[i]) i++;
            
        }
        return result;
    }
};

int main()
{
    Solution solution ;
    vector<int> numbers = {0,0,0,0};
    vector<vector<int>> result = solution.threeSum(numbers);
    cout<<"";
}