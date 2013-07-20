/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mergelistproblem;

/**
 *
 * @author zhipengh
 */
public class Node {
    public int value;
        public Node next;
        public Node() {
                value = 0;
                next = null;
        }
        public Node(int value, Node next) {
                this.value = value;
                this.next = next;
        }
}
