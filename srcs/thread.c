#include "philo.h"

void	create_threads(t_program *program, t_philo *philo, t_input *input)
{
	pthread_t	observer;
	int			i;

	if (pthread_create(&observer, NULL, &monitor, program->philo))
		destroy_all(program);
	i = 0;
	while (i < input->philo_count)
	{
		if (pthread_create(&program->philo[i].thread, NULL, &routine, &program->philo[i]))
			destroy_all(program);
		i++;
	}
	if (pthread_join(observer, NULL) != 0)
		destroy_all(program);
	i = 0;
	while (i < input->philo_count)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			destroy_all(program);
		i++;
	}
}