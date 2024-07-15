#include "philo.h"

void	philo_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!dead_loop(philo))
	{
		eat(philo);
		sleepy(philo);
		think(philo);
	}
	return (pointer);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	ph_print_philo("has taken a fork", philo);
	if (philo->philo_count == 1)
	{
		usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->right_fork);
	}
	pthread_mutex_lock(philo->left_fork);
	ph_print_philo("has taken a fork", philo);
	philo->eating = 1;
	ph_print_philo("is eating", philo);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	usleep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleepy(t_philo *philo)
{
	ph_print_philo("is sleeping", philo);
	usleep(philo->time_to_sleep);
}

void	think(t_philo *philo)
{
	ph_print_philo("is thinking", philo);
}