# Definition for singly-linked list.
class ListNode:
    def __init__(self, x, next=None):
        self.val = x
        self.next = next


class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        meet_node = self.cycleExists(head)
        if meet_node is None:
            return None

        # 根据速度关系可以推导出
        # 从起始节点和相遇结点开始运动，保持相同的速度
        # 最终一定能相遇
        p = head
        while 1:
            # 这里需要先判断，然后再移动
            # 因为可能出现相遇结点即为头结点的情况
            # 此时，链表完全是一个环
            if p == meet_node:
                return p
            p = p.next
            meet_node = meet_node.next

    def cycleExists(self, head: ListNode) -> ListNode:
        # 首先判断环是否存在
        # 定义slow，quick两个指针
        # slow指针每次移动一个结点，quick指针每次移动两个结点
        # 如果有环，首先两个指针都能进入环中
        # 由相对运动可知：二者一定能相遇
        # 如果存在环，返回相遇的结点，否则返回None
        slow, quick = head, head
        while quick:
            # 先移动后判断
            # 因为题目说一个结点的情况不是环
            try:
                slow = slow.next
                quick = quick.next.next
            except:
                return None
            if slow == quick:
                return slow

        # 此时链表无环，quick移动到末端
        return None

s = Solution()
a3 = ListNode(3)
a2 = ListNode(2, a3)
a1 = ListNode(1, a2)
a6 = ListNode(6, a3)
a5 = ListNode(5, a6)
a4 = ListNode(4, a5)
a3.next = a4

print(s.cycleExists(a1))
print(s.detectCycle(a1).val)

a1 = ListNode(1)
a2 = ListNode(2)
a1.next = a2
a2.next = a1
print(s.cycleExists(a1))
print(s.detectCycle(a1).val)
