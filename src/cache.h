#ifndef CACHE_H_
#define CACHE_H_

#include <stdint.h>
#include <stdbool.h>

typedef struct Way{
    uint8_t validBit;
    uint8_t dirtyBit;
    uint32_t tag;
    uint8_t *data;
} Way;

typedef struct Set{
    Way *wayArray;
    int *lru_counters; // keeps track of the counter for the number of times a way is used.
                       // The way with the lowest counter is the least used
}Set;

typedef struct Cache{
    int numSets;
    int numWays;
    int blockSize;
    Set *setArray;
    int used_counter;
} Cache;

Cache* cache_init(int numSets, int numWays, int BS);
void cache_free(Cache* cache);
Way* cache_search(Cache* cache, uint32_t addr);
void cache_insert(Cache* cache, uint32_t addr, uint8_t *data);
uint8_t read(Cache* cache, uint32_t addr);

#endif // CACHE_H_
