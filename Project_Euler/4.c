// In progress

#include <stdio.h>

// int		product(int number)
// {}

int		is_palindrome(long long number)
{
	long long	rev_num;
	long long	original_num;

	original_num = number;
	rev_num = 0;
	while (number)
	{
		rev_num = rev_num * 10 + (number % 10);
		number /= 10;
	}
	if (original_num == rev_num)
		return (1);
	return (0);
}

/*int		largest_pal(void)
{
	long long	three_dig1;
	long long	three_dig2;

	three_dig1 = 999;
	three_dig2 = 999;
	while (three_dig1 >= 100)
	{
		while (three_dig2 >= 100)
		{
			if (is_palindrome(three_dig1 * three_dig2))
				break ;
			three_dig2--;
		}
		three_dig1--;
	}
	return (three_dig);
}*/

int		largest_pal(void)
{
	long long	x;
	long long	y;
	long long	prod;

	prod = 0;
	x = 19;
	while (x >= 10)
	{
		y = x;
		while (y >= 10)
		{
			printf("x = %lld y = %lld\n", x, y);
			prod = x * y;
			if (is_palindrome(prod))
			{
				printf("break here, x = %lld y = %lld\n", x, y);
				return (prod);
			}
			y--;
		}
		x--;
	}
	return (prod);
}

// int		largest_pal(void)
// {
// 	long long	x;
// 	long long	y;
// 	long long	prod;
// 	// long long	temp;

// 	y = 999;
// 	prod = 0;
// 	x = 999;
// 	while (y >= 100)
// 	{
// 		while (x >= y)
// 		{
// 			printf("x = %lld y = %lld\n", x, y);
// 			prod = x * y;
// 			if (is_palindrome(prod))
// 			{
// 				printf("break here, x = %lld y = %lld\n", x, y);
// 				return (prod);
// 			}
// 			x--;
// 		}
// 		y -= 10;
// 	}
// 	return (prod);
// }

int		main()
{
	// int	number;
	// int	res1;
	int	res2;

	// number = 404;
	// res1 = is_palindrome(number);
	res2 = largest_pal();
	printf("%d\n", res2);
	return (0);
}