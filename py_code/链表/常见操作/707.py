class ListNode:
    def __init__(self, val=0, next=None):
        self.val, self.next = val, next


class MyLinkedList:

    def __init__(self):
        self.head = ListNode()

    def get(self, index: int) -> int:
        p, i = self.head, index
        while i >= 0 and p.next:
            i, p = i - 1, p.next
        if i == 0 and p.next is not None:
            return p.next.val
        else:
            return -1
        # elif i==0 and p.next is None:
        #     return -1
        # elif i!=0 and p.next is None:
        #     return -1

    def addAtHead(self, val: int) -> None:
        tmp = ListNode(val)
        tmp.next = self.head.next
        self.head.next = tmp

    def addAtTail(self, val: int) -> None:
        p = self.head
        while p.next:
            p = p.next
        tmp = ListNode(val)
        tmp.next = p.next
        p.next = tmp

    def addAtIndex(self, index: int, val: int) -> None:
        p, i = self.head, index
        # index<0和index=0要求一样
        if i < 0:
            i = 0
        while i and p.next:
            i, p = i - 1, p.next
        # i减为0
        if i == 0:
            tmp = ListNode(val)
            tmp.next = p.next
            p.next = tmp
        # i不为0,p.next为空.不插入
        elif i != 0 and p.next is None:
            pass

    def deleteAtIndex(self, index: int) -> None:
        if index >= 0:
            p, i = self.head, index + 1
            while i and p.next:
                q = p
                i, p = i - 1, p.next
            if i == 0:
                q.next = p.next

    def traverse(self):
        p = self.head
        while p.next:
            print(p.next.val)
            p = p.next
        print('-' * 10)


def reverseList(head: ListNode) -> ListNode:
    q, r = None, head
    while r :
        tmp = r.next
        r.next = q
        q = r
        r = tmp
    return q








# Your MyLinkedList object will be instantiated and called as such:
linkedList = MyLinkedList()
linkedList.traverse()

linkedList.addAtHead(1)
linkedList.traverse()

linkedList.addAtTail(3)
linkedList.traverse()

linkedList.addAtIndex(1, 2)
linkedList.traverse()

print(linkedList.get(1))
print('-' * 10)

linkedList.deleteAtIndex(1)
linkedList.traverse()

print(linkedList.get(2))
print('-' * 10)
