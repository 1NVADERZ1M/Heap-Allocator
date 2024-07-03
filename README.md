# Halloc - Simple Heap Allocator

Halloc is a minimalistic heap allocator implemented in C, designed to provide a basic understanding of dynamic memory allocation mechanisms. It's an educational tool for those interested in exploring low-level memory management concepts.

## Features

- **Efficient Memory Allocation**: Implements a simple yet efficient memory allocation strategy.
- **Customizable**: Easy to modify and extend, making it perfect for educational purposes.
- **Lightweight**: Minimalistic design with a focus on the core functionalities of a heap allocator.

## Getting Started

### Prerequisites

- GCC or any standard C compiler
- Linux environment for `mmap` functionality

### Installation

Clone the repository to your local machine:

```bash
git clone https://github.com/yourusername/halloc.git
```

Compile the source code:

```bash
gcc -o halloc halloc.c
```

### Usage

To use Halloc in your C projects, include `halloc.h` and link against the compiled `halloc` library.

## API Reference

- `void* allocate(size_t size)`: Allocates a block of memory of `size` bytes.
- `void deallocate(void* ptr)`: Frees the memory block pointed to by `ptr`.

## Contributing

Contributions are welcome! If you have suggestions for improvements or bug fixes, please feel free to fork the repository and submit a pull request.