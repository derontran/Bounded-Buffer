# Command for run : 
# make 
# ./BoundedBuffer
# Command for clean : make clean 


# Discussion: When I increase the buffer size from 2 to 128 and keep the number of producer at 2. the message start to formalize 
# it is readable, one sentences following by the other. this can be explained that the first thread is not be interrupted by any # one through out it's life meaning it had been doing it'work from the begining(first byte write in the buffer) to the end 
# (after finish write the last byte to the buffer). Noticed that this happened when the buffer size at 128 that bypass the 
# message's length. this can be used to draw out that because the buffer never empty for the first thread so the thread never 
# need to wait for any space to be available on the buffer. So it just keep winning the lock and write the full message to the 
# buffer without worry about the os will schedule it out. then come the second thread, just write the message in the buffer
# without compete
   