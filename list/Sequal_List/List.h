#ifndef _LIST_H_
#define _LIST_H_

typedef int ElemType; 
typedef struct Node *PtrToNode; 
typedef struct List *PtrToList; 

PtrToList List_Create(int capacity); 
void List_Destroy(PtrToList L); 
void List_Clear(PtrToList L); 

void List_Insert(PtrToList L, PtrToNode X, int P); 
void List_Delete(PtrToList L, int P); 
void Push_Front(PtrToList L, PtrToNode X); 
void Push_Back(PtrToList L, PtrToNode X); 
void Pop_Front(PtrToList L); 
void Pop_Back(PtrToList L); 

void List_Reverse(PtrToList L); 

void List_Get(const PtrToList L, const int P, PtrToNode X); 
int List_Find(const PtrToList L, const ElemType e); 

int List_Size(const PtrToList L); 
int List_Capacity(const PtrToList L); 
int List_Empty(const PtrToList L); 

void List_Print(const PtrToList L); 

void List_Sort(const PtrToList L); 

void List_Unique(const PtrToList L);

#endif
