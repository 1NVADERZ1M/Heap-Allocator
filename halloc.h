/*
 * ============================================================================
 *
 *       Filename:  halloc.h
 *
 *    Description:  Header file for halloc.c
 *
 *        Created:  06/30/2024 12:17:56
 *
 *         Author:  Ray Mier
 *   Organization:  None
 *
 * ============================================================================
 */

#ifndef HALLOC_H
#define HALLOC_H

#include <stddef.h> // For size_t

// Struct to hold metadata for blocks of memory on the heap.
typedef struct MemoryBlock {
    size_t size;
    struct MemoryBlock* next;
    struct MemoryBlock* prev;
    int isFree;
} MemoryBlock;

// Error codes
#define SUCCESS 0
#define ERROR_NULL_POINTER -1


//Global variables created in "halloc.c"
extern void* heapBase;
extern MemoryBlock* firstBlock;

//Functions for use in "halloc.h"
void halloc_initializeHeap(size_t numPages);
MemoryBlock* findFreeBlock(size_t size);
void splitBlock(MemoryBlock* block, size_t size);
void* halloc_allocate(size_t size);
void halloc_deallocate(void * ptr);

#endif 