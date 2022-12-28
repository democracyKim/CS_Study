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

// #include <stdio.h>

// int main()
// {
// 	int nums[] = {555,901,482,1771};
// 	printf("%d", findNumbers(nums, 4));
// }