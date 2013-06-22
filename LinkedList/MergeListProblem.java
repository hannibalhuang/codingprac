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


public class MergeListProblem {

    /**
     * @param args the command line arguments
     */
    
    public static Node mergeLists(Node head1, Node head2) {
                // your code goes here
                if(head1==null || head2==null) {
					return head1!=null ? head1 : head2;
				}
                     
				Node head = null;
				
                Node prev = null;
                     
				Node node1 = head1;
                     
				Node node2 = head2;
                     
				while(node1!=null && node2!=null) {
                    
					Node node;
                    
					if(node1.value<node2.value) {
                        
						node = node1;
                        
						node1 = node1.next;
					} 
                    
                    else {
                        
						node = node2;
                        
						node2 = node2.next;
					}
                    
					if(head==null) {
                        
						head = node;
					} 
                    
                    else {
                        
						prev.next = node;
					}
                    
					prev = node;
				}
				return head;
			}
    
    public static void main(String[] args) {
        // TODO code application logic here
    }
    
}
