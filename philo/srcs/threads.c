/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 23:36:17 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/11 22:32:38 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	*philo_work(void *arg)
{
	t_philo	*p;
	t_time	timer;

	p = (t_philo *)arg;
	if (p->id % 2 == 0)
		usleep(10000);
	timer.start = current_time();
	timer.last_action = timer.start;
	timer.last_meal = timer.start;
	while (++p->num_time_eaten * (p->data.have_last_arg) <= \
	(p->data.have_last_arg) * p->data.num_time_to_eat && \
	!is_dead(p, &timer))
	{
		eat(p, &timer);
		if (is_dead(p, &timer))
			return (NULL);
		print_message(p, &timer, "is sleeping", 0);
		usleep(p->data.time_to_sleep * 1000);
		if (is_dead(p, &timer))
			return (NULL);
		print_message(p, &timer, "is thinking", 0);
	}
	return (NULL);
}

void	thread_creation(t_philo **philo)
{
	int	i;

	i = -1;
	while (++i < (*philo)[0].data.philo_num)
		pthread_create(&(*philo)[i].philo, NULL, &philo_work, (*philo + i));
	i = -1;
	while (++i < (*philo)->data.philo_num)
		pthread_join((*philo)[i].philo, NULL);
	i = -1;
	while (++i < (*philo)->data.philo_num)
		pthread_mutex_destroy(&(*philo)[i].table[i].mutex_fork);
}
