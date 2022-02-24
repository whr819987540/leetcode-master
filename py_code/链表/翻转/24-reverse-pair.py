# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        fake_head = ListNode(next=head)
        q,r = fake_head,head
        while r and r.next:
            q.next = r.next
            r.next = q.next.next
            q.next.next = r

            q = r
            r = r.next
        return fake_head.next

    def traverse(self,head:ListNode):
        p = head
        while p:
            print(p.val)
            p = p.next
        print('-'*10)
s = Solution()

head = ListNode(1)
for i in range(4,1,-1):
    tmp = ListNode(val=i)
    tmp.next = head.next
    head.next = tmp
s.traverse(head)

head = s.swapPairs(head)
s.traverse(head)