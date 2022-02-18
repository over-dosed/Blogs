# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """

        if(head.next == None or head == None):
            return head
        result = self.reverseList(head.next)
        p = head
        while(p.next != None):
            p = p.next
        p.next = head
        head.next = None
        return result

node1 = ListNode(1)
node2 = ListNode(2)
node3 = ListNode(3)
node4 = ListNode(4)

node1.next = node2
node2.next = node3
node3.next = node4
node4.next = None

b = Solution()
print(b.reverseList(node1).val)