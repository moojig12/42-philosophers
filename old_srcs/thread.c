#include "philo.h"

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if  (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
	
}

void	create_threads(t_program *program, pthread_mutex_t *forks)
{
	pthread_t	observer;
	int	i;

	if (pthread_create(&observer, NULL, &monitor, program->philo))
		destroy_all("Thread create error", program, forks);
	i = 0;
	while (i < program->philo[0].philo_count)
	{
		if (pthread_create(&program->philo[i].thread, NULL, \
			&philo_routine, &program->philo[i]))
			destroy_all("Thread create error", program, forks);
		i++;
	}
	if (pthread_join(observer, NULL))
			destroy_all("Thread join error for observer", program, forks);
	i = 0;
	while (i < program->philo[0].philo_count)
	{
		if (pthread_join(program->philo[i].thread, NULL)  != 0)
			destroy_all("Thread join error for philo", program, forks);
		i++;
	}
}