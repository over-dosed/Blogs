#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int num[32] = {0};      // 开辟一个大小为32的数组

        int result = 0;

        for(int i = 0;i < 32 ;i++)
        {
            for(int x : nums)
            {
                num[i] = num[i] + ((x >> i) & 1 ); // &1 是取最后一位 ， 右移再取最后一位,各个数在相同位置的值相加
            }

            num[i] = num[i] % 3;               // 取余n ， 得到要求的数的该位值
        }

        for(int i = 0; i< 32; i++)
        {
            result = result + (num[i] << i);
        }

        return result;
    }
};