#include "philo.h"

t_input	*save_input(char **argv)
{
	t_input	*input;

	input = (t_input *)malloc(sizeof(t_input));
	input->philo_count = ph_atoi(argv[1]);
	input->time_to_die = ph_atoi(argv[2]);
	input->time_to_eat = ph_atoi(argv[3]);
	input->time_to_sleep = ph_atoi(argv[4]);
	if (argv[5])
		input->must_eat = ph_atoi(argv[5]);
	else
		input->must_eat = INT_MIN;
	return (input);
}

void	allocate_forks(pthread_mutex_t *forks, t_program *program, t_input input)
{
	int	i;

	i = 0;
	forks = (pthread_mutex_t *)malloc(input.philo_count * sizeof(pthread_mutex_t));
	if (!forks)
		perror("Failed to malloc forks");
	while (i < input.philo_count)
	{
		if (pthread_mutex_init(&forks[i], NULL))
			perror("Fork mutex init error");
		i++;
	}
	program->forks = forks;
}

t_philo	*allocate_philo(t_philo *philo, t_program *program, t_input *input)
{
	int	i;

	i = 0;
	philo = (t_philo *)malloc(input->philo_count * sizeof(t_philo));
	if (!philo)
		exit (1);
	while (i < input->philo_count)
	{
		philo[i].id = i + 1;
		philo[i].start_time = get_time();
		philo[i].last_eaten = get_time();
		philo[i].times_eaten = 0;
		philo[i].input = input;
		philo[i].eating = 0;
		philo[i].dead = &program->dead;
		philo[i].left_fork = &program->forks[i];
		if (i == 0)
			philo[i].right_fork = &program->forks[input->philo_count - 1];
		else
			philo[i].right_fork = &program->forks[i - 1];
		i++;
	}
	program->philo = philo;
	return (philo);
}

void	initiate_program(t_program *program, t_philo *philo, t_input *input)
{
	pthread_mutex_t	*forks;

	forks = NULL;
	program->dead = 0;
	allocate_forks(forks, program, *input);
	philo = allocate_philo(philo, program, input);
}