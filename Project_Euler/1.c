#include <stdio.h>

int     multiple(int number)
{
    int natural;
    int sum;

    natural = 0;
    sum = 0;
    while (natural < number)
    {
        if ((natural % 3) == 0 || (natural % 5) == 0)
            sum += natural;
        natural++;                
    }
    return (sum);
}

int     main(int ac, char **av)
{
	int	number;
    int    res1;
    int    res2;
	
	(void)ac;
    number = 10;
    res1 = multiple(number);
    number = 1000;
    res2 = multiple(number);
	remove(av[0]);
    printf("res1 [%u]\t res2 [%u]\n", res1, res2);
	return (0);
}