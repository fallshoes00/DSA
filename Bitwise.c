#include <stdio.h>

// Set 第n個bit為1
unsigned int set_bit(unsigned int num, int n) {
    return num | (1 << n);
}

// Clear 第n個bit為0
unsigned int clear_bit(unsigned int num, int n) {
    return num & ~(1 << n);
}

// Toggle 第n個bit 
unsigned int toggle_bit(unsigned int num, int n) {
    return num ^ (1 << n);
}

// Swap 
int swap_bits(int *a, int *b) {
  if(*a != *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
  }
}

// Count1: 算有幾個1
int count_bits_one(unsigned int x)
{
    int count = 0;
    while (x!=0)
    {
        x = x & (x-1);
	    count++;
    }
    return count;
}



int main() {
    unsigned int num = 0b101010; // Example number: 42 in binary
    int pos1 = 1, pos2 = 5;

    printf("Original number: %u (binary: 0b101010)\n", num);

    // Set bit
    unsigned int setResult = set_bit(num, 2);
    printf("Set bit at position 2: %u (binary: 0b101110)\n", setResult);

    // Clear bit
    unsigned int clearResult = clear_bit(num, 3);
    printf("Clear bit at position 3: %u (binary: 0b100010)\n", clearResult);

    // Toggle bit
    unsigned int toggleResult = toggle_bit(num, 4);
    printf("Toggle bit at position 4: %u (binary: 0b111010)\n", toggleResult);

    // Swap bits
    printf("Before Swap bits at position %d and %d\n", pos1, pos2);
    swap_bits(&pos1, &pos2);
    printf("After Swap bits at position %d and %d\n", pos1, pos2);

    // Count bit 1s
    int countResult = count_bits_one(num);
    printf("Number of 1s in %u: %d\n", num, countResult);

    return 0;
}
