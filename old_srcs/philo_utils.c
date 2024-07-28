#include "philo.h"

void	ph_print_philo(char *message, t_philo *philo)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_current_time() - philo->start_time;
	if (!dead_loop(philo))
		printf("%zu %d %s\n", time, philo->id, message);
	pthread_mutex_unlock(philo->write_lock);
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

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(milliseconds);
	return (0);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday error\n", 20);
	return (time.tv_sec * 1000 + time.tv_usec / 100);
}

void	destroy_all(char *str, t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (str)
		printf("%s\n", str);
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->dead_lock);
	while (i < program->philo[0].philo_count)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}