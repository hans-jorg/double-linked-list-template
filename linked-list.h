#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "linked-list-template.h"

/* Example node structure */
typedef struct LIST_NODE {
    struct LIST_NODE  *next;
    struct LIST_NODE  *prev;
    int               info;
} LIST_NODE;

INSERT_LINKED_LIST_INTERFACE(LIST_,LIST_NODE)

#endif // LINKED_LIST_H
