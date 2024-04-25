Double Linked List Template for C
=================================


Introduction
------------

This is a type-safe generic implementation of a double linked in C. In a double linked list, each node has
pointer to the next and the previous node in the list. It uses macros to generate code for
functions to manipulate the linked list for a specific type of data. The use of prefixes enables the
generation of code for more than one type of data.


Description
-----------

  To avoid the use of local static data and manage more than one list. So it is necessary that the used
defines a static variable of type LIST_NODE to work as dummy header. 

>> This dummy header will never contain any data!!!!

The dummy header will be used to start a transverse the list and test for the end of it.

Transferring the burden of creating area and never using static data, it is possible
have more than one linked list for a certain type and have linked list with different node.


>>  This routine NEVER EVER allocate data or free´d it. It never calls malloc, free or correlates.


>> This package defines two macros to join strings. They are called JOIN and JOIN2.

The API is shown below, where PREFIX and NODE area defined when calling the macros to implement the interface and the implementation.


    int PREFIX_Init (NODE *node);
    NODE *PREFIX_Next (NODE *node);
    NODE *PREFIX_Previous (NODE *node);
    void PREFIX_InsertAfter  (NODE *node, NODE *givennode);
    void PREFIX_InsertBefore (NODE *node, NODE *givennode);
    void PREFIX_Delete (NODE *node);

Usage
-----

The macros are 

* INSERT_LINKED_LIST_INTERFACE(PREFIX,NODE). To be used in the header file (FILE.h). The parameters are PREFIX, used to form the function names.
* INSERT_LINKED_LIST_IMPLEMENTATION(PREFIX,NODE). It must be used in the implementation file (FILE.c). The parameters must be exactly the same as the ones used above.




    \#include "linked-list-template.h"

    typedef struct LIST_NODE {
                  struct LIST_NODE   *next;
                  struct LIST_NODE   *prev;
                  // payload.
                  } LIST_NODE
   
    INSERT_LINKED_LIST_INTERFACE(LIST_,LIST_NODE)


The implementation has the following structure. It should be in a file named linked-list.c or whatever you like.
 

    #include "linked-list.h"

    INSERT_LINKED_LIST_IMPLEMENTATION(LIST_,LIST_NODE)


The main file should include the header file, define the dummy header file and initialize the list.

    #include "linked-list.h"
    
    LIST_NODE dummyheader;    // a dummy header. It does not contain data.
       ...
    LIST_NODE node1, node2;

    int main() {

         LIST__Init(&dummyheader);

         LIST_InsertAfter(&node1,&dummyheader);

    } 

It is possible to have different linked list. Each one must have a different dummy header. 

References
----------

1. [Doubly linked list](https://en.wikipedia.org/wiki/Doubly_linked_list)
2. [Doubly Linked List Tutorial](https://www.geeksforgeeks.org/doubly-linked-list-tutorial-2/)
3. [Doubly Linked List](https://www.programiz.com/dsa/doubly-linked-list)