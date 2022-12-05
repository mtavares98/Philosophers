/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 23:36:17 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/01 18:30:48 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	*philo_work(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->id % 2 == 0)
		usleep(1000);
	pthread_mutex_lock(p->print);
	pthread_mutex_unlock(p->print);
	while (++p->num_time_eaten * (p->data.have_last_arg) <= \
	(p->data.have_last_arg) * p->data.num_time_to_eat && \
	!is_dead(p))
	{
		eat(p);
		if (is_dead(p))
			return (NULL);
		print_message(p, "is sleeping", 0);
		usleep(p->data.time_to_sleep * 1000);
		if (is_dead(p))
			return (NULL);
		print_message(p, "is thinking", 0);
	}
	return (NULL);
}

void	thread_creation(t_philo **philo)
{
	t_time					*time;
	static pthread_mutex_t	print;
	int						i;

	time = init_timer();
	time->start = current_time();
	pthread_mutex_init(&print, NULL);
	i = -1;
	while (++i < (*philo)[0].data.philo_num)
	{
		(*philo)[i].print = &print;
		(*philo)[i].t = time;
		(*philo)[i].last_action = time->start;
		(*philo)[i].last_meal = time->start;
		pthread_create(&(*philo)[i].philo, NULL, &philo_work, (*philo + i));
	}
	i = -1;
	while (++i < (*philo)->data.philo_num)
		pthread_join((*philo)[i].philo, NULL);
	i = -1;
	while (++i < (*philo)->data.philo_num)
		pthread_mutex_destroy(&(*philo)[i].table[i].mutex_fork);
}
