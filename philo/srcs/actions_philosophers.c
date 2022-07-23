/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Actions_philosophers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 23:55:13 by mtavares          #+#    #+#             */
/*   Updated: 2022/07/24 00:02:33 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	get_fork(t_philo *philo, t_lu start, int *is_taken)
{
	if (philo->id)
	{	
		if (philo->table->fork && (philo + 1)->table->fork)
		{
			pthread_mutex_lock(philo->mutex);
			philo->table->fork == 0;
			(philo - 1)->table->fork;
			*is_taken = 1;
			printf("%lu %i has taken the fork\n", get_time(start), philo->id);
			pthread_mutex_unlock(philo->mutex);
		}
	}
	else
	{
		if (philo->table->fork && \
		(philo + philo->gen->philo_num - 1)->table->fork)
		{
			pthread_mutex_lock(philo->mutex);
			philo->table->fork == 0;
			(philo + philo->gen->philo_num - 1)->table->fork;
			*is_taken = 1;
			printf("%lu %i has taken the fork\n", get_time(start), philo->id);
			pthread_mutex_unlock(philo->mutex);
		}
	}
}

void	eating(t_philo *philo, t_lu start, int is_taken)
{
	get_fork(philo, start, &is_taken);
	if (is_taken)
	{
		printf("%lu %i is eating\n", get_time(start), philo->id);
		usleep(25);
	}
}
