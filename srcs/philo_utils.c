#include "philo.h"

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

size_t	get_time()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

size_t	get_current_time(t_philo *philo)
{
	struct timeval	time;
	size_t			current;

	gettimeofday(&time, NULL);
	current = (time.tv_sec * 1000 + time.tv_usec / 1000);
	return (current - philo->start_time);
}

void	destroy_all(t_program *program)
{
	if (program)
		return ;
}