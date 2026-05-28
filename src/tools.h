#ifndef TOOLS_H_
#define TOOLS_H_

#include <stdint.h>

//Functions for finding the bit fields
uint32_t get_offset(uint32_t addr, int BS);
uint32_t get_index(uint32_t addr, int SETS, int BS);
uint32_t get_tag(uint32_t addr, int SETS, int BS);

#endif // TOOLS_H_
