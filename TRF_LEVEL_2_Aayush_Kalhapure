class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def addTwoNumbers(l1, l2):
    dummy_head = ListNode(0)
    current = dummy_head
    carry = 0
    
    while l1 or l2 or carry:
        val1 = l1.val if l1 else 0
        val2 = l2.val if l2 else 0
        
        total = val1 + val2 + carry
        carry = total // 10
        current.next = ListNode(total % 10)
        current = current.next
        
        if l1:
            l1 = l1.next
        if l2:
            l2 = l2.next
    
    return dummy_head.next

def create_linked_list(arr):
    head = ListNode(arr[0])
    current = head
    for num in arr[1:]:
        current.next = ListNode(num)
        current = current.next
    return head

def print_linked_list(l):
    result = []
    while l:
        result.append(l.val)
        l = l.next
    print(result)

l1_input = list(map(int, input("Enter the digits of the first number in reverse order (e.g., 2 4 3): ").split()))
l2_input = list(map(int, input("Enter the digits of the second number in reverse order (e.g., 5 6 4): ").split()))

l1 = create_linked_list(l1_input)
l2 = create_linked_list(l2_input)

result = addTwoNumbers(l1, l2)

print("Resultant linked list:")
print_linked_list(result)
