#include "philo.h"

void	free_forks(pthread_mutex_t	*forks, int	count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	// free(forks);
}

void	free_philo(t_philo *philo)
{
	free(philo->input);
	// free(philo);
}

void	destroy_all(t_program *program)
{
	if (program)
	{
		if (program->forks)
			free_forks(program->forks, program->philo->input->philo_count);
		if (program->philo)
			free_philo(program->philo);
		pthread_mutex_destroy(&program->meal_lock);
		pthread_mutex_destroy(&program->dead_lock);
		pthread_mutex_destroy(&program->write_lock);
	}
}
