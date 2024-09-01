import java.util.Scanner;

class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class MyLinkedList {
    Node head;

    public MyLinkedList(Node head) {
        this.head = head;
    }
    public void display() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }
    public static MyLinkedList addTwoLists(MyLinkedList list1, MyLinkedList list2) {
        Node first = list1.head;
        Node second = list2.head;
        MyLinkedList result = new MyLinkedList(null);
        Node resultTail = null;
        int carry = 0;
        while (first != null || second != null) {
            int firstData = (first != null) ? first.data : 0;
            int secondData = (second != null) ? second.data : 0;
            int sum = firstData + secondData + carry;
            carry = sum / 10;
            Node newNode = new Node(sum % 10);
            if (result.head == null) {
                result.head = newNode;
                resultTail = newNode;
            } else {
                resultTail.next = newNode;
                resultTail = newNode;
            }
            // Move to the next nodes
            if (first != null) first = first.next;
            if (second != null) second = second.next;
        }
        if (carry > 0) {
            resultTail.next = new Node(carry);
        }
        return result;
    }
}

public class Linksum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Length of the first linked list: ");
        int n1 = sc.nextInt();
        System.out.print("Enter the head element of the first linked list: ");
        Node headOne = new Node(sc.nextInt());
        Node tailOne = headOne;
        System.out.println("Enter the remaining elements of the first linked list: ");
        for (int i = 2; i <= n1; i++) {
            tailOne.next = new Node(sc.nextInt());
            tailOne = tailOne.next;
        }
        MyLinkedList list1 = new MyLinkedList(headOne);
        System.out.print("The first linked list is: ");
        list1.display();
        System.out.print("Enter Length of the second linked list: ");
        int n2 = sc.nextInt();
        System.out.print("Enter the head element of the second linked list: ");
        Node headTwo = new Node(sc.nextInt());
        Node tailTwo = headTwo;
        System.out.println("Enter the remaining elements of the second linked list: ");
        for (int i = 2; i <= n2; i++) {
            tailTwo.next = new Node(sc.nextInt());
            tailTwo = tailTwo.next;
        }
        MyLinkedList list2 = new MyLinkedList(headTwo);
        System.out.print("The second linked list is: ");
        list2.display();
        MyLinkedList result = MyLinkedList.addTwoLists(list1,list2);
        System.out.print("The resultant linked list after adding is: ");
        result.display();
    }
}
