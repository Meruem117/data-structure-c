// 链表
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

bool InitList(LinkList &L) {
    L = (LNode *) malloc(sizeof(LNode));
    if (L == NULL) {
        return false;
    }
    L->next = NULL;
    return true;
}

bool InitList2(LinkList &L) {
    L = NULL;
    return true;
}

bool Empty(LinkList L) {
    return L->next == NULL;
}

bool Empty2(LinkList L) {
    return L == NULL;
}

bool ListInsert(LinkList &L, int i, int e) {
    if (i < 0) {
        return false;
    }
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }

    if (p == NULL) {
        return false;
    }
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool ListInsert2(LinkList &L, int i, int e) {
    if (i < 0) {
        return false;
    }
    if (i == 1) {
        LNode *s = (LNode *) malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s;
        return true;
    }
    LNode *p;
    int j = 1;
    p = L;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL) {
        return false;
    }
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool InsertNextNode(LNode *p, int e) {
    if (p == NULL) {
        return false;
    }
    LNode *s = (LNode *) malloc(sizeof(LNode));
    if (s == NULL) {
        return false;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool InsertPriorNode(LNode *p, int e) {
    if (p == NULL) {
        return false;
    }
    LNode *s = (LNode *) malloc(sizeof(LNode));
    if (s == NULL) {
        return false;
    }
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

bool ListDelete(LinkList &L, int i, int &e) {
    if (i < 0) {
        return false;
    }
    LNode *p;
    int j = 0;
    p = L;    // Lָ��ͷ��㣬ͷ����ǵ�0����㣬pָ��ͷ���
    while (p != NULL && j < i - 1) {    // ѭ���ҵ�i-1�����
        p = p->next;
        j++;
    }
    if (p == NULL) { // iֵ���Ϸ�
        return false;
    }
    if (p->next == NULL) { // ��i-1������û���������
        return false;
    }

    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(p);
    return true;
}

// ɾ��ָ�����
bool DeleteNode(LNode *p) {
    if (p == NULL) {
        return false;
    }
    LNode *q = p->next;
    p->data = p->next->data;    // ���p�����һ����㣬��������
    p->next = q->next;
    free(q);
    return true;
}

// ��λ���� - ��ͷ���
LNode *GetElem(LinkList L, int i) {
    // i=0 ����ͷ���, i>L���ȣ�����NULL
    if (i < 0) {
        return NULL;
    }
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

// ��ֵ����
LNode *LocateElem(LinkList L, int e) {
    LNode *p = L->next;
    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return p;
}

// �����
int Length(LinkList L) {
    int len = 0;
    LNode *p = L;
    while (p->next != NULL) {
        p = p->next;
        len++;
    }
    return len;
}

// β�巨����������
LinkList List_TailInsert(LinkList &L) {
    int x;
    L = (LinkList) malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

//  ͷβ�巨����������
LinkList List_HeadInsert(LinkList &L) {
    LNode *s;
    int x;
    L = (LinkList) malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

int main() {
    LinkList L;

    return 0;
}
