#include <stdio.h>
#include "List.h"

int main()
{
    PtrToList L = List_Create(); 
    //printf("List size: %d\n", List_Size(L)); 

    for (int i = 0; i < 10; ++i) {
        List_Insert(L, (PtrToNode)&i, 0); 
        //List_Insert(L, (PtrToNode)&i, i); 
        //List_Insert(L, (PtrToNode)&i, List_Size(L)); 
    }
    List_Print(L); 

    //printf("List size: %d\n", List_Size(L)); 

    //for (int i = 0; i < 5; ++i) {
    //    List_Delete(L, 0); 
    //    List_Delete(L, i); 
    //    List_Delete(L, List_Size(L)-1); 
    //}
    //List_Print(L); 
    //printf("List size: %d\n", List_Size(L)); 

    //for (int i = 0, j; i < 20; ++i) {
    //    j = List_Find(L, &i); 
    //    if ( j > 0) {
    //        printf("%d is Array[%d]\n", i, List_Find(L, &i)); 
    //    }
    //}

    //if (!List_Empty(L)) {
    //    List_Clear(L); 
    //}
    //printf("List size: %d\n", List_Size(L)); 

    // List_Reverse(L); 
    // List_Print(L); 

    List_Find(L, 5); 
    List_Print(L); 

    List_Destroy(L); 

    return 0; 
}
