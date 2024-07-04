#include <stdlib.h>
#include <stdbool.h>
#include <sys/mman.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <halloc.h>

/*
 * ============================================================================
 *
 *       Filename:  halloc.c
 *
 *    Description:  Simple heap allocator using mmap.
 *
 *        Created:  06/30/2024 12:17:56
 *
 *         Author:  Ray Mier
 *   Organization:  NoneAllocator
 *
 * ============================================================================
 */


//Global pointer to the start of heap.
void* heapBase = NULL;

//Global pointer to the head of the Memory Blocks (double linked-list)
MemoryBlock* firstBlock = NULL;


/*
 * Initializes the heap with mmap. 
 * 
 * mmap maps bytes to a pointer and sets them equal to 0.
 * 
 * @param size_t size: The page size to map. 
 */
void halloc_initializeHeap(size_t size){
    // Allocate initial heap block using mmap
    heapBase = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (heapBase == MAP_FAILED){
        perror("initializeHeap: mmap failed");
        heapBase = NULL;
    } else {
        firstBlock = (MemoryBlock*)heapBase;
        firstBlock->size = size - sizeof(MemoryBlock); 
        firstBlock->isFree = true;
        firstBlock->next = NULL;
        firstBlock->prev = NULL;
    }
}


/*
 * Iterates through the blocks and finds a free block with desired size.
 *
 * @param size The minimum desired size of the block
 * @return *MemoryBlock a pointer to the memory block
 */
MemoryBlock* findFreeBlock(size_t size){
    MemoryBlock* block = firstBlock;
    while(block != NULL){
        if (block-> isFree == true && block->size >= size) return block;
        else{
            block = block->next;
        }
    }
    perror("findFreeBlock: No free blocks fit the requested size.");
    return NULL;
}


/*
 * Splits block into two parts if the block is significantly larger than the desired size.
 *
 * If the block size is 128 bytes greater than the desired size, the block will be split.
 * 
 * @param MemoryBlock* block: the current block to split.
 * @param size_t size: the desired size. 
 */
void splitBlock(MemoryBlock* block, size_t size){
    if (block->size > size + 128) {
        // Calculate the address for the new block
        MemoryBlock* newBlock = (MemoryBlock*)((char*)block + sizeof(MemoryBlock) + size);
        
        // Set the new block's properties
        newBlock->size = block->size - size - sizeof(MemoryBlock);
        newBlock->isFree = true;
        newBlock->next = block->next;
        newBlock->prev = block;
        
        // Update the original block's properties
        block->size = size;
        block->next = newBlock;
        
        // If the original block had a next, update its prev to newBlock
        if (newBlock->next != NULL) {
            newBlock->next->prev = newBlock;
        }
    }
}


/*
 * Allocate a block of memory with at least the desired size.
 * 
 * @param size_t size: requested amount of memory to allocate. 
 * @return: pointer to the usable allocated memory. 
 */
void* halloc_allocate(size_t size){
    if (size == 0){
        return NULL;
    }
    MemoryBlock* block = findFreeBlock(size);
    if (block == NULL){
        return NULL;
    }

    splitBlock(block, size);
    block->isFree = false;
    return ((char*)block + sizeof(MemoryBlock));
}


/*
 * Merges adjacent free blocks to reduce fragmentation.
 * 
 * @param block The starting memory block to attempt merging from.
 * @return int Returns 0 on success, or a negative error code on failure.
 */
int mergeAdjacentFreeBlocks(MemoryBlock* block){
    if (block == NULL){
        perror("mergeAdjacentFreeBlocks: Null pointer passed as an argument.");
        return ERROR_NULL_POINTER;
    }
    if (block->isFree){
        // Merge with previous block if it's free.
        if (block->prev != NULL && block->prev->isFree){
            block->prev->size += block->size + sizeof(MemoryBlock);
            block->prev->next = block->next;
            if (block->next != NULL){
                block->next->prev = block->prev;
            }
            block = block->prev;
        }

        // Merge with next block if it's free.
        if (block->next != NULL && block->next->isFree){
            block->size += block->next->size + sizeof(MemoryBlock);
            block->next = block->next->next;
            if (block->next != NULL){
                block->next->prev = block;
            }
        }
    }
    return SUCCESS;
}


/*
 * Deallocate a block and attempt to merge with adjacent free blocks.
 *
 * @param void* ptr: pointer to the first address of usable memory.
 * 
 */
void* deallocate(void* ptr){
    // Pointer arithmatic to get the memory address to the header (MemoryBlock object)
    MemoryBlock* block = (char*)ptr - sizeof(MemoryBlock);
    block->isFree = true;
    mergeAdjacentFreeBlocks(block);
    block = NULL;
}


int main(){
    initializeHeap(4096); // Gives us 4kb of memory

    char* str = allocate(15 * sizeof(char));
    strcpy(str, "Hello World!");
    printf("Size: %zu\n", strlen(str));

    deallocate(str);

    int* nums = allocate(15 * sizeof(int));
    for (int i = 0; i < 15; i++){
        nums[i] = i;
    }

    for (int j = 0; j < 15; j++){
        printf("%d\t", nums[j]);
    }

    return 0;
}