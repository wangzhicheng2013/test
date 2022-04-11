#include <stdio.h>
#include <stdlib.h>
#define RTOS_TYPE
static void create_freertos_1(void)
{
    printf("create_freertos_1\n");
}
static void create_freertos_2(void)
{
    printf("create_freertos_2\n");
}
static void create_ucos(void)
{
    printf("create_ucos\n");
}
static void run_freertos_1(void)
{
    printf("run_freertos_1\n");
}
static void run_freertos_2(void)
{
    printf("run_freertos_2\n");
}
static void run_ucos(void)
{
    printf("run_ucos\n");
}
typedef struct _OsAdapter
{
    void (*create)(void);
    void (*run)(void);
} OsAdapter;
void create(void)
{
#ifdef RTOS_TYPE
    create_freertos_1();
    create_freertos_2();
#elif UCOS_TYPE
    create_ucos();
#endif
}
void run(void)
{
#ifdef RTOS_TYPE
    run_freertos_1();
    run_freertos_2();
#elif UCOS_TYPE
    run_ucos();
#endif
}
int main() 
{
    OsAdapter os;
    os.create = create;
    os.create();
    os.run = run;
    os.run();

    return 0;
}
