#include "memory.h"
#include <stdlib.h>
#include <string.h>

Memory* memory_init(uint32_t size){
    Memory* nuMemory = malloc(sizeof(Memory));
    uint8_t *data = calloc(size, sizeof(uint8_t));
    nuMemory->data = data;
    nuMemory->size = size;
    return nuMemory;
}

void memory_free(Memory* mem){
    free(mem->data);
    free(mem);
}

uint8_t* fetch_memory(Memory* mem, uint32_t memAddr, uint32_t size){
    uint8_t *fetched_block = malloc(size * sizeof(uint8_t));
    uint8_t *memData = mem->data;
    memcpy(fetched_block, memData + memAddr, size);
    return fetched_block;
}

void write_memory(Memory* mem, uint32_t memAddr, uint32_t size, uint8_t *data){
    uint8_t *memData = mem->data;
    memcpy(memData + memAddr, data, size);
}
