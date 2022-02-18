# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

from mailbox import NoSuchMailboxError


class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """

        # 仍是快慢双指针
        # 先遍历一遍俩链表，找到各自长度
        # 找到短一些的链表，暂时不动，长链表先运行到相同位置，再一起向前移动，寻找相同结点
        pA = headA
        pB = headB
        numA = 0
        numB = 0
        while pA:
            numA = numA +1
            pA = pA.next
        while pB:
            numB = numB +1
            pB = pB.next

        pA = headA
        pB = headB
        
        while(numA > numB):       # 长指针先行
            numA = numA -1
            pA = pA.next
        while(numB > numA):
            numB = numB -1
            pB = pB.next

        while(pA != pB and pA):
            pA = pA.next
            pB = pB.next

        return pA