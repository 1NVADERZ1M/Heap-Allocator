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
gcc -o halloc halloc.c -lrt
```

### Usage

To use Halloc in your C projects, include [`halloc.h`](command:_github.copilot.openRelativePath?%5B%7B%22scheme%22%3A%22file%22%2C%22authority%22%3A%22%22%2C%22path%22%3A%22%2Fhome%2Fmier%2FDocuments%2FProgram-Vault%2FC%2FProjects%2FHeap-Allocator%2Fhalloc.h%22%2C%22query%22%3A%22%22%2C%22fragment%22%3A%22%22%7D%5D "/home/mier/Documents/Program-Vault/C/Projects/Heap-Allocator/halloc.h") in your source files and compile your project with the `halloc` library.

## API Reference

- [`void halloc_initializeHeap(size_t numPages)`](command:_github.copilot.openSymbolFromReferences?%5B%7B%22%24mid%22%3A1%2C%22path%22%3A%22%2Fhome%2Fmier%2FDocuments%2FProgram-Vault%2FC%2FProjects%2FHeap-Allocator%2Fhalloc.c%22%2C%22scheme%22%3A%22file%22%7D%2C%7B%22line%22%3A38%2C%22character%22%3A5%7D%5D "C/Projects/Heap-Allocator/halloc.c"): Initializes the heap with a specified number of memory pages. A page is typically 4096 bytes. You can run `getconf PAGESIZE` in the terminal to see your system page size.
- `void* halloc_allocate(size_t size)`: Allocates a block of memory of [`size`](command:_github.copilot.openSymbolFromReferences?%5B%7B%22%24mid%22%3A1%2C%22path%22%3A%22%2Fhome%2Fmier%2FDocuments%2FProgram-Vault%2FC%2FProjects%2FHeap-Allocator%2Fhalloc.h%22%2C%22scheme%22%3A%22file%22%7D%2C%7B%22line%22%3A22%2C%22character%22%3A11%7D%5D "C/Projects/Heap-Allocator/halloc.h") bytes and returns a pointer to the beginning of the block.
- [`void halloc_deallocate(void* ptr)`](command:_github.copilot.openSymbolFromReferences?%5B%7B%22%24mid%22%3A1%2C%22path%22%3A%22%2Fhome%2Fmier%2FDocuments%2FProgram-Vault%2FC%2FProjects%2FHeap-Allocator%2Fhalloc.c%22%2C%22scheme%22%3A%22file%22%7D%2C%7B%22line%22%3A189%2C%22character%22%3A5%7D%5D "C/Projects/Heap-Allocator/halloc.c"): Frees the memory block pointed to by [`ptr`](command:_github.copilot.openSymbolFromReferences?%5B%7B%22%24mid%22%3A1%2C%22path%22%3A%22%2Fhome%2Fmier%2FDocuments%2FProgram-Vault%2FC%2FProjects%2FHeap-Allocator%2Fhalloc.h%22%2C%22scheme%22%3A%22file%22%7D%2C%7B%22line%22%3A42%2C%22character%22%3A30%7D%5D "C/Projects/Heap-Allocator/halloc.h").
- [`MemoryBlock* findFreeBlock(size_t size)`](command:_github.copilot.openSymbolFromReferences?%5B%7B%22%24mid%22%3A1%2C%22path%22%3A%22%2Fhome%2Fmier%2FDocuments%2FProgram-Vault%2FC%2FProjects%2FHeap-Allocator%2Fhalloc.h%22%2C%22scheme%22%3A%22file%22%7D%2C%7B%22line%22%3A21%2C%22character%22%3A15%7D%5D "C/Projects/Heap-Allocator/halloc.h"): Finds a free block with at least the specified size.
- [`void splitBlock(MemoryBlock* block, size_t size)`](command:_github.copilot.openSymbolFromReferences?%5B%7B%22%24mid%22%3A1%2C%22path%22%3A%22%2Fhome%2Fmier%2FDocuments%2FProgram-Vault%2FC%2FProjects%2FHeap-Allocator%2Fhalloc.c%22%2C%22scheme%22%3A%22file%22%7D%2C%7B%22line%22%3A95%2C%22character%22%3A5%7D%5D "C/Projects/Heap-Allocator/halloc.c"): Splits a block into two parts if it is significantly larger than the desired size.

## Contributing

Contributions are welcome! If you have suggestions for improvements or bug fixes, please feel free to fork the repository and submit a pull request.