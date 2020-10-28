#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Inspiration : marceloboeira
// I wanted to use a function checking if every single divider was a prime
// number. However, it takes much time to first check if a divider is prime and
// then if the number is divisable by this prime number. 
// I use a temp variable here. If a number is divisable by a divider, I put
// this divider in a variable, replace the number by its division by the
// divider, and the divider by 1 (since it will be incremented on the next line).
// The return value of prime_factor is long and not int since the value of temp
// could exceed the int_max.
long     prime_factor(long long number)
{
	int		divider;
	long	temp;

	divider = 2;
	temp = 0;
	while (divider <= number)
	{
		if (number % divider == 0)
		{
			temp = divider;
			number /= divider;
			divider = 1;
		}
		divider++;
	}
	return (temp);
}

// Can't use atoi here since we're working with long long
int     main()
{
	long		res2;
	long long	number;
	
	number = 600851475143;
	res2 = prime_factor(number);
	printf("%ld\n", res2);
	remove("a.out");
	return (0);
}