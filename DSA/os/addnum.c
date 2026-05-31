#include<stdio.h>
#include<stdint.h>
typedef struct {
    uint32_t high; // Most significant 32 bits
    uint32_t low;  // Least significant 32 bits
} uint64_custom_t;
void add_64bit(uint64_custom_t a, uint64_custom_t b, uint64_custom_t *result) {
    result->low = a.low + b.low;
    uint32_t carry = (result->low < a.low) ? 1 : 0; // Overflow check
    result->high = a.high + b.high + carry;
}

int main (){



      uint64_custom_t num1 = {0x00000001, 0xFFFFFFFF}; // 1 + 4294967295
      uint64_custom_t num2 = {0x00000000, 0x00000001}; // 0 + 1
      uint64_custom_t result;
      
      add_64bit(num1, num2, &result);
      uint64_t a = ((uint64_t)result.high << 32 ) | result.low; // Combine high and low parts
      printf("Result: High = %u, Low = %u\n", result.high, result.low);
      printf("Combined 64-bit result: %llu\n", (unsigned long long)a);
      return 0;      
}
