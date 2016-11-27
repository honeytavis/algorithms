#ifndef _LIST_H_
#define _LIST_H_

#include "Node.h"
#include <algorithm>

template<typename T>
class List {
public: 
  List() {
    init(); 
  }
  ~List() {
    clear(); 
    delete head; 
    delete tail; 
  }

  void insert(const T& x) {
  }

  void erase(T& x) {
  }

  void clear(PtrToList L) {
    while (!empty())
      pop_front(); 
  }

  int size() const {
    return _size; 
  }

  bool empty() const {
    return size() == 0; 
  }

  T& front() {
  }
  
  T& back() {
  }
 

  void push_front(const T& x) {
  }

  void push_back(const T& x) {
  }
  
  void pop_front() {
  }
  
  void pop_back() {
  }

  void reverse();

  Node<T>* find(const ElemType key); 

  void print(); 

  void Print_Lots(const PtrToList L, const PtrToList P); 

  void Swap_With_Next(const PtrToList L, const PtrToNode X); 

  PtrToList Intersect(const PtrToList L1, const PtrToList L2); 
  
  void merge(List<T>& L); 

private: 
  int _size; 
  Node<T>* _head; 
  Node<T>* _tail;
}; // List

struct Node {
    ElemType data; 
    struct Node* next; 
};

struct List {
    int size; 
    struct Node head; 
}; 

PtrToList List_Create() {
    PtrToList L = malloc(sizeof(struct List));
    if (L != NULL) {
        L->size = 0; 
        L->head.next = NULL; 
    } else {
        perror("malloc():"); 
        exit(FAILURE); 
    }

    return L; 
}

void List_Destroy(PtrToList L) {
    if (L != NULL) {
        List_Clear(L); 
        free(L); 
        L = NULL; 
    }
}

void List_Clear(PtrToList L) {
    if (L != NULL) {
        PtrToNode p = L->head.next; 
        L->head.next = NULL; 
        PtrToNode tmp; 
        while (p != NULL) {
            tmp = p->next; 
            free(p); 
            p = tmp; 
        }
        L->size = 0; 
    }
}

void List_Insert(PtrToList L, PtrToNode X, int P) {
    if ((L != NULL) && (P >= 0) && (P <= L->size)) {
        if (X != NULL) {
            PtrToNode tmp = malloc(sizeof(struct Node)); 
            if (tmp != NULL) {
                memcpy(tmp, X, sizeof(struct Node)); 
            }

            PtrToNode cur = &L->head; 
            for (int i = 0; i < P; ++i) {
                cur = cur->next; 
            }
            tmp->next = cur->next; 
            cur->next = tmp; 
            ++(L->size); 
        }
    }
} 

void List_Delete(PtrToList L, int P) {
    if ((L != NULL) && (P >= 0) && (P < L->size)) {
        PtrToNode cur = &L->head; 
        for (int i = 0; i < P; ++i) {
            cur = cur->next; 
        }
        PtrToNode tmp = cur->next; 
        cur->next = tmp->next; 
        tmp->next = NULL; 
        free(tmp); 
        --(L->size); 
    }
}

void Push_Front(PtrToList L, PtrToNode X) {
    List_Insert(L, X, 0); 
}

void Push_Back(PtrToList L, PtrToNode X) {
    List_Insert(L, X, L->size); 
}

void Pop_Front(PtrToList L) {
    List_Delete(L, 0); 
}

void Pop_Back(PtrToList L) {
    List_Delete(L, L->size-1); 
}

void List_Reverse(PtrToList L) {
    if (L != NULL) {
        PtrToNode start = &L->head; 
        PtrToNode cur = L->head.next; 
        start->next = NULL; // 摘下原链表的头结点

        PtrToNode tmp; 
        while (cur != NULL) {
            tmp = cur; 
            cur = cur->next; 
            tmp->next = start->next; // 头插法
            start->next = tmp; 
        }
    }
}

void List_Get(const PtrToList L, const int P, PtrToNode X) {
    if ((L != NULL) && (P >= 0) && (P < L->size)) {
        PtrToNode cur = &L->head;  
        for (int i = 0; i < P; ++i) {
            cur = cur->next; 
        }
        memcpy(X, cur->next, sizeof(struct Node)); 
    }
}

// int List_Find(const PtrToList L, const ElemType e) {
//     int ret = -1; 
//     if (L != NULL) {
//         PtrToNode cur = &L->head;
//         for (int i = 0; i < L->size; ++i, cur = cur->next) {
//             if (!memcmp(&e, &cur->next->data, sizeof(cur->data))) {
//                 ret = i; 
//                 //break; // 不需要
//             }
//         }
//     }
// 
//     return ret; 
// }

int List_Find(const PtrToList L, const ElemType e) {
    int ret = -1; 
    if (L != NULL) {
        PtrToNode cur = &L->head;
        for (int i = 0; i < L->size; ++i, cur = cur->next) {
            if (!memcmp(&e, &cur->next->data, sizeof(ElemType))) {
                PtrToNode tmp = cur->next;
                cur->next = tmp->next; 
                tmp->next = L->head.next; 
                L->head.next = tmp; 
                break; // 改变cur后，可能导致 i < L->size 满足条件时, cur->next 已经为空
                ret = 0; 
            }
            // printf("*\n"); 
        }
    }

    return ret; 
}

int List_Size(const PtrToList L) {
    int ret = -1; 
    if (L != NULL) {
        ret = L->size; 
    }

    return ret; 
}

int List_Empty(const PtrToList L) {
    return L->head.next == NULL; 
}

void List_Print(PtrToList L) {
    PtrToNode tmp = L->head.next; 
    while (tmp != NULL) {
        printf("%d ", tmp->data); 
        tmp = tmp->next; 
    }
    printf("\n"); 
}

void Print_Lots(const PtrToList L, const PtrToList P) { // O(n)
    int steps = 0; 
    PtrToNode Ppos = P->head.next;
    PtrToNode Lpos = L->head.next; 
    
    while (Lpos != NULL && Ppos != NULL) {
        if (Ppos->data == steps++) {
            printf("%d ", Lpos->data); 
            Ppos = Ppos->next; 
        } 
        Lpos = Lpos->next; 
    }
    printf("\n"); 
}

void Swap_With_Next(const PtrToList L, const PtrToNode X) {
    if (L != NULL && X != NULL) {
        PtrToNode before = &(L->head); 
        PtrToNode after = &(L->head); 
        while (before->next != NULL) {
        }
        if (before->next->data == X->data) {
            after = X->next; 
            before->next = after; 
            X->next = after->next; 
            after->next = X; 
        }
        after = after->next; 
        before = before->next; 
    }
}

PtrToList Intersect(const PtrToList L1, const PtrToList L2) {
    PtrToList L = malloc(sizeof(struct List)); 
    L->head.next = NULL; 
    if (L1 != NULL && L2 != NULL) {
        PtrToNode pos1 = L1->head.next; 
        PtrToNode pos2 = L1->head.next; 
        PtrToNode cur = &(L->head); 
        while (pos1 != NULL && pos2 != NULL) {
            if (pos1->data == pos2->data) {
                PtrToNode tmp = malloc(sizeof(struct Node)); 
                tmp->data = pos1->data; 
                tmp->next = NULL; 

                cur->next = tmp; 
                cur = cur->next; 
            } else if (pos1->data > pos2->data) {
                pos2 = pos2->next; 
            } else if (pos1-> data < pos2->data) {
                pos1 = pos1->next; 
            }
        }
    }
    return L; 
}

PtrToList Union(const PtrToList L1, const PtrToList L2) {
    PtrToList L = malloc(sizeof(struct List)); 
    L->head.next = NULL; 
    if (L1 != NULL && L2 != NULL) {
        PtrToNode pos1 = L1->head.next; 
        PtrToNode pos2 = L1->head.next; 
        PtrToNode cur = &(L->head); 
        PtrToNode tmp, e; 

        while (pos1 != NULL && pos2 != NULL) {
            if (pos1->data == pos2->data) {
                e = pos1; 
                pos1 = pos1->next; 
                pos2 = pos2->next; 
            } else if (pos1->data < pos2->data){
                e = pos1; 
                pos1 = pos1->next; 
            } else if (pos2->data < pos1->data){
                e = pos2; 
                pos2 = pos2->next; 
            }
            tmp = malloc(sizeof(struct Node)); 
            tmp->data = e->data; 
            tmp->next = NULL; 
            cur->next = tmp; 
            cur = cur->next; 
        }

        while (pos1 != NULL) {
            tmp = malloc(sizeof(struct Node)); 
            tmp->data = pos1->data; 
            tmp->next = NULL; 
            cur->next = tmp; 
            cur = cur->next; 
                
            pos1 = pos1->next; 
        }

        while (pos2 != NULL) {
            tmp = malloc(sizeof(struct Node)); 
            tmp->data = pos2->data; 
            tmp->next = NULL; 
            cur->next = tmp; 
            cur = cur->next; 

            pos2 = pos2->next; 
        }
    }
    return L; 
}

#endif
