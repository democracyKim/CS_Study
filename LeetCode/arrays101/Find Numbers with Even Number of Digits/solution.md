# [Find Numbers with Even Number of Digits][link]
[link]: https://leetcode.com/explore/featured/card/fun-with-arrays/521/introduction/3237/ "link"
Given an array nums of integers, return how many of them contain an even number of digits.

# Intuition
- Try to find the method of getting nums of digits.
- When you get digits, you should judge whether or not it is odd.

# Functions
- int HowManyDigits(int num)
: if (num / 10) > 1, you can add 1 to the digit

- int IsItEven (int num)
: Even numbers are numbers that are divisible by 2

# Complexity
- Time complexity:

- Space complexity:

# Code
```c
int HowManyDigits(int num)
{
	int	digit;

	digit = 1;
	while (num / 10)
	{
		digit++;
		num /= 10;
	}
	return (digit);
}

int IsItEven (int num)
{
	if ((num % 2) == 0)
		return (1);
	return (0);
}

int findNumbers(int* nums, int numsSize)
{
	int count;

	count = 0;
	for (int i = 0; i < numsSize; i++)
		count += IsItEven(HowManyDigits(*(nums + i)));
	return (count);
}
```