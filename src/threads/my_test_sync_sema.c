#include <stdio.h>
#include "tests.h"
#include "threads/thread.h"
#include "threads/synch.h"

struct semaphore sem;

void function_sema()
{
    printf("Message to send before critical region.\n My tid is %d\n", thread_current()->tid);
    sema_down(&sem);

    printf("Message to send before critical region.\n My tid is %d\n", thread_current()->tid);
    sema_up(&sem);

    printf("Message to send before critical region.\n My tid is %d\n", thread_current()->tid);
}

void my_test_sync_sema()
{
    sema_init_name(&sem, 1, "the_test_semaphore");
    printf("Test for semaphore\n");

    int i = 0;
    for (i = 0; i < 10; i++)
    {
        thread_create("test_th", PRI_DEFAULT, function_sema, NULL);
    }
}