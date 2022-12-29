# [Find Numbers with Even Number of Digits][link]
[link]: https://github.com/democracyKim/CS_Study/tree/main/LeetCode/arrays101/Find%20Numbers%20with%20Even%20Number%20of%20Digits "link"
Given an array nums of integers, return how many of them contain an even number of digits.

# Intuition
- Try to find the method of getting nums of digits.
- When you get digits, you should judge whether or not it is even.

# Functions
### int HowManyDigits(int num)
- if (num / 10) > 1, you can add 1 to the digit

### int IsItEven (int num)
- Even numbers are numbers that are divisible by 2

# Complexity
- Time complexity: O(n)

- Space complexity: O(1)

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
