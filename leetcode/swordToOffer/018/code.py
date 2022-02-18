import numpy as np
class Solution(object):

    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s = s.upper()
        left = 0
        right = len(s) -1

        while(left < right):
            while(left < right and not s[left].isdigit() and not s[left].isalpha()):                    # 如果左值不是字母或数字，left ++
                left += 1
            while(left < right and not s[right].isdigit() and not s[right].isalpha()):                    # 如果右值不是字母或数字，left ++
                right -= 1
            
            if(s[left] != s[right]):
                return False
            else:
                left += 1
                right -= 1
        
        return True

b = Solution()
a = " "
print((not a.isalpha()) and (not a.isdigit()))
print(b.isPalindrome("A man, a plan, a canal: Panama"))