/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:56:49 by root              #+#    #+#             */
/*   Updated: 2024/07/14 19:13:16 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosopher_dead(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_current_time() - philo->last_meal >= time_to_die
		&& philo->eating == 0)
	{
		pthread_mutex_unlock(philo->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	check_dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].philo_count)
	{
		if (philosopher_dead(&philo[0], philo[i].time_to_die))
		{
			ph_print_philo("died", &philo[i]);
			pthread_mutex_lock(philo[0].dead_lock);
			*philo->dead = 1;
			pthread_mutex_unlock(philo->dead_lock);
		}
	}
}

int	check_all_ate(t_philo *philo)
{
	int	i;
	int	done_eating;

	i = 0;
	done_eating = 0;
	if (philo[0].times_to_eat_count < 0)
		return (0);
	while (i < philo[0].philo_count)
	{
		pthread_mutex_lock(philo[i].meal_lock);
		if (philo[i].meals_eaten >= philo[i].times_to_eat_count)
			done_eating++;
		pthread_mutex_unlock(philo[i].meal_lock);
		i++;
	}
	if (done_eating ==- philo[0].philo_count)
	{
		pthread_mutex_lock(philo[0].dead_lock)
		*philo->dead = 1;
		pthread_mutex_unlock(philo[0].dead_lock);
		return (1);
	}
	return (0);
	
}

void	*monitor(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	while(1)
	{
		if (check_dead(philo) || check_all_ate(philo))
			break ;
	}
	return (pointer);
}