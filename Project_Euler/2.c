#include <stdio.h>
#include <stdlib.h>

// my first idea was to make use of recursive functions. however, a segfault
// occurs due to a buffer overflow. Therefore, I used a temp and redefinition
// of variables, based on codes found on github.
// Inspiration : RisingLight, nayuki
/*int		even_fib(int maximum)
{
	int	sum;
	int	term;
	int	number;

	number = 0;
	sum = 0;
	term = 0;
	while (number < maximum)
	{
		sum = number + (number - 1);
		number++;
	}
}
int		fibonacci(int term)
{
	int	sum;

	sum = 0;
	if (term < 0)
		return (-1);
	if (term == 0)
		return (0);
	if (term == 1)
		return (1);
	sum = fibonacci(term - 1) + fibonacci(term - 2);
	return (sum);
}*/

int		fibonacci(int term)
{
	int	sum;
	int	min_1_res;
	int	min_2_res;
	int	temp;

	sum = 0;
	min_2_res = 1;
	min_1_res = 2;
	while (min_2_res <= term)
	{
		if (min_2_res % 2 == 0)
			sum += min_2_res;
		temp = min_1_res + min_2_res;
		min_2_res = min_1_res;
		min_1_res = temp;
	}
	return (sum);
}

int		main()
{
	int	res;
	int	number;

	number = 4000000;
	res = fibonacci(number);
	printf("%d\n", res);
	remove("a.out");
	return (0);
}