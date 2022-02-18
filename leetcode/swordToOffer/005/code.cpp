#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words)
    {
        bool word_has_1[26] = {0};               // 26个英文字母，记录是否有该字母
        bool word_has_2[26] = {0};
        const char *p;

        int result = 0;

        for(int i = 0;i<words.size();i++)
        {
            p = words[i].data();

            for(int k = 0;k< 26;k++)             
            {
                word_has_1[k] = 0;             //初始化第一个记录
            }

            for(int k = 0;k<words[i].length();k++)
            {
                word_has_1[*(p + k) - 97] = 1;    //记录第一个数
            }
            
            for(int j = i+1;j<words.size();j++)     //第二重遍历
            {
                p = words[j].data();

                for(int k = 0;k< 26;k++)             
                {
                    word_has_2[k] = 0;             //初始化第二个记录
                }

                for(int k = 0;k<words[j].length();k++)
                {
                    word_has_2[*(p + k) - 97] = 1;    //记录第二个数
                }

                //两数都已记录，接下来逐位判断是否无相同字符

                bool attain = true;
                for(int k = 0;k<26;k++)
                {
                    if(word_has_1[k] && word_has_2[k])
                    {
                        attain = false;
                        break;
                    }
                }

                if(attain)
                {
                    result = words[i].length() * words[j].length() > result ? words[i].length() * words[j].length() : result;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution ;
    vector<string> words = {"abcw","baz","foo","bar","xtfn","abcdef"};
    int result = solution.maxProduct(words);
    cout<<result;
}