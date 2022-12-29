# [Squares of a Sorted Array][link]
[link]: https://leetcode.com/explore/featured/card/fun-with-arrays/521/introduction/3240/ "link"
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.  
- non-decreasing order: the next value of each number is the same or bigger.
	- ex) 1 2 3 3 5 8

- int* sortedSquares(int* nums, int numsSize, int* returnSize)

# Intuition
### solution 1: two-pass
- Finding the squares of each number and sorting.

### soulution 2: one-pass
- Because the input nums are in non-decreasing order, you can assume that the abs of the negative number are in non-increasing order. On the other hand, the abs of the positive number are in non-decreasing order. In other words, the largest abs of the negative number is on the left side, and that of the positive number is on the right side. We put the larger one in the res reversely.

- Make two variables, one is the left, and the other is the right.
- Compare the abs of two values, and input the larger value to the returnSize by transforming the square.

# Functions
### int square(int num)
- return the square of input number.

### int bigger_abs(int a, int b, int *start, int *end)
- return the bigger abs and move the index of it.

# Complexity
- Time complexity: O(n)

- Space complexity: O(1)

# Code
```c
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
// }
```