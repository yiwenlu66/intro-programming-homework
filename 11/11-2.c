/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-12-22
Description: Looping linked list operations.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100
#define INFTY 0x7fffffff

typedef struct node node;

struct node {
    char number[MAXLEN];
    char name[MAXLEN];
    int grade;
    node *next;
};

node *Insert(node *head, const char *number, const char *name, int grade);
node *copy(const node *head);
node *SelectMax(const node *head);
node *bubble(node *head);
node *search(const node *head, const char *number);
node *del(node *head, const char *number);  // "delete" is a keyword
int list(const node *head);
void print_node(const node *n);

int main()
{
    node *head_A = NULL, *head_B;
    char key[MAXLEN];
    list(head_A = Insert(head_A, "105", "n1", 1));
    list(head_A = Insert(head_A, "100", "n2", 8));
    list(head_A = Insert(head_A, "102", "n3", 6));
    list(head_A = Insert(head_A, "103", "n4", 4));
    list(head_A = Insert(head_A, "107", "n5", 3));
    list(head_A = Insert(head_A, "104", "n6", 2));
    list(head_A = Insert(head_A, "101", "n7", 7));
    list(head_A = Insert(head_A, "106", "n8", 5));
    list(head_B = copy(head_A));
    print_node(SelectMax(head_A));
    printf("\n");
    list(head_A = bubble(head_A));
    printf("enter number to search:\n");
    scanf("%s", key);
    print_node(search(head_A, key));
    printf("\n");
    printf("enter number to delete:\n");
    scanf("%s", key);
    print_node(del(head_A, key));
    printf("\n");
    list(head_A);
    return 0;
}

node *Insert(node *head, const char *number, const char *name, int grade)
{
    node *tail;
    node *new_node = (node *)malloc(sizeof(node));
    strcpy(new_node->number, number);
    strcpy(new_node->name, name);
    new_node->grade = grade;

    if (head == NULL)
        head = new_node;
    else {
        tail = head;
        while (tail->next != head)
            tail = tail->next;
        tail->next = new_node;
    }

    new_node->next = head;
    return head;
}

node *copy(const node *head)
{
    node *new_head;
    const node *p = head;
    if (head == NULL)
        return NULL;
    new_head = NULL;
    do {
        new_head = Insert(new_head, p->number, p->name, p->grade);
        p = p->next;
    } while (p != head);
    return new_head;
}

node *SelectMax(const node *head)
{
    int maxgrade = -INFTY;
    const node *p = head;
    node *result;
    do {
        if (p->grade > maxgrade) {
            maxgrade = p->grade;
            result = (node *)p;
        }
        p = p->next;
    } while (p != head);
    return result;
}

node *bubble(node *head)
{
    node *beforehead = (node *)malloc(sizeof(node));
    node *sortedhead = NULL;
    node *tail;
    node *p0, *p1, *p2, *t;

    if (head == NULL || head->next == NULL)
        return head;

    tail = head;
    do {
        tail = tail->next;
    } while (tail->next != head);
    tail->next = NULL;

    beforehead->next = head;

    while (beforehead->next != sortedhead) {
        p0 = beforehead;
        p1 = p0->next;
        p2 = p1->next;
        while (p2 != sortedhead) {
            t = p2->next;
            if (strcmp(p1->number, p2->number) > 0) {
                p0->next = p2;
                p2->next = p1;
                p1->next = t;
                p0 = p2;
                p2 = t;
            } else {
                p0 = p1;
                p1 = p2;
                p2 = t;
            }
        }
        sortedhead = p1;
    }

    head = beforehead->next;

    tail = head;
    do {
        tail = tail->next;
    } while (tail->next != NULL);
    tail->next = head;

    return head;
}

node *search(const node *head, const char *number)
{
    const node *p = head;
    do {
        if (!strcmp(p->number, number))
            return (node *)p;
        p = p->next;
    } while (p != head);
    return NULL;
}

node *del(node *head, const char *number)
{
    node *beforehead = (node *)malloc(sizeof(node));
    node *p0, *p1, *t;

    beforehead -> next = head;
    p0 = beforehead;
    p1 = p0->next;

    do {
        t = p1->next;
        if (!strcmp(p1->number, number)) {
            p0->next = t;
            return (node *)p1;
        }
        p1 = p1->next;
        p0 = p0->next;
    } while (p1 != head);

    return NULL;
}

int list(const node *head)
{
    int n = 0;
    const node *p = head;
    if (head == NULL)
        return 0;
    do {
        print_node(p);
        ++n;
        p = p->next;
    } while (p != head);
    printf("\n");
    return n;
}

void print_node(const node *n)
{
    if (n == NULL) {
        printf("does not exist\n");
        return;
    }
    printf("%s\t%s\t%d\n", n->number, n->name, n->grade);
}
