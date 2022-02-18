#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int left;
        int right;
        int middle;

        vector<int> result;

        for(int i = 0;i<numbers.size();i++)  // i 是头指针
        {
            left = i;
            right = numbers.size()-1;

            if(numbers[i] + numbers[right] == target)
            {
                result.push_back(i);
                result.push_back(right);
                return result;
            }

            while (right -1 > left)
            {
                middle = (left + right) /2;
                if(numbers[middle] + numbers[i] > target) right = middle;
                else if(numbers[middle] + numbers[i] < target) left = middle;
                else
                {
                    result.push_back(i);
                    result.push_back(middle);
                    return result;
                }
            }
            
        }
        return result;
    }
};

int main()
{
    Solution solution ;
    vector<int> numbers = {1,2,4,6,10};
    vector<int> result = solution.twoSum(numbers,8);
}