#include "cache.h"
#include "tools.h"
#include <stdlib.h>
#include <stdbool.h>

/*Initializes and allocates the structs and data types to create a cache*/
Cache* cache_init(int numSets, int numWays, int BS){
    Cache *nuCache = malloc(sizeof(Cache));
    nuCache->numSets = numSets;
    nuCache->numWays = numWays;
    nuCache->blockSize = BS;
    nuCache->used_counter = 0;
    Set *setArray = malloc(numSets * sizeof(Set));
    for (int i = 0; i < numSets; i++){
        int *lru_counters = malloc(numWays * sizeof(int));
        Way *wayArray = malloc(numWays * sizeof(Way));
        for (int j = 0; j < numWays; j++){
            uint8_t *data = malloc(BS * sizeof(uint8_t));
            Way nuWay = {0,0,0,data};
            wayArray[j] = nuWay;
            lru_counters[j] = 0;
        }
        setArray[i].wayArray = wayArray;
        setArray[i].lru_counters = lru_counters;
    }
    nuCache->setArray = setArray;
    return nuCache;
}

/*Deallocates data allocated by cache_init*/
void cache_free(Cache* cache){
    Set *setArray = cache->setArray;
    int numSets = cache->numSets;
    int numWays = cache->numWays;
    for (int i = 0; i < numSets; i++){
        Way *wayArray = setArray[i].wayArray;
        for (int j = 0; j < numWays; j++){
            free(wayArray[j].data);
        }
        free(wayArray);
        free(setArray[i].lru_counters);
    }
    free(setArray);
    free(cache);
}

/* Finds a set in cache by extracting a given address and returns a Way or a NULL:
 * Way -> Hit
 * NULL -> Miss*/
Way* cache_search(Cache* cache, uint32_t addr){
    uint32_t set = get_index(addr,cache->numSets,cache->blockSize);
    uint32_t tag = get_tag(addr,cache->numSets,cache->blockSize);
    Way *wayArray = cache->setArray[set].wayArray;
    for (int i = 0; i < cache->numWays; i++){
        if (wayArray[i].tag == tag && wayArray[i].validBit == 1){
            cache->used_counter++; // increments the counter for the number of times a way is used
            cache->setArray[set].lru_counters[i] = cache->used_counter;
            return &wayArray[i];
        }
    }
    return NULL;
}
