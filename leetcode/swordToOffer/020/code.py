class Solution(object):
    def countSubstrings(self, s):
        result = 0
        left = 0
        right = 0
        if(len(s) <2):
            return len(s)
        for i in range(len(s)-1):
            if(s[i+1] == s[i]):               # 偶数回文子串
                left = i
                right = i+1
                while(s[left]==s[right]):   # 相等
                    result = result + 1     
                    left = left -1
                    right = right + 1
                    if(left < 0  or right > len(s)-1):
                        break
            left = i
            right = i
            while(s[left]==s[right]):
                result = result + 1
                left = left -1
                right = right + 1
                if(left < 0  or right > len(s)-1):
                    break
        
        return (result + 1)

b = Solution()
print(b.countSubstrings("abacaba"))