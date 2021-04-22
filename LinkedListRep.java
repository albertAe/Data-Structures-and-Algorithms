public class LinkedListRep {
	
		Node head;

		static class Node { 
		   int data; 
		   Node next; 
		   Node(int d) 
		           { 
		                data = d; 
		                next = null; 
		            } // Constructor 
		        } 

		
		public static void main(String[] args) 
	    { 
			
	        /* Start with the empty list. */
			LinkedListRep llist = new LinkedListRep(); 
	  
	        llist.head = new Node(8); 
	        Node second = new Node(10); 
	        Node third = new Node(12); 
	        Node fourth = new Node(16);
	        Node fifth = new Node(9);
	        Node sixth = new Node(14);
	  
	        llist.head.next = second;
	        second.next = third;
	        third.next = fourth;
	        fourth.next = fifth;
	        fifth.next = sixth;
	        //sixth.next = llist.head;
	        
	        System.out.print("\nLinked list: "); 
		    llist.printList();
	        
	        llist.push(15); 
	        System.out.print("\nlist after inserting node 15: "); 
		    llist.printList();
	        
	        llist.insertAfter(third.next, 25);
	        System.out.print("\nlist after inserting node 25: "); 
		    llist.printList();
	        
	        llist.deleteNode(6);
	        System.out.print("\nlist after deleting node 9: "); 
		    llist.printList();
	        
	        llist.insertAfter(llist.head.next, 30);
	        System.out.print("\nlist after inserting node 30: "); 
		    llist.printList();
	        
	        llist.append(45);
	        System.out.print("\nlist after appending node 45: "); 
		    llist.printList();
		   
		    
	        llist.deleteNodeIterative(8);
	        System.out.print("\nlist after deleting node 8 after 15: "); 
		    llist.printList();
	        
		    }
		
		//Inserts a new Node at front of the list.
		public void push(int new_data) 
		{ 
		    Node new_node = new Node(new_data); 
		    new_node.next = head; 
		    head = new_node; 
		} 
		
		//Inserts a new node after the given prev_node.
		public void insertAfter(Node prev_node, int new_data)  
		{  
		    if (prev_node == null)  
		    {  
		        System.out.println("\nThe given previous node cannot be null");  
		        return;  
		    }  
		  
		    Node new_node = new Node(new_data);  
		    new_node.next = prev_node.next;  
		    prev_node.next = new_node;  
		}
		
		//Appends a new node at the end.
		public void append(int new_data) 
		{ 
		    Node new_node = new Node(new_data); 
		  
		    if (head == null) 
		    { 
		        head = new Node(new_data); 
		        return; 
		    } 
		  
		    new_node.next = null; 
		  
		    Node last = head;  
		    while (last.next != null) 
		        last = last.next; 
		  
		    last.next = new_node; 
		    return; 
		} 
		//This function prints contents of linked list starting from the given node 
		public void printList() 
	    { 
	        Node tnode = head; 
	        while (tnode != null) 
	        { 
	            System.out.print(tnode.data+" "); 
	            tnode = tnode.next; 
	        } 
	    } 
		
		
		void deleteNodeIterative(int key)
	    {
	        Node temp = head, prev = null;
	 
	        // If head node itself holds the key to be deleted
	        if (temp != null && temp.data == key) {
	            head = temp.next; // Changed head
	            return;
	        }
	 
	        // Search for the key to be deleted, keep track of
	        // the previous node as we need to change temp.next
	        while (temp != null && temp.data != key) {
	            prev = temp;
	            temp = temp.next;
	        }
	 
	        // If key was not present in linked list
	        if (temp == null)
	            return;
	 
	        // Unlink the node from linked list
	        prev.next = temp.next;
	    }

		void deleteNode(int position) {
            if (head == null)
                return;

            Node node = head;

            if (position == 0) {
                head = node.next;
                return;
            }
            // Find the key to be deleted
            for (int i = 0; node != null && i < position - 1; i++)
                node = node.next;

            // If the key is not present
            if (node == null || node.next == null)
                return;

            // Remove the node
            Node next = node.next.next;

            node.next = next;
        }
		}
		
	

