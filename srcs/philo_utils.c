#include "philo.h"

int	ph_print(char *message, int fd)
{
	int	len;

	len = 0;
	while (message[len])
	{
		len++;
	}
	write(fd, message, len);
	if (fd == 2)
		return (1);
	else
		return (0);
}

int	ph_atoi(char *input)
{
	int	count;
	int	number;
	int	sign;

	count = 0;
	sign = 1;
	while (input[count] == ' ' || (9 <= input[count] && input[count] <= 13))
		count++;
	if (input[count] == '-' || input[count] == '+')
	{
		if (input[count] == '-')
			sign *= -1;
		count++;
	}
	number = 0;
	while ('0' <= input[count] && input[count] <= '9')
	{
		number = (number * 10) + ((input[count] - '0'));
		count++;
	}
	return (sign * number);
}