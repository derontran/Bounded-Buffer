# producer-consumer problem also known as bounded-buffer problem
+ The producer repeatedly generates data and writes it into the buffer. The consumer repeatedly reads the data in the buffer, removing it in the course of reading it, and using that data in some way. In the first version of the problem, with an unbounded buffer, the problem is how to design the producer and consumer code so that, in their exchange of data, no data is lost or duplicated, data is read by the consumer in the order it is written by the producer, and both processes make as much progress as possible
+ The first case to consider is the one in which there is a single producer and a single consumer, and there is a finite-size buffer. The solution for the producer is to either go to sleep or discard data if the buffer is full. The next time the consumer removes an item from the buffer, it notifies the producer, who starts to fill the buffer again. In the same way, the consumer can go to sleep if it finds the buffer empty. The next time the producer puts data into the buffer, it wakes up the sleeping consumer. The solution can be reached by means of inter-process communication, typically using semaphores

### Command for run : 
1. make 
2. ./BoundedBuffer
### Command for clean : make clean 


# Discussion: 
+ When I increase the buffer size from 2 to 128 and keep the number of producer at 2. the message start to formalize one sentences following by the other. this can be explained that the first thread is not be interrupted by anyone through out it's life meaning it had been doing it'work from the begining(first byte write in the buffer) to the end after finish write the last byte to the buffer. Noticed that this happened when the buffer size at 128 that bypass the message's length (which is 71). this is  because the buffer never empty for the first thread so it never need to wait for any space to be available on the buffer and it just keep winning the lock and write the full message to the buffer.
   