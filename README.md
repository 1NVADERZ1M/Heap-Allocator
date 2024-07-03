# Halloc - Simple Heap Allocator

Halloc is a minimalistic heap allocator implemented in C, utilizing the `mmap` system call to manage memory. It's designed to provide a basic understanding of how dynamic memory allocation works under the hood, making it a valuable educational tool for those interested in low-level memory management.

## Features

- **Simple API**: Halloc exposes a straightforward interface for memory allocation and deallocation, making it easy to integrate and use in your projects.
- **Custom Memory Management**: By leveraging `mmap`, Halloc bypasses the standard C library's memory allocation routines, offering a sandbox to experiment with heap management concepts.
- **Double-Linked List**: The allocator uses a double-linked list to keep track of memory blocks, supporting both forward and backward traversal for efficient memory operations.

## Getting Started

### Prerequisites

- A C compiler (e.g., GCC, Clang)
- Linux environment (due to the use of `mmap` with `MAP_ANONYMOUS`)

### Compilation

To compile the Halloc program, use the following command:

```bash
gcc -o halloc halloc.c
'''
