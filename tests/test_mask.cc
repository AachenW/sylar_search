#include <stdint.h>
#include <iostream>

int main(int argc, char **argv) {
    uint32_t mask = (1 << (sizeof(uint32_t) * 8 - 10)) - 1; 
    std::cout << std::hex << mask << std::endl;
    return 0;
}
