# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # 首先获得两个链表的长度la,lb
    # 长的链表指针先走la-lb步
    # 然后以同样的速度移动
    # 如果指向的值相同，则有交点
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if headB is None or headA is None:
            return None

        la, lb = self.getListLength(headA), self.getListLength(headB)
        if la > lb:
            headA = self.moveNStep(headA, la - lb)
        elif la < lb:
            headB = self.moveNStep(headB, lb - la)

        q, r = headA, headB
        while q:
            if q == r:
                return q
            else:
                q, r = q.next, r.next
        return None

    def moveNStep(self, head: ListNode, n: int) -> ListNode:
        for i in range(n):
            head = head.next
        return head

    def getListLength(self, head: ListNode) -> int:
        p, cnt = head, 0
        while p:
            cnt += 1
            p = p.next
        return cnt
