#include <stdio.h>
#include "tests.h"
#include "threads/thread.h"
#include "threads/synch.h"

struct lock lock;

void function(){
    printf("Message to send before critical region.\n My tid is %d\n", thread_current()->tid);
    lock_acquire(&lock);

    printf("Message to send before critical region.\n My tid is %d\n", thread_current()->tid);
    lock_release(&lock);

    printf("Message to send before critical region.\n My tid is %d\n", thread_current()->tid);
}

void my_test_sync_lock()
{
    lock_init_name(&lock, "my_test_lock");
    printf("Test for locks\n");

    int i = 0;
    for (i = 0; i < 10; i++)
    {
        thread_create("my_thread", PRI_DEFAULT, function, NULL);
    }
}