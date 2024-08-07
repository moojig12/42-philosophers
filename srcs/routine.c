#include "philo.h"

void	philo_message(char *message, t_philo *philo)
{
	pthread_mutex_lock(philo->write_lock);
	if (!dead_loop(philo))
		printf("%ld %i %s\n", get_current_time(philo), philo->id, message);
	pthread_mutex_unlock(philo->write_lock);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	philo_message("has taken a fork", philo);
	if (philo->input->philo_count == 1)
	{
		ft_usleep(philo->input->time_to_die);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	philo_message("has taken a fork", philo);
	philo->eating = 1;
	philo_message("is eating", philo);
	pthread_mutex_lock(philo->meal_lock);
	// philo_message("has meal lock", philo);
	philo->times_eaten++;
	philo->last_eaten = get_time();
	pthread_mutex_unlock(philo->meal_lock);
	// philo_message("has unlocked meal", philo);
	ft_usleep(philo->input->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	think(t_philo *philo)
{
	philo_message("is thinking", philo);
}

void	sleepy(t_philo *philo)
{
	philo_message("is sleeping", philo);
	ft_usleep(philo->input->time_to_sleep);
	think(philo);
}


int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!dead_loop(philo))
	{
		eat(philo);
		sleepy(philo);
	}
	return (NULL);
}