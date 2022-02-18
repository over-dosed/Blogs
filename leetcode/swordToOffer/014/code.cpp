#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        int s1_int[26] = {0};// 定义大小为32的数组用于保存s1的各个字符的值
        int temp[26];// 定义大小为32的数组用于保存s2窗口处各个字符的值

        int s1_size = s1.size();
        int s2_size = s2.size();

        int i = 0;
        const char* s1_char = s1.data();
        const char* s2_char = s2.data();
        for(; i< s1_size ; i++)
        {
            s1_int[(s1_char[i]-97)] ++;     // 获取s1各字符值
        }

        i = 0;
        int right;
        while((s2_size - s1_size + 1) >  i)
        {
            copy(begin(s1_int),end(s1_int),begin(temp));
            right = i;
            
            while(right - i + 1 <= s1_size)
            {
                if(temp[s2_char[right] - 97] >0)
                {
                    temp[s2_char[right] - 97] --;
                    if(right - i + 1 == s1_size)
                    {
                        return true;
                    }
                    right = right + 1;
                }
                else break;
            }
            i = i + 1;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    string a = "ab";
    string b = "eidbaooo";
    bool result = solution.checkInclusion(a,b);
    cout<<result;
}