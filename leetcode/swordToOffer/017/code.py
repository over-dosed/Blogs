from ntpath import join
import numpy as np
class Solution(object):

    def createHash(self,s):
        hash = {}
        hash = hash.fromkeys(s,0)
        for i in range(len(s)):
            hash[s[i]] += 1
        return hash

    def allZero(self,hash):
        """
            :type hash: dict
        """

        for x in hash:
            if hash[x] > 0:
                return False
        
        return True

    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        if(len(s) < len(t)): 
            return ""

        result = "{0}{1}".format("1",s)
        hash = self.createHash(t)          # 创建hash表
        left = 0                   # 左右指针滑动窗口
        right = 0

        while(right < len(s)):
            if(s[right] in hash):
                hash[s[right]] -= 1
            while(self.allZero(hash)):    # 当该窗口满足存在所有字符的条件
                if(len(result) > (right - left + 1)):        # 长度最短
                    result = s[left:right+1]
                if(s[left] in hash):
                    hash[s[left]] += 1
                left += 1
            right = right + 1

        if(len(result) > len(s)): 
            result = ""
        return result

b = Solution()
print(b.minWindow("A","B"))
