# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    # 两边扫描
    # 第一遍获得结点总数
    # 第二遍获取对应的结点
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        total_nodes = self.totalNodeNum(head)
        if n > total_nodes:
            return head
        else:
            cnt = total_nodes - n
            fake_head = ListNode(next=head)
            p = fake_head
            while cnt:
                cnt, p = cnt - 1, p.next
            p.next = p.next.next
            return fake_head.next

    def totalNodeNum(self, head: ListNode) -> int:
        cnt = 0
        p = head
        while p:
            cnt += 1
            p = p.next
        return cnt

    # 只扫描一遍：双指针法
    # fast指针先移动n步，然后和slow指针一起移动
    # 当fast指针到底时，slow指针指向倒数第n个结点
    def remove(self, head: ListNode, n: int) -> ListNode:
        fake_head = ListNode(next=head)
        quick,slow = fake_head,fake_head
        for i in range(n):
            quick = quick.next

        while quick.next:
            quick = quick.next
            slow = slow.next

        slow.next = slow.next.next
        return fake_head.next
