#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"

#define FAILURE -1

struct Node {
    ElemType data; 
}; 

struct List {
    int size;  
    int capacity; 
    struct Node* array; 
}; 

PtrToList List_Create(int capacity) {
    PtrToList L = NULL; 
    if (capacity > 0) {
        L = malloc(sizeof(struct List)); 
        if (L != NULL) {
            L->size = 0; 
            L->capacity = capacity; 
            PtrToNode tmp = malloc(sizeof(struct Node)*capacity); 
            if (tmp != NULL) {
                L->array = tmp; 
            } else {
                List_Destroy(L); 
                exit(FAILURE); 
            }
        }
    }

    return L; 
} 

void List_Destroy(PtrToList L) {
#ifdef DEBUG
    printf("List_Destroy()\n"); 
#endif
    if (L != NULL) {
        if (L->array != NULL) {
            free(L->array); 
        }
        free(L); 
        L = NULL; 
    }
} 

void List_Clear(PtrToList L) {
    if (L != NULL) {
        L->size = 0; 
    }
} 

void List_Insert(PtrToList L, PtrToNode X, int P) {
    if ((L != NULL) && (P >= 0) && (P <= L->size)) {
        int inc = L->capacity; 
        if (L->size >= inc) {
            PtrToNode tmp = realloc(L->array, inc*2*sizeof(struct Node)); 
            if (tmp != NULL) {
                L->array = tmp;  
                L->capacity += inc; 
            } else {
                List_Destroy(L); 
                exit(FAILURE); 
            }
        }

        for (int i = L->size; i > P; --i) {
            L->array[i] = L->array[i-1]; 
        }
        memcpy(&(L->array[P]), X, sizeof(struct Node)); 
        ++(L->size); 
    }
} 

void List_Delete(PtrToList L, int P) {
    if ((L != NULL) && (P >= 0) && (P < L->size)){
        for (int i = P+1; i < L->size; ++i) {
            L->array[i-1] = L->array[i]; 
        }
        --(L->size); 
    }
} 

void Push_Front(PtrToList L, PtrToNode X) {
    List_Insert(L, X, 0); 
} 

void Push_Back(PtrToList L, PtrToNode X) {
    List_Insert(L, X, List_Size(L)-1); 
} 

void Pop_Front(PtrToList L) {
    List_Delete(L, 0); 
} 

void Pop_Back(PtrToList L) {
    List_Delete(L, List_Size(L)-1); 
} 

void List_Reverse(PtrToList L) {
    int tail = L->size - 1; 
    int N = L->size / 2 + 1;
    struct Node tmp; 
    for (int i = 0; i < N; ++i) {
        tmp = L->array[i]; 
        L->array[i] = L->array[tail - i]; 
        L->array[tail - i] = tmp; 
    }
} 

void List_Get(const PtrToList L, const int P, PtrToNode X) {
    if ((L != NULL) && (P >= 0) && (P < L->size)) {
        memcpy(X, &(L->array[P]), sizeof(struct Node));
    }
} 

// int List_Find(const PtrToList L, const ElemType e) {
//     int ret = -1; 
//     if (L != NULL) {
//         for (int i = 0; i < L->size; ++i) {
//             if (!memcmp(&(L->array[i].data), e, sizeof(struct Node))) {
//                 ret = i; 
//             }
//         }
//     }
// 
//     return ret; 
// } 

int List_Find(const PtrToList L, const ElemType e) {
    int ret = -1; 
    if (L != NULL) {
        for (int i = 0; i < L->size; ++i) {
            if (!memcmp(&(L->array[i].data), &e, sizeof(struct Node))) {
                struct Node tmp; 
                memcpy(&tmp, &L->array[0], sizeof(struct Node)); 
                memcpy(&(L->array[0]), &(L->array[i]), sizeof(struct Node));
                memcpy(&(L->array[i]), &tmp, sizeof(struct Node)); 
                ret = 0; 
            }
        }
    }

    return ret; 
} 

int List_Size(const PtrToList L) {
    return L->size; 
} 

int List_Capacity(const PtrToList L) {
    return L->capacity; 
} 

int List_Empty(const PtrToList L) {
    return L->size == 0; 
} 

void List_Print(const PtrToList L) {
    printf("List: "); 
    for (int i = 0; i < L->size; ++i) {
        printf("%d ", L->array[i].data); 
    }
    printf("\n"); 
}


void List_Sort(const PtrToList L) { // 选择排序
    int i, j, min_pos; 
    struct Node tmp; 
    if (L != NULL) {
        for (i = 0; i < L->size-1; ++i) {
            for (j = i+1, min_pos = i; j < L->size; ++j) {
                if (L->array[min_pos].data > L->array[j].data) {
                    min_pos = j; 
                }
            }
            memcpy(&tmp, &L->array[min_pos], sizeof(struct Node)); 
            memcpy(&L->array[min_pos], &L->array[i], sizeof(struct Node)); 
            memcpy(&L->array[i], &tmp, sizeof(struct Node)); 
        }
    }
}

void List_Unique(const PtrToList L) {
    if (L != NULL) {
        int i, j, k; 
        for (i = 0; i < L->size; ++i) {
            int dis = 0; 
            for (j = i+1; j < L->size; ++j) {
                if (!memcmp(&L->array[i], &L->array[j], sizeof(struct Node))) {
                    ++dis; 
                } else {
                    break; 
                }
            }
            for (k = j; k < L->size; ++k) {
                if (dis) {
                    memcpy(&L->array[k-dis], &L->array[k], sizeof(struct Node)); 
                }
            }
        }
    }
}
