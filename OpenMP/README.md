# OpenMP

The collection of compiler directives, library routines, and environment variables described in this document collectively define under the specification of the OpenMP Application Program Interface (OpenMP API) for shared-memory parallelism in C, C++ and Fortran programs

## Environment Variables

* OMP_NUM_THREADS : Specify the number of threads

## Runtime Library

* omp_get_thread_num() : Get the thread ID
* omp_get_num_threads() : Returns the number of threads currently executing some instruction
* omp_get_max_threads() : Maximum number of threads that can be created
* omp_set_num_threads(int num) : Set total threads

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

This is used to ensure that the block of code is executed only by a single thread instead of all the threads. Mostly used in I/O operations.