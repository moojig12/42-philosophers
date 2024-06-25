#include "philo.h"

static void	save_input(t_program *program, char **argv)
{
	program->time_to_die = ph_atoi(argv[2]);
	program->time_to_eat = ph_atoi(argv[3]);
	program->time_to_sleep = ph_atoi(argv[4]);
	program->philo_count = ph_atoi(argv[1]);
	if (argv[5])
		program->times_to_eat_count = ph_atoi(argv[5]);
	else
		program->times_to_eat_count = INT_MIN;
}

void	initiate_program(t_program *program, t_philo *philo, char **argv)
{
	save_input(program, argv);
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