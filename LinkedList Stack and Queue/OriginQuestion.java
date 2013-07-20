/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package originquestion;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.awt.Point;


/**
 *
 * @author zhipengh
 */
public class OriginQuestion {

    /**
     * @param args the command line arguments
     */

  public Point[] closestk( Point  myList[], int k ) {
  
  
      Comparator<Point> comparator = new PointComparator();
      PriorityQueue<Point> queue = new PriorityQueue<Point>(k, comparator);
      
      for(int i = 0;i < myList.length;i++) {
          
          
          if(i <= k)     
              queue.add(myList[i]);
         
          else {
              
              if(comparator.compare(myList[i], queue.peek())<0){
   					
                    queue.poll();
					
                    queue.add(myList[i]);
				}
              
          }
              
              
      }
      
      Point[] output = new Point[k];
      
      int i = k-1;
      
      while(!queue.isEmpty()) {
         
         output[i] = queue.poll();
         
         i--;
      }
      
      return output;
        
  }
  
  public class PointComparator implements Comparator<Point>
	  {

		public int compare(Point p1, Point p2)
		{
			
                        double disx = Math.sqrt(p1.x*p1.x + p1.y*p1.y);

                        double disy = Math.sqrt(p2.x*p2.x + p2.y*p2.y);

                        if (disx < disy)
				return -1;
			
			else if (disx > disy)		
				return 1;
			
			else return 0;
		}
          
	  }



    
    public static void main(String[] args) {
        // TODO code application logic here
    }
    
}
