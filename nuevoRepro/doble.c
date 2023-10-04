#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;

    struct Node *next;
    struct Node *prev;
};

struct Node *partition(struct Node *left, struct Node *right)
{
    struct Node *pivot = right;
    struct Node *i = left->prev;
    for (struct Node *ptr = left; ptr != right; ptr = ptr->next)
    {
        if (ptr->val <= pivot->val)
        {
            i = (i == NULL ? left : i->next);
            int temp = i->val;
            i->val = ptr->val;
            ptr->val = temp;
        }
    }
    i = (i == NULL ? left : i->next);
    int temp = i->val;
    i->val = pivot->val;
    pivot->val = temp;
    return i;
}

void QuickSort(struct Node *left, struct Node *right)
{
    if (right != NULL && left != right && left != right->next)
    {
        struct Node *p = partition(left, right);
        QuickSort(left, p->prev);
        QuickSort(p->next, right);
    }
}

int main()
{
    struct Node *head = malloc(sizeof(struct Node));
    head->val = 2;
    head->prev = NULL;
    struct Node *l1 = malloc(sizeof(struct Node));
    l1->val = 8;
    l1->prev = head;
    head->next = l1;
    struct Node *l2 = malloc(sizeof(struct Node));
    l2->val = 3;
    l2->prev = l1;
    l1->next = l2;
    struct Node *l3 = malloc(sizeof(struct Node));
    l3->val = 5;
    l3->prev = l2;
    l2->next = l3;
    struct Node *l4 = malloc(sizeof(struct Node));
    l4->val = 10;
    l4->prev = l3;
    l3->next = l4;
    l4->next = NULL;
    // 2<=>8<=>3<=>5<=>10=>NULL

    QuickSort(head, l4);
    while (head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    return 0;
}