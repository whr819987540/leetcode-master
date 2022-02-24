# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        fake_head = ListNode(next=head)
        p = fake_head
        while p.next:
            if p.val == val:
                p.next = p.next.next
            else:
                p = p.next

        return fake_head.next


        # if head is None:
        #     return head
        #
        # # deal with nodes except the head node
        # # remove the node whose val is equal to val
        # p = head
        # while p.next:
        #     if p.next.val == val:
        #         q = p.next
        #         p.next = q.next
        #         del q
        #     else:
        #         p = p.next
        #
        # # deal with head node
        # p = head
        # if p.val == val:
        #     p = p.next
        #     del head
        # return p
    def traverse(self,head:ListNode)->None:
        p = head
        while p:
            print(p.val)
            p = p.next
        print("-"*10)

s = Solution()
head = ListNode(4,None)
s.traverse(head)
for i in range(10):
    tmp = ListNode(i)
    tmp.next = head.next
    head.next = tmp
s.traverse(head)
head = s.removeElements(head,4)
print("return ",head.val)
s.traverse(head)