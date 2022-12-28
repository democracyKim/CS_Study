# [Max Consecutive Ones][maxlink]
[maxlink]: https://leetcode.com/explore/featured/card/fun-with-arrays/521/introduction/3238/ "link"
# Intuition
To find the max one, compare the new possible max and an old max.

# Approach
This problem gives you the number array and numsSize. 
- While searching 0th index to (numsSize -1)th index
  - if you find the 1, add 1 to the count, for counting consecutive 1.
  - else you find the 0, compare the count vs the max
- When you escape the loop, there are two variables - the count and the max
    - Before returning the answer, you should compare the count with the max. 

# Complexity
- Time complexity:
O(n)

- Space complexity:
O(1)

# Code
```c
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
```