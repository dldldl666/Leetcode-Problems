/*
 * @lc app=leetcode.cn id=2 lang=java
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */


// 具体实现的注意事项已经写在后面
// 思路上的关键点就是，对于链表问题，想要返回头结点，必须创建一个head指针指向头结点，然后再创立另一个tail指针不断遍历，只有这样才能返回整个链表。
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode ans;
        ListNode head = null;
        ListNode tail = null;
        int tensdigit = 0;
        while (l1 != null || l2 != null){
            int a;
            int b;
            if (l1 == null){
                a = 0;
            }
            else{
                a = l1.val;
            }
            if (l2 == null){
                b = 0;
            }
            else{
                b = l2.val;
            }
            int sum = a + b + tensdigit;
            if (head == null){
                head = tail = new ListNode(sum % 10);
            }
            else{
                tail.next = new ListNode(sum % 10); //这里需为tail.next 因为tail这里已经有东西了
                tail = tail.next;
            }
            tensdigit = sum / 10; // tensdigit 的计算必须放后面, 这里注意是sum/10 而不是a+b / 10 因为上一位的十位数也要记得加上
            if (l1 != null){
                l1 = l1.next;
            }
            if (l2 != null){
                l2= l2.next;
            }
        }
        if (tensdigit > 0){
            tail.next = new ListNode(tensdigit);
        }
        return head;
    }
    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }
}
// @lc code=end

