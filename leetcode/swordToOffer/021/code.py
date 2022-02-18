# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from asyncio.windows_events import NULL


class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        pre = head                # 记录当前结点的前n个结点
        p = head 
        for i in range(n):
            if(p.next == None):
                return head.next
            p = p.next
        while(p.next != None):
            p = p.next
            pre = pre.next
        pre.next = pre.next.next

        return head