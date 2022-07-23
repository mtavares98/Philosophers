/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 22:01:21 by mtavares          #+#    #+#             */
/*   Updated: 2022/07/24 00:06:28 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	think(t_philo *philo, t_lu start)
{
	usleep(25);
	printf("%lu %i is thinking\n", get_time(start), philo->id);
}

static void	sleep(t_philo *philo, t_lu start)
{
	printf("%lu %i is sleeping\n", get_time(start), philo->id);
	usleep(25);
}

void	*routine(void *args)
{
	t_lu		start;	
	t_philo		*philo;
	int			is_taken;

	start = get_time(0);
	philo = (t_philo *)args;
	is_taken = 0;
	while (check_num_times_to_eat(*philo->gen) || philo->is_dead)
	{
		if (!philo->is_dead)
			eating(philo, start, is_taken);
		if (!philo->is_dead)
			sleep(philo, start);
		if (!philo->is_dead)
			think(philo, start);
		else
			return (NULL);
	}
	return (NULL);
}

void	thread_creation(t_philo *p)
{
	int			i;

	i = -1;
	pthread_mutex_init(p->mutex, NULL);
	while (++i < p->gen->philo_num)
	{
		if (pthread_create(&p->philo, NULL, &routine, (void *)(p + i)) != 0)
			exit (printf("Error during thread creation\n"));
		if (pthread_detach(p->philo) != 0)
			exit (printf("Error during detach\n"));
	}
	pthread_mutex_destroy(p->mutex);
	pthread_exit(0);
	printf("Threads has been killed\n");
	i = -1;
}
