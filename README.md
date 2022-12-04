In C++:
A list is a contiguous container,so it stores its elements in contiguous memory.
Whereas a vector is a non-contiguous container, so it doesn't store its elements in contiguous memory.
You should note that insertion and deletion in the center of a vector are very expensive since moving all the details takes a long time.

=> LINKED LIST
A linked list is a linear set of data elements (nodes).

But, what are its components?
In fact, each node has two different parts:

1. The first part holds the information of the node.
2. The second parts contains the address of the next node.

And why do we use it?

---> Fast Insertion/Deletion Time:

- As a matter of fact, inserting a new node at the beginning or end of a linked list takes constant time (O(1)) since the only steps are to initialize a new node and then update the pointers; while insertion at the middle of the linked list takes linear time (O(n))
- Similarly, deletion of the nodes at the beginning and end of the linked list take constant time while deleting a node in the middle of the linked list takes linear time.

--->Better use of Memory:
Actually, memory locations are allocated per node preventing memory leaks that might happen in case of arrays.

Which type will we be focusing on in our code?
There are three main types of a linked list:

- Simple Linked List
- Doubly Linked List
- Circular Linked List
But,we will be focusing on implementing a Simple Linked List.

In order to get how to implement a simple linked list, we will create a “LinkedList” class that encapsulates a linked list used to store short integers.