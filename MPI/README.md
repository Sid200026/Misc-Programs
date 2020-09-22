# MPI

```bash
apple@Apples-MacBook-Air MPI % export "2 defines the number of cores you want to use"
apple@Apples-MacBook-Air MPI % mpicc -o hello hello_world.c
apple@Apples-MacBook-Air MPI % mpirun -np 2 hello
```

### Communicator and Rank

The first concept is the notion of a communicator. A communicator defines a group of processes that have the ability to communicate with one another. In this group of processes, each is assigned a unique rank, and they explicitly communicate with one another by their ranks.

The foundation of communication is built upon send and receive operations among processes. A process may send a message to another process by providing the rank of the process and a unique tag to identify the message. The receiver can then post a receive for a message with a given tag (or it may not even care about the tag), and then handle the data accordingly. Communications such as this which involve one sender and receiver are known as point-to-point communications.

### MPI_Init

Initializes the MPI environment. This routine must be called by one thread only. That thread is called the main thread and must be the thread that calls MPI_Finalize.

During MPI_Init, all of MPI’s global and internal variables are constructed. For example, a communicator is formed around all of the processes that were spawned, and unique ranks are assigned to each process. Currently, MPI_Init takes two arguments that are not necessary, and the extra parameters are simply left as extra space in case future implementations might need them.

### MPI_Comm_size

Returns the size of the communicator ie. number of process that have the ability to communicate with one another.

### MPI_COMM_WORLD

MPI_COMM_WORLD (which is constructed for us by MPI) encloses all of the processes in the job, so this call should return the amount of processes that were requested for the job.

### MPI_Comm_rank

Returns the rank of all the communicators

### MPI_Get_processor_name

Gets the name of the processor in which the current thread resides

### MPI_Finalize

MPI_Finalize is used to clean up the MPI environment. No more MPI calls can be made after this one.

### Sending and Receiving Messages in MPI

MPI’s send and receive calls operate in the following manner. First, process A decides a message needs to be sent to process B. Process A then packs up all of its necessary data into a buffer for process B. These buffers are often referred to as envelopes since the data is being packed into a single message before transmission (similar to how letters are packed into envelopes before transmission to the post office). After the data is packed into a buffer, the communication device (which is often a network) is responsible for routing the message to the proper location. The location of the message is defined by the process’s rank.

Even though the message is routed to B, process B still has to acknowledge that it wants to receive A’s data. Once it does this, the data has been transmitted. Process A is acknowledged that the data has been transmitted and may go back to work.

Sometimes there are cases when A might have to send many different types of messages to B. Instead of B having to go through extra measures to differentiate all these messages, MPI allows senders and receivers to also specify message IDs with the message (known as tags). When process B only requests a message with a certain tag number, messages with different tags will be buffered by the network until B is ready for them.

### Datatypes in MPI

int -> MPI_INT
char -> MPI_CHAR
....

### MPI_Send

MPI_Send(
void\* data,
int count,
MPI_Datatype datatype,
int destination,
int tag,
MPI_Comm communicator)

### MPI_Recv

MPI_Recv(
void* data,
int count,
MPI_Datatype datatype,
int source,
int tag,
MPI_Comm communicator,
MPI_Status* status)

The first argument is the data buffer. The second and third arguments describe the count and type of elements that reside in the buffer. MPI_Send sends the exact count of elements, and MPI_Recv will receive at most the count of elements (more on this in the next lesson). The fourth and fifth arguments specify the rank of the sending/receiving process and the tag of the message. The sixth argument specifies the communicator and the last argument (for MPI_Recv only) provides information about the received message.

### MPI_STATUS_IGNORE

Ignore the status argument of MPI_Recv

### Status Structure MPI_Status

The rank of the sender. The rank of the sender is stored in the MPI_SOURCE element of the structure. That is, if we declare an MPI_Status stat variable, the rank can be accessed with stat.MPI_SOURCE.

The tag of the message. The tag of the message can be accessed by the MPI_TAG element of the structure (similar to MPI_SOURCE).

The length of the message. The length of the message does not have a predefined element in the status structure. Instead, we have to find out the length of the message with MPI_Get_count.

### Length of the message from the status structure MPI_Get_count

MPI_Get_count(
MPI_Status* status,
MPI_Datatype datatype,
int* count)

### MPI_Probe

Get the status before using MPI_Recv

### Blocking Communication

The above two MPI_Send and MPI_Recv are examples of blocking communications. This means that the entire execution process is stopped unless some information is send or received.

### Non-Blocking Communication

#### MPI_Isend, MPI_Irecv, MPI_Request, MPI_Wait

```c

int MPI_Isend(
    const void *buf,
    int count,
    MPI_Datatype datatype,
    int dest,
    int tag,
    MPI_Comm comm,
    MPI_Request *request)

int MPI_Irecv(
  void *buf,
  int count,
  MPI_Datatype datatype,
  int source,
  int tag,
  MPI_Comm comm,
  MPI_Request *request
);

int MPI_Wait(MPI_Request *request, MPI_Status *status) // Waits for an MPI request to complete

```

We need to use MPI_Wait on the non-blocking request before using finalize. The MPI_Wait is a blocking statement.

### All the above methods are point to point communication ie. between two processors

### Broadcast

A broadcast is one of the standard collective communication techniques. During a broadcast, one process sends the same data to all processes in a communicator. One of the main uses of broadcasting is to send out user input to a parallel program, or send out configuration parameters to all processes.

```c
MPI_Bcast(
    void* data,
    int count,
    MPI_Datatype datatype,
    int root,
    MPI_Comm communicator
)
```

`MPI_Bcast(&num, 1, MPI_INT, MASTER, MPI_COMM_WORLD);`

The MPI_Bcast must be available to all the processes. The process having its rank = MASTER will be responsible for broadcasting the message whereas all the other processes will listen to it.

#### MPI_Barrier

Used for synchronization of processes

```c
MPI_Barrier(MPI_Comm communicator)
```

### Scatter

https://mpitutorial.com/tutorials/mpi-scatter-gather-and-allgather/

Refer to the Scatter vs Bcast image to get the difference between MPI_Bcast and MPI_Scatter. Broadcast allows us to send the same message to all the processes whereas scatter allows us to send different messages to everyone.

### Gather

Opposite of scatter. It gathers value from different processes into a single process. ( Useful in parallel tasks like merge function in merge sort ).

```c
int MPI_Gather(
  void *sendbuf,
  int sendcnt,
  MPI_Datatype sendtype,
  void *recvbuf,
  int recvcnt, // Count of elements in each receive
  MPI_Datatype recvtype,
  int root,
  MPI_Comm comm
);
```

We can even pass `NULL` in the sendbuf.

### All Gather

```c
MPI_Allgather(
    void* send_data,
    int send_count,
    MPI_Datatype send_datatype,
    void* recv_data,
    int recv_count,
    MPI_Datatype recv_datatype,
    MPI_Comm communicator)
```

Given a set of elements distributed across all processes, MPI_Allgather will gather all of the elements to all the processes. In the most basic sense, MPI_Allgather is an MPI_Gather followed by an MPI_Bcast. The illustration below shows how data is distributed after a call to MPI_Allgather.

MPI_Allgather does not have any root process.

### Reduce and AllReduce

Very similar to gather except that it allows to do computations on the input buffer.

```c
MPI_Reduce(
    void* send_data,
    void* recv_data,
    int count,
    MPI_Datatype datatype,
    MPI_Op op,
    int root,
    MPI_Comm communicator)
```

Similar to MPI_Gather, MPI_Reduce takes an array of input elements on each process and returns an array of output elements to the root process. The output elements contain the reduced result.

```
MPI_MAX - Returns the maximum element.
MPI_MIN - Returns the minimum element.
MPI_SUM - Sums the elements.
MPI_PROD - Multiplies all elements.
MPI_LAND - Performs a logical and across the elements.
MPI_LOR - Performs a logical or across the elements.
MPI_BAND - Performs a bitwise and across the bits of the elements.
MPI_BOR - Performs a bitwise or across the bits of the elements.
MPI_MAXLOC - Returns the maximum value and the rank of the process that owns it.
MPI_MINLOC - Returns the minimum value and the rank of the process that owns it.
```

The difference between reduce and allreduce is the same as gather and allgather.

```c
MPI_Allreduce(
    void* send_data,
    void* recv_data,
    int count,
    MPI_Datatype datatype,
    MPI_Op op,
    MPI_Comm communicator)
```
