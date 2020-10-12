#include <stdio.h>
#include "tests/threads/tests.h"
#include "threads/init.h"
#include "threads/malloc.h"
#include "threads/synch.h"
#include "threads/thread.h"
#include "devices/timer.h"

void thread_body(void* the_thread){
    print_thread_info(thread_current());
}

void print_thread_info(struct thread* the_thread){
    printf("Thread's name: %s\n Tid: %d\n Status: %d\n", the_thread->name, the_thread->tid, the_thread->status);
}