#include <stdio.h>

int bad_int_size_is_32() {
	int set_msb = 1 << 31;

	//if we follow bit level integer coding rules
	int beyond_msb = set_msb << 1;
	// = 1 << 31 << 1

	//if we don't
	//int beyond_msb = set_msb * 2;

	return set_msb && !beyond_msb;
}

int bad_int_size_is_32_for_16bit() {
	int set_msb = 1 << 15 << 15 << 1;
	
	int beyond_msb = set_msb << 1;
	// = 1 << 15 << 15 << 1 << 1

	//int beyond_msb = set_msb * 2;

	return set_msb && !beyond_msb;
}