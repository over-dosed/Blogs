#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        int s1_int[26] = {0};// 定义大小为32的数组用于保存s1的各个字符的值
        int temp[26];// 定义大小为32的数组用于保存s2窗口处各个字符的值

        vector<int> result;

        int s1_size = p.size();
        int s2_size = s.size();

        int i = 0;
        const char* s1_char = p.data();
        const char* s2_char = s.data();
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
                        result.push_back(i);
                    }
                    right = right + 1;
                }
                else break;
            }
            i = i + 1;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string a = "cbaebabacd";
    string b = "abc";
    vector<int> result = solution.findAnagrams(a,b);
    for(int x : result) cout<<x;
}