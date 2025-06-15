#include "include/prand.h"

uint32_t prand(uint32_t max){
    srand(time(NULL));
    uint32_t pseudorandom;
    pseudorandom = rand();
    return pseudorandom % max;
}
