#include <stdio.h>

#define assert(condition)							\
do {															\
if ((condition)) {											\
printf("Test success: %s\n", #condition);		\
} else {														\
printf("Test FAIL: %s\n", #condition);			\
}																\
} while(0)


int main(void)
{
	assert(threefourths(2147483647) == 1610612735);
}

/*
*this function operate 3/4x
*
*@param x
*
*@return		3/4x
*/
int threefourths(int x)
{
	//first, compare (x / 4 * 4) and x
	//second, x / 4 and * 3
	//plus the distance of first comparison / 4 * 3

	int comparison = x / 4 * 4;
	int before = x / 4 * 3;

	return before + (x - comparison) * 3 / 4;
}