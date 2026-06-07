#include "../src/memory.h"
#include <stdio.h>
#include <stdlib.h>

void check(uint8_t *expected, uint8_t *actual, uint32_t size, char *test_name){
    for (uint32_t i = 0; i < size; i++){
        if (expected[i] != actual[i]){
            printf("%s -> Test Failed, expected %u , got %u \n", test_name, expected[i], actual[i]);
        }
    }
    printf("%s -> Test Passed!\n", test_name);
}

int main(void){
    uint8_t *result;
    Memory *nuMem = memory_init(16);
    uint8_t *data = nuMem->data;
    for (int i = 0; i < 16; i++){ // Populates the data with values
        data[i] = i;
    }

    result = fetch_memory(nuMem, 6, 5); // fetch a block of data with 5 elements starting at index
    uint8_t actual[5] = {6,7,8,9,10};
    check(actual, result, 5, "test fetch_memory");
    free(result);
    memory_free(nuMem);

    return 0;
}
