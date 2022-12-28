int WhatIsMax(int count, int max)
{
	if (count >= max)
		return count;
	return max;
}

int findMaxConsecutiveOnes(int* nums, int numsSize)
{
	int count;
	int	max;

	count = 0;
	max = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (*(nums + i) == 1)
			count++;
		else
		{
			max = WhatIsMax(count, max);
			count = 0;
		}
	}
    return (WhatIsMax(count, max));
}
