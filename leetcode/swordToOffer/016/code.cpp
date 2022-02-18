#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    // 哈希映射
int lengthOfLongestSubstring(string s) {
    int n = s.length();
    if (n <= 1) return n;

    int maxLen = 0;
    int left = 0, right = 0;
    // 存储窗口中每个字符及其位置的下一个位置
    // 表示如果再次碰到这个字符的时候，那么 left 就跳到这个字符所在位置的下一个位置
    unordered_map<char, int> window;
    while (right < n) {
        char currChar = s[right];
        unordered_map<char, int>::iterator it = window.find(currChar);
        int currCharIndex = (it == window.end() ? -1 : it->second);
        left = max(left, currCharIndex);
        maxLen = max(maxLen, right - left + 1);

        window[currChar] = right + 1;
        right++;
    }
    return maxLen;
}
};

int main()
{
    Solution solution;
    string b = "xyzabcasoyx";
    int result = solution.lengthOfLongestSubstring(b);
    cout<<result;
}