/**
 *  @file  linked-LIST_.c
 *
 *  @author Hans
 *  @date   23/4/2024
 *
 *  @note  An implementation of a double linked LIST_
 *
 *  @note  It will be transformed into a template
 *
 *  @note  An effort was made to avoid local static data. So it is neccessary that the used
 *         defines a static variable of type LIST_NODE. This will never containt any data!!!!
 *         It will be used to start a transverse and test for the end of it
 *
 *  @note  Transfering the burden of creating area and never using static data, it is possible
 *         have more than one linked LIST_. Just define a header for each one.
 *
 *  @code
 *        LIST_NODE LIST_;    // a header. It does not contain data.
 *        ...
 *            LIST__Init(LIST_);
 *
 *  @note  This routine NEVER EVER allocate data or free´d it. It never calls malloc, free or
 *         correlates.
 */

#include "linked-list.h"


INSERT_LINKED_LIST_IMPLEMENTATION(LIST_,LIST_NODE)
