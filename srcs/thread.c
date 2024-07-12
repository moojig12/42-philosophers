/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:05:12 by root              #+#    #+#             */
/*   Updated: 2024/07/12 21:39:36 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_single_thread(t_program *program, pthread_mutex_t *forks, char* mode, int i)
{
	if (ph_strcmp("philo", mode))
	{
		if (pthread_create(&program->philo[i].thread, NULL, \
			&philo_routine, &program->philo[i]))
			destroy_all("Thread error", program, forks);
	}
	else
	{
		if (pthread_create(&program->observer, NULL, &monitor, program->philo))
		destroy_all("Thread error", program, forks);
	}
}

void	create_threads(t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < program->philo_count)
	{
		create_single_thread(program, forks, "philo", i);
	}
}