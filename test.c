#include <stdio.h>
#include <assert.h>
#define MAKE_INSTANCE 1
#define FREE_INSTANCE 0
typedef struct 
{
    int age;
    char name[12];
} record;
static record * operate_instance(int flag) 
{
    static record *pRecord = NULL;
    if (MAKE_INSTANCE == flag) 
    {
        if (NULL != pRecord)
        {
            printf("the instance existed!\n");
            return pRecord;
        }
        else
        {
            pRecord = (record *)malloc(sizeof(record));
            if (NULL == pRecord) 
            {
                printf("malloc failed!\n");
                return NULL;
            }
            else
            {
                printf("malloc success!\n");
                return pRecord;
            }
        }
    }
    else if (FREE_INSTANCE == flag)
    {
        if (NULL != pRecord)
        {
            printf("free memory!\n");
            free(pRecord);
            pRecord = NULL;
            return pRecord;
        }
        else
        {
            printf("the pointer is NULL!\n");
            return pRecord;
        }
    }
}
record *make_instance() 
{
    record *pRecord = operate_instance(MAKE_INSTANCE);
    return pRecord;
}
void free_instance()
{
    record *pRecord = operate_instance(FREE_INSTANCE);
    if (NULL == pRecord)
    {
        printf("free ok!\n");
    }
}
int main() {
    record *pRecord1 = make_instance();
    record *pRecord2 = make_instance();
    assert(pRecord1 == pRecord2);
    free_instance();

    return 0;
}
