# OpenMP

The collection of compiler directives, library routines, and environment variables described in this document collectively define under the specification of the OpenMP Application Program Interface (OpenMP API) for shared-memory parallelism in C, C++ and Fortran programs

## Environment Variables

- OMP_NUM_THREADS : Specify the number of threads

## Runtime Library

- omp_get_thread_num() : Get the thread ID
- omp_get_num_threads() : Returns the number of threads currently executing some instruction
- omp_get_max_threads() : Maximum number of threads that can be created
- omp_set_num_threads(int num) : Set total threads

## C Directive

```c
#pragma omp <construct>
```

### NOTE : If the braces are not present then the directive will be applied to the next line only

## Parallel Region Construct

A parallel region is a block of code that will be executed by multiple threads at the same time. Any variable declared inside a parallel block is a **private** variables whereas any variable declared outside the parallel block is a shared variable.

## Shared Variable

A shared variable can be treated as a read-only entitiy. When a shared variable is being accessed in a parallel construct we need to make sure there is no case of read-write conflict or it may lead to race condtions.

## Private Variable

Each thread will have a copy of the private variable and it's scope is limited to that thread only. This resolves read-write conflict however leads to excess use of storage.

Use shared variable when that variable will only be used for reading. Use private variable when we also need to write.

Accessing and Updating each element of an array irrespective of any other elements is done via shared variable because each thread will only access one part of the array instead of array as a whole.

### NOTE : Master always has thread number 0

## Private Construct

```c
#pragma omp parallel private(variable name)
```

When using the above parallel construct the value of the variable (if assigned) before the parallel construct is not present in the parallel construct.

Suppose the value outside was 10. 10 won't be accessible by the threads inside the parallel construct. Each thread would need to define the value inside the parallel construct before using it or else we'll get some garbage value. After the parallel construct has finished executing, the value of the private variable outside the construct will be same as the value it had before the construct.

## Concept of team

Suppose we have set the variable OMP_NUM_THREADS=4

When the master thread encounters

```c
#pragma omp parallel
```

3 new threads are created. These 3 thread along with the master forms a **team**.

## For Directive

```c
#pragma omp parallel for
for(i=0; i<num; i++) {

}
```

By default the loop variable i will be a private variable. However this is not applicable for nested loops. In case of nested loops, only the outer loop has its variable private by default. However the inner loop variable can be set to private by default by initializing the variable inside the forloop or else using the private directive

```c
#pragma omp parallel for private(inner_loop_variable)
```

#### Using For inside Parallel work construct

```c
#pragma omp parallel
{
	#pragma omp for
}
```

Use the above if parallel construct also needs to contain parallel for.

Use the below if parallel construct only contains the for.

```c
#pragma omp parallel for
```

## No Wait Directive

```c
#pragma omp parallel for nowait
```

What no wait does is that when a thread has completed the execution of the for loop, it won't wait for other threads to finish executing. It will go an execute the next piece of code that is present.

## Barrier Directive

```c
#pragma omp barrier
```

The above directive is used to halt the code execution at a point inside a parallel construct to ensure that all the threads have reached the same point. This is used as a synchronization mechanism.

Many directives in OpenMP already provide us with an implicit barrier ( unless nowait clause is supplied )

## Section Directive

```c
#pragma omp parallel sections
{
	#pragma omp section
		<CODE>
	#pragma omp section
		<CODE>
}
```

The section construct is one way to distribute different tasks to different threads. Each section will be executed by only one thread.

It is not possible to determine if one section will be executed before another or if two sections will be executed by the same thread.A thread may execute more than one section if there are more sections than threads.

## Single Directive

```c
#pragma omp single
```

This is used to ensure that the block of code is executed only by a single thread instead of all the threads. Mostly used in I/O operations.single.

## Thread Private Directive

```c
#pragma omp threadprivate(var_name)
```

Thread Private is used to globally associate a private value with each thread. It is similar to private. However the key difference is private is scope specific ie. it's value cannot be accessed by the same thread from outside the scope. Thread Private directive allows accessing private variables from one parallel scope to another.

## First Private Directive

- Used with For Loop
- Can also be used with parallel construcy

```c
#pragma omp parallel for firstprivate(x)
```

Firstprivate specifies that each thread should have its own instance of a variable (similar to private), and that the variable should be initialized with the value of the variable that is present in the parallel or serial construct.

In simple words, if a variable is private only, it doesn't inherit the value that was present already. First Private allows us to inherit that value.

## Last Private Directive

- Used only with loops

```c
#pragma omp parallel for lastprivate(x)
```

Last private is similar to private. The only difference, the variable x will now hold the last computer value in the for loop. For example if x was initially 0 and inside the parallel for we increment it to 10, then after that parallel construct is over, the value of x will be updated to 10.

## Critical Construct

```c
#pragma omp critical
```

Ensures that the enclosed block of code is executed by one thread at a time. Single Directive ensures that the block of code is executed by only one thread.

## Master Directive

```c
#pragma omp master
```

Ensures that the enclosed block of code is executed only by the master thread ie. 0

## Shared Directive

```c
#pragma omp parallel shared(x)
```

This directive is already implemented by default ie. variables initialized outside the parallel construct are treated as shared variables.

## Reduction Directive

```c
#pragma omp parallel for reduction(operator: varname)
```

This directive is used to find the sum, product or any other mathematical operator inside a for loop which otherwise would have caused a read-write conflict. For eg `sum_of_var += arr[i];` causes a conflict. However if it was defined as `reduction(+,sum_of_var)` then it would be correct.

So in simple terms, reduction directive allows us to find the sum, product of array elements.

## Atomic Directive

```c
#pragma omp atomic
```

Similar to critical but only for a single statement.

## Ordered Directive

```c
#pragma omp ordered
```

Executes the code sequentially among the threads.

## Copyprivate Directive

```c
#pragma omp single copyprivate(var_name)
```

Broadcast values of privates from one thread of a team to the other threads in the team.

## Locking mechanism

```c
omp_lock_t lock;
omp_init_lock(&lock);
#pragma omp parallel
{
	omp_set_lock(&lock);
	omp_unset_lock(&lock);
}
omp_destroy_loc(&lock);
```

## Scheduling Mechanism

A schedule in OpenMP decides how loop iterations are divided among the threads. OpenMP supports 5 kinds of schedules for OpenMP

- static
- dynamic
- guided
- auto
- runtime

### Static Scheduling ( Default Scheduling )

Divides the iterations in a set of chunks

`schedule(static, chunk_size)`

if no chunk_size if specified, OpenMP tries to distribute it evenly among all the threads. Else it will assign the first n ( chunk_size ) iterations to the first thread, then the next n to the second thread and so on.

### Dynamic Scheduling

Divides the iterations in a set of chunks. In static, the iterations are associated at first. So thread 0 knows which iterations it needs to execute. However in dynamic scheduling, we do not know after the first set of execution which thread will be given the responsibility to execute the next chunk of tasks. So it may happen that one thread executes all the task.

OpenMP divides the iterations into chunks of size chunk-size. Each thread executes a chunk of iterations and then requests another chunk until there are no more chunks available.

There is no particular order in which the chunks are distributed to the threads. The order changes each time when we execute the for loop.

`schedule(dynamic, chunk_size)`

This scheduling is determined at run time.

#### In default scheduling

thread 1 is assigned to do iterations 1 to 8;

thread 2 is assigned to do iterations 9 to 16.

#### In static scheduling, using a "chunksize" of 4:

thread 1 is assigned to do iterations 1 to 4 and 9 to 12.

thread 2 is assigned to do iterations 5 to 8 and 13 to 16.

#### In dynamic scheduling, using a "chunksize" of 3:

thread 1 is assigned to do iterations 1 to 3.

thread 2 is assigned to do iterations 4 to 6. However if thread1 completes execution before thread2 can be given a chunk, then the chink will be given to thread1

The next chunk is iterations 7 to 9, and will be assigned to whichever thread finishes its current work first, and so on until all work is completed.

### Guided Scheduling

Similar to dynamic scheduling, but the chunk size starts off large and decreases to better handle load imbalance between iterations. The optional chunk parameter specifies them minimum size chunk to use. By default the chunk size is approximately loop_count/number_of_threads.

So in guided scheduling, we may have one of the thread executing a chunk of size 30 and another thread executing a chunk of size 2. All these values are determined during runtime. The paramater chunk_size refers to the minimum chunk size possible.

### Auto Scheduling

`#pragma omp for schedule(auto)`

Let the compiler decide the type of scheduling to run

### Setting the default scheduling type

```c
omp_set_schedule(omp_sched_static);
omp_set_schedule(omp_sched_dynamic);
omp_set_schedule(omp_sched_guided);
omp_set_schedule(omp_sched_auto);
```

OR

```bash
export OMP_SCHEDULE=dynamic
```

- def-sched-var - controls the implementation defined default scheduling of loop regions.
- run-sched-var - stores scheduling information to be used for loop regions using the RUNTIME schedule clause

All the above set_schedule commands sets the run-sched-var variable.
