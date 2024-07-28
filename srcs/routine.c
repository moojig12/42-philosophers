#include "philo.h"

void	philo_message(char *message, t_philo *philo)
{
	printf("%ld %i %s\n", get_current_time(philo), philo->id, message);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	philo_message("has taken a fork", philo);
	if (philo->input->philo_count == 1)
	{
		usleep(philo->input->time_to_die);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	philo_message("has taken a fork", philo);

	philo->eating = 1;
	philo_message("is eating", philo);
	// pthread_mutex_lock(philo->meal_lock);
	philo->times_eaten++;
	philo->last_eaten = get_time();
	// pthread_mutex_unlock(philo->meal_lock);
	usleep(philo->input->time_to_eat);
	philo->eating = 0;

	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleepy(t_philo *philo)
{
	philo_message("is sleeping", philo);
	usleep(philo->input->time_to_sleep);
}

void	think(t_philo *philo)
{
	philo_message("is thinking", philo);
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (philo->dead == 0)
	{
		eat(philo);
		sleepy(philo);
		think(philo);
	}
	return (NULL);
}