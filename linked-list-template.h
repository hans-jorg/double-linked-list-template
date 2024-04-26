#ifndef LINKED_LIST_TEMPLATE_H
#define LINKED_LIST_TEMPLATE_H
/**
 *  @file  linked-list-template.c
 *
 *  @author Hans
 *  @date   23/4/2024
 *
 *  @note  An implementation of a double linked LIST_
 * *
 *  @note  An effort was made to avoid local static data. So it is neccessary that the user
 *         defines a static variable of type LIST_NODE to work as a dummy header.
 *         This node will never containt any data!!!!
 *         It will be used to start a transverse and test for the end of it
 *
 *  @note  Transfering the burden of creating area and never using static data, it is possible
 *         have more than one linked LIST_. Just implements functions with different prefixes.
 *
 *  @note  Example of a header file (linked-list.h). Name can be changed
 *
 *  @code
 *
 *         #include "linked-list-template.h"
 *
 *         typedef struct LIST_NODE {
 *                struct LIST_NODE   *next;
 *                struct LIST_NODE   *prev;
 *                // payload.
 *         } LIST_NODE
 *
 *         INSERT_LINKED_LIST_INTERFACE(LIST_,LIST_NODE)
 *
 *  @note  Example of a C source code file with the linked list implementation named linked-list.c
 *         or whatever you want.
 *
 *  @code
 *
 *         #include "linked-list.h"
 *
 *         INSERT_LINKED_LIST_IMPLEMENTATION(LIST_,LIST_NODE)
 *
 *
 *
 *
 *
 *         LIST_NODE dummyheader;    // a dummy header. It does not contain data.
 *        ...
 *            LIST__Init(&dummyheader);
 *
 *  @note  This routine NEVER EVER allocate data or free´d it. It never calls malloc, free or
 *         correlates.
 */


#define JOIN(A,B) JOIN2(A,B)
#define JOIN2(A,B) A##B

#define INSERT_LINKED_LIST_INTERFACE(LLT_PREFIX,LLT_NODE)                       \
int JOIN(LLT_PREFIX,Init)(LLT_NODE *node);                                      \
LIST_NODE *JOIN(LLT_PREFIX,Next)(LLT_NODE *node);                               \
LIST_NODE *JOIN(LLT_PREFIX,Previous)(LLT_NODE *node);                           \
void JOIN(LLT_PREFIX,InsertAfter)(LLT_NODE *node, LLT_NODE *givennode);         \
void JOIN(LLT_PREFIX,InsertBefore)(LLT_NODE *node, LLT_NODE *givennode);        \
void JOIN(LLT_PREFIX,Delete)(LLT_NODE *node);


#define INSERT_LINKED_LIST_IMPLEMENTATION(LLT_PREFIX,LLT_NODE)   \
/**                                                              \
 *  @brief  Insert node after given node                         \
 */                                                              \
int JOIN(LLT_PREFIX,Init)(LLT_NODE *node) {                      \
                                                                 \
    node->next = node;                                           \
    node->prev = node;                                           \
}                                                                \
/**                                                              \
 *  @brief  Insert node after given node                         \
 */                                                              \
LLT_NODE *JOIN(LIST_,Next)(LLT_NODE *node) {                     \
                                                                 \
    return node->next;                                           \
}                                                                \
                                                                 \
/**                                                              \
 *  @brief  Insert node after given node                         \
 */                                                              \
LLT_NODE *JOIN(LLT_PREFIX,Previous)(LLT_NODE *node) {            \
                                                                 \
    return node->prev;                                           \
}                                                                \
                                                                 \
/**                                                              \
 *  @brief  Insert node after given node                         \
 */                                                              \
void JOIN(LLT_PREFIX,InsertAfter)(LLT_NODE *node, LLT_NODE *givennode) {    \
LLT_NODE *nextnode,*prevnode;                                    \
                                                                 \
    nextnode = givennode->next;                                  \
    prevnode = nextnode->prev;                                   \
                                                                 \
    givennode->next = node;                                      \
    nextnode->prev = node;                                       \
                                                                 \
    node->next = nextnode;                                       \
    node->prev = givennode;                                      \
                                                                 \
}                                                                \
                                                                 \
/**                                                              \
 *  @brief  Insert node after given node                         \
 */                                                              \
void JOIN(LLT_PREFIX,InsertBefore)(LLT_NODE *node, LLT_NODE *givennode) {   \
LLT_NODE *nextnode,*prevnode;                                    \
                                                                 \
    prevnode = givennode->prev;                                  \
    nextnode = prevnode->next;                                   \
                                                                 \
    node->next = givennode;                                      \
    givennode->prev = node;                                      \
                                                                 \
    prevnode->next = node;                                       \
    node->prev = prevnode;                                       \
                                                                 \
}                                                                \
                                                                 \
/**                                                              \
 *  @brief  Remove a node from LIST_                             \
 */                                                              \
void JOIN(LLT_PREFIX,Delete)(LLT_NODE *node) {                   \
LLT_NODE *prevnode,*nextnode;                                    \
                                                                 \
    prevnode = node->prev;                                       \
    nextnode = node->next;                                       \
                                                                 \
    prevnode->next = nextnode;                                   \
    nextnode->prev = prevnode;                                   \
                                                                 \
    /* To avoid dangling pointers */                             \
    node->prev = 0;                                              \
    node->next = 0;                                              \
}                                                                \


#endif // LINKED_LIST_TEMPLATE_H
