//#include <stdio.h>
#include <stdlib.h>

int square(int num)
{
	return (num * num);
}

int bigger_abs(int a, int b, int *left, int *right)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a > b)
	{
		(*left)++;
		return (a);
	}
	(*right)--;
	return (b);
}

int* sortedSquares(int* nums, int numsSize, int* returnSize)
{
	int	left;
	int right;
	int *res;
	int i;

	*returnSize = numsSize;
	left = 0;
	right = numsSize - 1;
	i = right;
	res = (int *)malloc(sizeof(int) * (numsSize));
	while (left <= right)
	{
		res[i] = square(bigger_abs(*(nums + left), *(nums + right), &left, &right));
		//printf("res = %d\n", res[i]);
		i--;
	}
	return (res);
}

// int main(){
// 	int nums[] = {-4, -1, 0, 3, 10};
// 	int size = 5;
// 	int *res = sortedSquares(nums, 5, &size);
}
