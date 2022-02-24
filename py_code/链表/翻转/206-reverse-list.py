# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head is None:
            return head
        q,r = head,head.next
        while r:
            tmp = r.next
            r.next = q
            q = r
            r = tmp
        return q
