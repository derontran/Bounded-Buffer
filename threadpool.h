/* Course: Comp3430
 * Assignment : 2 
 * Question: 2
 * Student Name : Thai Tran
 * Student number : 7785767
 * Userid : tranttt 
 * Purpose: implement a thread pool 
 */

#ifndef THREAD_POOL
#define THREAD_POOL
#include "Sema.h"
#include "pthread.h"
#include <stdlib.h>
typedef struct tpool
{
   pthread_t *threads;
   sem semInit;
   sem semClean;
   void (*function)();
   int shutdown;
   int total_thread;
} thread_pool;
thread_pool pool; // declare a pool

// init pool
void threadpool_init(void *, void *, int);
// clean pool
void clean(thread_pool *);

#endif // !THREAD_POOL
