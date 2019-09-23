#include <stdio.h>

int any_odd_one(unsigned x)
{
	//show as bit, mask = 10101010101010101010101010101010 (odd bit is all equal 1)
	unsigned mask = 0xaaaaaaaa;

	//when x & mask, if any outcome has value, x has 1 in its odd bit.
	//if data has value, its "not" is 0, 0's "not" is 1. so if double "not" at value, it becomes 1.
	//double "not" at zero, it becomes 0 (0 -> 1 -> 0)

	return !!(x & mask);	
}

//Test
int main(void)
{
	unsigned x = 0x55555555;

	printf("%d", any_odd_one(x));
	
}