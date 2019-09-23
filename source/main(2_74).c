#include <stdio.h>
#include <limits.h>


/*Return most significant bit*/
int msb(int x)
{
	return (x >= 0) ? 0 : 1;
}


/*
*this function determine whether arguments can be subtracted without overflow
*
*@param x		front one in the formula
*@param y		the other one in the formula
*
*@return int		if this operation causes overflow, return 1, otherwise return 0.
*/
int tsub_ok(int x, int y)
{
	//1. x = plus		y = plus			=> nothing
	//2. x = plus		y = minus		=> msb(x) != msb(x+y) (except, -8)
	//3. x = minus	y = plus			=> same with case 2.
	//4. x = minus	y = minus		=> same with case 1.

	return (((msb(x) != msb(y)) && (msb(x - y) != msb(x))) || (y == INT_MIN));
}


int main()
{
	//it's overflow
	int x1 = INT_MAX;
	int y1 = INT_MIN;

	//it's overflow
	int x2 = 1;
	int y2 = INT_MIN + 1;

	//it's not overflow
	int x3 = INT_MIN + 1;
	int y3 = 1;

	//it's overflow
	int x4 = INT_MIN + 1;
	int y4 = 2;


	printf("case 1 result is %d. it is \"%d\"\n", x1 - y1, tsub_ok(x1, y1));
	printf("case 2 result is %d. it is \"%d\"\n", x2 - y2, tsub_ok(x2, y2));
	printf("case 3 result is %d. it is \"%d\"\n", x3 - y3, tsub_ok(x3, y3));
	printf("case 4 result is %d. it is \"%d\"\n", x4 - y4, tsub_ok(x4, y4));
	
	return 0;
}