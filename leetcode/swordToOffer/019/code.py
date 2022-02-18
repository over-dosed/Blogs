class Solution(object):
    def validPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """

        # s 由小写字母组成，一样的双指针思路
        left = 0
        right = len(s)-1
        temp_l = 0
        temp_r = 0

        while(left < right):
            if(s[left] != s[right]):                     # 字符不匹配      
                if(s[left + 1] == s[right]):             # 若可以左跳
                    temp_l = left
                    temp_r = right             
                    left += 1
                    while(left < right):
                        if(s[left] != s[right]):        # 左跳失败
                            left = temp_l
                            right = temp_r
                            break;
                        left = left + 1
                        right = right - 1
                    if(left != temp_l):                 #左跳成功
                        return True
                if(s[left] == s[right -1]):           # 不能左跳或左跳失败 ， 若可以右跳
                    right = right -1
                    while(left < right): 
                        if(s[left] != s[right]):      # 右跳失败
                            return False
                        left = left + 1
                        right = right - 1
                else:
                    return False                      # 无法左跳也无法右跳
            left = left + 1
            right = right - 1
        
        return True

b = Solution()
print(b.validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga"))