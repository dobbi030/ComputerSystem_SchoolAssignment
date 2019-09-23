#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define assert(condition)							\
do {															\
if ((condition)) {											\
printf("Test success: %s\n", #condition);		\
} else {														\
printf("Test FAIL: %s\n", #condition);			\
}																\
} while(0)


void* mock_calloc(size_t nmemb, size_t size);
int msb(int x);
int size_t_multi_ok(size_t x, size_t y);


int main()
{
	//It is overflow
	assert(mock_calloc((size_t)1 << 63, (size_t)1 << 63) == NULL);

	//size is 0
	assert(mock_calloc(0, 5) == NULL);

	//size is 0
	assert(mock_calloc(5, 0) == NULL);

	//well done!
	assert(mock_calloc(1234, 3) != NULL);
}


/*Implement calloc
*
*@param nmemb	a number of data type
*@param size		size of data type
*
*@return				pointer of allocated data
*/
void* mock_calloc(size_t nmemb, size_t size)
{
	//if size multipliance is overflow, return NULL
	//if size of nmemb is 0, return NULL
	if (nmemb == 0 || size == 0 || !(size_t_multi_ok(nmemb, size)))
		return NULL;

	void* data = malloc(nmemb * size);

	memset(data, 0, nmemb * size);

	return data;
}


/*Return most significant bit*/
int msb(int x)
{
	return (x >= 0) ? 0 : 1;
}


/*
*this function determine whether unsigned arguments can be multiplied without overflow
*
*@param x	the front data in the operation
*@param y	next data in the operation
*
*@return		if operation success without overflow, return 0, otherwise return 1.
*/
int size_t_multi_ok(size_t x, size_t y)
{
	return (x == 0 || (x * y) / x == y);
}
