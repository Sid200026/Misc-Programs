# Node Module System

### There are some modules that need to be loaded like fs and some that need not be loaded like console. We use the require function to load in other modules. The require function will return the content of that module and we need to store it in a variable.

### We can even import our own files by using the require function. Whenever a file is passed in as required, nodejs will completely execute the file. However each file has its own scope. So variables in one file cannot be accessed by the other file. However we have a way to do it. Using module.exports. Whatever we assign to module.exports, that acts as a return value when we require the file

## Important Links

[NodeJS Documentation](https://nodejs.org/dist/latest-v12.x/docs/api/ "NodeJS Documentation")

## Using custom npm packages

#### After installing a package using npm, we can use that package in our code using 
`require('package_name')`

# FS Module

### Using this module


    const fs = require('fs');


### All file system operations have synchronous and asynchronous forms.

### The asynchronous form always takes a completion callback as its last argument. The arguments passed to the completion callback depend on the method, but the first argument is always reserved for an exception. If the operation was completed successfully, then the first argument will be null or undefined.

    const fs = require('fs');

    fs.unlink('/tmp/hello', (err) => {

        if (err) throw err;

    console.log('successfully deleted /tmp/hello');
    });


### Exceptions that occur using synchronous operations are thrown immediately and may be handled using try…catch, or may be allowed to bubble up.

### There is no guaranteed ordering when using asynchronous methods. Suppose we want to create a file and then delete it. It may happen that due to asynchronous calls delete ran first which can cause an error. To resolve this use adelete in the callback of create file call.

### In busy processes, use the asynchronous versions of the calls. The synchronous versions will block the entire process until they complete, halting all connections.

---
#### Warning : Omitting the callback may be deprecated in the future.
---

### Most fs operations accept filepaths that may be specified in the form of a string, a Buffer, or a URL object using the file: protocol. Mostly we can use the string object to specify the file however we may need to use Byte form in case of posix operating systems which treat file paths as opaque byte sequences.

### String form paths are interpreted as UTF-8 character sequences identifying the absolute or relative filename. Relative paths will be resolved relative to the current working directory as specified by process.cwd().

### The process. cwd() method is an inbuilt application programming interface of the process module which is used to get the current working directory of the node. js process

### On POSIX systems, for every process, the kernel maintains a table of currently open files and resources. Each open file is assigned a simple numeric identifier called a file descriptor. At the system-level, all file system operations use these file descriptors to identify and track each specific file. Windows systems use a different but conceptually similar mechanism for tracking resources. To simplify things for users, Node.js abstracts away the specific differences between operating systems and assigns all open files a numeric file descriptor.

### The fs.open() method is used to allocate a new file descriptor. Once allocated, the file descriptor may be used to read data from, write data to, or request information about the file.

### Most operating systems limit the number of file descriptors that may be open at any given time so it is critical to close the descriptor when operations are completed. Failure to do so will result in a memory leak that will eventually cause an application to crash.

    fs.open('/open/some/file.txt', 'r', (err, fd) => {
        if (err) throw err;
        fs.fstat(fd, (err, stat) => {
            if (err) throw err;
            // use stat

            // always close the file descriptor!
            fs.close(fd, (err) => {
            if (err) throw err;
            });
        });
    });

# Command Line Arguments

### argv stands for argument vector

    console.log(process.argv)

## Output

    [
    '/usr/local/bin/node',
    '/Users/sid/Documents/Programming/NodeJS/Node Module System/command_line_args.js',
    'Siddharth'
    ]

# Debugger

### NodeJS comes with a built-in debugger, which can be used by
    node inspect app.js

### We would need to use debugger keyboard to pause program execution at some point. Then we can go to chrome://inspect to debug the nodejs application.