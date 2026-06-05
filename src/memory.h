#ifndef MEMORY_H_
#define MEMORY_H_

#include <stdio.h>
#include <stdint.h>

typedef struct Memory{
    uint8_t *data;
    uint32_t size;
}Memory;

Memory* memory_init(uint32_t size);
void memory_free(Memory* mem);
uint8_t* fetch_memory(Memory* mem, uint32_t memAddr, uint32_t size);
void write_memory(Memory* mem, uint32_t memAddr, uint32_t size, uint8_t *data);


#endif // MEMORY_H_
