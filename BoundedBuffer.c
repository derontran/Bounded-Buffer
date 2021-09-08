/* Course: Comp3430
 * Assignment : 2 
 * Question: 2
 * Student Name : Thai Tran
 * Student number : 7785767
 * outrid : tranttt 
 * Purpose: implement a bounded buffer 
 */

#include "Sema.h"
#include "threadpool.h"
#include "string.h"
#include "stdio.h"
#define MAX_BUFFER 128
#define NUM_PRODUCER 4
sem empty;
sem full;
sem lock;
int BUFFER[MAX_BUFFER];
int in = 0;
int out = 0;

typedef struct args_t
{
    char *strings;
    int len;
} args_t;

void write(char value)
{
    BUFFER[in] = value;
    in = (in + 1) % MAX_BUFFER;
}
char read()
{
    char tmp = BUFFER[out];
    out = (out + 1) % MAX_BUFFER;
    return tmp;
}

void *producer(void *agg)
{
    args_t *args = (args_t *)agg;

    int i;
    for (i = 0; i < args->len; i++)
    {
        sem_wait(&empty);
        sem_wait(&lock);

        write(args->strings[i]);
        sem_post(&lock);
        sem_post(&full);
    }

    return NULL;
}

void *consumer(int arg)
{
    int index, max;
    char temp;
    max = (int)(arg);
    for (index = 0; index < max; index++)
    {
        sem_wait(&full);
        sem_wait(&lock);
        temp = read();
        sem_post(&lock);
        sem_post(&empty);
        printf("%c", temp);
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    sem_init(&lock, 1);
    sem_init(&empty, MAX_BUFFER);
    sem_init(&full, 0);

    args_t arg; // innit arg storing string and len of string
    arg.strings = "Now is the time for all good people to come to the aid of their country";
    arg.len = strlen(arg.strings);

    // start running
    threadpool_init(producer, &arg, NUM_PRODUCER);
    int bytes = (arg.len) * (NUM_PRODUCER);
    consumer(bytes);
}