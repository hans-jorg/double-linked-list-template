/**
 *  @file test-linked-list.c
 *
 */

#include <stdio.h>

#include "linked-list.h"

LIST_NODE n1,n2,n3,n4,n5;
LIST_NODE list;


void Print_List(LIST_NODE *list) {
LIST_NODE *p;
int index;

    p = LIST_Next(list);

    index = 0;
    while( p != list ) {
        printf("%d: %d | ",index++,p->info);
        p = LIST_Next(p);
    }
    putchar('\n');
}

int main() {
LIST_NODE *p;

    printf("Starting test...\n");
    LIST_Init(&list);
    Print_List(&list);

    printf("Insert 1 as first\n");
    n1.info = 1;
    LIST_InsertAfter(&n1,&list);
    Print_List(&list);

    printf("Insert 2 as first\n");
    n2.info = 2;
    LIST_InsertAfter(&n2,&list);
    Print_List(&list);

    printf("Delete 1\n");
    LIST_Delete(&n1);
    Print_List(&list);

    printf("Insert 3 before 2\n");
    n3.info = 3;
    LIST_InsertBefore(&n3,&n2);
    Print_List(&list);

    printf("Insert 4 after 3\n");
    n4.info = 4;
    LIST_InsertAfter(&n4,&n3);
    Print_List(&list);

    printf("Insert 5 as first\n");
    n5.info = 5;
    LIST_InsertAfter(&n5,&list);
    Print_List(&list);

    printf("Delete 2\n");
    LIST_Delete(&n2);
    Print_List(&list);

    printf("Delete 3\n");
    LIST_Delete(&n3);
    Print_List(&list);

    printf("Delete 4\n");
    LIST_Delete(&n4);
    Print_List(&list);

    printf("Delete 5\n");
    LIST_Delete(&n5);
    Print_List(&list);

    printf("Ending test...\n");

    return 0;
}
