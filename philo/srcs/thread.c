/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:42:21 by mtavares          #+#    #+#             */
/*   Updated: 2022/07/29 01:07:21 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	printf("Sou fantastico de %i\n", philo->id);
	return (NULL);
}

void	thread_creation(t_philo	**philo)
{
	int	i;

	i = -1;
	while (++i < (*philo)->data->philo_num)
	{
		pthread_mutex_init(&(*philo)[i].table[i].mutex_fork, NULL);
		pthread_create(&(*philo)[i].philo, NULL, &routine, (*philo + i));
	}
	i = -1;
	while (++i < (*philo)->data->philo_num)
	{
		pthread_mutex_destroy(&(*philo)[i].table[i].mutex_fork);
		pthread_join((*philo)[i].philo, NULL);
	}
}
