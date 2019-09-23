#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
	//change x to character, we can replace x's specific byte.
	unsigned char* p = &x;

	//Little Endian
	*(p + i) = b;

	//Big Endian
	//*(p + 3 - i) = b;

	return x;
}


int main(void)
{
	printf("%0x\n", replace_byte(0x12345678, 2, 0xAB));
	printf("%0x\n", replace_byte(0x12345678, 0, 0xAB));

	return 0;
}