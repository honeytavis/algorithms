#include "List.h"
#include <stdio.h>

int main()
{
    PtrToList L = List_Create(10); 
    // printf("List size: %d, capacity: %d\n", List_Size(L), List_Capacity(L)); 

    for (int i = 0; i < 20; ++i) {
        List_Insert(L, (PtrToNode)&i, 0); 
        List_Insert(L, (PtrToNode)&i, i); 
        // List_Insert(L, (PtrToNode)&i, List_Size(L)); 
    }
    List_Print(L); 

    // printf("List size: %d, capacity: %d\n", List_Size(L), List_Capacity(L)); 

    // for (int i = 0; i < 10; ++i) {
    //     List_Delete(L, 0); 
    //     List_Delete(L, i); 
    //     List_Delete(L, List_Size(L)-1); 
    // }
    // List_Print(L); 
    // printf("List size: %d, capacity: %d\n", List_Size(L), List_Capacity(L)); 
    // 

    // if (!List_Empty(L)) {
    //     List_Clear(L); 
    // }
    // List_Print(L); 
    // printf("List size: %d, capacity: %d\n", List_Size(L), List_Capacity(L)); 
    
    // List_Reverse(L); 
    // List_Print(L); 
    
    // List_Find(L, 3); 
    // List_Print(L); 

    List_Sort(L); 
    List_Print(L); 
    
    List_Unique(L); 
    List_Print(L); 

    List_Destroy(L); 

    return 0; 
}
