class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        fast = head
        slow = head

        while(fast and fast.next):
            slow = slow.next
            fast = fast.next.next

            if(slow == fast):      # 快慢指针相遇
                fast = head             # 新建指针，指向开头，当该指针以同样速度与slow相遇时，两者都在环形开头
                while (fast != slow):
                    fast = fast.next
                    slow = slow.next
                return fast
        return None

node1 = ListNode(3)
node2 = ListNode(2)
node3 = ListNode(0)
node4 = ListNode(4)

node1.next = node2
node2.next = node3
node3.next = node4
node4.next = node2

b = Solution()
print(b.detectCycle(node1))