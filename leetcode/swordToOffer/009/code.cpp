#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        int size = nums.size();
        int result = 0;
        int left = 0;
        int right = 0;

        int temp = 1;

        while (right<size)
        {
            temp *= nums[right];
            while (temp >= k)
                {
                    temp /= nums[left];
                    left ++;
                    if(left == size) return 0;
                }
            result += (right - left +1);
            right ++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> numbers = {1,2,3};
    int result = solution.numSubarrayProductLessThanK(numbers,0);
    cout<<result;
}
