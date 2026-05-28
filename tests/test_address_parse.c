#include "../src/tools.h"
#include <stdio.h>

void check(char *test_name, uint32_t expected, uint32_t actual){
    if (expected == actual){
        printf("%s -> Test Passed!\n", test_name);
    } else{
        printf("%s -> Test Failed, expected %u , got %u \n", test_name, expected, actual);
    }
}

int main(void){
    uint32_t result;

    printf("Simple Test - Address: 0x000005FF, Block Size: 64, Sets: 8\n");
    result = get_offset(0x000005FF, 64);
    check("offset: 63", 63, result);

    result = get_index(0x000005FF, 8, 64);
    check("index: 7", 7, result);

    result = get_tag(0x000005FF, 8, 64);
    check("tag: 2", 2, result);

    printf("\n");

    printf("Zeros Test - Address: 0x00000000, Block Size: 128, Sets: 8\n");
    result = get_offset(0x00000000, 128);
    check("offset: 0", 0, result);

    result = get_index(0x00000000, 8, 128);
    check("index: 0", 0, result);

    result = get_tag(0x00000000, 8, 128);
    check("tag: 0", 0, result);

    printf("\n");

    printf("010 Test - Address: 0x00000040, Block Size: 64, Sets: 8\n");
    result = get_offset(0x00000040, 64);
    check("offset: 0", 0, result);

    result = get_index(0x00000040, 8, 64);
    check("index: 1", 1, result);

    result = get_tag(0x00000040, 8, 64);
    check("tag: 0", 0, result);

    return 0;
}
