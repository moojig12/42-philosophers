#include "philo.h"

int	all_ate(t_philo *philo)
{
	int	hungry;
	int	i;

	if (philo->input->must_eat == INT_MIN)
		return (0);
	i = 0;
	hungry = 0;
	while (i < philo->input->philo_count)
	{
		if (philo[i].times_eaten < philo->input->must_eat)
			hungry = 1;
		i++;
	}
	if (hungry == 1)
		return (1);
	else
		return (0);
}

int	lookup_dead(t_philo *philo)
{
	if (!philo)
		return (1);
	return (0);
}

void	*monitor(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (1)
	{
		if (lookup_dead(philo) || all_ate(philo))
			break ;
	}
	return (NULL);
}