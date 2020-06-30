
#include <stdlib.h>
#include <stdio.h>
struct Node {
    int data;
    struct Node* next;
}*first=NULL,*second=NULL; // first is global pointer


// param A: Array
// param n: Length
void create(int A[], int n) {
    int i;
    // t: temp ptr, last traces the ele of linkedlist
    struct Node *t, *last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void create2(int A[], int n)
{
    int i;
    // t: temp ptr, last traces the ele of linkedlist
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void display(struct Node *p){
    while(p!=NULL){
        printf("%d  ",p->data);
        p = p->next;
    }
}
void R_Display(struct Node *p){
    if(p!=NULL){
        printf("%d  ", p->data);
        R_Display(p->next);
    }
}
int countElem(struct Node *p){
    int i = 0;
    while(p!=NULL){
        i++;
        p=p->next;
    }
    return i;
}
int R_countElem(struct Node *p){
    if (p != NULL)
    {
        return R_countElem(p) + 1;
    }
    else
    {
        return 0;
    }
}
int sum(struct Node *p){
    int i = 0;
    while (p != NULL)
    {
        i+=p->data;
        p = p->next;
    }
    return i;
}
int R_sum(struct Node *p){
    if(p!=NULL){
        return p->data + R_sum(p->next);
    }
    return 0;
}
int maxNum(struct Node *p){
    int min = INT_MIN;
    while (p != NULL)
    {
        if(min<p->data){
            min = p->data;
        }
        p=p->next;
    }
    return min;
}
int R_maxNum(struct Node *p){
    if(p==NULL){
        return INT_MIN;
    }else{
        int x = R_maxNum(p->next);
        if(x>p->data){
            return x;
        }else{
            return p->data;
        }
    }
}
int minNum(struct Node *p)
{
    int max = INT_MAX;
    while (p != NULL)
    {
        if (max > p->data)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}
int R_minNum(struct Node *p)
{
    if (p == NULL)
    {
        return INT_MAX;
    }
    else
    {
        int x = R_minNum(p->next);
        if (x < p->data)
        {
            return x;
        }
        else
        {
            return p->data;
        }
    }
}
struct Node *LSearch(struct Node *p, int key){
    while(p !=NULL){
        if(p->data == key){
            return p;
        }else{
            p = p->next;
        }
    }
    return NULL;
}

struct Node *R_LSearch(struct Node *p, int key){
    if(p!=NULL){
        if(p->data == key){
            return p;
        }else{
            return R_LSearch(p->next,key);
        }
    }
    return NULL;
}

struct Node *S_LSearch(struct Node *p, int key){
    struct Node *q;
    while(p!=NULL){
        if(p->data==key){
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

void insert(struct Node *p, int x, int index){
    struct Node *t;
    if(index <0 || index>countElem(p)){
        return;
    }
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if(index == 0){
        t->next = p;
        first = t;
    }else{
        struct Node *q;
        for (int i = 0; i < index; i++)
        {
            q = p;
            p = p->next;
        }

        if (p->next == NULL)
        {
            p->next = t;
            t->next = NULL;
        }
        else
        {
            q->next = t;
            t->next = p;
        }
    }

}
void SelectionSort(struct Node *head)
{
    struct Node *start = head;
    struct Node *traverse;
    struct Node *min;

    while (start->next)
    {
        min = start;
        traverse = start->next;

        while (traverse)
        {
            /* Find minimum element from array */
            if (min->data > traverse->data)
            {
                min = traverse;
            }

            traverse = traverse->next;
        }
        int temp = start->data;
        start->data = min->data;
        min->data = temp;
        start = start->next;
    }
}

void insertInOrder(struct Node *p, int i){
    struct Node *q = (struct Node *)malloc(sizeof(struct Node));
    q->data = i;
    if(p==NULL){
        q->next = p;
        first = q;
    }else{
        struct Node *t;
        while(p!=NULL){
            if(q->data<p->data){
                break;
            }
            t=p;
            p=p->next;
        }
        t->next= q;
        q->next = p;
    }
}
void deleteFromHead(struct Node *p){
    if(p==NULL){
        printf("This linkedlist contains no element");
        return;
    }
    struct Node *q;
    q=p->next;
    first->next = q;
    first = q;
}
void deleteFromIdx(struct Node *p, int index){
    struct Node *q;
    int x;
    if(index<0 || index>countElem(p)){
        printf("Invalid index\n");
        return;
    }else{
        if(index==0){
            deleteFromHead(p);
        }else{
            for (int i = 0; i < index-1; i++)
            {
                p = p->next;
            }
            if(p->next->next == NULL){
                p->next = NULL;
            }else{
                p->next = p->next->next;
            }
        }
    }
}
int checkIfSorted(struct Node *p){
    int temp = INT_MIN;
    while(p!=NULL){
        if(p->data<temp){
            return -1;
        }
        temp = p->data;
        p=p->next;
    }
    return 0;
}

void removeDuplicates(struct Node *p){
    struct Node *cur = p;
    struct Node *next_next;

    if(cur == NULL){
        return;
    }
    while(cur->next != NULL){
        if(cur->data == cur->next->data){
            next_next = cur->next->next;
            cur->next =  next_next;
        }else{
            cur=cur->next;
        }
    }
}
// ptr2 ptr1 cur
void reverseList(struct Node *cur){
    struct Node *ptr1=NULL,*ptr2=NULL;
    while(cur!=NULL){
        ptr2 = ptr1;
        ptr1 = cur;
        cur = cur->next;
        ptr1->next = ptr2;
    }
    first = ptr1;
}
void concateTwoList(struct Node *fList, struct Node *sList){
    display(fList);
    printf("----\n");
    display(sList);
    printf("----\n");
    while(fList->next!=NULL)
        fList = fList->next;
    fList->next = sList;
}
int isLoop(struct Node *f){
    struct Node *p,*q;
    q=p=f;
    do{
        p=p->next;
        q=q->next;
        // check if it becomes null, if not null, move to next null
        if(q!=NULL){
            q=q->next;
        }else{
            q = NULL;
        }
    }while(p&&q &&p!=q);
    if(p==q){
        return 1;
    }else{
        return 0;
    }
}
int main()
{
    int A[] = { 3,5,7,10,15 };
    create(A, 5);
    R_Display(first);
    printf("\nNumber of node : %d",countElem(first));
    printf("\nSum : %d", R_sum(first));
    printf("\nMax : %d",R_maxNum(first));
    printf("\nMin : %d", R_minNum(first));
    struct Node *temp;
    temp = S_LSearch(first, 10);
    if(!temp){
        printf("\nKey is not found");
    }else{
        printf("\nKey number %d is found at linkedlist\n",temp->data);
    }
    R_Display(first);
    insert(first,9,countElem(first)-1);
    printf("\n");
    R_Display(first);
    SelectionSort(first);
    printf("\n");
    display(first);
    printf("\n");
    insertInOrder(first,16);
    display(first);
    deleteFromHead(first);
    printf("\n");
    display(first);
    printf("\n");
    deleteFromIdx(first,1);
    display(first);
    printf("\n");
    insert(first,100,0);
    display(first);
    printf("\n");
    if(checkIfSorted(first)==-1){
        printf("Linkedlist isn't sorted");
    }else{
        printf("Linkedlist is sorted");
    }
    deleteFromHead(first);
    insertInOrder(first,9);
    insertInOrder(first, 9);
    insertInOrder(first, 9);
    insertInOrder(first, 9);
    printf("\n");
    display(first);
    removeDuplicates(first);
    printf("\n");
    display(first);
    printf("\n");
    reverseList(first);
    display(first);
    printf("\n");
    int B[] = {9,18,22,66};
    create2(B, 4);
    concateTwoList(first,second);
    SelectionSort(first);
    removeDuplicates(first);
    printf("\n");
    display(first);
    return 0;
}
