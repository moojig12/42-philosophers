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
		// pthread_mutex_lock(philo->meal_lock);
		if (philo[i].times_eaten < philo->input->must_eat)
			hungry = 1;
		// pthread_mutex_unlock(philo->meal_lock);
		i++;
	}
	if (hungry == 1)
		return (0);
	else
	{
		pthread_mutex_lock(philo->dead_lock);
		*philo->dead = 1;
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
}

int	philo_dead(t_philo *philo, int time_to_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if (((get_time() - philo->last_eaten) > time_to_die) \
	&& philo->eating == 0)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	lookup_dead(t_philo *philo)
{
	int	i;

	i = 0;
	/* if (!philo)
		return (1); */
	while (i < philo->philo_count)
	{
		if (philo_dead(&philo[i], philo->input->time_to_die))
		{
			philo_message("died", philo);
			pthread_mutex_lock(philo->dead_lock);
			*philo->dead = 1;
			pthread_mutex_unlock(philo->dead_lock);
			return (1);
		}
		i++;
	}
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
	return (philo);
}