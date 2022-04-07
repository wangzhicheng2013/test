#include <stdio.h>
#include <stdlib.h>
typedef struct _DATA
{
    int protoType_data;
    struct _DATA *(*copy)(struct _DATA *);
} DATA;
DATA *data_copy(DATA *pData)
{
    DATA *pResult = (DATA *)malloc(sizeof(DATA));
    if (NULL == pResult) 
    {
        return NULL;
    }
    memmove(pResult, pData, sizeof(DATA));
    return pResult;
}
DATA *clone(DATA *pData) 
{
    return pData->copy(pData);
}
int main() 
{
    DATA *A, *B, *C;
    A = (DATA *)malloc(sizeof(DATA));
    if (NULL == A)
    {
        return -1;
    }
    A->copy = data_copy;
    B = clone(A);
    C = clone(A);
    if (B) 
    {
        free(B);
    }
    if (C) 
    {
        free(C);
    }
    free(A);
    
    return 0;
}
