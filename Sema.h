/* Course: Comp3430
 * Assignment : 2 
 * Question: 2
 * Student Name : Thai Tran
 * Student number : 7785767
 * Userid : tranttt 
 * Purpose: semaphore implementation 
 */

#ifndef SEMA
#define SEMA
#include "pthread.h"

typedef struct semaphore
{
   volatile int value;
   pthread_cond_t cond;
   pthread_mutex_t lock;
} sem;
void sem_init(sem *, int); // init semaphore
void sem_wait(sem *);      // wait
void sem_post(sem *);      // signal
void sem_broadcast(sem *); // wake waiting thread
void sem_destroy(sem *);   // destroy sem
#endif                     // !SEMAPHORE