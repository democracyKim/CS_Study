//#include <stdio.h>
#include <stdlib.h>

int bigger_square(int a, int b, int *left, int *right)
{
	if (a * a > b * b)
	{
		(*left)++;
		return (a * a);
	}
	(*right)--;
	return (b * b);
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
		res[i] = bigger_square(*(nums + left), *(nums + right), &left, &right);
		i--;
	}
	return (res);
}

// int main(){
// 	int nums[] = {-4, -1, 0, 3, 10};
// 	int size = 5;
// 	int *res = sortedSquares(nums, 5, &size);
}
