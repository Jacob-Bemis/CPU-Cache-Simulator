#include "tools.h"
#include <stdint.h>


//Function for calculating log base 2
int calc_log_2(int num);

uint32_t get_offset(uint32_t addr, int BS){
    int offset_bits = calc_log_2(BS);
    uint32_t offset_MASK = (1 << offset_bits) - 1; //set the LSB to be the same number of bits as the offset
    addr = addr & offset_MASK; // clear left most bits
    return addr;
}

uint32_t get_index(uint32_t addr, int SETS, int BS){
    int offset_bits = calc_log_2(BS);
    int index_bits = calc_log_2(SETS);
    uint32_t index_MASK = (1 << index_bits) - 1;//set the LSB to be the same number of bits as the index
    addr = addr >> offset_bits;
    addr = addr & index_MASK; // clear left most bits
    return addr;
}

uint32_t get_tag(uint32_t addr, int SETS, int BS){
    int offset_bits = calc_log_2(BS);
    int index_bits = calc_log_2(SETS);
    int tag_bits = 32 - offset_bits - index_bits;
    uint32_t tag_MASK = (1 << tag_bits) - 1;//set the LSB to be the same number of bits as the tag
    addr = addr >> (offset_bits + index_bits);
    addr = addr & tag_MASK; // clear left most bits
    return addr;
}

int calc_log_2(int num){
    int div_count = 0;
    while (num > 1){
        num = num / 2;
        div_count++;
    }
    return div_count;
}
