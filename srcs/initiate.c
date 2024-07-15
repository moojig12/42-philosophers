#include "philo.h"

void	save_input(t_philo *philo, char **argv)
{
	philo->philo_count = ph_atoi(argv[1]);
	philo->time_to_die = ph_atoi(argv[2]);
	philo->time_to_eat = ph_atoi(argv[3]);
	philo->time_to_sleep = ph_atoi(argv[4]);
	if (argv[5])
		philo->times_to_eat_count = ph_atoi(argv[5]);
	else
		philo->times_to_eat_count = INT_MIN;
}

void	initiate_program(t_program *program, t_philo *philo)
{
	program->found_dead = 0;
	program->philo = philo;
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
	return ;
}

void	initiate_forks(pthread_mutex_t *forks, int philo_count)
{
	int	i;

	i = 0;
	while (i < philo_count)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	initiate_philosophers(t_philo *philo, pthread_mutex_t *forks, \
	t_program *program, char **argv)
{
	int	i;

	i = 0;
	while (i < ph_atoi(argv[1]))
	{
		philo[i].id = i + 1;
		save_input(&philo[i], argv);
		philo[i].eating = 0;
		philo[i].meals_eaten = 0;
		philo[i].start_time = get_current_time();
		philo[i].last_meal = get_current_time();
		philo[i].dead = &program->found_dead;
		philo[i].dead_lock = &program->dead_lock;
		philo[i].meal_lock = &program->meal_lock;
		philo[i].write_lock = &program->write_lock;
		if (i == 0)
			philo[i].right_fork = &forks[philo[i].philo_count - 1];
		else
			philo[i].right_fork = &forks[i - 1];
		i++;
	}
}