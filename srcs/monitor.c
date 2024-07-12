/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:56:49 by root              #+#    #+#             */
/*   Updated: 2024/07/12 21:28:36 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	*monitor(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	while(1)
	{
		if (check_if_dead(philo) || check_if_all_ate(philo))
			break ;
	}
	return (pointer);
}